#ifndef APPLICATION_H
#define APPLICATION_H

#include "window.hpp"
#include "renderer.hpp"
#include "editor.hpp"

class ExtexApplication {
public:
  ExtexApplication() = default;
  virtual ~ExtexApplication() = default;

  STATUS Start();

private:
  Window *m_window;
  Editor *m_editor;
  Renderer *m_renderer;

  STATUS m_lastStatus;
};

#endif /* APPLICATION_H */
