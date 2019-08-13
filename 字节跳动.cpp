#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
��֪ÿ����Ϣ��������ɶ�������B�����ģ����䳤��Ϊn��Ȼ�����Ϣ����k�Σ�ÿ�������ƶ�0��1��...��k - 1λ��
���磺B = 1001010��k = 4;
1001010
 1001010
  1001010
   1001010
Ȼ���ÿһ�н��������������Ұ��������õĽ����¼���������ǽ�������ΪS(����)��
�����������ӵĽ��Ϊ��1110100110
��󣬽��������Ϣs��k�����Է���
���ܹ����Ѿ�ʵ���ˣ�Ҫ����д�����ܹ��̵ĳ���

���룺
��һ��������������n��k��
�ڶ�������һ���������ַ�����s��������n+k-1��

�����
�������B 
*/


//�����ַ�����Ϊs�����ܺ���ַ�����Ϊstr
string Decode(int n,int k, string s)
{
	string str;
	int q = 0;//s���±�
	str += s[q];//s�ĵ�һ��Ԫ�ؾ���str�ĵ�һ��Ԫ��
	q++;
	int x;//�м����ֵ
	

	for (int i = 0; i < n - 1; i++)
	{
		int len = str.size();//str�ĳ��ȣ����ܵ�����һֱ���ӣ�str�ĳ��Ⱦ�һֱ����
		if (len < k)//str�ĳ���С�����ش������ͷ���ÿ�δ�str��һ��Ԫ�ؿ�ʼ���Ĺ���
		{
			x = str[0] - '0';
			x ^= (s[q] - '0');
			for (int j = 1; j < len; j++)
			{
				x ^= (str[j] - '0');			
			}
			
			str += x + '0';
		}
		else//str�ĳ��ȴ������ش������ͷ���ÿ�δ�str���һ��Ԫ�ؿ�ʼ���Ĺ���
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