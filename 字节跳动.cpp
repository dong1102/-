#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
已知每条信息都被编译成二级制数B（明文），其长度为n，然后该信息被下k次，每次向右移动0、1、...、k - 1位。
例如：B = 1001010，k = 4;
1001010
 1001010
  1001010
   1001010
然后对每一列进行异或操作，并且把最终所得的结果记录下来，我们将次数称为S(密文)。
例如上述例子的结果为：1110100110
最后，将编码的信息s和k发给对方。
加密过程已经实现了，要求你写出解密过程的程序。

输入：
第一行输入两个整数n和k；
第二行输入一个二进制字符串是s，长度是n+k-1；

输出：
输出明文B 
*/


//加密字符串称为s，解密后的字符串称为str
string Decode(int n,int k, string s)
{
	string str;
	int q = 0;//s的下标
	str += s[q];//s的第一个元素就是str的第一个元素
	q++;
	int x;//中间过渡值
	

	for (int i = 0; i < n - 1; i++)
	{
		int len = str.size();//str的长度，解密的内容一直增加，str的长度就一直增加
		if (len < k)//str的长度小于下载次数，就符合每次从str第一个元素开始异或的规律
		{
			x = str[0] - '0';
			x ^= (s[q] - '0');
			for (int j = 1; j < len; j++)
			{
				x ^= (str[j] - '0');			
			}
			
			str += x + '0';
		}
		else//str的长度大于下载次数，就符合每次从str最后一个元素开始异或的规律
		{
			int z = len - 1;
			int y = k - 2;
			x = str[z] - '0';
			x ^= (s[q] - '0');

			while (y)
			{
				x ^= (str[--z] - '0');
				y--;
			}

			str += x + '0';
		}
		q++;
		
	}	
	return str;
	
}

int main()
{
	int n, k;
	cin >> n;
	cin >> k;
	string s;
	cin >> s;
	if (k > 1)
	{
		cout << Decode(n, k, s) << endl;
	}
	else
		cout << s << endl;
}
#if 0
#endif