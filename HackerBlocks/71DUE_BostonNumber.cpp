#include<bits/stdc++.h>

using namespace std;

int main(){

    int x;
    cin>>x;

    int sumOfPrimefactors = 0;
    int temp = x;
    while(temp%2 == 0){
        sumOfPrimefactors += 2;
        temp /= 2;
        // cout<<sumOfPrimefactors<<"-sumOfPrimefactors"<<endl;
    }
    for(int i=3; i<=sqrt(x); i= i+2){
        // cout<<i<<"-i"<<endl;
        while (temp%i == 0) {
            sumOfPrimefactors += i;
            temp /= i;
            // cout<<sumOfPrimefactors<<"-sumOfPrimefactors"<<endl;
        }
    }

    int sumOfDigits = 0;
    temp = x;
    for(temp; temp>0; temp = temp/10){
        sumOfDigits = sumOfDigits + temp%10;
        // cout<<sumOfDigits<<"-sumOfDigits"<<endl;
    }

    if(sumOfDigits == sumOfPrimefactors){
        cout<<1;
    }else{
        cout<<0;
    }


    return 0;
}
