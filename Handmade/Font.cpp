#include "Font.h"



Font::Font()
{
}


Font::~Font()
{
}

void Font::Init()
{
	TheTexture::Instance()->LoadFontFromFile("Assets/Fonts/Impact.ttf", 100, "FONT");

	std::string tag = "FONT";
	SetTag(tag);
	m_text.SetFont("FONT");
	m_text.SetColor(255, 0, 0);
	m_text.SetText("Hellooooo0000");
	m_text.SetSize(600, 400);
}

void Font::Draw()
{
	m_text.Draw(500, 500);
}

