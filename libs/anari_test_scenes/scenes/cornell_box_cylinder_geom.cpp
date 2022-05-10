// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#include "cornell_box_cylinder_geom.h"

namespace anari {
namespace scenes {

// cone mesh data
static std::vector<glm::vec3> vertices = {
    // Cylinder
    {0.00f, 0.80f, 0.00f},
    {0.00f, -0.80f, 0.00f}};

static std::vector<float> radiuses = {
    // Cylinder
    0.5f};

static std::vector<glm::uint8> caps = {
    // Cylinder
    1, 1};

static std::vector<glm::vec4> colors = {
    // Cone
    {1.0f, 0.0f, 0.0f, 1.0f},
    {0.0f, 1.0f, 0.0f, 1.0f}
};

// CornelBox definitions //////////////////////////////////////////////////////

CornellBoxCylinder::CornellBoxCylinder(anari::Device d) : TestScene(d)
{
  m_world = anari::newObject<anari::World>(m_device);
}

CornellBoxCylinder::~CornellBoxCylinder()
{
  anari::release(m_device, m_world);
}

anari::World CornellBoxCylinder::world()
{
  return m_world;
}

void CornellBoxCylinder::commit()
{
  auto d = m_device;

  auto geom = anari::newObject<anari::Geometry>(d, "cylinder");

  anari::setAndReleaseParameter(d,
      geom,
      "vertex.position",
      anari::newArray1D(d, vertices.data(), vertices.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.color",
      anari::newArray1D(d, colors.data(), colors.size()));
  anari::setAndReleaseParameter(
      d,
      geom, 
      "vertex.cap", 
      anari::newArray1D(d, caps.data(), caps.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "primitive.radius",
      anari::newArray1D(d, radiuses.data(), radiuses.size()));

  anari::commit(d, geom);

  auto surface = anari::newObject<anari::Surface>(d);
  anari::setAndReleaseParameter(d, surface, "geometry", geom);

  auto mat = anari::newObject<anari::Material>(d, "matte");
  anari::setParameter(d, mat, "color", "color");
  anari::commit(d, mat);
  anari::setAndReleaseParameter(d, surface, "material", mat);

  anari::commit(d, surface);

  anari::setAndReleaseParameter(
      d, m_world, "surface", anari::newArray1D(d, &surface));
  anari::release(d, surface);

  anari::Light light;

  float irradiance = 2.5f;
  float angularDiameter = 0.0f;

  float red = 0.22f;
  float green = 0.22f;
  float blue = 0.15f;

  float dirX = 0.0f;
  float dirY = 0.0f;
  float dirZ = 1.0f;

  if (anari::deviceImplements(d, "ANARI_KHR_AREA_LIGHTS")) {
      light = anari::newObject<anari::Light>(d, "directional");
      anari::setParameter(d, light, "color", glm::vec3(red, green, blue));
      anari::setParameter(d, light, "direction", glm::vec3(dirX, dirY, dirZ));
      anari::setParameter(d, light, "irradiance", irradiance);
      anari::setParameter(d, light, "angularDiameter", angularDiameter);
  } else {
    light = anari::newObject<anari::Light>(d, "directional");
    anari::setParameter(d, light, "direction", glm::vec3(0.f, -0.5f, 1.f));
  }

  anari::commit(d, light);

  anari::setAndReleaseParameter(
      d, m_world, "light", anari::newArray1D(d, &light));

  anari::release(d, light);

  anari::commit(d, m_world);
}

TestScene *sceneCornellBoxCylinder(anari::Device d)
{
  return new CornellBoxCylinder(d);
}

} // namespace scenes
} // namespace anari
