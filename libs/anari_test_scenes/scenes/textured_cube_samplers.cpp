// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

#include "textured_cube_samplers.h"

#include "anari/anari_cpp/ext/glm.h"
#include "glm/ext/matrix_transform.hpp"


static void anari_free(void *ptr, void *)
{
  std::free(ptr);
}

namespace anari {
namespace scenes {

static std::vector<glm::vec3> vertices = {
    //
    {-.5f, .5f, 0.f},
    {.5f, .5f, 0.f},
    {-.5f, -.5f, 0.f},
    {.5f, -.5f, 0.f},
    //
};

static std::vector<glm::uvec3> indices = {
    //
    {0, 2, 3},
    {3, 1, 0},
    //
};

static std::vector<glm::vec2> texcoords = {
    //
    {0.f, 1.f},
    {1.f, 1.f},
    {0.f, 0.f},
    {1.f, 0.f},
    //
};

static anari::Array2D makeTextureData(anari::Device d, int dim)
{
  auto *data = new glm::vec3[dim * dim];

  for (int h = 0; h < dim; h++) {
    for (int w = 0; w < dim; w++) {
      bool even = h & 1;
      if (even)
        data[h * dim + w] = w & 1 ? glm::vec3(1.0f) : glm::vec3(.1f);
      else
        data[h * dim + w] = w & 1 ? glm::vec3(.1f) : glm::vec3(1.0f);
    }
  }

  return anariNewArray2D(
      d, data, &anari_free, nullptr, ANARI_FLOAT32_VEC3, dim, dim);
}

// CornelBox definitions //////////////////////////////////////////////////////

TexturedCubeSamplers::TexturedCubeSamplers(anari::Device d) : TestScene(d)
{
  m_world = anari::newObject<anari::World>(m_device);
}

TexturedCubeSamplers::~TexturedCubeSamplers()
{
  anari::release(m_device, m_world);
}

anari::World TexturedCubeSamplers::world()
{
  return m_world;
}

std::vector<ParameterInfo> TexturedCubeSamplers::parameters()
{
  return {
      {"filter", ANARI_BOOL, true, "Use nearest filter (linear will be used instead)"},
      {"wrapMode1(clampToEdge, repeat, mirrorRepeat)", ANARI_INT32, int(1), "1 - clampToEdge, 2 - repeat, 3 - mirrorRepeat"},
      {"wrapMode2(clampToEdge, repeat, mirrorRepeat)", ANARI_INT32, int(1), "1 - clampToEdge, 2 - repeat, 3 - mirrorRepeat"},
  };
}

void TexturedCubeSamplers::commit()
{
  anari::Device d = m_device;

  const bool filter = getParam<bool>("filter", true);
  int wrapMode1 = getParam<int>("wrapMode1(clampToEdge, repeat, mirrorRepeat)", 1);
  int wrapMode2 = getParam<int>("wrapMode2(clampToEdge, repeat, mirrorRepeat)", 1);

  if (wrapMode1 < 1 || wrapMode1 > 3)
    throw std::runtime_error("'wrapMode1' must be 1,2 or 3");

  if (wrapMode2 < 1 || wrapMode2 > 3)
    throw std::runtime_error("'wrapMode2' must be 1,2 or 3");

  auto geom = anari::newObject<anari::Geometry>(d, "triangle");
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.position",
      anari::newArray1D(d, vertices.data(), vertices.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "vertex.attribute0",
      anari::newArray1D(d, texcoords.data(), texcoords.size()));
  anari::setAndReleaseParameter(d,
      geom,
      "primitive.index",
      anari::newArray1D(d, indices.data(), indices.size()));
  anari::commit(d, geom);

  auto surface = anari::newObject<anari::Surface>(d);
  anari::setAndReleaseParameter(d, surface, "geometry", geom);

  auto tex = anari::newObject<anari::Sampler>(d, "image2D");
  anari::setAndReleaseParameter(d, tex, "image", makeTextureData(d, 8));
  anari::setParameter(d, tex, "inAttribute", "attribute0");
  
  const float inTransform[16] = {
      0.5f, 0.5f, 0.4f, 0.f,
      0.1f, 0.2f, 0.3f, 0.f,
      0.f, 0.f, 1.f, 0.f,
      0.f, 0.f, 0.f, 0.f};
    
  anari::setParameter(d, tex, "inTransform", inTransform);

  const float outTransform[16] = {
      0.5f, 0.5f, 0.4f, 0.f,
      0.1f, 0.2f, 0.3f, 0.f,
      0.f, 0.f, 0.1f, 0.f,
      0.7f, 0.1f, 0.3f, 0.f};

  anari::setParameter(d, tex, "outTransform", outTransform);

  anari::setParameter(d, tex, "inAttribute", "attribute0");

  if (filter) {
      anari::setParameter(d, tex, "filter", "nearest");
      printf("Setting filter to nearest\n");
  } else {
      anari::setParameter(d, tex, "filter", "linear");
      printf("Setting filter to linear\n"); 
  }
  std::cout << wrapMode1;
  switch (wrapMode1) {
      case 1:
        anari::setParameter(d, tex, "WrapMode1", "clampToEdge");
        printf("Setting WrapMode1 to clampEdge.\n");
        break;
      case 2:
        anari::setParameter(d, tex, "WrapMode1", "repeat");
        printf("Setting WrapMode1 to repeat.\n");
        break;
      case 3:
        anari::setParameter(d, tex, "WrapMode1", "mirrorRepeat");
        printf("Setting WrapMode1 to mirrorRepeat.\n");
        break;
      default:
        throw std::runtime_error("'WrapMode1' must be >= 1 and <= 3");
        break;
  }
  std::cout << wrapMode1;
  switch (wrapMode2) {
      case 1:
        anari::setParameter(d, tex, "WrapMode2", "clampToEdge");
        printf("Setting WrapMode2 to clampEdge.\n");
        break;
      case 2:
        anari::setParameter(d, tex, "WrapMode2", "repeat");
        printf("Setting WrapMode2 to repeat.\n");
        break;
      case 3:
        anari::setParameter(d, tex, "WrapMode2", "mirrorRepeat");
        printf("Setting WrapMode2 to mirrorRepeat.\n");
        break;
      default:
        throw std::runtime_error("'WrapMode2' must be >= 1 and <= 3");
        break;
  }


  
  //auto tMat = glm::mat4(1.f);
  //auto vec = glm::vec4(1.f, 0, 0, 0);
  //auto 

  /*auto tmat = glm::mat4(0, 0, 0, 1.f, 0, 0, 1.f, 0, 0, 1.f, 0, 0, 0, 1.f, 0, 0);
  anari::setParameter(d, tex, "outTransform", tmat);*/

  anari::commit(d, tex);

  auto mat = anari::newObject<anari::Material>(d, "matte");
  anari::setAndReleaseParameter(d, mat, "color", tex);
  anari::commit(d, mat);
  anari::setAndReleaseParameter(d, surface, "material", mat);
  anari::commit(d, surface);

  auto group = anari::newObject<anari::Group>(d);
  anari::setAndReleaseParameter(
      d, group, "surface", anari::newArray1D(d, &surface));
  anari::commit(d, group);

  anari::release(d, surface);

  std::vector<anari::Instance> instances;

  auto createInstance = [&](float rotation, glm::vec3 axis) {
    auto inst = anari::newObject<anari::Instance>(d);

    auto tl = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, .5f));
    auto rot = glm::rotate(glm::mat4(1.f), rotation, axis);
    glm::mat4x3 xfm = rot * tl;
    anari::setParameter(d, inst, "transform", xfm);
    anari::setParameter(d, inst, "group", group);
    anari::commit(d, inst);
    return inst;
  };

  instances.push_back(createInstance(glm::radians(0.f), glm::vec3(0, 1, 0)));
  instances.push_back(createInstance(glm::radians(180.f), glm::vec3(0, 1, 0)));
  instances.push_back(createInstance(glm::radians(90.f), glm::vec3(0, 1, 0)));
  instances.push_back(createInstance(glm::radians(270.f), glm::vec3(0, 1, 0)));
  instances.push_back(createInstance(glm::radians(90.f), glm::vec3(1, 0, 0)));
  instances.push_back(createInstance(glm::radians(270.f), glm::vec3(1, 0, 0)));

  anari::setAndReleaseParameter(d,
      m_world,
      "instance",
      anari::newArray1D(d, instances.data(), instances.size()));

  anari::release(d, group);
  for (auto i : instances)
    anari::release(d, i);

  setDefaultLight(m_world);

  anari::commit(d, m_world);
}

std::vector<Camera> TexturedCubeSamplers::cameras()
{
  Camera cam;
  cam.position = glm::vec3(1.25f);
  cam.at = glm::vec3(0.f);
  cam.direction = glm::normalize(cam.at - cam.position);
  cam.up = glm::vec3(0, 1, 0);
  return {cam};
}

TestScene *sceneTexturedCubeSamplers(anari::Device d)
{
  return new TexturedCubeSamplers(d);
}

} // namespace scenes

ANARI_TYPEFOR_SPECIALIZATION(glm::mat4, ANARI_FLOAT32_MAT4);
} // namespace anari
