// Copyright 2020 The Khronos® Group Inc.
#pragma once

#include <string>
#include <utility>

#include "GLTFBufferView.h"
#include "GLTFObject.h"

namespace GLTF {
class Image : public GLTF::Object {
 public:
  std::string uri;
  unsigned char* data = NULL;
  size_t byteLength = 0;
  std::string mimeType;
  GLTF::BufferView* bufferView = NULL;

  explicit Image(std::string uri);
  Image(std::string uri, unsigned char* data, size_t byteLength,
        std::string fileExtension);
  virtual ~Image();

  static GLTF::Image* load(std::string path, bool writeAbsoluteUris);
  std::pair<int, int> getDimensions();
  virtual std::string typeName();
  virtual void writeJSON(void* writer, GLTF::Options* options);

 private:
  const std::string cacheKey;

  Image(std::string uri, std::string cacheKey);
  Image(std::string uri, std::string cacheKey, unsigned char* data,
        size_t byteLength, std::string fileExtension);
};
}  // namespace GLTF
