#include<iostream>
#include<cstring>
using namespace std;

const int N = 100;
const int x1[4] = {0, 0, 1, 1};
const int x2[4] = {0, 1, 0, 1};
const int y[4] = {0, 1, 1, 1};

int F(float n);

int main()
{
	float w1 = 0.2;
	float w2 = 0.4;
	float theta = 0.3;
	float epsilon = 0.4;
	int flag = 0;
	for(int i = 0; i < 10; i++){
		int res = F(w1*x1[i%4] + w2*x2[i%4] - theta);
		if(res == y[i%4]){
			flag++;
			if(flag == 4){
				break;
			}
		}else{
			theta = theta + epsilon*(y[i%4] - res)*(-1);
			w1 = w1 + epsilon*(y[i%4] - res)*x1[i%4];
			w2 = w2 + epsilon*(y[i%4] - res)*x2[i%4];
			flag = 0;
		}
	}
	int x,y;
	cout<<"please enter x and y :"<<endl;
	while(cin>>x && cin>>y){
		cout<<(F(w1*x + w2*y - theta))<<endl<<endl;
	} 
	return 0;
}

int F(float n){
	return (n >= 0? 1 : 0);
}

