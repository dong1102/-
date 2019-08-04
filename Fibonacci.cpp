#include <iostream>
#include <vector>
#include <string>

using namespace std;

//1、青蛙跳台阶，一次可以跳1或者2格，共n阶台阶，问有多少种上台阶的方法？

/*分析：
 * 对于本题前提只有一次跳一阶，和跳两阶。
 * 如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f（n - 1）;
 * 假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n - 2);
 * 那么这个时候就能够得到总的跳法为 f(n) = f(n - 1) + f(n - 2)，
 * 然后这个出口就是:只有一阶的时候f(1) = 1, 只有两阶的时候f(2) = 2;
*/
int FrogJump(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	if(n == 2)
	{
		return 2;
	}

	int j1 = 1;
	int j2 = 2;
	int tmp = 0;
	for(int i = 2; i < n;i++)
	{
		tmp = j1 + j2;
		j1 = j2;
		j2 = tmp;
	}
	return tmp;
}

int main()
{
	int n;
	cin>>n;
	cout <<"青蛙跳上"<<n<<"级台阶可以用"<<FrogJump(n)<<"种方法。"<<endl;
}
#if 0
//斐波拉且数列

class Fibonacci
{
public:
	//递归方法
	int ReFibonacci(int n)
	{
		if(n == 0)
		{
			return 0;
		}
		else if(n == 1)
		{
			return 1;
		}
		else
		{
			return ReFibonacci(n-1) + ReFibonacci(n-2);
		}
	}

	//循环方法
	int LoFibonacci(int n)
	{
		if(n == 0)
		{
			return 0;
		}
		if(n == 1)
		{
			return 1;
		}

		int lf0 = 0;
		int lf1 = 1;
		int tmp = 0;
		for(int i = 1; i < n; i++)
		{
			tmp = lf0 + lf1;
			lf0 = lf1;
			lf1 = tmp;
		}
		return tmp;
	}
};

int main()
{
	int n;
	cin>>n;
	Fibonacci F;
	cout <<"递归:"<<F.ReFibonacci(n) << endl;
	cout << "非递归：" << F.LoFibonacci(n) << endl;

	return 0;
}
#endif
