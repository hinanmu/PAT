#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int recordsNum;
    scanf("%d",&recordsNum);
    vector<string> id;
    string temp;
    temp.resize(15);
    char idChar[15];

    int beginHour = 24;
    int beginMin = 0;
    int beginSec = 0;
    int endHour = 0;
    int endMin = 0;
    int endSec = 0;

    int tempHour = 0;
    int tempMin = 0;
    int tempSec = 0;

    int unlock;
    int lock;

    for(int i = 0;i < recordsNum;i++)
    {
        scanf("%s",idChar);
        temp = idChar;
        //puts(temp.c_str());

        id.push_back(temp);

        scanf("%d:%d:%d",&tempHour,&tempMin,&tempSec);
        if(tempHour <= beginHour)
        {
            if(tempHour == beginHour)
            {
                if(tempMin <= beginMin)
                {
                    if(tempMin == beginMin)
                    {
                        if(tempSec < beginSec)
                        {
                            beginSec = tempSec;

                            unlock = i;
                        }
                    }
                    else
                    {
                        beginMin = tempMin;
                        beginSec = tempSec;

                        unlock = i;
                    }
                }
            }
            else
            {
                beginHour = tempHour;
                beginMin = tempMin;
                beginSec = tempSec;

                unlock = i;
            }

        }
        scanf("%d:%d:%d",&tempHour,&tempMin,&tempSec);
        if(tempHour >= endHour)
        {
            if(tempHour == endHour)
            {
                if(tempMin >= endMin)
                {
                    if(tempMin == endMin)
                    {
                        if(tempSec > endSec)
                        {
                            endSec = tempSec;

                            lock = i;
                        }
                    }
                    else
                    {
                        endMin = tempMin;
                        endSec = tempSec;

                        lock = i;
                    }
                }
            }
            else
            {
                endHour = tempHour;
                endMin = tempMin;
                endSec = tempSec;

                lock = i;
            }

        }
    }


    cout <<id[unlock]<<" "<<id[lock];
    return 0;
}
