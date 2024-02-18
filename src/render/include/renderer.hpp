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
/* FILE NAME  : renderer.hpp                                                                       */
/* DESCRIPTION: Main endering engine, receives and handles each render job.                        */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-15                                                                         */
/***************************************************************************************************/

#ifndef RENDERER_H
#define RENDERER_H

#include "renderers/renderer_base.hpp"
#include "renderers/renderer_background.hpp"

#define RENDERER_QUEUE_MAX 1024

/**
 * @class Renderer
 * @brief Manages the rendering pipeline.
 *
 * Inherits from ComponentBase to integrate with an application's component
 * system. This class encapsulates the setup and usage of shaders and vertex
 * array objects (VAOs) to render graphics. It provides methods for initializing
 * the rendering resources, updating the rendering logic, and destroying the
 * resources.
 */
class Renderer : public ComponentPubSub {
public:
  Renderer() {}
  virtual ~Renderer() {}

  /**
   * @brief Initializes rendering resources.
   *
   * @return STATUS indicating the success or failure of the initialization
   * process.
   */
  STATUS Initialize();

  /**
   * @brief Updates the rendering logic.
   *
   * Performs rendering operations using the jobs in the queue. This
   * method should be called in the application's main loop to render each
   * frame.
   *
   * @return STATUS indicating the success of the rendering update.
   */
  STATUS Update();

  /**
   * @brief Destroys rendering resources.
   *
   * @return STATUS indicating the success of the resource cleanup.
   */
  STATUS Destroy();

private:
  EVENT_HANDLER OnQueueRender(const Event &e);

  RendererBase *m_renderers[RENDERER_TYPES_MAX];
  ComponentRenderable *m_renderQueue[RENDERER_QUEUE_MAX];
  UINT16 m_queueInsertPosition;
};

#endif /* RENDERER_H */
