////装饰器模式
////简单版
//#include<iostream>
//using namespace std;
//
//class Phone
//{
//public :
//	Phone()
//	{}
//	virtual ~Phone()
//	{}
//	virtual void showDecorate()
//	{
//	}
//};
//
//
//
//class NokiaPhone : public  Phone
//{
//private:
//	string name;
//public :
//	NokiaPhone(string _name)
//		:name(_name)
//	{}
//	~NokiaPhone()
//	{}
//	void  showDecorate()
//	{
//		cout << name <<"'s decoration"<< endl;
//	}
//};
//
//
//class DecoratePhoneA : public Phone //具体的装饰A
//{
//public :
//	DecoratePhoneA(Phone* _ph):ph(_ph)
//	{}
//
//	void showDecorate()
//	{
//		ph->showDecorate();
//		AddDecorate();
//	}
//
//private:
//	void AddDecorate()
//	{
//		cout <<"add Pendant" << endl;      //增加挂件
//	}
//
//	Phone *ph;
//
//};
//
//class DecoratePhoneB : public Phone
//{
//public:
//	DecoratePhoneB(Phone* _ph):ph(_ph){
//
//	}
//	void showDecorate()
//	{
//		ph->showDecorate();
//		AddDecorate();
//	}
//private:
//	void  AddDecorate()
//	{
//		cout << "add ScreenCover"<< endl;      //屏幕贴膜
//	}
//
//	Phone *ph;
//};
