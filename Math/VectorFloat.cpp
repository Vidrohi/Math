#include "VectorFloat.h"
#include <sstream>

VectorFloat VectorFloat::UnitX(1.f, 0.f, 0.f);
VectorFloat VectorFloat::UnitY(0.f, 1.f, 0.f);
VectorFloat VectorFloat::UnitZ(0.f, 0.f, 1.f);
VectorFloat VectorFloat::Zero(0.f, 0.f, 0.f);

VectorFloat::VectorFloat(float x, float y, float z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
    , m_w(1)
{}

VectorFloat::VectorFloat()
    : m_x(0)
    , m_y(0)
    , m_z(0)
    , m_w(1)
{}

VectorFloat::VectorFloat(const VectorFloat& other)
    : m_x(other.m_x)
    , m_y(other.m_y)
    , m_z(other.m_z)
    , m_w(1)
{}

VectorFloat::VectorFloat(float* xyz)
    : m_x(*xyz)
    , m_y(*(xyz + 1))
    , m_z(*(xyz + 2))
    , m_w(1)
{
}

VectorFloat VectorFloat::operator+(const VectorFloat& other) const
{
    VectorFloat result(m_x + other.m_x
        , m_y + other.m_y
        , m_z + other.m_z);

    return result;
}

VectorFloat& VectorFloat::operator+=(const VectorFloat& other)
{
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return *this;
}

VectorFloat VectorFloat::operator*(float scale) const
{
    VectorFloat result(m_x * scale
        , m_y * scale
        , m_z * scale);

    return result;
}

VectorFloat& VectorFloat::operator*=(float scale)
{
    m_x *= scale;
    m_y *= scale;
    m_z *= scale;
    return *this;
}

void VectorFloat::Normalize()
{
    float len = GetLength();
    m_x /= len;
    m_y /= len;
    m_z /= len;
}

VectorFloat VectorFloat::GetNormalized() const
{
    VectorFloat result(*this);
    result.Normalize();
    return result;
}

float VectorFloat::GetLengthSquared() const
{
    return m_x * m_x + m_y * m_y + m_z * m_z;
}

float VectorFloat::GetLength() const
{
    return std::sqrt(GetLengthSquared());
}

float VectorFloat::Dot(const VectorFloat& other) const
{
    return (m_x * other.m_x + m_y * other.m_y + m_z * other.m_z);
}

VectorFloat VectorFloat::Cross(const VectorFloat& other) const
{
    return { m_y * other.m_z - m_z * other.m_y,
            m_z * other.m_x - m_x * other.m_z,
            m_x * other.m_y - m_y * other.m_x };
}

std::string VectorFloat::GetAsString() const
{
    std::ostringstream vectorAsString;
    vectorAsString<<m_x <<" " <<m_y<< " "<< m_z;
    return vectorAsString.str();
}
