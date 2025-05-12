#include <iostream>

int alpha[26], cnt = 0;
std::string input;

int main()
{
    std::cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        if(input[i] >= 97){
            alpha[input[i]-97]++;
        }
        else{
            alpha[input[i]-65]++;
        }
    }
    int max = 0, max_index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > max)
        {
            max = alpha[i];
            max_index = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max == alpha[i])
        {
            cnt++;
        }
        
    }

    cnt > 1 ? std::cout << "?" : std::cout << (char)(max_index+65);
}