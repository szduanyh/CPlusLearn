#include<iostream>
#include"Queue.h"

using namespace std;

int main(){

	CQueue<int> qu;

	int i = 0;
	int d;

	/*while (i++ < 10)
	{
		qu.push(i);
	}*/

	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.pop(d);
	qu.pop(d);
	qu.push(4);
	qu.push(5);
	qu.push(6);
	qu.push(7);
	qu.push(8);

	
	while (qu.pop(d))
	{
		cout << d << endl;
	}

	return 0;
}