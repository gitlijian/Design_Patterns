//
//  main.cpp
//  ProxyPattern
//
//  Created by lijian on 2020/8/2.
//  Copyright © 2020 lijian. All rights reserved.
//

/*
 参考：https://refactoringguru.cn/design-patterns/proxy/cpp/example
 
 C++ 代理模式
 代理是一种结构型设计模式， 让你能提供真实服务对象的替代品给客户端使用。 代理接收客户端的请求并进行一些处理 （访问控制和缓存等）， 然后再将请求传递给服务对象。

 代理对象拥有和服务对象相同的接口， 这使得当其被传递给客户端时可与真实对象互换。
 
 使用示例：
 尽管代理模式在绝大多数 C++ 程序中并不常见， 但它在一些特殊情况下仍然非常方便。 当你希望在无需修改客户代码的前提下于已有类的对象上增加额外行为时， 该模式是无可替代的。

 识别方法：
 代理模式会将所有实际工作委派给一些其他对象。 除非代理是某个服务的子类， 否则每个代理方法最后都应该引用一个服务对象。
 
 */

#include <iostream>
/**
 * The Subject interface declares common operations for both RealSubject and the
 * Proxy. As long as the client works with RealSubject using this interface,
 * you'll be able to pass it a proxy instead of a real subject.
 */
class Subject {
 public:
  virtual void Request() const = 0;
};
/**
 * The RealSubject contains some core business logic. Usually, RealSubjects are
 * capable of doing some useful work which may also be very slow or sensitive -
 * e.g. correcting input data. A Proxy can solve these issues without any
 * changes to the RealSubject's code.
 */
class RealSubject : public Subject {
 public:
  void Request() const override {
    std::cout << "RealSubject: Handling request.\n";
  }
};

/**
 * The Proxy has an interface identical to the RealSubject.
 */
class Proxy : public Subject {
  /**
   * @var RealSubject
   */
 private:
  RealSubject *real_subject_;

  bool CheckAccess() const {
    // Some real checks should go here.
    std::cout << "Proxy: Checking access prior to firing a real request.\n";
    return true;
  }
  void LogAccess() const {
    std::cout << "Proxy: Logging the time of request.\n";
  }

  /**
   * The Proxy maintains a reference to an object of the RealSubject class. It
   * can be either lazy-loaded or passed to the Proxy by the client.
   */
 public:
  Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {
  }

  ~Proxy() {
    delete real_subject_;
  }
      /**
       * The most common applications of the Proxy pattern are lazy loading,
       * caching, controlling the access, logging, etc. A Proxy can perform one of
       * these things and then, depending on the result, pass the execution to the
       * same method in a linked RealSubject object.
       */
      void Request() const override {
        if (this->CheckAccess()) {
          this->real_subject_->Request();
          this->LogAccess();
        }
      }
    };
    /**
     * The client code is supposed to work with all objects (both subjects and
     * proxies) via the Subject interface in order to support both real subjects and
     * proxies. In real life, however, clients mostly work with their real subjects
     * directly. In this case, to implement the pattern more easily, you can extend
     * your proxy from the real subject's class.
     */
    void ClientCode(const Subject &subject) {
      // ...
      subject.Request();
      // ...
    }


#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}
