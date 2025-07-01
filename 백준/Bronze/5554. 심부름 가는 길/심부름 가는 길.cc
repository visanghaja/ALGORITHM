#include <iostream>
using namespace std;

int main() {
    int tmp, sum = 0;
    for(int i=0; i<4; i++) {
        cin>>tmp;
        sum += tmp;
    }
    cout<<sum/60<<endl;
    cout<<sum%60<<endl;
    return 0;
}