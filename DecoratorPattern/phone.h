//装饰器模式
//普通版
#include<iostream>
using namespace std;

class Phone
{
public :
	Phone()
	{}
	virtual ~Phone()
	{}
	virtual void showDecorate()
	{}
};

class iPhone  : public Phone  //具体手机类
{
private:
	string name;
public:
	iPhone(string _name)
		:name(_name)
	{}
	~iPhone()
	{}
	void showDecorate()
	{
		cout << name<<"'s decoration"<< endl;
	}
};

class NokiaPhone : public  Phone
{
private:
	string name;
public :
	NokiaPhone(string _name)
		:name(_name)
	{}
	~NokiaPhone()
	{}
	void  showDecorate()
	{
		cout << name <<"'s decoration"<< endl;
	}
};

class DecoratorPhone :public Phone
{
private :
	Phone* m_phone; //要装饰的手机
public:
	DecoratorPhone(Phone *phone)
		:m_phone(phone)
	{}
	virtual void showDecorate()
	{
		m_phone->showDecorate();
	}
};

class DecoratePhoneA : public DecoratorPhone //具体的装饰A
{
public :
	DecoratePhoneA(Phone* ph)
		:DecoratorPhone(ph)
	{}
	void showDecorate()
	{
		DecoratorPhone::showDecorate();
		AddDecorate();
	}
private:
	void AddDecorate()
	{
		cout <<"add Pendant" << endl;      //增加挂件
	}

};

class DecoratePhoneB : public DecoratorPhone
{
public:
	DecoratePhoneB(Phone* ph)
		:DecoratorPhone(ph)
	{}
	void showDecorate()
	{
		DecoratorPhone::showDecorate();
		AddDecorate();
	}
private:
	void  AddDecorate()
	{
		cout << "add ScreenCover"<< endl;      //屏幕贴膜
	}

};
