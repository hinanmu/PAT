#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct student{
    string id;
    int c,m,e,a;
    int bestGrade;
    char bestSub;
}stu[2000];

bool cmpA(student a,student b)
{
    return a.a > b.a;
}

bool cmpC(student a,student b)
{
    return a.c > b.c;
}

bool cmpM(student a,student b)
{
    return a.m > b.m;
}

bool cmpE(student a,student b)
{
    return a.e > b.e;
}

int main()
{
    int n,m;
    string tempId;
    tempId.resize(6);
    scanf("%d%d",&n,&m);
    vector<int> resultRank;
    vector<string> resultSub;

    for(int i = 0;i < n;i++)
    {
        stu[i].id.resize(6);
        scanf("%s%d%d%d",&stu[i].id[0],&stu[i].c,&stu[i].m,&stu[i].e);
        stu[i].a = ( stu[i].c + stu[i].m + stu[i].e ) / 3;
    }

    for(int i = 0;i < m;i++)
    {
        scanf("%s",&tempId[0]);
        int flag = 0;
        int rankA,rankC,rankM,rankE;

        for(int j = 0;j < n;j++)
        {
            if(stu[j].id == tempId)
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            resultRank.push_back(0);
            resultSub.push_back("N/A");
            continue;
        }

        sort(stu,stu + n,cmpA);
        for(int j = 0;j < n;j++)
        {
            if(stu[j].id == tempId)
            {
                rankA = j + 1;
                int k = j;
                while(k >= 0)
                {
                    if(stu[j].a == stu[k].a)
                    {
                        rankA = k + 1;
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }

            }
        }

        sort(stu,stu + n,cmpC);
        for(int j = 0;j < n;j++)
        {
            if(stu[j].id == tempId)
            {
                rankC = j + 1;
                int k = j ;
                while(k >= 0)
                {
                    if(stu[j].c == stu[k].c)
                    {
                        rankC = k + 1;
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        sort(stu,stu + n,cmpM);
        for(int j = 0;j < n;j++)
        {
            if(stu[j].id == tempId)
            {
                rankM = j + 1;
                int k = j;
                while(k >= 0)
                {
                    if(stu[j].m == stu[k].m)
                    {
                        rankM = k + 1;
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        sort(stu,stu + n,cmpE);
        for(int j = 0;j < n;j++)
        {
            if(stu[j].id == tempId)
            {
                rankE = j + 1;
                int k = j;
                while(k >= 0)
                {
                    if(stu[j].e == stu[k].e)
                    {
                        rankE = k + 1;
                        k--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        if(rankA <= rankC && rankA <= rankE && rankA <= rankM)
        {

            resultRank.push_back(rankA);
            resultSub.push_back("A");
        }
        else if(rankC < rankA && rankC <= rankE && rankC <= rankM)
        {
            resultRank.push_back(rankC);
            resultSub.push_back("C");
        }
        else if(rankM < rankA && rankM < rankC && rankM <= rankE)
        {
            resultRank.push_back(rankM);
            resultSub.push_back("M");
        }
        else
        {
            resultRank.push_back(rankE);
            resultSub.push_back("E");
        }
    }

    for(int i = 0;i < m;i++)
    {
        if(resultRank[i] != 0)
        {
            printf("%d %s\n",resultRank[i],resultSub[i].c_str());
        }
        else
        {
            printf("%s\n",resultSub[i].c_str());
        }
    }
    return 0;
}
