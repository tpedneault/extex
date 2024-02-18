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
/* FILE NAME  : shader.hpp                                                                         */
/* DESCRIPTION: Implementation of OpenGL shader and shader programs.                               */
/* AUTHOR     : Thomas Pedneault                                                                   */
/* DATE       : 2024-02-18                                                                         */
/***************************************************************************************************/

#ifndef SHADER_H
#define SHADER_H

#include "types.hpp"

#include <GL/glew.h>

/**
 * @class Shader
 * @brief Manages the compilation and linkage of GLSL shaders into a program.
 *
 * The Shader class encapsulates functionality to create, compile, and link GLSL
 * shaders. It provides methods to add shaders from source code, compile them
 * into a shader program, and bind or unbind the program for rendering
 * operations. The class also handles the cleanup of shader resources.
 */
class Shader {
public:
  /**
   * @brief Initializes the shader program.
   *
   * Creates a new shader program and sets the internal program ID. This method
   * should be called before adding any shaders.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Initialize();

  /**
   * @brief Destroys the shader program and frees its resources.
   *
   * Deletes the shader program from the GPU, cleaning up all associated
   * resources.
   *
   * @return STATUS indicating the success of the operation.
   */
  STATUS Destroy();

  /**
   * @brief Binds the shader program for use in rendering operations.
   */
  void Bind();

  /**
   * @brief Unbinds any shader program from the current rendering context.
   */
  void Unbind();

  /**
   * @brief Adds a shader of the given type to the shader program.
   *
   * Compiles the provided shader source code and attaches it to the shader
   * program. If compilation fails, an error is logged with the compilation
   * message.
   *
   * @param type The type of shader to add (e.g., GL_VERTEX_SHADER).
   * @param source The GLSL source code of the shader.
   * @return STATUS indicating the success of the shader compilation and
   * attachment.
   */
  STATUS AddShader(GLenum type, CSTR source);

  /**
   * @brief Adds a shader of the given type to the shader program.
   *
   * Loads the contents of the provided file, compiles the source code, and
   * attaches it to the shader program. If compilation fails, an error is logged
   * with the compilation message.
   *
   */
  STATUS AddShaderFromFile(GLenum type, CSTR path);

  /**
   * @brief Links the attached shaders into a complete shader program.
   *
   * After successfully attaching vertex and fragment shaders, this method
   * links them into a usable shader program. If linking fails, an error is
   * logged.
   *
   * @return STATUS indicating the success of the linking process.
   */
  STATUS CompileProgram();

private:
  UINT32 m_ID; ///< The OpenGL ID of the shader program.
};

#endif /* SHADER_H */
