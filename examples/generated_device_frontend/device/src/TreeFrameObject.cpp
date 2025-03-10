// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

// This file was generated by generate_device_frontend.py from FrameObject.cpp

#include "TreeSpecializations.h"
#include "anari/type_utility.h"

#include <cstdlib>
#include <cstring>

#include "RecursivePrint.h"

namespace anari_sdk {
namespace tree {

Object<Frame>::Object(ANARIDevice d, ANARIObject handle)
    : DefaultObject(d, handle)
{}

void Object<Frame>::commit()
{
  DefaultObject::commit();

  size[0] = size[1] = 16; // some non null placeholder value
  current.size.get(ANARI_UINT32_VEC2, size);

  uint32_t elements = size[0] * size[1];

  ANARIDataType colorType = ANARI_UNKNOWN;
  ANARIDataType depthType = ANARI_UNKNOWN;
  if (current.color.get(ANARI_DATA_TYPE, &colorType)) {
    color.resize(elements * anari::sizeOf(colorType));
  }
  if (current.depth.get(ANARI_DATA_TYPE, &depthType)) {
    depth.resize(elements); // only FLOAT32 is valid
  }
}

void *Object<Frame>::mapFrame(const char *channel,
    uint32_t *width,
    uint32_t *height,
    ANARIDataType *pixelType)
{
  *width = size[0];
  *height = size[1];
  if (std::strncmp(channel, "color", 5) == 0) {
    *pixelType = colorType;
    return color.data();
  } else if (std::strncmp(channel, "depth", 5) == 0) {
    *pixelType = depthType;
    return depth.data();
  } else {
    *width = *height = 0;
    return nullptr;
  }
}

void Object<Frame>::unmapFrame(const char *channel)
{
  (void)channel;
}

void Object<Frame>::renderFrame()
{
  recursivePrint(device, handle);
}

void Object<Frame>::discardFrame() {}

int Object<Frame>::frameReady(ANARIWaitMask mask)
{
  (void)mask;
  return 1;
}

} // namespace tree
} // namespace anari_sdk
