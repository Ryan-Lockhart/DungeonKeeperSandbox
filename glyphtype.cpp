#include "glyphtype.hpp"
#include <stdexcept>

GlyphType::GlyphType(std::string path, size_t glyphWidth, size_t glyphHeight) :
	m_Texture(new raylib::Texture(path)),
	m_Width(m_Texture->GetWidth()),
	m_Height(m_Texture->GetHeight()),
	m_GlyphWidth(glyphWidth),
	m_GlyphHeight(glyphHeight)
{
	size_t glyphCountX = m_Width / m_GlyphWidth;
	size_t glyphCountY = m_Height / m_GlyphHeight;

	m_GlyphRects.reserve(glyphCountX * glyphCountY);

	for (size_t y = 0; y < m_Height; y += m_GlyphHeight)
		for (size_t x = 0; x < m_Width; x += m_GlyphWidth)
			m_GlyphRects.push_back(new raylib::Rectangle(x, y, m_GlyphWidth, m_GlyphHeight));
}

GlyphType::~GlyphType()
{
	delete m_Texture;

	for (auto& rect : m_GlyphRects)
		delete rect;
}

const raylib::Rectangle& GlyphType::GetRect(size_t index) const
{
	try
	{ return *m_GlyphRects.at(index); }
	catch (std::out_of_range e)
	{ throw (e.what()); }
}

void GlyphType::DrawGlyph(size_t glyphIndex, raylib::Color color, raylib::Rectangle destination, raylib::Vector2 origin, float rotation, float scale) const
{
	m_Texture->DrawTiled(GetRect(glyphIndex), destination, origin, rotation, scale, color);
}

void GlyphType::DrawGlyph(Glyph glyph, raylib::Rectangle destination, raylib::Vector2 origin, float rotation, float scale) const
{
	m_Texture->DrawTiled(GetRect(glyph.GetIndex()), destination, origin, rotation, scale, glyph.GetColor());
}
