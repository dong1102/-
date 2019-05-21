## BF算法： ##

时间复杂度为：O(m*n)。

    #include<iostream>
	#include<string>
	using namespace std;
	
	int BF(const string& S,const string& T,int pos)
	{
	    int len_s = S.size();
	    int len_t = T.size();
	    int i = pos;	//主串的位置
	    int j = 0;	//子串的位置
	
	    while (i < len_s && j < len_t)
	    {
	        if (S[i] == T[j])	//匹配
	        {
	            i++;
	            j++;
	        }
	        else	//失配
	        {
	            j = 0;	//j归0
	            i = i - j + 1;	//i回退
	        }
	    }
	    if (j >= len_t)	//子串完成匹配，则找到
	    {
	        return i - j;
	    }
	    else
	    {
	        return -1;
	    }
	}
	
	int main()
	{
	    string S;
	    string T;
	    int pos;
	    cin >> S;
	    cin >> T;
	    cin >> pos;
	    cout << BF(S,T,pos) << endl;
	
	    return 0;
	}
## KMP算法： ##
时间复杂度为：O(m+n)。
    
	//获取next数组函数
	static int *Git_nextval(const string& T)
	{
	    int len = T.size();
	    int *next = new int[len]; //j初次回退后的位置k的数组
	    int *nextval = new int[len]; //j最终的回退位置k的数组
	    next[0] = -1;//初始化0和1
	    next[1] = 0;
	
	    int j = 0;
	    int k = -1;
	    while (j < len-1)
	    {
	        if (k == -1 || T[k] == T[j])	//next[j+1] == k+1
	        {
	            next[++j] = ++k;
	        }
	        else
	        {
	            k = next[k];	//k继续回溯前缀（此时的k就相当第一次失配时的**j**），相当于重复k = next[j]的过程。
	        }
	    }
	
	    nextval[0] = -1;//初始化第一个元素
	    for (int i = 1; i < len; i++)
	    {
	        if (T[i] == T[next[i]])		//T[i] == T[k]，这样导致回退后的位置k不是j的最终回退位置。
	        {
	            nextval[i] = nextval[next[i]];	//一次性回退到位
	        }
	        else	//T[i] != T[k]
	        {
	            nextval[i] = next[i];	//说明k已回退到位
	        }
	    }
	    delete[]next;
	    return nextval;
	}
	
	int KMP(const string& S,const string& T,int pos)//和BF算法基本一样
	{
	    int len_s = S.size();
	    int len_t = T.size();
	    int *nextval = Git_nextval(T);
	
	    int i = pos;
	    int j = 0;
	    while (i < len_s && j < len_t)
	    {
	        if (j == -1 || S[i] == T[j])
	        {
	            i++;
	            j++;
	        }
	        else
	        {
	            j = nextval[j];
	        }
	    }
	    delete[]nextval;
	    if (j == len_t)
	    {
	        return i - j;
	    }
	    else
	    {
	        return -1;
	    }
	}
	
	int main()
	{
	    string S;
	    string T;
	    int pos;
	    cin >> S;
	    cin >> T;
	    cin >> pos;
	    cout << KMP(S, T, pos) << endl;
	
	    return 0;
	}

详细分析过程CSDN：https://mp.csdn.net/mdeditor/90321710