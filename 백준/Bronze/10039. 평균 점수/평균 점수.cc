#include <iostream>

using namespace std;

int sum = 0;

int main()
{
    for(int i = 0; i < 5; i++){
        int score;
        cin >> score;
        if(score < 40){
            sum += 40;
        }
        else{
            sum += score;
        }
    }
    
    cout << sum/5;
    
    return 0;
}