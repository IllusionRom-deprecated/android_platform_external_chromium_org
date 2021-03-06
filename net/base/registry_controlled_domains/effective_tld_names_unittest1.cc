/* C++ code produced by gperf version 3.0.3 */
/* Command-line: gperf -a -L C++ -C -c -o -t -k '*' -NFindDomain -ZPerfect_Hash_Test1 -P -K name_offset -Q stringpool1 -D effective_tld_names_unittest1.gperf  */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "effective_tld_names_unittest1.gperf"

// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
// Test file used by registry_controlled_domain_unittest.
// We edit this file manually, then run
// gperf -a -L "C++" -C -c -o -t -k '*' -NFindDomain -ZPerfect_Hash_Test1 -P -K name_offset -Q stringpool1 -D effective_tld_names_unittest1.gperf >  effective_tld_names_unittest1.cc
// to generate the perfect hashmap.
#line 10 "effective_tld_names_unittest1.gperf"
struct DomainRule {
  int name_offset;
  int type;  // 1: exception, 2: wildcard, 4: private
};

#define TOTAL_KEYWORDS 11
#define MIN_WORD_LENGTH 1
#define MAX_WORD_LENGTH 11
#define MIN_HASH_VALUE 1
#define MAX_HASH_VALUE 17
/* maximum key range = 17, duplicates = 0 */

class Perfect_Hash_Test1
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static const struct DomainRule *FindDomain (const char *str, unsigned int len);
};

inline unsigned int
Perfect_Hash_Test1::hash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18,  0, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18,  0,  0,  0,
      18,  5,  0, 18, 18,  0,  0, 18, 18,  0,
       5,  0,  0, 18,  0, 18,  5, 18,  0, 18,
      18, 18,  0, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
      18, 18, 18, 18, 18, 18
    };
  register int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[10]];
      /*FALLTHROUGH*/
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      /*FALLTHROUGH*/
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      /*FALLTHROUGH*/
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      /*FALLTHROUGH*/
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      /*FALLTHROUGH*/
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      /*FALLTHROUGH*/
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      /*FALLTHROUGH*/
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      /*FALLTHROUGH*/
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

struct stringpool1_t
  {
    char stringpool1_str0[sizeof("c")];
    char stringpool1_str1[sizeof("jp")];
    char stringpool1_str2[sizeof("b.c")];
    char stringpool1_str3[sizeof("ac.jp")];
    char stringpool1_str4[sizeof("bar.jp")];
    char stringpool1_str5[sizeof("no")];
    char stringpool1_str6[sizeof("baz.bar.jp")];
    char stringpool1_str7[sizeof("bar.baz.com")];
    char stringpool1_str8[sizeof("priv.no")];
    char stringpool1_str9[sizeof("pref.bar.jp")];
    char stringpool1_str10[sizeof("private")];
  };
static const struct stringpool1_t stringpool1_contents =
  {
    "c",
    "jp",
    "b.c",
    "ac.jp",
    "bar.jp",
    "no",
    "baz.bar.jp",
    "bar.baz.com",
    "priv.no",
    "pref.bar.jp",
    "private"
  };
#define stringpool1 ((const char *) &stringpool1_contents)
const struct DomainRule *
Perfect_Hash_Test1::FindDomain (register const char *str, register unsigned int len)
{
  static const struct DomainRule wordlist[] =
    {
#line 21 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str0, 2},
#line 15 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str1, 0},
#line 22 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str2, 1},
#line 16 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str3, 0},
#line 17 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str4, 2},
#line 23 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str5, 0},
#line 18 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str6, 2},
#line 20 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str7, 0},
#line 24 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str8, 4},
#line 19 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str9, 1},
#line 25 "effective_tld_names_unittest1.gperf"
      {(int)(long)&((struct stringpool1_t *)0)->stringpool1_str10, 4}
    };

  static const signed char lookup[] =
    {
      -1,  0,  1,  2, -1,  3,  4,  5, -1, -1,  6,  7,  8, -1,
      -1, -1,  9, 10
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist[index].name_offset + stringpool1;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist[index];
            }
        }
    }
  return 0;
}
#line 26 "effective_tld_names_unittest1.gperf"

