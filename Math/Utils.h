#pragma once
#include <corecrt_math_defines.h>

namespace Utils
{
	float DegreesToRadians(float degrees)
	{
		return degrees * static_cast<float>(M_PI)/ 180.0f;
	}

	float RadiansToDegrees(float radians)
	{
		return 180.f * radians / static_cast<float>(M_PI);
	}
}