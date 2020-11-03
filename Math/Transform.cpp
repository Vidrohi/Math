#include "Transform.h"

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

    Vector3 Row0({ val[0][0],val[0][1],val[0][2] });
    Vector3 Row1({ val[1][0],val[1][1],val[1][2] });
    Vector3 Row2({ val[2][0],val[2][1],val[2][2] });

    Vector3 OtherCol0({ other(0,0), other(1,0), other(2,0) });
    Vector3 OtherCol1({ other(0,1), other(1,1), other(2,1) });
    Vector3 OtherCol2({ other(0,2), other(1,2), other(2,2) });
    /************************************************************************/
    //R
    /************************************************************************/
    //x basis
    result(0, 0) = Row0.Dot(OtherCol0);
    result(0, 1) = Row0.Dot(OtherCol1);
    result(0, 2) = Row0.Dot(OtherCol2);
    /************************************************************************/
    //y basis
    result(1, 0) = Row1.Dot(OtherCol0);
    result(1, 1) = Row1.Dot(OtherCol1);
    result(1, 2) = Row1.Dot(OtherCol2);
    /************************************************************************/
    //z basis
    result(2, 0) = Row2.Dot(OtherCol0);
    result(2, 1) = Row2.Dot(OtherCol1);
    result(2, 2) = Row2.Dot(OtherCol2);
    /************************************************************************/

    /************************************************************************/
    /// TODO : FINISH THIS
    Vector3 Row3({ val[3][0],val[3][1],val[3][2]});
    //T
    //result(3, 0) = Row3.Dot(OtherCol0);
    //result(3, 1) = Row3.Dot(OtherCol1);
    //result(3, 2) = Row3.Dot(OtherCol2);

    return result;
}

Transform Transform::GetRotation() const
{
    Transform result(*this);
    result(3, 0) = 0.f;
    result(3, 1) = 0.f;
    result(3, 2) = 0.f;

    return result;
}

Transform Transform::GetTranslation() const
{
    Transform result;
    result(3, 0) = val[3][0];
    result(3, 1) = val[3][1];
    result(3, 2) = val[3][2];

    return result;
}

Vector3 Transform::GetPosition() const
{
    Vector3 Row3({ val[3][0],val[3][1],val[3][2] });
    return Row3;
}

Transform Transform::CreateRotationMatrix(float eulerXYZ[3])
{
    Transform result;
    /* if (fabs(eulerXYZ[0]) > std::numeric_limits<float>::epsilon())
     {

     }

     if (fabs(eulerXYZ[1]) > std::numeric_limits<float>::epsilon())
     {

     }

     if (fabs(eulerXYZ[2]) > std::numeric_limits<float>::epsilon())
     {

     }
    }*/
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
    result(3, 0) = fabs(scaleXYZ[0] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[0] : 1.f;
    result(3, 1) = fabs(scaleXYZ[1] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[1] : 1.f;
    result(3, 2) = fabs(scaleXYZ[2] - 1.f) > std::numeric_limits<float>::epsilon() ? scaleXYZ[2] : 1.f;
    return result;
}

Transform Transform::CreateMatrix(float eulerXYZ[3], float posXYZ[3], float scaleXYZ[3])
{
    Transform result;
    return result;
}
