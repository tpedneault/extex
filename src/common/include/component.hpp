#ifndef COMPONENT_H
#define COMPONENT_H

#include "types.hpp"

class ComponentBase {
public:
  virtual ~ComponentBase() = default;
  virtual STATUS Initialize() = 0;
  virtual STATUS Update() = 0;
  virtual STATUS Destroy() = 0;
};

#endif /* COMPONENT_H */
