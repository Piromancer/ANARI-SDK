// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#include "cornell_box_cone_geom.h"

namespace anari {
namespace scenes {

// cone mesh data
static std::vector<glm::vec3> vertices = {
    // Cone
    {0.00f, 0.80f, 0.00f},
    {0.00f, -0.80f, 0.00f}
};

static std::vector<float> radiuses = {
    // Cone
    0.1f,
    1.0f
};

static std::vector<glm::uint8> caps = {
    // Cone
    0,
    1
};

static std::vector<glm::vec4> colors = {
    // Cone
    {0.725f, 0.710f, 0.68f, 1.0f},
    {0.725f, 0.710f, 0.68f, 1.0f}
};

// CornelBox definitions //////////////////////////////////////////////////////

CornellBoxCone::CornellBoxCone(anari::Device d) : TestScene(d)
{
  m_world = anari::newObject<anari::World>(m_device);
}

CornellBoxCone::~CornellBoxCone()
{
  anari::release(m_device, m_world);
}

anari::World CornellBoxCone::world()
{
  return m_world;
}

void CornellBoxCone::commit()
{
  auto d = m_device;

  auto geom = anari::newObject<anari::Geometry>(d, "cone");

  anari::setAndReleaseParameter(d,
      geom,
      "vertex.position",
      anari::newArray1D(d, vertices.data(), vertices.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.color",
      anari::newArray1D(d, colors.data(), colors.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.cap", anari::newArray1D(d, caps.data(), caps.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.radius",
      anari::newArray1D(d, radiuses.data(), radiuses.size()));

  anari::commitParameters(d, geom);

  auto surface = anari::newObject<anari::Surface>(d);
  anari::setAndReleaseParameter(d, surface, "geometry", geom);

  auto mat = anari::newObject<anari::Material>(d, "matte");
  anari::setParameter(d, mat, "color", "color");
  anari::commitParameters(d, mat);
  anari::setAndReleaseParameter(d, surface, "material", mat);

  anari::commitParameters(d, surface);

  anari::setAndReleaseParameter(
      d, m_world, "surface", anari::newArray1D(d, &surface));
  anari::release(d, surface);

  anari::Light light;

    light = anari::newObject<anari::Light>(d, "quad");
    anari::setParameter(d, light, "color", glm::vec3(0.78f, 0.551f, 0.183f));
    anari::setParameter(d, light, "intensity", 47.f);
    anari::setParameter(d, light, "position", glm::vec3(-0.23f, 0.98f, -0.16f));
    anari::setParameter(d, light, "edge1", glm::vec3(0.47f, 0.0f, 0.0f));
    anari::setParameter(d, light, "edge2", glm::vec3(0.0f, 0.0f, 0.38f));

  anari::commitParameters(d, light);

  anari::setAndReleaseParameter(
      d, m_world, "light", anari::newArray1D(d, &light));

  anari::release(d, light);

  anari::setAndReleaseParameter(
      d, m_world, "light", anari::newArray1D(d, &light));
  //anari::commitParameters(d, cam);
  //anari::release(d, cam);

  anari::commitParameters(d, m_world);
}

TestScene *sceneCornellBoxCone(anari::Device d)
{
  return new CornellBoxCone(d);
}

} // namespace scenes
} // namespace anari
