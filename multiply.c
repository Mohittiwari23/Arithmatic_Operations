#include<stdio.h>
void multiply(int base,int bita,int bitb,int *arr_a,int *arr_b){
    int bit;
    if(bita>=bitb)
        bit=bita+1;
    else
        bit=bitb+1;
    int M[bit],Q[bit],ans[2*bit];
    for(int i=0;i<bit;i++){
        M[i]=*(arr_a+i);
        Q[i]=*(arr_b+i);
    }
    if(bita>bitb){
        M[bita]=0;
        for(int i=bitb;i<bit;i++)
            Q[i]=0;
    }
    else{
        Q[bitb]=0;
        for(int i=bita;i<bit;i++)
            M[i]=0;
    }

    int A[bit],Q_1=0,counter=bit,M_1[bit];
    for(int i=0;i<bit;i++){
        A[i]=0;
    }
    for(int i=0;i<bit;i++){
        M_1[i]=M[i]^1;
    }
    int carr=0;
    M_1[0]=M_1[0]+1;
    for(int i=0;i<bit;i++){
        if(M_1[i]+carr==2){
            M_1[i]=0;
            carr=1;
        }
        else{
            M_1[i]=M_1[i]+carr;
            carr=0;
        }
    }
    carr=0; 
    while(counter>0){
        if(Q[0]==0 && Q_1==1){
            printf("\nA+M\n");
            for(int i=0;i<bit;i++){
                if(A[i]+M[i]+carr!=2){ 
                    A[i]=(A[i]+M[i]+carr)%2;
                    carr=(A[i]+M[i]+carr)/2;
                }
                else{
                    carr=1;
                    A[i]=0;
                }
            }
            Q_1=Q[0];
            for(int i=0;i<bit;i++){
                Q[i]=Q[i+1];
            }
            Q[bit-1]=A[0];
            for(int i=0;i<bit-1;i++){
                A[i]=A[i+1];
            }
            printf("\nq=");
	        for(int i=0;i<bit;i++){
		        printf("%d",Q[(bit-1)-i]);
	        }
            printf("\na=");
	        for(int i=0;i<bit;i++){
		        printf("%d",A[(bit-1)-i]);
	        }
            printf("\nq-1=%d\n",Q_1);

        }
        else if(Q[0]==1 && Q_1==0){
            printf("\nA-M\n");
            for(int i=0;i<bit;i++){
                if(A[i]+M_1[i]+carr!=2){ 
                    A[i]=(A[i]+M_1[i]+carr)%2;
                    carr=(A[i]+M_1[i]+carr)/2;
                }
                else{
                    carr=1;
                    A[i]=0;
                }
            }
            Q_1=Q[0];
            for(int i=0;i<bit;i++){
                Q[i]=Q[i+1];
            }
            Q[bit-1]=A[0];
            for(int i=0;i<bit-1;i++){
                A[i]=A[i+1];
            }
            printf("\nq=");
	        for(int i=0;i<bit;i++){
		        printf("%d",Q[(bit-1)-i]);
	        }
            printf("\na=");
	        for(int i=0;i<bit;i++){
		        printf("%d",A[(bit-1)-i]);
	        }
            printf("\nq-1=%d\n",Q_1);
        }
        else{
            printf("\nasr\n");
            Q_1=Q[0];
            for(int i=0;i<bit;i++){
                Q[i]=Q[i+1];
            }
            Q[bit-1]=A[0];
            for(int i=0;i<bit-1;i++){
                A[i]=A[i+1];
            }
            printf("\nq=");
	        for(int i=0;i<bit;i++){
		        printf("%d",Q[(bit-1)-i]);
	        }
            printf("\na=");
	        for(int i=0;i<bit;i++){
		        printf("%d",A[(bit-1)-i]);
	        }
            printf("\nq-1=%d\n",Q_1);
        }
        counter--;
    }
    for(int i=0;i<bit;i++){
        ans[i]=Q[i];
    }    
    for(int i=0;i<bit;i++){
        ans[bit+i]=A[i];
    }
}

int main(){
    int a=10,b=20;
    int base=10;
	int bita=1,bitb=1;
	for(int i=2;i<a;i=i*2){
		bita++;
	}
	for(int i=2;i<b;i=i*2){
		bitb++;
	}
	int arr_a[bita];
	for(int i=0;a>0;i++){
		arr_a[i]=a%2;
		a=a/2;
	}
	int arr_b[bitb];
	for(int i=0;b>0;i++){
		arr_b[i]=b%2;
		b=b/2;
	}
    multiply(base,bita,bitb,arr_a,arr_b);
}