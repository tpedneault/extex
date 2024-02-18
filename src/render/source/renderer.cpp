#include "renderer.hpp"

#include "spdlog/spdlog.h"

STATUS Renderer::Initialize() {
  // Initialize the renderers.
  m_renderers[RENDERER_BACKGROUND] = new RendererBackground();

  // Subscribe to each event this component should listen for.
  Subscribe(EVENT_QUEUE_RENDER, BIND_EVENT_HANDLER(OnQueueRender));

  return SUCCESS;
}

STATUS Renderer::Update() {
  // Render all elements in the queue.
  for(UINT16 i = 0; i < m_queueInsertPosition; i++) {
    RENDERER_TYPE renderer = m_renderQueue[i]->GetRendererID();
    m_renderers[renderer]->Render(m_renderQueue[i]);
  }

  // All items in the render queue were rendered, go back to the beginning of the queue.
  m_queueInsertPosition = 0;

  return SUCCESS;
}

STATUS Renderer::Destroy() {
  return SUCCESS;
}

EVENT_HANDLER Renderer::OnQueueRender(const Event &e) {
  if(m_queueInsertPosition >= RENDERER_QUEUE_MAX - 1) {
    spdlog::error("Failed to add event to the queue. Queue is full.");
  }

  m_renderQueue[m_queueInsertPosition] = (ComponentRenderable*)e.data;
  m_queueInsertPosition++;
}
