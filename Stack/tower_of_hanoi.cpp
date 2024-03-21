#include<iostream>
using namespace std;
void hanoi(int n,char beg,char aux,char end){
	if(n==1){
		cout<<"Move disc from "<<beg<<" to "<<end<<"\n";
	}
	else{
		hanoi(n-1,beg,end,aux);
		hanoi(1,beg,aux,end);
		hanoi(n-1,aux,beg,end);
	}
}
int main(){
    // cout<<"Name : Manish Choudhary\nURN : 2203495\n\n";
    // cout<<"Name: Karamveer Kaur\nURN: 2203479\n\n";
    // cout<<"Name: Jaspreet Singh\nURN: 2203473\n\n";
    cout<<"Name: Karan Kashyap\nURN: 2203481\n\n";
	int num;
	cout<<"enter the number of discs: ";
	cin>>num;
	hanoi(num,'A','B','C');
}