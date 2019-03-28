
#pragma once

#include "../core/Shape.h"

// Mikaus Whiteley
// I assume the point of this file is to keep a layer of abstraction between the use of msdf and
// the underlying font loading mechanism, but I use FT2 in my own system, and am okay with this leak
// in abstraction.
// In UAP the word generic is a keyword, and causes build issues, assign it properly here
// and then undefine it for future code to use as intended.
#define generic GenericFromFreeTypeLibrary
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_OUTLINE_H
#undef generic


namespace msdfgen {

class FreetypeHandle;
class FontHandle;

/// Initializes the FreeType library
FreetypeHandle * initializeFreetype();
/// Deinitializes the FreeType library
void deinitializeFreetype(FreetypeHandle *library);
/// Loads a font file and returns its handle
FontHandle * loadFont(FreetypeHandle *library, const char *filename);
/// Unloads a font file
void destroyFont(FontHandle *font);
/// Returns the size of one EM in the font's coordinate system
bool getFontScale(double &output, FontHandle *font);
/// Returns the width of space and tab
bool getFontWhitespaceWidth(double &spaceAdvance, double &tabAdvance, FontHandle *font);
/// Loads the shape prototype of a glyph from font file - Added by Mikaus Whiteley
bool loadGlyph(Shape &output, FT_Face fontFace, int unicode, double *advance = NULL);
/// Loads the shape prototype of a glyph from font file
bool loadGlyph(Shape &output, FontHandle *font, int unicode, double *advance = NULL);
/// Returns the kerning distance adjustment between two specific glyphs.
bool getKerning(double &output, FontHandle *font, int unicode1, int unicode2);

}
