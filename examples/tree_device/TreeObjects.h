// Copyright 2021 The Khronos Group
// SPDX-License-Identifier: Apache-2.0

// This file was generated by generate_device_frontend.py
// Don't make changes to this directly

#pragma once
#include "TreeParameter.h"
namespace anari {
namespace tree {
class ParameterPack {
public:
   virtual bool set(const char *paramname, ANARIDataType type, const void *mem) = 0;
   virtual void unset(const char *paramname) = 0;
   virtual ParameterBase& operator[](size_t idx) = 0;
   virtual ParameterBase& operator[](const char *paramname) = 0;
   virtual const char** paramNames() const = 0;
   virtual size_t paramCount() const = 0;
};
class Device : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_DEVICE;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_STATUS_CALLBACK> statusCallback;
   Parameter<ANARI_VOID_POINTER> statusCallbackUserData;

   Device(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Array1D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_ARRAY1D;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_UINT64_BOX1> region;

   Array1D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Array2D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_ARRAY2D;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;

   Array2D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Array3D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_ARRAY3D;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;

   Array3D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Frame : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_FRAME;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_WORLD> world;
   Parameter<ANARI_RENDERER> renderer;
   Parameter<ANARI_CAMERA> camera;
   Parameter<ANARI_UINT32_VEC2> size;
   Parameter<ANARI_DATA_TYPE> color;
   Parameter<ANARI_DATA_TYPE> depth;
   Parameter<ANARI_DATA_TYPE> normal;
   Parameter<ANARI_DATA_TYPE> albedo;
   Parameter<ANARI_BOOL> accumulation;
   Parameter<ANARI_BOOL> variance;

   Frame(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Group : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GROUP;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> surface;
   Parameter<ANARI_ARRAY1D> volume;
   Parameter<ANARI_ARRAY1D> light;

   Group(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Instance : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_INSTANCE;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_MAT3x4> transform;
   Parameter<ANARI_GROUP> group;
   Parameter<ANARI_ARRAY1D> motion_transform;
   Parameter<ANARI_ARRAY1D> motion_scale;
   Parameter<ANARI_ARRAY1D> motion_rotation;
   Parameter<ANARI_ARRAY1D> motion_translation;
   Parameter<ANARI_FLOAT32_BOX1> time;

   Instance(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class World : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_WORLD;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> instance;
   Parameter<ANARI_ARRAY1D> surface;
   Parameter<ANARI_ARRAY1D> volume;
   Parameter<ANARI_ARRAY1D> light;

   World(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class RendererDefault : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_RENDERER;
   static constexpr const char *subtype = "default";
   Parameter<ANARI_STRING> name;

   RendererDefault(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Surface : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SURFACE;
   static constexpr const char *subtype = nullptr;
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_GEOMETRY> geometry;
   Parameter<ANARI_MATERIAL> material;

   Surface(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class CameraOmnidirectional : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_CAMERA;
   static constexpr const char *subtype = "omnidirectional";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32_VEC3> up;
   Parameter<ANARI_FLOAT32_MAT3x4> transform;
   Parameter<ANARI_FLOAT32_BOX2> imageRegion;
   Parameter<ANARI_FLOAT32> apertureRadius;
   Parameter<ANARI_FLOAT32> focusDistance;
   Parameter<ANARI_STRING> stereoMode;
   Parameter<ANARI_FLOAT32> interpupillaryDistance;
   Parameter<ANARI_STRING> layout;
   Parameter<ANARI_ARRAY1D> motion_transform;
   Parameter<ANARI_ARRAY1D> motion_scale;
   Parameter<ANARI_ARRAY1D> motion_rotation;
   Parameter<ANARI_ARRAY1D> motion_translation;
   Parameter<ANARI_FLOAT32_BOX1> time;
   Parameter<ANARI_FLOAT32_BOX1> shutter;

   CameraOmnidirectional(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class CameraOrthographic : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_CAMERA;
   static constexpr const char *subtype = "orthographic";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32_VEC3> up;
   Parameter<ANARI_FLOAT32_MAT3x4> transform;
   Parameter<ANARI_FLOAT32_BOX2> imageRegion;
   Parameter<ANARI_FLOAT32> apertureRadius;
   Parameter<ANARI_FLOAT32> focusDistance;
   Parameter<ANARI_STRING> stereoMode;
   Parameter<ANARI_FLOAT32> interpupillaryDistance;
   Parameter<ANARI_FLOAT32> aspect;
   Parameter<ANARI_ARRAY1D> motion_transform;
   Parameter<ANARI_ARRAY1D> motion_scale;
   Parameter<ANARI_ARRAY1D> motion_rotation;
   Parameter<ANARI_ARRAY1D> motion_translation;
   Parameter<ANARI_FLOAT32_BOX1> time;
   Parameter<ANARI_FLOAT32_BOX1> shutter;

   CameraOrthographic(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class CameraPerspective : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_CAMERA;
   static constexpr const char *subtype = "perspective";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32_VEC3> up;
   Parameter<ANARI_FLOAT32_MAT3x4> transform;
   Parameter<ANARI_FLOAT32_BOX2> imageRegion;
   Parameter<ANARI_FLOAT32> apertureRadius;
   Parameter<ANARI_FLOAT32> focusDistance;
   Parameter<ANARI_STRING> stereoMode;
   Parameter<ANARI_FLOAT32> interpupillaryDistance;
   Parameter<ANARI_FLOAT32> fovy;
   Parameter<ANARI_FLOAT32> aspect;
   Parameter<ANARI_ARRAY1D> motion_transform;
   Parameter<ANARI_ARRAY1D> motion_scale;
   Parameter<ANARI_ARRAY1D> motion_rotation;
   Parameter<ANARI_ARRAY1D> motion_translation;
   Parameter<ANARI_FLOAT32_BOX1> time;
   Parameter<ANARI_FLOAT32_BOX1> shutter;

   CameraPerspective(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometryCone : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "cone";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_radius;
   Parameter<ANARI_ARRAY1D> vertex_cap;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;
   Parameter<ANARI_STRING> caps;

   GeometryCone(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometryCurve : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "curve";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_radius;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;
   Parameter<ANARI_FLOAT32> radius;

   GeometryCurve(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometryCylinder : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "cylinder";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_cap;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;
   Parameter<ANARI_ARRAY1D> primitive_radius;
   Parameter<ANARI_FLOAT32> radius;
   Parameter<ANARI_STRING> caps;

   GeometryCylinder(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometryQuad : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "quad";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_normal;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;

   GeometryQuad(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometrySphere : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "sphere";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_radius;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;
   Parameter<ANARI_FLOAT32> radius;

   GeometrySphere(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class GeometryTriangle : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_GEOMETRY;
   static constexpr const char *subtype = "triangle";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> primitive_color;
   Parameter<ANARI_ARRAY1D> primitive_attribute0;
   Parameter<ANARI_ARRAY1D> primitive_attribute1;
   Parameter<ANARI_ARRAY1D> primitive_attribute2;
   Parameter<ANARI_ARRAY1D> primitive_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_id;
   Parameter<ANARI_ARRAY1D> vertex_position;
   Parameter<ANARI_ARRAY1D> vertex_normal;
   Parameter<ANARI_ARRAY1D> vertex_color;
   Parameter<ANARI_ARRAY1D> vertex_attribute0;
   Parameter<ANARI_ARRAY1D> vertex_attribute1;
   Parameter<ANARI_ARRAY1D> vertex_attribute2;
   Parameter<ANARI_ARRAY1D> vertex_attribute3;
   Parameter<ANARI_ARRAY1D> primitive_index;

   GeometryTriangle(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightDirectional : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "directional";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32> irridance;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32> angularDiameter;
   Parameter<ANARI_FLOAT32> radiance;
   Parameter<ANARI_BOOL> visible;

   LightDirectional(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightPoint : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "point";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32> intensity;
   Parameter<ANARI_FLOAT32> power;
   Parameter<ANARI_FLOAT32> radius;
   Parameter<ANARI_FLOAT32> radiance;
   Parameter<ANARI_BOOL> visible;

   LightPoint(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightSpot : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "spot";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32> openingAngle;
   Parameter<ANARI_FLOAT32> falloffAngle;
   Parameter<ANARI_FLOAT32> intensity;
   Parameter<ANARI_FLOAT32> power;

   LightSpot(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class MaterialMatte : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_MATERIAL;
   static constexpr const char *subtype = "matte";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3, ANARI_SAMPLER, ANARI_STRING> color;

   MaterialMatte(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class MaterialTransparentMatte : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_MATERIAL;
   static constexpr const char *subtype = "transparentMatte";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3, ANARI_SAMPLER, ANARI_STRING> color;
   Parameter<ANARI_FLOAT32, ANARI_SAMPLER, ANARI_STRING> opacity;

   MaterialTransparentMatte(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class SamplerImage1D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SAMPLER;
   static constexpr const char *subtype = "image1D";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> image;
   Parameter<ANARI_STRING> inAttribute;
   Parameter<ANARI_STRING> filter;
   Parameter<ANARI_STRING> wrapMode1;
   Parameter<ANARI_FLOAT32_MAT4> inTransform;
   Parameter<ANARI_FLOAT32_MAT4> outTransform;

   SamplerImage1D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class SamplerImage2D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SAMPLER;
   static constexpr const char *subtype = "image2D";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY2D> image;
   Parameter<ANARI_STRING> inAttribute;
   Parameter<ANARI_STRING> filter;
   Parameter<ANARI_STRING> wrapMode1;
   Parameter<ANARI_STRING> wrapMode2;
   Parameter<ANARI_FLOAT32_MAT4> inTransform;
   Parameter<ANARI_FLOAT32_MAT4> outTransform;

   SamplerImage2D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class SamplerImage3D : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SAMPLER;
   static constexpr const char *subtype = "image3D";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY3D> image;
   Parameter<ANARI_STRING> inAttribute;
   Parameter<ANARI_STRING> filter;
   Parameter<ANARI_STRING> wrapMode1;
   Parameter<ANARI_STRING> wrapMode2;
   Parameter<ANARI_STRING> wrapMode3;
   Parameter<ANARI_FLOAT32_MAT4> inTransform;
   Parameter<ANARI_FLOAT32_MAT4> outTransform;

   SamplerImage3D(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class SamplerPrimitive : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SAMPLER;
   static constexpr const char *subtype = "primitive";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY1D> array;

   SamplerPrimitive(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class SamplerTransform : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SAMPLER;
   static constexpr const char *subtype = "transform";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_STRING> inAttribute;
   Parameter<ANARI_FLOAT32_MAT4> transform;

   SamplerTransform(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class Spatial_FieldStructuredRegular : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_SPATIAL_FIELD;
   static constexpr const char *subtype = "structuredRegular";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_ARRAY3D> data;
   Parameter<ANARI_FLOAT32_VEC3> origin;
   Parameter<ANARI_FLOAT32_VEC3> spacing;
   Parameter<ANARI_STRING> filter;

   Spatial_FieldStructuredRegular(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class VolumeScivis : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_VOLUME;
   static constexpr const char *subtype = "scivis";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_SPATIAL_FIELD> field;
   Parameter<ANARI_FLOAT32_BOX1> valueRange;
   Parameter<ANARI_ARRAY1D> color;
   Parameter<ANARI_ARRAY1D> color_position;
   Parameter<ANARI_ARRAY1D> opacity;
   Parameter<ANARI_ARRAY1D> opacity_position;
   Parameter<ANARI_FLOAT32> densityScale;

   VolumeScivis(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightRing : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "ring";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> direction;
   Parameter<ANARI_FLOAT32> openingAngle;
   Parameter<ANARI_FLOAT32> falloffAngle;
   Parameter<ANARI_FLOAT32> intensity;
   Parameter<ANARI_FLOAT32> power;
   Parameter<ANARI_FLOAT32> radius;
   Parameter<ANARI_FLOAT32> innerRadius;
   Parameter<ANARI_FLOAT32> radiance;
   Parameter<ANARI_ARRAY1D, ANARI_ARRAY2D> intensityDistribution;
   Parameter<ANARI_FLOAT32_VEC3> c0;
   Parameter<ANARI_BOOL> visible;

   LightRing(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightQuad : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "quad";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32_VEC3> position;
   Parameter<ANARI_FLOAT32_VEC3> edge1;
   Parameter<ANARI_FLOAT32_VEC3> edge2;
   Parameter<ANARI_FLOAT32> intensity;
   Parameter<ANARI_FLOAT32> power;
   Parameter<ANARI_FLOAT32> radiance;
   Parameter<ANARI_STRING> side;
   Parameter<ANARI_ARRAY1D, ANARI_ARRAY2D> intensityDistribution;
   Parameter<ANARI_BOOL> visible;

   LightQuad(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
class LightHdri : public ParameterPack {
public:
   ANARIDevice device;
   static const int type = ANARI_LIGHT;
   static constexpr const char *subtype = "hdri";
   Parameter<ANARI_STRING> name;
   Parameter<ANARI_FLOAT32_VEC3> color;
   Parameter<ANARI_FLOAT32_VEC3> up;
   Parameter<ANARI_ARRAY2D> radiance;
   Parameter<ANARI_STRING> layout;
   Parameter<ANARI_FLOAT32> scale;
   Parameter<ANARI_BOOL> visible;

   LightHdri(ANARIDevice d);
   bool set(const char *paramname, ANARIDataType type, const void *mem) override;
   void unset(const char *paramname) override;
   ParameterBase& operator[](size_t idx) override;
   ParameterBase& operator[](const char *paramname) override;
   const char** paramNames() const override;
   size_t paramCount() const override;
};
}
}
