/*dn = pn+1 - pn,pn,为第i个素数，dn为2
*输入N
*输出不超过N的满足猜想的素数对的个数
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int isPrime(int n){
	if(n == 2 | n ==3)
		return 1;
	double tmp = sqrt(n)+1;
	for(int i = 2; i < tmp; ++i)
		if(n%i == 0)
			return 0;
	return 1;
}

int main(){
	int N;
	scanf("%d",&N);
	int count = 0;
	if(N==2){
		printf("0");
		return 0;
	}
	for(int i = 2; i != N-1;++i)
		if(isPrime(i)&&isPrime(i+2))
			++count;
	printf("%d",count);
	
}
