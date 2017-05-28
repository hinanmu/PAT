#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main()
{
    char input[101];
    scanf("%s",input);

    int length = strlen(input);
    int sum = 0;
    for(int i = 0;i < length;i++)
    {
        sum += input[i] - 48;
    }

    if(sum == 0)
    {
        printf("%s","zero");
    }
    vector<st
    while(sum / 1 != 0)
    {
        int temp = sum % 10;
        sum = sum / 10;

        switch(temp)
        {ring> output;

        case 0:
            output.push_back("zero");
            break;
        case 1:
            output.push_back("one");
            break;
        case 2:
            output.push_back("two");
            break;
        case 3:
            output.push_back("three");
            break;
        case 4:
            output.push_back("four");
            break;
        case 5:
            output.push_back("five");
            break;
        case 6:
            output.push_back("six");
            break;
        case 7:
            output.push_back("seven");
            break;
        case 8:
            output.push_back("eight");
            break;
        case 9:
            output.push_back("nine");
            break;
        }
    }

    for(int i = output.size() - 1;i >= 0;i--)
    {
        if(i == 0)
        {
            printf("%s",output[i].c_str());
        }
        else
        {
            printf("%s ",output[i].c_str());
        }

    }
    return 0;
}
