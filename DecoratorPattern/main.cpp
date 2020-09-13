//#include<iostream>
//using namespace std;
//
//#include "finery.h"
//
//int main(int argc,char ** argv){
//
//    Person1 *xc = new Person1("xiaocai");
//
//    cout<<"first decoration:\n";
//
//    Tshirts *ts = new Tshirts();
//    BigTrouser *bt = new BigTrouser();
//
//    ts->Decorate(xc);
//    bt->Decorate(ts);
//
//    bt->Show();
//
//    cout<<"\nSecond decoration:\n";
//
//    Sneakers *sn = new Sneakers();
//    LeatherShoes *ls = new LeatherShoes();
//
//    sn->Decorate(xc);
//    ls->Decorate(sn);
//
//    ls->Show();
//
//
//    return 0;
//}

#include "phone.h"
int main(){

    Phone* ph = new NokiaPhone("16300");

	Phone *dpa = new DecoratePhoneA(ph);//增加挂件

	Phone* dpb = new DecoratePhoneB(dpa);//增加贴膜

    //Phone* dpb = new DecoratePhoneB(dpa);//增加贴膜

	dpb->showDecorate();

	delete ph;
	delete dpa;
	delete dpb;
	return 0;

    return 0;
}
