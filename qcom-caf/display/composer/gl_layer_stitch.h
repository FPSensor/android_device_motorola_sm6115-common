/*
 * Copyright (c) 2019-2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __GL_LAYER_STITCH_H__
#define __GL_LAYER_STITCH_H__

#include <gralloc_priv.h>
#include <vector>

#include "gl_common.h"

namespace sdm {
struct StitchParams {
  const private_handle_t *src_hnd = nullptr;
  const private_handle_t *dst_hnd = nullptr;
  GLRect src_rect;
  GLRect dst_rect;
  GLRect scissor_rect;
  int src_acquire_fence_fd = -1;
  int dst_acquire_fence_fd = -1;
};

class GLLayerStitch {
 public:
  static GLLayerStitch* GetInstance(bool secure);
  static void Destroy(GLLayerStitch *intf);

  virtual int Blit(const std::vector<StitchParams> &stitch_params, int *release_fence_fd) = 0;
 protected:
  virtual ~GLLayerStitch() { }
};

}  // namespace sdm

#endif  // __GL_LAYER_STITCH_H__
