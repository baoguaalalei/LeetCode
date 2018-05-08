#include<iostream>
#include<assert.h>
using namespace std;
classA{
	public:	int a;
	A(){
		a1 = 1;
		a2 = 2;
		a3 = 3;
		a = 4;
		}
    void fun(){
    cout << a << endl;    //正确
    cout << a1 << endl;   //正确
    cout << a2 << endl;   //正确，类内访问
    cout << a3 << endl;   //正确，类内访问
 }
public:
  int a1;
protected:
  int a2;
private:
  int a3;
};


int main(){
  A itema;
  itema.a = 10;    //正确
  itema.a1 = 20;   //正确
  itema.a2 = 30;   //错误，类外不能访问protected成员
  itema.a3 = 40;   //错误，类外不能访问private成员
  system("pause");
  return 0;
}

#include<iostream>
#include<assert.h>

using namespace std;
classA{
	public: inta;
	A(){
		a1 = 1;
		a2 = 2;
		a3 = 3;
		a = 4;
		}
    void fun(){
		cout << a << endl;    //正确
		cout << a1 << endl;   //正确
		cout << a2 << endl;   //正确
		cout << a3 << endl;   //正确
		}
	public:
	inta1;
	protected:
	inta2;
	private:
	inta3;
	};

classB : public A{
	public:
	int a;
	B(int i)
	{
		A();
		a = i;
	}
	void fun(){
		cout << a << endl;       //正确，public成员
		cout << a1 << endl;       //正确，基类的public成员，在派生类中仍是public成员。
		cout << a2 << endl;       //正确，基类的protected成员，在派生类中仍是protected可以被派生类访问。
        cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
	}
};

int main(){
	B b(10);
	cout << b.a << endl;
	cout << b.a1 << endl;   //正确
	cout << b.a2 << endl;   //错误，类外不能访问protected成员
	cout << b.a3 << endl;   //错误，类外不能访问private成员
	system("pause");
	return 0;
}


2.protected继承：

代码如下：
#include<iostream>
#include<assert.h>
using namespace std;
class A{
	public:
	int a;
    A(){
		a1 = 1;
        a2 = 2;
        a3 = 3;
        a = 4;
		}
    void fun(){
		cout << a << endl;    //正确
		cout << a1 << endl;   //正确
        cout << a2 << endl;   //正确
        cout << a3 << endl;   //正确
		}
    public:
	int a1;
	protected:
	int a2;
    private:
	int a3;
	};
class B : protected A{
	public:
	int a;
	B(int i){
		A();
        a = i;
    }
  void fun(){
    cout << a << endl;       //正确，public成员。
    cout << a1 << endl;       //正确，基类的public成员，在派生类中变成了protected，可以被派生类访问。
    cout << a2 << endl;       //正确，基类的protected成员，在派生类中还是protected，可以被派生类访问。
    cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int main(){
	B b(10);
    cout << b.a << endl;       //正确。public成员
    cout << b.a1 << endl;      //错误，protected成员不能在类外访问。
    cout << b.a2 << endl;      //错误，protected成员不能在类外访问。
    cout << b.a3 << endl;      //错误，private成员不能在类外访问。
    system("pause");
    return 0;
}

3.private继承：

#include<iostream>
#include<assert.h>
using namespace std;
class A{
	public:
	int a;
    A(){ 
	a1 = 1;
    a2 = 2;
    a3 = 3;
    a = 4;
	}
    void fun(){
		cout << a << endl;    //正确
        cout << a1 << endl;   //正确
        cout << a2 << endl;   //正确
        cout << a3 << endl;   //正确
		}
    public:
	int a1;
    protected:
	int a2;
	private:
	int a3;
};
class B : private A{
	public:
    int a;
    B(int i){
		A();
		a = i;
		}
    void fun(){
		cout << a << endl;       //正确，public成员。
		cout << a1 << endl;       //正确，基类public成员,在派生类中变成了private,可以被派生类访问。
		cout << a2 << endl;       //正确，基类的protected成员，在派生类中变成了private,可以被派生类访问。
		cout << a3 << endl;       //错误，基类的private成员不能被派生类访问。
  }
};
int main(){
  B b(10);
  cout << b.a << endl;       //正确。public成员
  cout << b.a1 << endl;      //错误，private成员不能在类外访问。
  cout << b.a2 << endl;      //错误, private成员不能在类外访问。
  cout << b.a3 << endl;      //错误，private成员不能在类外访问。
  system("pause");
  return 0;
}


































