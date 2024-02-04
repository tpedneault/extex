#ifndef FONT_H
#define FONT_H

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include "types.hpp"

/**
 * @class Font
 * @brief Manages font loading and glyph rendering using FreeType.
 *
 * This class encapsulates the functionality required to load fonts from files,
 * initialize FreeType library and face objects, and load specific glyphs at
 * a designated font height. It is designed to facilitate text rendering in
 * graphics applications.
 */
class Font {
public:
  /**
   * @brief Constructs a Font object with the specified font file path.
   *
   * @param fontPath Path to the font file.
   */
  Font(CSTR fontPath);

  /**
   * @brief Initializes the FreeType library and loads the specified font face.
   *
   * This method must be called before attempting to load glyphs or set the font
   * height.
   *
   * @return STATUS indicating the success of the initialization.
   */
  STATUS Initialize();

  /**
   * @brief Destroys the FreeType face and library objects, releasing resources.
   *
   * @return STATUS indicating the success of the cleanup process.
   */
  STATUS Destroy();

  /**
   * @brief Sets the pixel height for the font, affecting glyph loading.
   *
   * This method sets the height in pixels for glyphs of the font. It should be
   * called before loading any glyphs to ensure they are rasterized at the
   * correct size.
   *
   * @param height The desired height in pixels for glyphs of the font.
   * @return STATUS indicating the success of setting the font height.
   */
  STATUS SetFontHeight(UINT32 height);

  /**
   * @brief Loads a specific glyph into the FreeType face for the given
   * character.
   *
   * This method loads the glyph associated with the specified character into
   * the FreeType face, making it ready for rendering.
   *
   * @param glyph The character whose glyph is to be loaded.
   * @return STATUS indicating the success of loading the glyph.
   */
  STATUS LoadGlyph(char glyph);

private:
  CSTR m_path;          ///< Path to the font file.
  FT_Library m_library; ///< FreeType library instance.
  FT_Face m_face;       ///< FreeType face object for the loaded font.
};

#endif /* FONT_H */
