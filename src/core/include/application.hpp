#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.hpp"
#include "renderer.hpp"

#include <spdlog/spdlog.h>

class ExtexApplication {
public:
  ExtexApplication() = default;
  virtual ~ExtexApplication() = default;

  STATUS Start();

private:
  Window *m_Window;
  Renderer *m_Renderer;
  STATUS m_lastStatus;
};

#endif /* APPLICATION_H */
