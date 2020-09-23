/*
    将对象组合成树形结构以表示“部分-整体”的层次结构。组合使得用户对单个对象和组合对象的使用具有一致性
*/
#include<iostream>
#include<string>
#include <memory>
#include<list>
using namespace std;

class Company
{ // 基类
public:
    Company(string name) { m_name=name; }
    virtual ~Company() {}
    virtual void Add(shared_ptr<Company> pCom) {}
    virtual void Remove(shared_ptr<Company> pCom) {}

    virtual void Show(int depth)
    {
        for(int i=0; i<depth; i++)
            cout<<"-";
        cout<<m_name<<endl;
    }
    virtual void LineOfDuty(){} // 履行职责
protected:
    string m_name;
};

class ConcreteCompany : public Company
{ // 具体公司类
public:
    ConcreteCompany(string name) : Company(name) {}
    virtual ~ConcreteCompany() {}
    // 位于树的中间，可以增加子树
    void Add(shared_ptr<Company> pCom){ m_listCompany.push_back(pCom); }
    void Remove(shared_ptr<Company> pCom) { m_listCompany.remove(pCom); }
    void Show(int depth)
    {
        for(int i=0;i<depth;i++)
            cout<<"-";
        cout<<m_name<<endl;

        for(const auto& company:m_listCompany)
            company->Show(depth+2);
    }
    void LineOfDuty()
    {
        for(const auto& company:m_listCompany)
        {
            company->LineOfDuty();
        }
    }
private:
    list<shared_ptr<Company>> m_listCompany;
};

// 具体部门 财务部
class FinanceDepartment : public Company
{
public:
    FinanceDepartment(string name):Company(name) {}
    virtual ~FinanceDepartment() {}
    virtual void Show(int depth)
    {
        for(int i=0;i<depth;i++)
            cout<<"-";
        cout<<m_name<<endl;
    }
    virtual void LineOfDuty()
    {
        cout<<m_name<<" 公司财务收支管理"<<endl;
    }
};

// 具体部门 人力资源部
class HRDepartment : public Company
{
public:
    HRDepartment(string name):Company(name){}
    virtual ~HRDepartment() {}
    virtual void Show(int depth)
    {
        for(int i=0;i<depth;i++)
            cout<<"-";
        cout<<m_name<<endl;
    }
    virtual void LineOfDuty()
    {
        cout<<m_name<<" 员工招聘培训管理"<<endl;
    }
};

// 客户端
int main()
{
    shared_ptr<Company> root=make_shared<ConcreteCompany>("总公司");
    shared_ptr<Company> leaf1=make_shared<HRDepartment>("总公司人力资源部");
    shared_ptr<Company> leaf2=make_shared<FinanceDepartment>("总公司财务部");
    root->Add(leaf1);
    root->Add(leaf2);
    
    // 分公司A
    shared_ptr<Company> midA=make_shared<ConcreteCompany>("分公司A");
    shared_ptr<Company> leaf3=make_shared<HRDepartment>("分公司A人力资源部");
    shared_ptr<Company> leaf4=make_shared<FinanceDepartment>("分公司A财务部");
    midA->Add(leaf3);
    midA->Add(leaf4);
    root->Add(midA);

    // 分公司B
    shared_ptr<Company> midB=make_shared<ConcreteCompany>("分公司B");
    shared_ptr<Company> leaf5=make_shared<HRDepartment>("分公司B人力资源部");
    shared_ptr<Company> leaf6=make_shared<FinanceDepartment>("分公司B财务部");
    midB->Add(leaf5);
    midB->Add(leaf6);
    root->Add(midB);

    // 分公司A_1
    shared_ptr<Company> midA_1=make_shared<ConcreteCompany>("分公司A_1");
    shared_ptr<Company> leaf9=make_shared<HRDepartment>("分公司A_1人力资源部");
    shared_ptr<Company> leaf10=make_shared<FinanceDepartment>("分公司A_1财务部");
    midA_1->Add(leaf9);
    midA_1->Add(leaf10);
    midA->Add(midA_1);

    // 分公司B_1
    shared_ptr<Company> midB_1=make_shared<ConcreteCompany>("分公司B_1");
    shared_ptr<Company> leaf11=make_shared<HRDepartment>("分公司B_1人力资源部");
    shared_ptr<Company> leaf12=make_shared<FinanceDepartment>("分公司B_1财务部");
    midB_1->Add(leaf11);
    midB_1->Add(leaf12);
    midB->Add(midB_1);

    cout<<"\n 结构图: "<<endl;
    root->Show(1);

    cout<<"\n 职责: "<<endl;
    root->LineOfDuty();

    return 0;
}