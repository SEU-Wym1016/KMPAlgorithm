// KMP.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
class String
{
public:
    char *str;
    int len;
    int *f; 
    String(const char *s=nullptr)
    {
        if (s==nullptr)
        {
            str=nullptr;
            len=0;
            f=nullptr;
        }
        else
        {
            len=strlen(s);
            str=new char[len+1];
            strcpy(str,s);
            f=new int[len];
        }
    }
    ~String()
    {
        delete[] str;
        delete[] f;
    }
	void failure()
	{
		if(len==0)
        return;
		f[0]=0;
		for(int i=1;i<len;i++)
		{
			int k=f[i-1];
			while(k>0&&str[i]!=str[k])
			{
				k=f[k-1];
			}
			if(str[i]==str[k])
            {
                k++;
            }
			f[i]=k;
		}
	}
	int KMPfind(String &pat)
	{
		pat.failure();
		int i=0,j=0;
		int patLen=pat.len;
		while(i<len&&j<patLen)
		{
			if(str[i]==pat.str[j])
			{
				i++;
				j++;
			}
            else
			{
				if(j == 0)
					i++; 
				else
					j = pat.f[j-1];
			}
		}
		if(j==patLen)
		return i-patLen;
		return -1;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	String test1("mydickisbig");
	String find1("dick");
	cout<<test1.KMPfind(find1);
	system("pause");
	return 0;
}
