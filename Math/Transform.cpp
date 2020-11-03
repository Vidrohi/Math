#include <cassert>

#include "Transform.h"
#include "Utils.h"

Transform::Transform()
{
    val[3][3] = 1.f;
}

float& Transform::operator()(int idx_x, int idx_y)
{
    return val[idx_x][idx_y];
}

float Transform::operator()(int idx_x, int idx_y) const
{
    return val[idx_x][idx_y];
}

Transform Transform::operator*(const Transform& other)
{
    Transform result;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			for (int k = 0; k < 3; ++k)
			{
				result(r,c) += val[r][k] * other(k, c);
			}
		}
	}

	for (int c = 0; c < 3; c++)
	{
		result(3, c) = other(3, c);
		for (int k = 0; k < 3; ++k)
		{
			result(3, c) += val[3][k] * other(k, c);
		}
	}

    return result;
}

Transform& Transform::operator*=(const Transform& other)
{
	// TODO OPTIMIZE
	*this = (*this * other);
	return *this;
}

Transform Transform::GetRotation() const
{
    Transform result(*this);
    result.SetRow(3, Vector3(), 1.0f);

    return result;
}

Transform Transform::GetTranslation() const
{
    Transform result;
	result.SetRow(3, Vector3(val[3][0], val[3][1], val[3][2]), 1.0f);

    return result;
}

Vector3 Transform::GetPosition() const
{
    Vector3 Row3({ val[3][0],val[3][1],val[3][2] });
    return Row3;
}

void Transform::SetRow(int rowIdx, const Vector3& v, float w)
{
	assert(("Invalid index for component access!\n" , (rowIdx >= 0) && (rowIdx < 3)));
	val[rowIdx][0] = v.x();
	val[rowIdx][1] = v.y();
	val[rowIdx][2] = v.z();
	val[rowIdx][3] = w;
}

Transform Transform::CreateRotationMatrix(float eulerXYZ[3])
{
    Transform result(Transform::CreateIdentity());
	result *= CreateRotationAboutX(eulerXYZ[0]);
	result *= CreateRotationAboutY(eulerXYZ[1]);
	result *= CreateRotationAboutZ(eulerXYZ[2]);
    return result;
}

Transform Transform::CreateRotationAboutX(float eulerDegressX)
{
	if (fabs(eulerDegressX) > std::numeric_limits<float>::epsilon())
	{
		return Transform::CreateIdentity();
	}

	Transform result(Transform::CreateIdentity());
	float angleInRadians = Utils::DegreesToRadians(eulerDegressX);
	float cosine = cos(angleInRadians);
	float sine = sin(angleInRadians);

	result(1,1) = cosine;
	result(2,2) = cosine;
	result(2,1) = -1 * sine;
	result(1,2) = sine;

	return result;
}

Transform Transform::CreateRotationAboutY(float eulerDegressY)
{
	if (fabs(eulerDegressY) > std::numeric_limits<float>::epsilon())
	{
		return Transform::CreateIdentity();
	}

	Transform result(Transform::CreateIdentity());
	float angleInRadians = Utils::DegreesToRadians(eulerDegressY);
	float cosine = cos(angleInRadians);
	float sine = sin(angleInRadians);

	result(0,0) = cosine;
	result(2,2) = cosine;
	result(0,2) = -1 * sine;
	result(2,0) = sine;

	return result;
}

Transform Transform::CreateRotationAboutZ(float eulerDegressZ)
{
	if (fabs(eulerDegressZ) > std::numeric_limits<float>::epsilon())
	{
		return Transform::CreateIdentity();
	}

	Transform result(Transform::CreateIdentity());
	float angleInRadians = Utils::DegreesToRadians(eulerDegressZ);
	float cosine = cos(angleInRadians);
	float sine = sin(angleInRadians);

	result(0,0) = cosine;
	result(1,1) = cosine;
	result(1,0) = -1 * sine;
	result(0,1) = sine;

	return result;
}

Transform Transform::CreateTranslationMatrix(float posXYZ[3])
{
    Transform result;
    result(3, 0) = fabs(posXYZ[0]) > std::numeric_limits<float>::epsilon() ? posXYZ[0] : 0.f;
    result(3, 1) = fabs(posXYZ[1]) > std::numeric_limits<float>::epsilon() ? posXYZ[1] : 0.f;
    result(3, 2) = fabs(posXYZ[2]) > std::numeric_limits<float>::epsilon() ? posXYZ[2] : 0.f;
    return result;
}

Transform Transform::CreateScaleMatrix(float scaleXYZ[3])
{
    Transform result;
    result(0, 0) = fabs(scaleXYZ[0] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[0] : 1.f;
    result(1, 1) = fabs(scaleXYZ[1] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[1] : 1.f;
    result(2, 2) = fabs(scaleXYZ[2] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[2] : 1.f;
    return result;
}

Transform Transform::CreateMatrix(float eulerXYZ[3], float posXYZ[3], float scaleXYZ[3])
{
    Transform result;
    return result;
}

const Transform Transform::CreateIdentity()
{
	Transform result;
	result.SetRow(0, Vector3(1.0f, 0.0f, 0.0f), 0.0f);
	result.SetRow(1, Vector3(1.0f, 1.0f, 0.0f), 0.0f);
	result.SetRow(2, Vector3(1.0f, 0.0f, 1.0f), 0.0f);
	result.SetRow(3, Vector3(0.0f, 0.0f, 0.0f), 1.0f);
	return result;
}
