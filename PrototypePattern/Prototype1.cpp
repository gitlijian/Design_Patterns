//#include <iostream>
//using namespace std;
//
////抽象类
//class Prototype
//{
//public:
//	 Prototype(){}
//	 ~Prototype(){}
//
//	 virtual Prototype *clone() = 0;
//};
//
////原型模式类
//class ConcretePrototypeA :public Prototype
//{
//public:
//    //构造函数初始化过程
//	ConcretePrototypeA() :member(0){
//
//        cout<<"beg:---------------------------\n";
//        //模拟一个非常耗时的初始化操作
//        for(int i = 0;i<5;++i){
//            cout<<"I am initizlizing....\n";
//            _sleep(1000);
//        }
//
//        cout<<"end:---------------------------\n";
//
//	}
//	~ConcretePrototypeA(){}
//
//	ConcretePrototypeA(const ConcretePrototypeA &rhs){
//		member = rhs.member;
//	}
//
//	virtual Prototype* clone() override {
//		cout << "copy of self" << endl;
//		Prototype * proClo = (Prototype*)new ConcretePrototypeA(*this);
//		return proClo;
//	}
//
//	void SetMem(int mem){
//	    this->member = mem;
//	}
//
//	int GetMem(){
//        return member;
//	}
//
//	void ShowMem(){
//        cout<<"mem:"<<member<<endl;
//	}
//
//
//private:
//	int member;     //成员变量
//};
//
//int main(int argc, char **argv)
//{
//	//生成对象
//	ConcretePrototypeA *conPro = new ConcretePrototypeA();
//
//	//重新动态生成对象
//	ConcretePrototypeA  * clo1 = new ConcretePrototypeA();
//	clo1->SetMem(10);
//
//	//普通生成对象
//	ConcretePrototypeA  clo2 ;
//	clo2 = *conPro;
//    //clo2->SetMem(20);
//
//	conPro->ShowMem();
//	clo1->ShowMem();
//	clo2.ShowMem();
//
//	delete conPro;
//	conPro = NULL;
//
//	delete clo1;
//	clo1 = NULL;
//
//
//
//	return 0;
//}
