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

	// ���������δ� ���̰� �ݵ�� 1�̾�� �Ѵ�. ��ġ�����ε� �׷���?
	cout << LU << endl;
	if (LU == 1.0f)
	{
		cout << "Lengh 1" << endl;
	}
	else
	{
		cout << "Length not 1" << endl;
	}

	// 1�� ������ ������ �ŵ������ص� ������ 1�̾�� �Ѵ�.
	// ���� �׷���?
	float powLU = powf(LU, 1.0e6f);
	cout << "LU^(10^6) = " << powLU << endl;

	return 0;
}