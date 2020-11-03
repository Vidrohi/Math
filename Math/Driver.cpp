#include <stdio.h>
#include "Vector3.h"
#include "Transform.h"

int main()
{
	printf("BS");

	Vector3 vOne(1.f, 1.f, 0.f);
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

	printf("\n Projection %s", Vector3::Project(other, horizontal).GetAsString().c_str());
	printf("\n Distance %f", Vector3::GetHorizontalDistance(other, horizontal));

	printf("\n ************************************ \n");

	Transform t;
	printf("\n Transform:\n%s", t.GetAsString().c_str());

	Transform identityTx(Transform::CreateIdentity());
	printf("\n Identity Transform:\n%s", identityTx.GetAsString().c_str());

	Vector3 rightTri(3.f, 4.f, 5.f);
	Vector3 vProd = rightTri * identityTx;
	printf("\n Product Identity:\n%s", vProd.GetAsString().c_str());

	float oneAcrossAllthree[3] = { 1.f, 1.f, 1.f };
	Transform unitTranslation(Transform::CreateTranslationMatrix(oneAcrossAllthree));
	vProd = rightTri * unitTranslation;
	printf("\n Translate %s by 1 along each axis \n%s", rightTri.GetAsString().c_str(), vProd.GetAsString().c_str());

	Transform rotate45DegreesAboutZ(Transform::CreateRotationAboutZ(45.f));
	vProd = Vector3::UnitX * rotate45DegreesAboutZ;
	printf("\n Rotate %s by 45 along z axis \n%s", Vector3::UnitX.GetAsString().c_str(), vProd.GetAsString().c_str());

	printf("\n Translate %s by 1 along each axis \n%s", vProd.GetAsString().c_str(), (vProd * unitTranslation).GetAsString().c_str());

	Transform combineRotationAndTranslation(rotate45DegreesAboutZ * unitTranslation);
	printf("\n Rotate %s by 45 along z axis then translate by 1 unit along each axis\n%s", Vector3::UnitX.GetAsString().c_str(), (Vector3::UnitX * combineRotationAndTranslation).GetAsString().c_str());
	Transform combineTranslationAndRotation(unitTranslation * rotate45DegreesAboutZ);
	printf("\n Translate by 1 unit along each axis then Rotate %s by 45 along z axis\n%s", Vector3::UnitX.GetAsString().c_str(), (Vector3::UnitX * combineTranslationAndRotation).GetAsString().c_str());

	Transform rotate45DegreesAboutX(Transform::CreateRotationAboutX(45.f));
	vProd = Vector3::UnitX * rotate45DegreesAboutX;
	printf("\n Rotate %s by 45 along x axis \n%s", Vector3::UnitX.GetAsString().c_str(), vProd.GetAsString().c_str());

	Transform rotate45DegreesAboutY(Transform::CreateRotationAboutY(45.f));
	vProd = Vector3::UnitX * rotate45DegreesAboutY;
	printf("\n Rotate %s by 45 along y axis \n%s", Vector3::UnitX.GetAsString().c_str(), vProd.GetAsString().c_str());


	printf("\n ************************************ \n");

	getchar();

	return 0;
}