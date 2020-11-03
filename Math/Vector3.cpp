#include "Vector3.h"
#include <sstream>

Vector3 Vector3::UnitX(1.f, 0.f, 0.f);
Vector3 Vector3::UnitY(0.f, 1.f, 0.f);
Vector3 Vector3::UnitZ(0.f, 0.f, 1.f);
Vector3 Vector3::Zero(0.f, 0.f, 0.f);

Vector3::Vector3(float x, float y, float z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{}

Vector3::Vector3()
    : m_x(0.f)
    , m_y(0.f)
    , m_z(0.f)
{}

Vector3::Vector3(const Vector3& other)
    : m_x(other.m_x)
    , m_y(other.m_y)
    , m_z(other.m_z)
{}

Vector3::Vector3(float xyz[3])
    : m_x(*xyz)
    , m_y(*(xyz + 1))
    , m_z(*(xyz + 2))
{
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;
    return *this;
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return { m_x - other.m_x
            , m_y - other.m_y
            , m_z - other.m_z };
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return { m_x + other.m_x
        , m_y + other.m_y
        , m_z + other.m_z };
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return *this;
}

Vector3 Vector3::operator*(float scale) const
{
    return { m_x * scale
        , m_y * scale
        , m_z * scale };
}

Vector3& Vector3::operator*=(float scale)
{
    m_x *= scale;
    m_y *= scale;
    m_z *= scale;
    return *this;
}

Vector3 Vector3::operator/(float scale) const
{
    return { m_x / scale
    , m_y / scale
    , m_z / scale };
}

void Vector3::Normalize()
{
    float len = GetLength();
    m_x /= len;
    m_y /= len;
    m_z /= len;
}

Vector3 Vector3::GetNormalized() const
{
    /*
    * Slightly less optimal, made the more optimal one because this is a very frequent math operation
    * VectorFloat result(*this);
    * result.Normalize();
    * return result;
    */

    float len = GetLength();
    return{ m_x / len,
            m_y / len,
            m_z / len };
}

float Vector3::GetLengthSquared() const
{
    return m_x * m_x + m_y * m_y + m_z * m_z;
}

float Vector3::GetLength() const
{
    return std::sqrt(GetLengthSquared());
}

float Vector3::Dot(const Vector3& other) const
{
    return (m_x * other.m_x + m_y * other.m_y + m_z * other.m_z);
}

Vector3 Vector3::Cross(const Vector3& other) const
{
    return { m_y * other.m_z - m_z * other.m_y,
            m_z * other.m_x - m_x * other.m_z,
            m_x * other.m_y - m_y * other.m_x };
}

std::string Vector3::GetAsString() const
{
    std::ostringstream vectorAsString;
    vectorAsString<<m_x <<" " <<m_y<< " "<< m_z;
    return vectorAsString.str();
}

Vector3 Vector3::Project(const Vector3& vectorToProject, const Vector3& projectOn)
{
    // Qproj = Q * (P.Q / |Q|^2)
    return projectOn * (projectOn.Dot(vectorToProject)) / projectOn.GetLengthSquared();
}

float Vector3::GetHorizontalDistance(const Vector3& positionVector, const Vector3& directionVector)
{
    // D = P - Qproj
     return (positionVector - (Project(positionVector, directionVector))).GetLength();
}
