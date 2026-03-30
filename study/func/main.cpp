#include <iostream>
#include <random>
using namespace std;
const int kMaxStr = 100;
bool isEqual(const char str1[], const char str2[]);



int main()
{
	cout << endl;
	// char user_input[100];
	// cout << "Input: ";
	// cin >> user_input;
	cout << "Hello World!" << endl;

	int i;
	i = 123;

	cout << i << " " << sizeof(i) << endl;
	
	float f = 123.456f;
	double d = 123.456; 
	
	cout << f << " " << sizeof(f) << endl;
	cout << d << " " << sizeof(d) << endl;
	
	char c[] = "안";
	char str[] = "안녕";
	// std::string
	cout << c << " " << sizeof(c) << endl;
	cout << str << " " << sizeof(str) << endl;
	
	i = 987.654;
	cout << "int from double: " << i << endl;
	f = 567.89;
	cout << "float from double: " << f << endl;

	i += 100;
	i++;

	bool is_good = true;
	is_good = false;

	cout << is_good << endl;
	cout << boolalpha << true << endl;
	cout << is_good << endl;
	cout << noboolalpha << is_good << endl;

	int arr[3] = {1, 2, 3};

	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	arr[1] = 20;
	cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;

	// char input[100];
	// cin >> input; 
	// // 빈칸 줄바꿈 까지 입력받음
	// cin.ignore(100, '\n'); // 버퍼 비우기
	// // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
	// cout << input << endl;

	// cin.getline(input, sizeof(input));
	// cout << input << endl;

	int number = -1;
	cin >> number;
	cout << number << endl;

	if (number % 2 == 0) {
		cout << "Even" << endl;
	} else {
		cout << "Odd" << endl;
	}

	int my_arr[] = {1,2,3,4,5,4,3,2,1};
	cout << my_arr[0] << " ";
	for (int i = 1; my_arr[i] > my_arr[i-1]; i++){
		cout << my_arr[i] << " ";
	}
	cout << endl;
	
	char my_string[] = "Hello\0, World!";
	for (int i = 0; my_string[i] != '\0'; i++){
		cout << my_string[i];
	}
	cout << endl;

	//난수 생성
	// std::random_device rd; // 시드 생성
	// std::mt19937 gen(rd()); // 난수 생성기 초기화
	// std::uniform_int_distribution<> distrib(1, 99); // 0부터 99 사이의 난수 생성
	
	// int rand_number = distrib(gen);

	// while(true)
	// {
	// 	int geuss;
	// 	cout << "입력: ";
	// 	cin >> geuss;
	// 	if(rand_number == geuss){
	// 		cout << "맞았습니다!"<< endl;
	// 		break;
	// 	}
	// 	else if (rand_number < geuss){
	// 		cout << "down" << endl;
	// 	}
	// 	else{
	// 		cout << "up" << endl;
	// 	}

	// }
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int a = 123;

	cout << &a << endl;

	int *b = &a;
	cout << b << " " << *b << endl;

	std::string pstr[] = {"Hello", "안녕"};
	for (int i = 0; i < sizeof(pstr) / sizeof(pstr[0]); i++){
		cout << *(pstr + i) << endl;
	}
	char str1[kMaxStr];
	while(1)
	{
		cin.getline(str1, sizeof(str1));
		if (isEqual(str1, "stop")){
			cout << "종료합니다." << endl;
			break;
		}
		else{
			cout << "계속합니다." << endl;
		}
	}


	return 0;
}

bool isEqual(const char str1[], const char str2[])
{
	for (int i = 0; i<kMaxStr; i++){
		if (str1[i] != str2[i]){
			return false;
		}
		if (str1[i] == '\0'){
			return true;
		}
	}
	return true;
}