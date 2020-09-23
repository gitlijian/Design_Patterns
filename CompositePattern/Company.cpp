/*
    ��������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ�����ʹ���û��Ե����������϶����ʹ�þ���һ����
*/
#include<iostream>
#include<string>
#include <memory>
#include<list>
using namespace std;

class Company
{ // ����
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
    virtual void LineOfDuty(){} // ����ְ��
protected:
    string m_name;
};

class ConcreteCompany : public Company
{ // ���幫˾��
public:
    ConcreteCompany(string name) : Company(name) {}
    virtual ~ConcreteCompany() {}
    // λ�������м䣬������������
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

// ���岿�� ����
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
        cout<<m_name<<" ��˾������֧����"<<endl;
    }
};

// ���岿�� ������Դ��
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
        cout<<m_name<<" Ա����Ƹ��ѵ����"<<endl;
    }
};

// �ͻ���
int main()
{
    shared_ptr<Company> root=make_shared<ConcreteCompany>("�ܹ�˾");
    shared_ptr<Company> leaf1=make_shared<HRDepartment>("�ܹ�˾������Դ��");
    shared_ptr<Company> leaf2=make_shared<FinanceDepartment>("�ܹ�˾����");
    root->Add(leaf1);
    root->Add(leaf2);
    
    // �ֹ�˾A
    shared_ptr<Company> midA=make_shared<ConcreteCompany>("�ֹ�˾A");
    shared_ptr<Company> leaf3=make_shared<HRDepartment>("�ֹ�˾A������Դ��");
    shared_ptr<Company> leaf4=make_shared<FinanceDepartment>("�ֹ�˾A����");
    midA->Add(leaf3);
    midA->Add(leaf4);
    root->Add(midA);

    // �ֹ�˾B
    shared_ptr<Company> midB=make_shared<ConcreteCompany>("�ֹ�˾B");
    shared_ptr<Company> leaf5=make_shared<HRDepartment>("�ֹ�˾B������Դ��");
    shared_ptr<Company> leaf6=make_shared<FinanceDepartment>("�ֹ�˾B����");
    midB->Add(leaf5);
    midB->Add(leaf6);
    root->Add(midB);

    // �ֹ�˾A_1
    shared_ptr<Company> midA_1=make_shared<ConcreteCompany>("�ֹ�˾A_1");
    shared_ptr<Company> leaf9=make_shared<HRDepartment>("�ֹ�˾A_1������Դ��");
    shared_ptr<Company> leaf10=make_shared<FinanceDepartment>("�ֹ�˾A_1����");
    midA_1->Add(leaf9);
    midA_1->Add(leaf10);
    midA->Add(midA_1);

    // �ֹ�˾B_1
    shared_ptr<Company> midB_1=make_shared<ConcreteCompany>("�ֹ�˾B_1");
    shared_ptr<Company> leaf11=make_shared<HRDepartment>("�ֹ�˾B_1������Դ��");
    shared_ptr<Company> leaf12=make_shared<FinanceDepartment>("�ֹ�˾B_1����");
    midB_1->Add(leaf11);
    midB_1->Add(leaf12);
    midB->Add(midB_1);

    cout<<"\n �ṹͼ: "<<endl;
    root->Show(1);

    cout<<"\n ְ��: "<<endl;
    root->LineOfDuty();

    return 0;
}