#include "application.hpp"

#include <spdlog/spdlog.h>

#include "event_bus.hpp"

#define INITIALIZE_COMPONENT(component, errorMessage)                          \
  do {                                                                         \
    component->SetEventBus(&eventBus);                                         \
    m_lastStatus = component->Initialize();                                    \
    if (m_lastStatus != SUCCESS) {                                             \
      spdlog::error(errorMessage);                                             \
      return m_lastStatus;                                                     \
    }                                                                          \
  } while (0)

STATUS ExtexApplication::Start() {
  EventBus eventBus;

  m_window = new Window(1280, 720, "Extex");
  m_editor = new Editor();
  m_renderer = new Renderer();

  INITIALIZE_COMPONENT(m_window, "Failed to initialize Window.");
  INITIALIZE_COMPONENT(m_editor, "Failed to initialize Editor.");
  INITIALIZE_COMPONENT(m_renderer, "Failed to initialize Renderer.");

  while(m_window->IsWindowOpen()) {
    m_editor->Update();
    m_window->Update();
    m_renderer->Update();
  }

  m_renderer->Destroy();
  m_editor->Destroy();
  m_window->Destroy();

  return SUCCESS;
}
