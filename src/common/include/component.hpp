#ifndef COMPONENT_H
#define COMPONENT_H

#include "types.hpp"
#include "event_bus.hpp"
#include "vao.hpp"

#include "spdlog/spdlog.h"

class ComponentBase {
public:
  virtual STATUS Initialize() = 0;
  virtual STATUS Update() = 0;
  virtual STATUS Destroy() = 0;
};

enum RENDERER_TYPE { RENDERER_BACKGROUND, RENDERER_TYPES_MAX };

class ComponentRenderable : public ComponentBase {
public:
  virtual RENDERER_TYPE GetRendererID() const = 0;

protected:
  VertexArrayObject m_vao;
};

class ComponentPubSub : public ComponentBase {
public:
  virtual void SetEventBus(EventBus *bus) { m_eventBus = bus; }

protected:
  STATUS Subscribe(EVENT_TYPES type, EventListener listener) {
    if(m_eventBus == nullptr) {
      spdlog::error("Failed to subscribe to event. Event Bus is not set.");
      return FAILURE;
    }

    return m_eventBus->Subscribe(type, listener);
  }

  STATUS Publish(const Event &event) {
    if(m_eventBus == nullptr) {
      spdlog::error("Failed to publish event. Event Bus is not set.");
      return FAILURE;
    }

    return m_eventBus->Publish(event);
  }

  EventBus *m_eventBus;
};

#endif /* COMPONENT_H */
