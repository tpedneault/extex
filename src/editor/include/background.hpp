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
/* FILE NAME  : background.hpp                                                                     */
/* DESCRIPTION: Contains the implementation of a background to be renderered in the text editor.   */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-15                                                                         */
/***************************************************************************************************/

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "component.hpp"
#include "shader.hpp"

class Background : public ComponentRenderable {
public:
  Background();
  virtual ~Background();

  virtual STATUS Initialize();
  virtual STATUS Update();
  virtual STATUS Destroy();

  virtual RENDERER_TYPE GetRendererID() const;

  Shader &GetShader();

private:
  Shader m_shader;
  bool m_initializedShader;
};

#endif /* BACKGROUND_H */
