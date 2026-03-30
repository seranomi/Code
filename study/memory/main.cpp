#include <iostream>

using namespace std;
const int kMaxStr = 100;

int Min(int a, int b)
{
	return a < b ? a : b;
}

struct MyStruct
{
	int first;
	int second;

	int Sum()
	{
		return first + second;
	}
};

class MyString
{
public:
	MyString(const char *init_str)
	{
		cout << "MyString(const char *init_str)" << endl;

		// 1. 글자 수 확인
		size_ = 0;
		while(init_str[size_] != '\0')
		{
			size_++;
		}

		// 2. 글자 수 0 아니면 할당
		if (size_ > 0){
			str_ = new char[size_];
		}

		// 3. 복사
		memcpy(str_, init_str, size_);
	}

	~MyString()
	{
		// 호출 시점 확인
		cout << "Destructor" << endl;

		size_ = 0;
		if (str_)
			delete[] str_;
	}

	void Resize(int new_size)
	{
		char *new_str = new char[new_size];

		memcpy(new_str, str_, Min(new_size, size_));

		delete[] str_;
		str_ = new_str;
		size_ = new_size;
	}

	void Print()
	{
		for (int i = 0; i < size_; i++)
		{
			cout << str_[i];
		}
		cout << endl;
	}

	void Append(MyString *app_str)
	{
		int old_size = size_;
		Resize(size_ + app_str->size_);

		for(int i = old_size; i < size_; i++){
			str_[i] = app_str->str_[i - old_size];
		}
	}


private:
	int size_ = 0;
	char *str_ = nullptr;

};

int main()
{
	char str1[] = "Hello World!";
	char str2[kMaxStr];

	memcpy(str2, str1, Min(sizeof(str1), sizeof(str2)));
	cout << str2 << endl;

	char *dynamic_array = new char[kMaxStr];

	// 주의 동적할당 메모리는 변수 사이즈가 포인터 사이즈이다.
	memcpy(dynamic_array, str1, Min(sizeof(str1), kMaxStr));
	cout << dynamic_array << endl;

	cout << str1 << " " << str2 << " " << dynamic_array << endl;
	cout << size_t(str1) << " " << size_t(str2) << " " << size_t(dynamic_array) << endl;

	delete[] dynamic_array;

	MyStruct a;
	a.first = 1;
	a.second = 2;

	cout << sizeof(a) << endl;
	cout << a.Sum() << endl;

	MyStruct *ptr_a = &a;

	ptr_a->first = 4;
	
	cout << (*ptr_a).first << " " << (*ptr_a).second << " " << (*ptr_a).Sum() << endl;
	cout << ptr_a->first << " " << ptr_a->second << " " << ptr_a->Sum() << endl;

	MyStruct pairs[10];
	for(int i = 0; i < 10; i++){
		pairs[i].first = i;
		pairs[i].second = i*10;
	}
	for(int i = 0; i < 10; i++){
		cout << pairs[i].Sum() << endl;
	}

	MyString str3("ABCDE");
	MyString str4("123");

	str3.Print();
	str3.Append(&str4);
	str3.Print();
	str3.Append(&str4);
	str3.Print();


	return 0;
}