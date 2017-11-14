#include "stdafx.h"
#include "Arrow.h"

Arrow::Arrow(const float x, const float y, const int type) : Object(x, y, type)
{
	Size = 2;
	Speed = 100.0f;
	LifeTime = 10000.0f;
	Life = 10.0f;

	Color.r = 0.0f;
	Color.g = 1.0f;
	Color.b = 0.0f;
	Color.a = 1.0f;

	Direction.x = (((float)std::rand() / (float)RAND_MAX) - 0.5f);
	Direction.y = (((float)std::rand() / (float)RAND_MAX) - 0.5f);
	// 교수님 코드 참고
	// printf("%f, %f \n", Direction.x, Direction.y);

	ParentNode = NULL;
	erase_arrow = false;
}

Arrow::~Arrow()
{
}

void Arrow::Render(Renderer * renderer)
{
	renderer->DrawSolidRect(Position.x, Position.y, 0, Size, Color.r, Color.g, Color.b, Color.a);
}

void Arrow::Update(DWORD time)
{
	float s = (float)time / 1000.0f;

	Position.x += Direction.x * Speed * s * 3;
	Position.y += Direction.y * Speed * s * 3;

	if (Position.x <= -250 + Size / 2 || Position.x >= 250 - Size / 2)
		erase_arrow = true;
	if (Position.y <= -250 + Size / 2 || Position.y >= 250 - Size / 2)
		erase_arrow = true;

	LifeTime -= 0.1f;
}
