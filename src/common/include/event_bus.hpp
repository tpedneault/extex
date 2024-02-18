/***************************************************************************************************/
/*                                                                                                 */
/*                       $$$$$$$$\ $$\   $$\ $$$$$$$$\ $$$$$$$$\ $$\   $$\                         */
/*                       $$  _____|$$ |  $$ |\__$$  __|$$  _____|$$ |  $$ |                        */
/*                       $$ |      $$\ $$  |   $$ |   $$ |      $$\ $$  |                          */
/*                       $$$$$\     $$$$  /    $$ |   $$$$$\     $$$$  /                           */
/*                       $$  __|    $$  $$<     $$ |   $$  __|    $$  $$<                          */
/*                       $$ |      $$  /$$\    $$ |   $$ |      $$  /$$\                           */
/*                       $$$$$$$$\ $$ /  $$ |   $$ |   $$$$$$$$\ $$ /  $$ |                        */
/*                       \________|\__|  \__|   \__|   \________|\__|  \__|                        */
/*                                                                                                 */
/***************************************************************************************************/
/* FILE NAME  : event_bus.hpp                                                                      */
/* DESCRIPTION: Event Bus implementation, allows each components to communicate with each other.   */
/*              This implementation allows the system to be fully decoupled.                       */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-16                                                                         */
/***************************************************************************************************/

#ifndef EVENT_BUS_H
#define EVENT_BUS_H

#include <typeinfo>
#include <functional>

#include "types.hpp"
#include "event.hpp"

#define EVENT_BUS_LISTENERS_MAX 100

// Macro to bind a member function to an instance with a placeholder for one argument
// This macro should only be used in the Initialize() function of a ComponentPubSub.
#define BIND_EVENT_HANDLER(method) [this](const Event& e) { this->method(e); }

#define EVENT_HANDLER void

typedef std::function<void(const Event&)> EventListener;

struct EventListenerEntry {
  EventListener listeners[EVENT_BUS_LISTENERS_MAX];
  UINT16 listenersCount;
};

class EventBus {
public:
  EventBus();
  virtual ~EventBus();

  STATUS Subscribe(EVENT_TYPES type, EventListener listener);
  STATUS Publish(const Event& event);

private:
  EventListenerEntry m_listeners[EVENT_TYPES_MAX];
};

#endif /* EVENT_BUS_H */
