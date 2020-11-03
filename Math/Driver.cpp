#include <stdio.h>
#include "Vector3.h"

int main()
{
    printf("BS");

    Vector3 vOne(1.f,1.f,0.f);
    printf("\n %f", Vector3::UnitX.Dot(vOne.GetNormalized()));
    Vector3 crossResult(Vector3::UnitY.Cross(Vector3::UnitZ));
    printf("\n %s", crossResult.GetAsString().c_str());
    printf("\n %f", vOne.Dot(crossResult.GetNormalized()));
    printf("\n %s", Vector3::Zero.GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());
    printf("\n %s", (vOne + vOne).GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());
    printf("\n %s", (vOne += vOne).GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());

    Vector3 horizontal(10.f, 0.f, 0.f);
    Vector3 other(4.f, 12.f, 0.f);

    printf("\n Projection %s", Vector3::Project(other,horizontal).GetAsString().c_str());
    printf("\n Distance %f", Vector3::GetHorizontalDistance(other, horizontal));

    getchar();

    return 0;
}