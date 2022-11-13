#include <iostream>
#include <fstream>	// 파일 
#include <string>	// string class
#include <cmath>	// 부동소수 연산
#include <cfloat>	// 부동소수 연산
#include <vector>	// 동적으로 크기가 자료구조

using namespace std;

// 하나의 점을 표시하는 구조체
// long double -> 소수점 자리수 오차를 줄이기 위해서 
// 소수점 아래 6자리 출력 -> 소수점 아래 7자리
// 소수점 오차를 줄이기 위해서 정밀한 값을 사용했다. 
typedef struct Point {
	long double x;
	long double y;
} P;

// 점 정보
typedef struct Point_info {
	long double dis;	// 중심 점과의 거리
	size_t c_num;		// 중심 점의 번호
}P_info;

// 군집 정보
typedef struct Cluster_info {
	Point center;	// 중심점
	size_t c_size;	// 해당 군집의 점 개수 
}C_info;

long double cal_dis( const Point&, const Point& );	// 거리 계산
Point cal_cent( long double, long double, long double );	// 중심점 구하기
bool not_change( const Point&, const Point& );				// 1.125125125125125125125125125125 != 1.1


vector<P> *points;			// 입력받은 점 배열
vector<C_info> *c_info;		// cluster_info
vector<P_info> *p_infos;	// 내 기준 가장 가까운 점과 거리 배열

int main( void )
{
	cout.precision( 6 );
	cout.setf( ios::fixed );
	ifstream fout;
	int input_k;
	string file_name;

	cout << "파일 이름과 k 값을 입력하세요: ";
	cin >> file_name >> input_k;

	fout.open( file_name, ios::out );

	if (fout.is_open())
	{
		string str;
		getline( fout, str );
		points = new vector<P>( stoi( str ) );
		c_info = new vector<C_info>( input_k );
		p_infos = new vector<P_info>( stoi( str ) );

		int i = 0;
		while (getline( fout, str ))
		{
			// 274.53652630530405 266.6164204713247
			// 274.536526305
			string f_str = str.substr( 0, str.find( "." ) + 8 );
			string b_str = str.substr( str.find( " " ), str.find( ".", str.find( " " ) ) - str.find( " " ) + 8 );

			// 오차 줄일 때, 버림, 반올림, 올림 중에 하나를 썼더니 됐다.
			long double f_d = floor( stold( f_str, nullptr ) * 1000000.0l ) / 1000000.0l;
			long double b_d = floor( stold( b_str, nullptr ) * 1000000.0l ) / 1000000.0l;
			(*points)[i] = P{ f_d, b_d};
			i += 1;
		}
	}
	
	cout << "초기 클러스터의 구성 : \n";
	(*c_info)[0].center = (*points)[0];
	for (int i = 1; i < input_k; i += 1)
	{
		int last = points->size();
		long double max = 0;
		for (int j = 1; j < last; j += 1)
		{
			long double dis_min = cal_dis( (*c_info)[0].center, (*points)[j] );

			for (int k = 1; k < i; k += 1)
			{
				long double temp = cal_dis( (*c_info)[k].center, (*points)[j] );
				if (dis_min > temp)
				{
					dis_min = temp;
				}
			}

			if (max < dis_min)
			{
				max = dis_min;
				(*c_info)[i].center = (*points)[j];
			}
		}
		cout << "\t클러스터 " << i << ": 중심점 = ";
		cout << "(" << (*c_info)[i].center.x << ", " << (*c_info)[i].center.y << "\n";
	}



	bool is_same = false;
	int cnt = 2;
	while (!is_same)
	{
		for (int i = 0; i < input_k; i += 1)
		{
			(*c_info)[i].c_size = 0;
		}
		
		int last = points->size();
		for (int i = 1; i < last; i += 1)
		{
			(*p_infos)[i].c_num = 0;
			(*p_infos)[i].dis = cal_dis( (*c_info)[0].center, (*points)[i] );
			for (int j = 1; j < input_k; j += 1)
			{
				long double temp = cal_dis( (*c_info)[j].center, (*points)[i] );

				if ((*p_infos)[i].dis > temp)
				{
					(*p_infos)[i].c_num = j;
					(*p_infos)[i].dis = temp;
				}
			}
		}

		P* centers = new P[input_k] {};
		for (int i = 0; i < last; i += 1)
		{
			(*c_info)[(*p_infos)[i].c_num].c_size += 1;
			
			centers[(*p_infos)[i].c_num].x += (*points)[i].x;
			centers[(*p_infos)[i].c_num].y += (*points)[i].y;
		}

		
		for (int i = 0; i < input_k; i += 1)
		{
			P cent = cal_cent( centers[i].x, centers[i].y, (long double)(*c_info)[i].c_size );

			if (not_change( (*c_info)[i].center, cent ))
			{
				is_same = true;
			}
			else
			{
				(*c_info)[i].center = cent;
				is_same = false;
			}
		}
		if (!is_same)
		{
			cout << cnt << "번째 클러스터 구성:\n";
			for (int i = 0; i < input_k; i += 1)
			{
				cout << "\t클러스터 " << i << ": 중심점 = ";
				cout << "(" << (*c_info)[i].center.x << ", " << (*c_info)[i].center.y << ")" << "\n";
			}
			cnt += 1;
		}
		
		delete[] centers;
		cout << "\n";
	}
	cout << "### 클러스터 구성 완료!! : 반복 횟수 = " << cnt - 1 << "\n";
	for (int i = 0; i < input_k; i += 1)
	{
		cout << "\t클러스터 " << i << ": 중심점 = ";
		cout << "(" << (*c_info)[i].center.x << ", " << (*c_info)[i].center.y << "), point 수 = " << (*c_info)[i].c_size << ", 최장 거리 = " << (*p_max)[i].dis << "\n";
	}

	delete points;
	delete c_info;
	delete p_infos;
	
	fout.close();

	return 0;
}

long double cal_dis( const Point& p1, const Point& p2)
{
	return sqrt( pow( p1.x - p2.x, 2 ) + pow( p1.y - p2.y, 2 ) );
}

Point cal_cent( long double x, long double y, long double size )
{
	return Point{
		ceil( (x / size) * 1000000.0l ) / 1000000.0l,	// 0.1234561238 -> 0.123456
		ceil( (y / size) * 1000000.0l ) / 1000000.0l	// 소수점 오차 제거
	};
}

bool not_change( const Point& p1, const Point& p2 )
{
	return (abs( p1.x - p2.x ) < DBL_EPSILON) && (abs(p1.y - p2.y) < DBL_EPSILON);	// 부동소수점 비교 인터넷에서 봤음
}