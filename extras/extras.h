// Copyright 2015 Google Inc. All Rights Reserved.
//
// Use of this source code is governed by a BSD-style license
// that can be found in the COPYING file in the root of the source
// tree. An additional intellectual property rights grant can be found
// in the file PATENTS. All contributing project authors may
// be found in the AUTHORS file in the root of the source tree.
// -----------------------------------------------------------------------------
//

#ifndef WEBP_EXTRAS_EXTRAS_H_
#define WEBP_EXTRAS_EXTRAS_H_

#include "webp/types.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "webp/encode.h"

#define WEBP_EXTRAS_ABI_VERSION 0x0000    // MAJOR(8b) + MINOR(8b)

//------------------------------------------------------------------------------

// Returns the version number of the extras library, packed in hexadecimal using
// 8bits for each of major/minor/revision. E.g: v2.5.7 is 0x020507.
WEBP_EXTERN(int) WebPGetExtrasVersion(void);

//------------------------------------------------------------------------------
// Ad-hoc colorspace importers.

// Import luma sample (gray scale image) into 'picture'. The 'picture'
// width and height must be set prior to calling this function.
WEBP_EXTERN(int) WebPImportGray(const uint8_t* gray, WebPPicture* picture);

// Import rgb sample in RGB565 packed format into 'picture'. The 'picture'
// width and height must be set prior to calling this function.
WEBP_EXTERN(int) WebPImportRGB565(const uint8_t* rgb565, WebPPicture* pic);

// Import rgb sample in RGB4444 packed format into 'picture'. The 'picture'
// width and height must be set prior to calling this function.
WEBP_EXTERN(int) WebPImportRGB4444(const uint8_t* rgb4444, WebPPicture* pic);

//------------------------------------------------------------------------------

// Parse a bitstream, search for VP8 (lossy) header and report a
// rough estimation of the quality factor used for compressing the bitstream.
// Any error (invalid bitstream, lossless compression, incomplete header, etc.)
// will return a value of -1.
WEBP_EXTERN(int) VP8EstimateQuality(const uint8_t* const data, size_t size);

//------------------------------------------------------------------------------

#ifdef __cplusplus
}    // extern "C"
#endif

#endif  /* WEBP_EXTRAS_EXTRAS_H_ */
