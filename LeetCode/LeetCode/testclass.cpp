#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person(string n = "default", int a = 0); //string置空，后面访问name会运行出错(空指针访问)
	void getcontent()const;
};

Person::Person(string n,int a) : name(n), age(a) {}
void Person::getcontent()const {
	cout << "name: " << name << ",  age: " << age << endl;
}

class Student : public Person{
public:
private:
	float score;
public:
	Student(float s=0);
	void getcontent() const;
};

Student::Student(float s) :Person(),score(s){}
void Student::getcontent()const {
	Person::getcontent();
	cout << "score: " << score << endl;
}

int main01() {
	Person* p = new Person(string("ddd"),33);
	Student* s = new Student(89.5);
	p->getcontent();
	s->getcontent();
	//Student *stu = new Person(); //子类指针指向父类对象，编译错误
	Person* per = new Student(); //父类指针指向子类对象，多态的应用之一

	return 0;
}


//STL test1: 以","作为分割，将一串字符串截取子串放入容器中
vector<string> getSubStr(string str) {
	//返回值不能用引用，vector没有移动构造。加引用后返回的是空
	vector<string> res;
	vector<string>::iterator it=res.begin();
	int len = str.size();
	int start(0),pos(0);
	while ((pos = str.find(",", start))!=-1) {
		string strtmp = str.substr(start, pos - start);
		res.push_back(strtmp);
		start = ++pos;
	}
	return res;
}

int main() {
	string s = "2fa, ,, 23,qwer";
	vector<string> res;
	res = getSubStr(s);
	for (string e : res)
		cout << e << endl;
	return 0;
}



