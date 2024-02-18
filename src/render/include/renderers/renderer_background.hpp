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
/* FILE NAME  : renderer_background.hpp                                                            */
/* DESCRIPTION: Renders the given background to the framebuffer.                                   */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-16                                                                         */
/***************************************************************************************************/

#ifndef RENDERER_BACKGROUND_H
#define RENDERER_BACKGROUND_H

#include "renderer_base.hpp"
#include "background.hpp"

class RendererBackground : public RendererBase {
public:
  virtual void Render(ComponentRenderable *component);
};

#endif /* RENDERER_BACKGROUND_H */
