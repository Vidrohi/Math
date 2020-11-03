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

    Transform GetRotation() const;
    Transform GetTranslation() const;

    Vector3 GetPosition() const;

    static Transform CreateRotationMatrix(float eulerXYZ[3]);
    static Transform CreateTranslationMatrix(float posXYZ[3]);
    static Transform CreateScaleMatrix(float scaleXYZ[3]);

    static Transform CreateMatrix(float eulerXYZ[3], float posXYZ[3], float scaleXYZ[3]);

private:
    float val[4][4] = {0.0f};
};

