#include "editor.hpp"
#include "component.hpp"
#include "event.hpp"
#include "renderers/renderer_base.hpp"


STATUS Editor::Initialize() { return SUCCESS; }

STATUS Editor::Update() {
  Publish({ EVENT_QUEUE_RENDER, &m_background });
  return SUCCESS;
}

STATUS Editor::Destroy() { return SUCCESS; }
