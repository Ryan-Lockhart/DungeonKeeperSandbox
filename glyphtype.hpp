#ifndef GLYPHTYPE_H

#define GLYPHTYPE_H
#include <raylib-cpp.hpp>
#include <vector>
#include "glyph.hpp"

class GlyphType
{
public:
	GlyphType(std::string path, size_t glyphWidth, size_t glyphHeight);
	~GlyphType();

	void DrawGlyph(size_t glyphIndex, raylib::Color color, raylib::Rectangle destination, raylib::Vector2 origin = raylib::Vector2(0, 0), float rotation = 0.0f, float scale = 1.0f) const;
	void DrawGlyph(Glyph glyph, raylib::Rectangle destination, raylib::Vector2 origin = raylib::Vector2(0, 0), float rotation = 0.0f, float scale = 1.0f) const;
private:
	raylib::Texture* m_Texture;

	size_t m_Width;
	size_t m_Height;

	size_t m_GlyphWidth;
	size_t m_GlyphHeight;

	std::vector<raylib::Rectangle*> m_GlyphRects;

	const raylib::Rectangle& GetRect(size_t index) const;
};

#endif
