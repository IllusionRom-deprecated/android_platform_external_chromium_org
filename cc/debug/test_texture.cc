// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/debug/test_texture.h"

#include "third_party/khronos/GLES2/gl2.h"

namespace cc {

size_t TextureSizeBytes(gfx::Size size, ResourceFormat format) {
  unsigned int components_per_pixel = 4;
  unsigned int bytes_per_component = 1;
  return size.width() * size.height() * components_per_pixel *
         bytes_per_component;
}

TestTexture::TestTexture()
    : format(RGBA_8888), filter(GL_NEAREST_MIPMAP_LINEAR) {}

TestTexture::~TestTexture() {}

void TestTexture::Reallocate(gfx::Size size, ResourceFormat format) {
  this->size = size;
  this->format = format;
  this->data.reset(new uint8_t[TextureSizeBytes(size, format)]);
}

}  // namespace cc
