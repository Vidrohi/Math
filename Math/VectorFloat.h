#pragma once
#include <string>

class VectorFloat
{
public:
    VectorFloat();
    VectorFloat(float x, float y, float z);
    VectorFloat(float* xyz);
    VectorFloat(const VectorFloat& other);

    VectorFloat operator +(const VectorFloat& other) const;
    VectorFloat& operator +=(const VectorFloat& other);

    VectorFloat operator *(float scale) const;
    VectorFloat& operator *=(float scale);

    void Normalize();
    VectorFloat GetNormalized() const;

    float GetLengthSquared() const;
    float GetLength() const;

    float Dot(const VectorFloat& other) const;
    VectorFloat Cross(const VectorFloat& other) const;

    std::string GetAsString() const;

    static VectorFloat UnitX;
    static VectorFloat UnitY;
    static VectorFloat UnitZ;
    static VectorFloat Zero;
private:
    float m_x, m_y, m_z, m_w;
};

