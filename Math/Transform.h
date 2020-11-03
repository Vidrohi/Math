#pragma once
#include "Vector3.h"

class Transform
{
public:
    Transform();
    Transform(const Transform& other) = default;

    float& operator()(int idx_x, int idx_y);
    float operator()(int idx_x, int idx_y) const;
    Transform operator*(const Transform& other);
	Transform& operator*=(const Transform& other);

    Transform GetRotation() const;
    Transform GetTranslation() const;

    Vector3 GetPosition() const;

	void SetRow(int rowIdx, const Vector3& v, float w);

    static Transform CreateRotationMatrix(float eulerDegreesXYZ[3]);
	static Transform CreateRotationAboutX(float eulerDegressX);
	static Transform CreateRotationAboutY(float eulerDegressY);
	static Transform CreateRotationAboutZ(float eulerDegressZ);
    static Transform CreateTranslationMatrix(float posXYZ[3]);
    static Transform CreateScaleMatrix(float scaleXYZ[3]);

    static Transform CreateMatrix(float eulerXYZ[3], float posXYZ[3], float scaleXYZ[3]);
	static const Transform CreateIdentity();

private:
    float val[4][4] = {0.0f};
};

