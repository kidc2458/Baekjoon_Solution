// 2775.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int main()
{
	int T = 0, k = 0, n = 0;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> k;
		cin >> n;

		int* arr = new int[n];
		for (int j = 1; j <= n; ++j)
			arr[j - 1] = j;
		for (int t = 0; t < k; ++t)
			for (int j = 1; j < n; ++j)
				arr[j] = arr[j - 1] + arr[j];

		cout << arr[n - 1] << endl;
		delete arr;
	}
}