#pragma once

class Body {
public:
	Body() = default;
	~Body() = default;

private:
};

class World
{
public:
	World() = default;
	~World() = default;

	void Step();
private:
	long long m_TimeStep = 1 / 60.0f;
	float m_Gravity = 9.0f;
};
