// Given an array of strings, return all groups of strings that are anagrams.
// Note: All inputs will be in lower-case.

/* 
**解法：
**（1）建立一个multimap，遍历所有单词，当取得一个单词时，将它排序后，以排序后的字符串为键，排序前的字符串为值插入到multimap中，同时将键保存在set中。
**（2）遍历键的集合set，当取一个键时，计算它在multimap出现的次数，如果次数小于等于1（当然，次数不可能小于1），说明只有一个单词对应该键，就什么也不干，如果次数大于1，就获得这个键在multimap中的起始和结束位置，将值插入到结果vector中。
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
using namespace std;
#define WORDMAX 100  //数组最大值上限
FILE *fp,*fp1;       //文件指针
char word[WORDMAX],sig[WORDMAX],oldsig[WORDMAX];//单词数组，签名数组，以前签名数组
char word1[WORDMAX],sig1[WORDMAX],word2[WORDMAX],sig2[WORDMAX]; //sort函数中所用的中转数组
 
//qsort函数所用确定顺序的函数
int charcomp(const void *x,const void *y){return *(int*)x-*(int*)y; }
 
//************************************************************************
void sign(){  //签名函数
    fp1=fopen("aftertipdictory.txt","w");//将签名后结果写入文件，用于sort函数输入
    if((fp=fopen("dictory.txt","r"))==NULL)//单词源文件
        exit(1);
    while(fscanf(fp,"%s",word)!=EOF){
        //printf("%s  \n",word);
        for(int i=0;i<strlen(word);i++)
        {
         word[i]=tolower(word[i]);  //对输入内容进行小写字母化处理
        }
        strcpy(sig,word);
        qsort(sig,strlen(sig),sizeof(char),charcomp);//生成签名
        //printf("%s %s \n",sig,word);
        fprintf(fp1,"%s %s \n",sig,word);
    }
    fclose(fp1);
    if(fclose(fp)!=0)
         exit(1);
}
//***********************************************************************
//这是对签名后的文件内容进行排序的程序，据说linux有现成的系统排序。
void SortTheDictionary()  
{  
     
    cout<<"正在对签名文件进行排序！！";  
    //实现签名的排序 并生成新文件  
    char *temp = "aftertipdictory.txt";  
    ofstream outfile("aftersort.txt",ios::out);  
    assert(outfile);  
    while (true)  
    {  
        ifstream tmp1(temp,ios::in);  
        //因为要删除上一个旧文件，需要清空  
        ofstream tmp2("temp2.txt",ios::out);  
        assert(tmp1);  
        assert(tmp2);  
        //find the smallest one in the current text  
        if(! (tmp1>>sig>>word))  break;  
        while (tmp1>>sig1>>word1)  
        {  
            //将当前文件中最小的签名提取出到最终文件，其他放到临时文件中  
            if (strcmp(sig1,sig) > 0)  
            {  
                tmp2<<sig1<<'\t'<<'\t'<<word1<<endl;  
            }  
            else 
            {  
                strcpy(sig2,sig);  
                strcpy(word2,word);  
                strcpy(sig,sig1);  
                strcpy(word,word1);  
                tmp2<<sig2<<'\t'<<'\t'<<word2<<endl;  
            }  
   
        }  
        outfile.seekp(0,ios::end);  
        outfile<<sig<<'\t'<<'\t'<<word<<endl;  
        tmp1.close();  
        tmp2.close();  
        //copy剩下未排序的元素  
        //temp2 -> temp1  
        ifstream f2("temp2.txt",ios::in);  
        ofstream f1("temp1.txt",ios::out);  
        //assert(f1);  
        //assert(f2);  
        f2.seekg(0);  
        while (f2>>sig>>word)  
        {  
            f1<<sig<<'\t'<<'\t'<<word<<endl;  
        }  
        f1.close();  
        f2.close();  
        //更改下次排序原文件  
        temp = "temp1.txt";  
    }  
    outfile.close();  
    cout<<endl<<"排序完毕"<<endl;  
}  
///********************************************************
//这是对排序后文件进行挤压处理，并输出最终结果的函数
void squash(){
    int linenum = 0;
    strcpy(oldsig, " ");
    if((fp=fopen("aftersort.txt","r"))==NULL)//打开排序后文件
        exit(1);
    while(fscanf(fp,"%s %s",sig,word)!=EOF) 
    {
        if (strcmp(oldsig, sig) != 0 && linenum > 0)//如若当前单词签名与上一个单词签名不一样，换行输出
            printf("\n");
        strcpy(oldsig, sig);
        linenum++;
        printf("%s ", word);
        //printf("\n");
    }
    printf("\n");
    if(fclose(fp)!=0)
         exit(1);
}
//再加两句可以把结果输出到文件中，还有前两个函数中对于打开文件使用权限要注意，如果没有文件，要可以自动生成
//**********************************************************
int main()
  {
    sign();
    cout<<"sign完毕"<<endl;
    SortTheDictionary(); 
    cout<<"开始变位词显示"<<endl;
    squash();
    return 0;
  }

class Solution {  
public:  
    vector<string> anagrams(vector<string> &strs) {  
        // IMPORTANT: Please reset any member data you declared, as  
        // the same Solution instance will be reused for each test case.  
        if(strs.size() <= 1)  
            return vector<string>();  
          
        multimap<string, string> records;  
        set<string> sset;  
        string tmp;  
  
        for(vector<string>::iterator iter = strs.begin();  
                                     iter != strs.end(); ++iter) {  
            tmp = *iter;  
            sort(tmp.begin(), tmp.end());  
            records.insert(make_pair(tmp, *iter));  
            sset.insert(tmp);  
        }  
  
        vector<string> svec;  
        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> loc;  
        for(set<string>::iterator iter = sset.begin();  
                                  iter != sset.end(); ++iter) {  
            if(records.count(*iter) > 1) {  
                loc = records.equal_range(*iter);  
                for(multimap<string, string>::iterator iter = loc.first;  
                                                       iter != loc.second; ++iter) {  
                    svec.push_back((*iter).second);                                             
                }  
            }  
        }  
  
        return svec;  
    }  
};
