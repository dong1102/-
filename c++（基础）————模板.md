  # 一、模板是干什么的？ #
**比如实现一个简单的比较大小的函数，如果要比较int、double、char等多种类型的数据，那么有多少中数据类型，我们就得实现多少个比较函数，然而这些函数除了类型不同之外，其他代码都是一样的（也就是代码实现的功能都相同，只是类型不同）。所以为了解决这种问题，我们就引入了模板，模板就是为了代码重用而生的**

# 二、函数模板： #
**函数模板提供了一种函数行为，该函数行为可以用多种不同的类型进行调用；也就是说它和普通的函数很相似，唯一的区别就是函数的元素未确定（这些元素在使用时被参数化）。**

## **1、定义函数模板：** ##

    template <typename T>		//T是模板的类型参数
	T const& max(T const& a, T const& b)	//返回两者中较大的数
	{
	    return a > b ? a : b;
	}

上面定义中，类型参数T表示的是，调用者调用这个函数时所指定的任意类型，可以使用任何类型来实例化该类型参数，只要所用类型提供模板使用的操作就可以。

## **2、使用函数模板：** ##

    #include <iostream>
	#include <string>
	using namespace std;
	
	template <typename T>
	T const& Max(T const& a, T const& b)
	{
	    return a > b ? a : b;
	}
	
	int main()
	{
	    int a1 = 3, b1 = 4;
	    cout << "int: " << Max(a1, b1) << endl;	//用整型实例化参数
	
	    char a2 = '1', b2 = '2';
	    cout << "char: " << Max(a2, b2) << endl;	//用char实例化参数
	
	    double a3 = 3.123, b3 = 3.124;
	    cout << "double: " << Max(a3, b3) << endl;	//用double实例化参数
	
	    string a4 = "asd", b4 = "asx";
	    cout << "string: " << Max(a4, b4) << endl;	//用string实例化参数
	    return 0;
	}
    
	输出：
	int: 4
	char: 2
	double: 3.124
	string: asx

对于上述例子而言，并不是把模板编译成一个可以处理任何类型的单一实体，而是对与实例化模板参数的每种类型，都从模板产生出一个不同的实体。即针对上边四种类型的每一种，都被Max()编译了一次。
    
**1、模板实例化：**

https://blog.csdn.net/djh971102/article/details/89315299

**2、模板实参的推演（类型自推）：模板参数的推演并不适合返回值类型。**

https://blog.csdn.net/djh971102/article/details/89315299

## **3、函数模板参数：** ##

**1、不显示指定模板实参：**

通常模板参数与调用参数是相关的，这个概念称为：函数模板的实参推演（类型自推），可以像普通函数那样调用函数模板。

    template <typename T>
	T const& Max(T const& a, T const& b)
	{
	    return a > b ? a : b;
	}
	...
	cout << Max(4, 5) << endl;	//用int来实例化T

**2、显式指定模板实参：**

有些特殊情况，比如不能由调用参数来决定模板参数时，在调用时必须显示指定模板实参。

    template <typename T1,typename T2,typename RT>
	RT const& Max1(T1 const& a, T2 const& b)；

模板参数的推演并不适合返回值类型,然而RT并没有出现在调用参数的类型里面，函数调用并不能推演出RT，因此，必须显示的指定模板实参列表。

    template <typename T1,typename T2,typename RT>
	RT const& Max1(T1 const& a, T2 const& b)
	{
	    return a > b ? a : b;
	}
	...
	cout << Max1<int ,int,int>(4, 5) << endl;

**3、只显示指定第一个模板实参：**

这种情况仅适用于第一个模板参数作为函数返回值。

    template <typename RT,typename T1, typename T2>
	RT const& Max1(T1 const& a, T2 const& b)
	{
	    return a > b ? a : b;
	}
	...
	cout << Max1<int>(4, 5) << endl;

## 4、重载函数模板： ##

**和普通函数一样，函数模板也可以被重载。对于非模板函数和同名的函数模板，如果其他条件都相同，那么再调用的时候，重载解析过程通常会调用非模板函数。**

**值得注意的是，模板不允许自动类型转换，但普通函数可以进行自动类型转换。**

    template <typename T>
	T const& Max(T const& a, T const& b)
	{
	    cout << "template:" << (a > b ? a : b);
	    return a > b ? a : b;
	}
	
	int const& Max(int const& a, int const& b)
	{
	    cout<<"void:"<< (a > b ? a : b);
	    return (a > b ? a : b);
	}
	int main()
	{
	    int a1 = 3, b1 = 4;
	    Max(a1, b1) ;	//调用普通函数
	
	    char a2 = '1', b2 = '2';
	    Max(a2, b2) ;	//调用模板函数
	
	    double a3 = 3.123, b3 = 3.124;
	    Max(a3, b3);	//调用模板函数
	
	    string a4 = "asd", b4 = "asx";
	    Max(a4, b4);	//调用模板函数
		   
		Max('a', 4);//调用普通函数（自动类型转换）
	    return 0;
	}

	输出：
	void:4
	template:2
	template:3.124
	template:asx
	void:97
	请按任意键继续. . .
# 三、类模板： #

## 1、定义类模板： ##

**类模板的定义和函数模板是相似的**

用标准库模板vector实现类模板Stack<>

    template <typename T>
	class Stack
	{
	private:
	    vector<T> elems;    //存储元素的容器
	
	public:
	    void push(T const& val)    //入栈
	    {
	        elems.push_back(val);
	    }
	
	    void pop()     //出栈
	    {
	        if (elems.empty())
	        {
	            throw - 1;
	        }
	
	        elems.pop_back();
	    }
	
	    T top()const  //返回栈顶元素
	    {
	        if (elems.empty())
	        {
	            throw - 1;
	        }
	            
	        return elems.back();
	        
	    }
	
	    bool empty()const  //判空
	    {
	        return elems.empty();
	    }
	};

通过上述代码可知，这个类的**类型是Stack<T>,其中T是模板参数，当在声明中需要使用该类的类型时，必须使用Stack<T>。**

**如果定义模板的成员函数在类外，则必须指定该成员函数是一个函数模板，而且还需要用这个类模板的完整类型限定符**。比如上述代码中的push函数在类外实现如下：

    template <typename T>
	void Stack<T>::push(T const& val)    //入栈
	{
	    elems.push_back(val);
	}
## 2、使用类模板： ##

**为了使用类模板对象，必须显示的指定模板实参。**

    int main()
	{
	    Stack<int> St;
	
	    for (int i = 0; i < 5; i++)
	    {      
	        St.push(i);		//入栈
	    }
	   
	    while (!St.empty())		//判空
	    {
	        cout << St.top() << endl;		//栈顶
	        St.pop();		//出栈
	    }
	
	    return 0;
	}

以上述代码为例，对于**所有调用的成员函数，都会实例化出基于int类型的函数代码**（只是被调用了的）。另外一方面，**如果类模板中含有静态成员，那么用来实例化的每种类型，都会实例化这些静态成员**。

**1、给定大小的用发：**

    int main()
	{	    	
	    Stack<int> St[10];	//存除十个整形数据的栈

	    return 0;
	}

**2、重命名：**

    typedef Stack<int>  int_Satck;	//Stack<int> 与 int_Satck 等价；

    Stack<int> St1;	//ok
    int_Satck St2;	//ok

**3、模板套用：**

    Stack< Stack<int> > St;
## 3、类模板的特化： ##
**1、全特化：**

1、为了特化一个类模板，首先在起始处声明一个template<>,然后声明名来特化类的类型。这个类型被用作模板实参，且必须在类名的后面直接指定：

    template <>
	class Stack<string>
	{
		...
	}
2、进行类模板的特化时，每个成员函数都必须重新定义为普通函数，原来模板函数中的每一个T也相应地被进行特化的类型取代：

    void Stack<string>::push(string const& val)    //入栈
	{
	    cout << "void Stack<string>::push(string const& val)" << endl;	//测试如果用string来实例化对象，看调用的是不是特化后的类模板方法。
	    elems.push_back(val);
	}

	测试：
	Stack<string> S;
    S.push("1");

	输出：
	void Stack<string>::push(string const& val)
	请按任意键继续. . .
**2、局部特化：在特定的环境下指定类模板的特定实现，并要求某些模板参数必须由用户来定义**。

    //类模板
	template <typename T1,typename T2>
	class MyClass
	{
	    ...
	};
	//局部特化1：两个模板参数类型相同
	template <typename T>
	class MyClass<T,T>
	{
		...
	};
	
	//局部特化2：第二个模板参数类型为int
	template <typename T>
	class MyClass<T,int>
	{
		...
	};
	//局部特化3：两个模板参数都是指针类型
	template <typename T1, typename T2>
	class MyClass<*T1, *T2>
	{
		...
	};

想要了解更多有关模板的知识，详见 《C++ Template The Complete Guide》。
