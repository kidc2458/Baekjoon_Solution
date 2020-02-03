// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>


using namespace std;

vector<unsigned int> s_time; //시작 시간
vector<unsigned int> e_time; //끝 시간
vector<unsigned int> d_time; //소요 시간
list<int> r_index;

void SubLogTime(string & log)
{
	unsigned int endTime = 0;

	endTime += (unsigned int)(log[11] - '0') * 36000;
	endTime += (unsigned int)(log[12] - '0') * 3600;
	endTime += (unsigned int)(log[14] - '0') * 600;
	endTime += (unsigned int)(log[15] - '0') * 60;
	endTime += (unsigned int)(log[17] - '0') * 10;
	endTime += (unsigned int)(log[18] - '0');
	endTime *= 1000;
	endTime += (unsigned int)(log[20] - '0') * 100;
	endTime += (unsigned int)(log[21] - '0') * 10;
	endTime += (unsigned int)(log[22] - '0');

	e_time.push_back(endTime);

	unsigned int duration = 0;

	{
		unsigned int tmp = 0;
		unsigned int j = 1, k = 1000;
		for (int i = log.length() - 2; i > 23; --i)
		{
			if (log[i] == '.')
			{
				duration *= k;
				j *= k;
			}
			else
			{
				tmp = (unsigned int)(log[i] - '0');
				duration += tmp * j;
				j *= 10;
				if (k > 1)
					k /= 10;
			}
		}
	}

	d_time.push_back(duration);

	if (endTime < duration)
		s_time.push_back((24 * 360000) - (duration - endTime));
	else
		s_time.push_back(endTime - duration);
}

int solution(vector<string> lines) {
	int answer = 0;

	for (auto & log : lines)
	{
		SubLogTime(log);
	}

	unsigned int endTime = e_time.back() - 1000;
	unsigned int size = s_time.size();

	for (int i = 0; i < size; ++i)
	{
		int count = 0;
		for (int j = 0; j < size; ++j)
		{
			if (s_time[i] > e_time[j] || e_time[i] < s_time[j])
			{
			}
			else
			{
				++count;
			}
		}

		--count;
		if (answer < count)
			answer = count;
	}



	//for (unsigned int i = 0; i < endTime; ++i)
	//{
	//	int count = 0;
	//	list<int> index;
	//	for (unsigned int j = 0; j < size; ++j)
	//	{
	//		if (e_time[j] < i || s_time[j] > i + 1000)
	//		{
	//		}
	//		else
	//		{
	//			++count;
	//			index.push_back(j);
	//		}
	//	}

	//	if (answer < count)
	//	{
	//		r_index = index;
	//		answer = count;
	//	}
	//}

	//int count = lines.size();
	//for (int i = 0; i < count; ++i)
	//{
	//	cout << s_time[i] << " " << e_time[i] << " " << d_time[i] << endl;
	//}

	return answer;
}

int main()
{
	vector<string> input;
	input.push_back("2019-01-01 00:00:02.321 3.12s");
	input.push_back("2019-01-01 00:04:29.012 11.923s");
	input.push_back("2019-01-01 00:07:29.123 112.76s");
	input.push_back("2019-01-01 00:11:29.064 334.16s");
	input.push_back("2019-01-01 00:13:29.453 522.11s");
	input.push_back("2019-01-01 00:17:29.340 323.44s");
	input.push_back("2019-01-01 00:18:29.500 23.123s");
	input.push_back("2019-01-01 00:24:29.112 11.32s");
	input.push_back("2019-01-01 00:32:29.924 56.123s");
	input.push_back("2019-01-01 00:44:29.490 23.132s");
	input.push_back("2019-01-01 00:56:29.001 2.1s");

	cout << solution(input) << endl;

	for (auto index : r_index)
		cout << index << " ";
	cout << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
