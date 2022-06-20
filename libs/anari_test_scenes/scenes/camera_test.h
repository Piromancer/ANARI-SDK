// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "scene.h"

namespace anari {
namespace scenes {

TestScene *sceneCameraTest(anari::Device d);

struct CameraTest : public TestScene
{
  CameraTest(anari::Device d);
  ~CameraTest();

  anari::World world() override;
  //std::vector<Camera> cameras() override;

  void commit() override;

 private:
  anari::World m_world{nullptr};
};

} // namespace scenes
} // namespace anari
