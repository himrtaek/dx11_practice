#include <iostream>
#include <Windows.h>
#include <xnamath.h>

using namespace std;

ostream& operator<<(ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);

	os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ")";
	return os;
}

int main()
{
	cout.precision(8);

	if (!XMVerifyCPUSupport())
	{
		cout << "xna math not supported" << endl;
		return 0;
	}

	XMVECTOR u = XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f);
	XMVECTOR n = XMVector3Normalize(u);

	float LU = XMVectorGetX(XMVector3Length(n));

	// 수학적으로는 길이가 반드시 1이어야 한다. 수치적으로도 그럴까?
	cout << LU << endl;
	if (LU == 1.0f)
	{
		cout << "Lengh 1" << endl;
	}
	else
	{
		cout << "Length not 1" << endl;
	}

	// 1을 임의의 지수로 거듭제곱해도 여전히 1이어야 한다.
	// 과연 그럴까?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	return 0;
}