#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power(int m,int n){
    int ans=1;
    while(n>0){
        ans=ans*m;
        n--;
    }
    return ans;
}
void add(int base,int x,int y){
	int  bit,carr=0,ans=0,a1=0,b1=0,count=0;
	int bita=1,bitb=1,j=0;
	while(x!=0){
		a1=a1+((x%10)*power(base,j));
		x=x/10;
		j++;
	}
	j=0;
	while(y!=0){
		b1=b1+((y%10)*power(base,j));
		y=y/10;
		j++;
	}
	for(int i=2;i<a1;i=i*2){
		bita++;
	}
	for(int i=2;i<b1;i=i*2){
		bitb++;
	}
	if(bita>bitb)
		bit=bita+1;
	else
		bit=bitb+1;
	int a[bit],b[bit];
	for(int i=0;i<bit;i++){
		a[i]=a1%2;
		b[i]=b1%2;
		a1=a1/2;
		b1=b1/2;
	}
	for(int i=0;i<bit;i++){
		ans=ans+((a[i]^b[i]^carr)*power(2,i));
		carr=(a[i]&b[i])|(carr&(a[i]^b[i]));
	}
	printf("%d\n",ans);
	int temp=ans;
	while(temp>0){
		temp=temp/base;
		count++;
	}
	int val[count];
	for(int i=0;ans>0;i++){
		val[i]=ans%base;
		ans=ans/base;
	}	
	for(int i=0;i<count;i++)
		printf("%d",val[(count-1)-i]);
}

int main(){
    int a=1010,b=10100;
    int base=2;
	add(base,a,b);
}
