#pragma once
#include <string>

class Vector3
{
public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(float xyz[3]);
    Vector3(const Vector3& other);

    Vector3 operator +(const Vector3& other) const;
    Vector3& operator +=(const Vector3& other);

    Vector3 operator -(const Vector3& other) const;
    Vector3& operator -=(const Vector3& other);

    Vector3 operator *(float scale) const;
    Vector3& operator *=(float scale);

    Vector3 operator /(float scale) const;

    void Normalize();
    Vector3 GetNormalized() const;

    float GetLengthSquared() const;
    float GetLength() const;

    float Dot(const Vector3& other) const;
    Vector3 Cross(const Vector3& other) const;

    std::string GetAsString() const;

    static Vector3 Project(const Vector3& vectorToProject, const Vector3& projectOn);
    static float GetHorizontalDistance(const Vector3& positionVector, const Vector3& directionVector);

    static Vector3 UnitX;
    static Vector3 UnitY;
    static Vector3 UnitZ;
    static Vector3 Zero;

    float x() const { return m_x; }
    float y() const { return m_y; }
    float z() const { return m_z; }
private:
    float m_x, m_y, m_z;
};

