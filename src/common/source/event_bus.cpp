#include "event_bus.hpp"

#include <spdlog/spdlog.h>

EventBus::EventBus() {}

EventBus::~EventBus() {}

STATUS EventBus::Subscribe(EVENT_TYPES type, EventListener listener) {
  if (m_listeners[type].listenersCount >= EVENT_BUS_LISTENERS_MAX - 1) {
    spdlog::error("Failed to subscribe listener, maximum of listeners has been reached.");
    return FAILURE;
  }

  UINT16 index = m_listeners[type].listenersCount;
  m_listeners[type].listeners[index] = listener;
  m_listeners[type].listenersCount++;

  return SUCCESS;
}

STATUS EventBus::Publish(const Event &event) {
  for (UINT16 i = 0; i < m_listeners[event.type].listenersCount + 1; i++) {
    if (m_listeners[event.type].listeners[i]) {
      m_listeners[event.type].listeners[i](event);
    }
  }
  return SUCCESS;
}
