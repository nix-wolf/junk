#include <stdio.h>

main(){
int x,y,z,n,i;

n=3;
x = y = z = 0;

printf("%d\n", n);

for(i=0;i<=n;++i){	
	if((x+y+z)==n)
		printf("%d %d %d\n",x,y,z);		

	x = i;	
	y = i+1;
	z = y+1;
	
	if(y==n)
		y=0;

	if(z != (n-x-y))
		z=n-x-y;
	     


	
}
}
