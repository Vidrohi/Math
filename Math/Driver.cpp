#include <stdio.h>
#include "VectorFloat.h"

int main()
{
    printf("BS");

    VectorFloat vOne(1.f,1.f,0.f);
    printf("\n %f", VectorFloat::UnitX.Dot(vOne.GetNormalized()));
    VectorFloat crossResult(VectorFloat::UnitY.Cross(VectorFloat::UnitZ));
    printf("\n %s", crossResult.GetAsString().c_str());
    printf("\n %f", vOne.Dot(crossResult.GetNormalized()));
    printf("\n %s", VectorFloat::Zero.GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());
    printf("\n %s", (vOne + vOne).GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());
    printf("\n %s", (vOne += vOne).GetAsString().c_str());
    printf("\n %s", vOne.GetAsString().c_str());

    getchar();

    return 0;
}