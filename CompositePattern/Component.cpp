/* 
    组合模式：将对象组合成树形结构以表示‘部分-整体’的层次结构。
    组合模式使得用户对单个对象和组合对象的使用具有一致性
*/

#include<iostream>
#include<list>
#include<string>
using namespace std;

class Component
{ // 为组合中的对象声明接口，在适当情况下，实现所有类共有接口的默认行为
    protected: 
        string name;
    
    public:
        Component(string n){ name=n; }
        virtual ~Component(){};
        virtual void Add(Component* c)=0;
        virtual void Remove(Component* c)=0;
        virtual void Display(int depth)=0;
};

class Leaf : public Component
{ // 在组合中表示叶节点对象，叶节点没有子节点
public:
    Leaf(string name) : Component(name) {}
    void Add(Component* c){} // 叶节点没有Add功能，但这样做能使接口具备一致性，这就是透明方式，如果不加入Add和Remove方法，那就是安全方式
    void Remove(Component* c) {} 
    void Display(int depth) { cout<<name<<" "<<depth<<endl; }
};

class Composite : public Component 
{ // 定义有枝节点行为，用来存储子部件
private:
    list<Component*> children;
public:
    Composite(string name) : Component(name) {}
    void Add(Component* c) { children.push_back(c); };
    void Remove(Component* c) { children.remove(c); } ;
    void Display(int depth) 
    {
        cout<<name<<" "<<depth<<endl;
        for(auto c=children.begin(); c != children.end(); c++)
        {
            (*c)->Display(depth+1);
        }
    }
};

int main()
{ // 客户端代码
    Composite* root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite* comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf CB"));
    root->Add(comp);

    Composite* comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp->Add(comp2);

    root->Display(1);

    return 0;
}
/* output:
root 1
Leaf A 3
Leaf B 3
Composite X 3
Leaf XA 5
Leaf CB 5
Composite XY 5
Leaf XYA 7
Leaf XYB 7
*/