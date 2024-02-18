#include "renderers/renderer_background.hpp"

void RendererBackground::Render(ComponentRenderable *obj) {
  Background* background = (Background*) obj;

  glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
