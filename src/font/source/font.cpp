#include "font.hpp"

#include <spdlog/spdlog.h>

Font::Font(CSTR fontPath) : m_path(fontPath) {}

STATUS Font::Initialize() {
  INT32 result;

  result = FT_Init_FreeType(&m_library);
  if(result != SUCCESS) {
    spdlog::error("Failed to initialize FreeType library for %s", m_path);
    return FAILURE;
  }

  result = FT_New_Face(m_library, m_path, 0, &m_face);
  if(result != SUCCESS) {
    spdlog::error("Failed to load the font face for %s", m_path);
    return FAILURE;
  }

  return SUCCESS;
}

STATUS Font::Destroy() {
  FT_Done_Face(m_face);
  FT_Done_FreeType(m_library);
  return SUCCESS;
}

STATUS Font::SetFontHeight(UINT32 height) {
  INT32 result = FT_Set_Pixel_Sizes(m_face, 0, height);
  if(result != SUCCESS) {
    spdlog::error("Failed to set font size for %s", m_path);
    return FAILURE;
  }

  return SUCCESS;
}

STATUS Font::LoadGlyph(char glyph) {
  INT32 result;

  result = FT_Load_Char(m_face, glyph, FT_LOAD_RENDER);
  if(result != SUCCESS) {
    spdlog::error("Failed to load glyph '%s' for %s", glyph, m_path);
    return FAILURE;
  }

  return SUCCESS;
}

