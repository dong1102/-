#include<iostream>
#include<string>
using namespace std;

/*
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"
*/

string countAndSay(int n) 
{
        string s = "1";
        int tmp = 1;
        string s1 ;
        string s2;

        while(n > 1)//报数次数
        {         
            int i = 0;//指针
            while(i < s.size())//报数
            {
                while((i < s.size() - 1) && s[i] == s[i+1])//判断相同项（如11）
                {
                    tmp += 1;
                    i++;
                }
		s2 = '0' + tmp;
                s1 += s2 + s[i];
                tmp = 1;
                i++;
            }
            s = s1;
	    s1 = "";
            n--;
        
        }
        
        return s;
}

int main()
{
	int i;
	cout << "请输入："<< endl;
	cin >> i;
	cout << countAndSay(i) << endl; 

	return 0;
}
