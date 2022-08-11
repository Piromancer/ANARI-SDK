// This file was generated by $generator from $template

#pragma once

// anari
#include "$prefixObject.h"
#include "$prefixObjects.h"
#include "anari/backend/DeviceImpl.h"

#include <atomic>
#include <memory>
#include <mutex>
#include <type_traits>
#include <vector>

#ifdef _WIN32
#ifdef DEVICE_STATIC_DEFINE
#define DEVICE_INTERFACE
#else
#ifdef anari_library_$libraryname_EXPORTS
#define DEVICE_INTERFACE __declspec(dllexport)
#else
#define DEVICE_INTERFACE __declspec(dllimport)
#endif
#endif
#elif defined __GNUC__
#define DEVICE_INTERFACE __attribute__((__visibility__("default")))
#else
#define DEVICE_INTERFACE
#endif

// clang-format off
$begin_namespaces

void anariRetainInternal(ANARIDevice, ANARIObject, ANARIObject);
void anariReleaseInternal(ANARIDevice, ANARIObject, ANARIObject);
void anariDeleteInternal(ANARIDevice, ANARIObject);
void anariReportStatus(ANARIDevice,
    ANARIObject source,
    ANARIDataType sourceType,
    ANARIStatusSeverity severity,
    ANARIStatusCode code,
    const char *format,
    ...);
// clang-format on

template <class T>
T deviceHandle(ANARIDevice d)
{
  anari::DeviceImpl *ad = reinterpret_cast<anari::DeviceImpl *>(d);
  return static_cast<T>(ad);
}

struct DEVICE_INTERFACE $prefixDevice : public anari::DeviceImpl
{
  // Data Arrays //////////////////////////////////////////////////////////////

  ANARIArray1D newArray1D(const void *appMemory,
      ANARIMemoryDeleter deleter,
      const void *userdata,
      ANARIDataType,
      uint64_t numItems1,
      uint64_t byteStride1) override;

  ANARIArray2D newArray2D(const void *appMemory,
      ANARIMemoryDeleter deleter,
      const void *userdata,
      ANARIDataType,
      uint64_t numItems1,
      uint64_t numItems2,
      uint64_t byteStride1,
      uint64_t byteStride2) override;

  ANARIArray3D newArray3D(const void *appMemory,
      ANARIMemoryDeleter deleter,
      const void *userdata,
      ANARIDataType,
      uint64_t numItems1,
      uint64_t numItems2,
      uint64_t numItems3,
      uint64_t byteStride1,
      uint64_t byteStride2,
      uint64_t byteStride3) override;

  void *mapArray(ANARIArray) override;
  void unmapArray(ANARIArray) override;

  // Renderable Objects ///////////////////////////////////////////////////////

  ANARILight newLight(const char *type) override;

  ANARICamera newCamera(const char *type) override;

  ANARIGeometry newGeometry(const char *type) override;
  ANARISpatialField newSpatialField(const char *type) override;

  ANARISurface newSurface() override;
  ANARIVolume newVolume(const char *type) override;

  // Surface Meta-Data ////////////////////////////////////////////////////////

  ANARIMaterial newMaterial(const char *material_type) override;

  ANARISampler newSampler(const char *type) override;

  // Instancing ///////////////////////////////////////////////////////////////

  ANARIGroup newGroup() override;

  ANARIInstance newInstance() override;

  // Top-level Worlds /////////////////////////////////////////////////////////

  ANARIWorld newWorld() override;

  // Object + Parameter Lifetime Management ///////////////////////////////////

  int getProperty(ANARIObject object,
      const char *name,
      ANARIDataType type,
      void *mem,
      uint64_t size,
      ANARIWaitMask mask) override;

  void setParameter(ANARIObject object,
      const char *name,
      ANARIDataType type,
      const void *mem) override;

  void unsetParameter(ANARIObject object, const char *name) override;

  void commitParameters(ANARIObject object) override;

  void release(ANARIObject) override;
  void retain(ANARIObject) override;
  void retainInternal(ANARIObject, ANARIObject);
  void releaseInternal(ANARIObject, ANARIObject);

  // FrameBuffer Manipulation /////////////////////////////////////////////////

  ANARIFrame newFrame() override;

  const void *frameBufferMap(ANARIFrame fb,
      const char *channel,
      uint32_t *width,
      uint32_t *height,
      ANARIDataType *pixelType) override;

  void frameBufferUnmap(ANARIFrame fb, const char *channel) override;

  // Frame Rendering //////////////////////////////////////////////////////////

  ANARIRenderer newRenderer(const char *type) override;

  void renderFrame(ANARIFrame) override;
  int frameReady(ANARIFrame, ANARIWaitMask) override;
  void discardFrame(ANARIFrame) override;

  /////////////////////////////////////////////////////////////////////////////
  // Helper/other functions and data members
  /////////////////////////////////////////////////////////////////////////////

  $prefixDevice(ANARILibrary);
  ~$prefixDevice() = default;

  ObjectBase *fromHandle(ANARIObject handle);
  template <class T, class H>
  T handle_cast(H handle)
  {
    ObjectBase *base = fromHandle(handle);
    if (base && is_convertible<T>::check(base)) {
      return static_cast<T>(base);
    } else {
      return nullptr;
    }
  }

 private:
  // object allocation and translation

  friend void anariDeleteInternal(ANARIDevice, ANARIObject);
  friend void anariReportStatus(ANARIDevice,
      ANARIObject source,
      ANARIDataType sourceType,
      ANARIStatusSeverity severity,
      ANARIStatusCode code,
      const char *format,
      ...);

  template <typename R, typename T, typename... ARGS>
  R allocate(ARGS... args)
  {
    std::lock_guard<std::recursive_mutex> guard(mutex);
    uintptr_t idx = objects.size();
    ANARIObject handle = reinterpret_cast<ANARIObject>(idx);
    // avoid the device handle which is just an arbitrary pointer
    if (handle == this_device()) {
      objects.emplace_back(nullptr);
      idx = objects.size();
      handle = reinterpret_cast<R>(idx);
    }
    objects.emplace_back(new Object<T>(this_device(), handle, args...));
    return static_cast<R>(handle);
  }

  void deallocate(ANARIObject handle)
  {
    uintptr_t id = reinterpret_cast<uintptr_t>(handle);
    std::lock_guard<std::recursive_mutex> guard(mutex);
    if (id < objects.size()) {
      return objects[id].reset(nullptr);
    }
  }

  std::atomic<int64_t> refcount;
  std::recursive_mutex mutex;
  std::vector<std::unique_ptr<ObjectBase>> objects;

  ANARIStatusCallback statusCallback;
  const void *statusCallbackUserData;

  Object<$namespace::Device> deviceObject;
};

template <class T, class H>
T handle_cast(ANARIDevice d, H handle)
{
  return deviceHandle<$prefixDevice *>(d)->handle_cast<T>(handle);
}

$end_namespaces
