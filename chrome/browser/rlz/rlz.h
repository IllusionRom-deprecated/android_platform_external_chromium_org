// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_RLZ_RLZ_H_
#define CHROME_BROWSER_RLZ_RLZ_H_

#include "build/build_config.h"

#if defined(ENABLE_RLZ)

#include <map>
#include <string>

#include "base/basictypes.h"
#include "base/gtest_prod_util.h"
#include "base/memory/singleton.h"
#include "base/strings/string16.h"
#include "base/threading/sequenced_worker_pool.h"
#include "base/time/time.h"
#include "content/public/browser/notification_observer.h"
#include "content/public/browser/notification_registrar.h"
#include "rlz/lib/rlz_lib.h"

class Profile;
namespace net {
class URLRequestContextGetter;
}

// An interface to provide financial ping implementation.
class RLZTrackerDelegate {
 public:
  // Sends the financial ping to the RLZ servers. This method is virtual to
  // allow tests to override.
  virtual bool SendFinancialPing(const std::string& brand,
                                 const string16& lang,
                                 const string16& referral) = 0;
};

// RLZ is a library which is used to measure distribution scenarios.
// Its job is to record certain lifetime events in the registry and to send
// them encoded as a compact string at most twice. The sent data does
// not contain information that can be used to identify a user or to infer
// browsing habits. The API in this file is a wrapper around the open source
// RLZ library which can be found at http://code.google.com/p/rlz.
//
// For partner or bundled installs, the RLZ might send more information
// according to the terms disclosed in the EULA.
class RLZTracker : public content::NotificationObserver,
                   public RLZTrackerDelegate {
 public:
  // Initializes the RLZ library services for use in chrome. Schedules a delayed
  // task that performs the ping and registers some events when 'first-run' is
  // true.
  //
  // When |send_ping_immediately| is true, a financial ping should be sent
  // immediately after a first search is recorded, without waiting for |delay|.
  // However, we only want this behaviour on first run.
  //
  // If the chrome brand is organic (no partners) then the pings don't occur.
  static bool InitRlzFromProfileDelayed(Profile* profile,
                                        bool first_run,
                                        bool send_ping_immediately,
                                        base::TimeDelta delay);

  // Records an RLZ event. Some events can be access point independent.
  // Requires write access to the HKCU registry hive on windows.
  static void RecordProductEvent(rlz_lib::Product product,
                                 rlz_lib::AccessPoint point,
                                 rlz_lib::Event event_id);

  // For the point parameter of RecordProductEvent.
  static const rlz_lib::AccessPoint CHROME_OMNIBOX;
  static const rlz_lib::AccessPoint CHROME_HOME_PAGE;

  // Gets the HTTP header value that can be added to requests from the
  // specific access point.  The string returned is of the form:
  //
  //    "X-Rlz-String: <access-point-rlz>\r\n"
  //
  static std::string GetAccessPointHttpHeader(rlz_lib::AccessPoint point);

  // Gets the RLZ value of the access point.
  // Returns false if the rlz string could not be obtained. In some cases
  // an empty string can be returned which is not an error.
  static bool GetAccessPointRlz(rlz_lib::AccessPoint point, string16* rlz);

  // Invoked during shutdown to clean up any state created by RLZTracker.
  static void CleanupRlz();

#if defined(OS_CHROMEOS)
  // Clears all product state. Should be called when turning RLZ off. On other
  // platforms, this is done by product uninstaller.
  static void ClearRlzState();
#endif

  // This method is public for use by the Singleton class.
  static RLZTracker* GetInstance();

  // Enables zero delay for InitRlzFromProfileDelayed. For testing only.
  static void EnableZeroDelayForTesting();

 private:
  friend class RlzLibTest;
  friend class TestRLZTrackerDelegate;
  friend class base::RefCountedThreadSafe<RLZTracker>;
  friend struct DefaultSingletonTraits<RLZTracker>;

  FRIEND_TEST_ALL_PREFIXES(RlzLibTest, GetAccessPointRlzIsCached);
  FRIEND_TEST_ALL_PREFIXES(RlzLibTest, ObserveHandlesBadArgs);
  FRIEND_TEST_ALL_PREFIXES(RlzLibTest, PingUpdatesRlzCache);

  // Called by InitRlzFromProfileDelayed with values taken from |profile|.
  static bool InitRlzDelayed(bool first_run,
                             bool send_ping_immediately,
                             base::TimeDelta delay,
                             bool is_google_default_search,
                             bool is_google_homepage,
                             bool is_google_in_startpages);

  // Used by test code to override the default RLZTracker instance returned
  // by GetInstance().
  static void SetTrackerForTest(RLZTracker* tracker);

  RLZTracker();
  explicit RLZTracker(RLZTrackerDelegate* delegate);
  virtual ~RLZTracker();

  // Performs initialization of RLZ tracker that is purposefully delayed so
  // that it does not interfere with chrome startup time.
  void DelayedInit();

  // Sends the financial ping to the RLZ servers and invalidates the RLZ string
  // cache since the response from the RLZ server may have changed then.
  // Protected so that its accessible from tests.
  void SendFinancialPingNow();

  // Implementation called from InitRlzDelayed() static method.
  bool Init(bool first_run,
            bool send_ping_immediately,
            base::TimeDelta delay,
            bool google_default_search,
            bool google_default_homepage,
            bool is_google_in_startpages);

  // Gets the cached accesspoint rlz. Returns false if the cache doesn't exist.
  bool GetCachedAccessPointRlz(rlz_lib::AccessPoint point, string16* rlz);

#if defined(OS_CHROMEOS)
  // Implementation called from ClearRlzState static method.
  void ClearRlzStateImpl();
#endif

  // Schedules the delayed initialization. This method is virtual to allow
  // tests to override how the scheduling is done.
  void ScheduleDelayedInit(base::TimeDelta delay);

  // Schedules a call to rlz_lib::RecordProductEvent(). This method is virtual
  // to allow tests to override how the scheduling is done.
  void ScheduleRecordProductEvent(rlz_lib::Product product,
                                  rlz_lib::AccessPoint point,
                                  rlz_lib::Event event_id);
  // Schedules a call to rlz_lib::RecordFirstSearch(). This method is virtual
  // to allow tests to override how the scheduling is done.
  void ScheduleRecordFirstSearch(rlz_lib::AccessPoint point);

  // Schedules a call to rlz_lib::SendFinancialPing(). This method is virtual
  // to allow tests to override how the scheduling is done.
  void ScheduleSendFinancialPing();

  // Schedules a call to GetAccessPointRlz() on the I/O thread if the current
  // thread is not already the I/O thread, otherwise does nothing. Returns
  // true if the call was scheduled, and false otherwise. This method is
  // virtual to allow tests to override how the scheduling is done.
  void ScheduleGetAccessPointRlz(rlz_lib::AccessPoint point);


#if defined(OS_CHROMEOS)
  // Schedules a call to ClearRlzStateImpl().
  void ScheduleClearRlzState();
#endif

  // Implementation called from RecordProductEvent() static method
  // on SequencedWorkerPool.
  bool RecordProductEventImpl(rlz_lib::Product product,
                              rlz_lib::AccessPoint point,
                              rlz_lib::Event event_id);

  // Records FIRST_SEARCH event. Scheduled on SequencedWorkerPool
  // in Observe.
  void RecordFirstSearchImpl(rlz_lib::AccessPoint point);

  // Implementation of GetAccessPointRlz() invoked on SequencedWorkerPool.
  // This caches RLZ strings for all access points. If we had
  // a successful ping, then we update the cached value.
  void GetAccessPointRlzImpl(rlz_lib::AccessPoint point);

  void Cleanup();

  // Overridden from RZLTrackerDelegate:
  virtual bool SendFinancialPing(const std::string& brand,
                                 const string16& lang,
                                 const string16& referral) OVERRIDE;

  // content::NotificationObserver implementation:
  virtual void Observe(int type,
                       const content::NotificationSource& source,
                       const content::NotificationDetails& details) OVERRIDE;

  // Configuation data for RLZ tracker. Set by call to Init().
  bool first_run_;
  bool send_ping_immediately_;
  bool is_google_default_search_;
  bool is_google_homepage_;
  bool is_google_in_startpages_;

  // Unique sequence token so that tasks posted by RLZTracker are executed
  // sequentially in the blocking pool.
  base::SequencedWorkerPool::SequenceToken worker_pool_token_;

  // Keeps track if the RLZ tracker has already performed its delayed
  // initialization.
  bool already_ran_;

  // Keeps a cache of RLZ access point strings, since they rarely
  // change.  The cache must be protected by a lock since it may be
  // accessed from the UI thread for reading and the global blocking
  // pool for reading and/or writing.
  base::Lock cache_lock_;
  std::map<rlz_lib::AccessPoint, string16> rlz_cache_;

  // Keeps track of whether the omnibox or host page have been used.
  bool omnibox_used_;
  bool homepage_used_;

  // Main and (optionally) reactivation brand codes, assigned on UI thread.
  std::string brand_;
  std::string reactivation_brand_;

  content::NotificationRegistrar registrar_;

  RLZTrackerDelegate* delegate_;  // not owned.

  // Minimum delay before sending financial ping after initialization.
  base::TimeDelta min_init_delay_;

  DISALLOW_COPY_AND_ASSIGN(RLZTracker);
};

#endif  // defined(ENABLE_RLZ)

#endif  // CHROME_BROWSER_RLZ_RLZ_H_
