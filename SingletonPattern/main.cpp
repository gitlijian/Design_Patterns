//
//  main.cpp
//  SingletonPattern
//
//  Created by lijian on 2020/7/17.
//  Copyright © 2020 lijian. All rights reserved.
//

#include <iostream>
using namespace std;
/*
设计一个类，只能生成该类的一个实例
饿汉单例：在类装载时完成了初始化，静态成员对象初始化成功
类加载速度相比懒汉慢，但获取对象的速度快，是一种典型的以时间换取空间的做法
优点：线程安全
缺点：不管你用不用这个对象，他都会先创建出来，会造成浪费内存空间
 */
//class Singleon
//{
//private:
//    Singleon()
//    {
//        cout << "Singleon()" << endl;
//    }
//    static Singleon* instance;
//public:
//    static Singleon* GetSingleon()
//    {
//        return instance;
//    }
//    static Singleon* Destroy()
//    {
//        delete instance;
//        instance = NULL;
//        return instance;
//    }
//};
//
//Singleon* Singleon::instance = new Singleon();
//int main()
//{
//    Singleon* sl1 = Singleon::GetSingleon();
//    Singleon* sl2 = Singleon::GetSingleon();
//    Singleon* sl3 = Singleon::GetSingleon();
//    cout << sl1 << endl;
//    cout << sl2 << endl;
//    cout << sl3 << endl;
//
//    return 0;
//}

// 懒汉单例
//class Singleon
//{
//private:
//    Singleon()
//    {
//        cout << "Singleon()" << endl;
//    }
//    static Singleon*instance;
//public:
//    static Singleon* GetSingleon()
//    {
//        if (NULL == instance)
//        {
//            instance = new Singleon();
//            cout << "对象创建成功" << endl;
//        }
//        else
//        {
//            cout << "对象已经创建成功，无须再建" << endl;
//        }
//        return instance;
//    }
//    static Singleon* Destroy()
//    {
//        delete instance;
//        instance = NULL;
//        return instance;
//    }
//};
//Singleon* Singleon::instance =  NULL;
//int main()
//{
//    Singleon* sl1 = Singleon::GetSingleon();
//    Singleon* sl2 = Singleon::GetSingleon();
//    Singleon* sl3 = Singleon::GetSingleon();
//    cout << sl1 << endl;
//    cout << sl2 << endl;
//    cout << sl3 << endl;
//
//    return 0;
//}

/*
 上面的懒汉模式的代码是有问题的，当多线程运行时，创建实例的时间一长，一个线程正在创建实例，
 另一个线程同时也创建实例，就会导致出现多个不同的实例
 线程安全的懒汉模式
 */
class Singleton
{
public:
    static Singleton* GetInstance()
    {
        // 第一次检查：实例化单例对象后，就不会再进入加锁逻辑
        if (p_singleton_ == nullptr)
        {
            std::lock_guard<std::mutex> lock(mux_);
            // 第二次检查：可能两个线程同时通过第一次检查，一个线程获得锁时，可能另外一个线程已经实例化单体
            if (p_singleton_ == nullptr)
            {
                p_singleton_ = new Singleton();
                cout << "对象创建成功" << endl;
            }
        }
        else
        {
             cout << "对象已经创建成功，无须再建" << endl;
        }
        return p_singleton_;
    }
private:
    Singleton()
    {
        cout << "Singleon()" << endl;
    }
    static Singleton * p_singleton_ ;
    static std::mutex mux_;
};
 
std::mutex Singleton::mux_;
Singleton * Singleton::p_singleton_ = nullptr;
int main()
{
    auto p1 = Singleton::GetInstance();
    auto p2 = Singleton::GetInstance();
    cout<<p1<<endl;
    cout<<p2<<endl;
    return 0;
}

/*
单例模式的使用场景：
1、有频繁实例化然后销毁的情况，也就是频繁的 new 对象，可以考虑单例模式；

2、创建对象时耗时过多或者耗资源过多，但又经常用到的对象；

3、频繁访问 IO 资源的对象，例如数据库连接池或访问本地文件；
*/
