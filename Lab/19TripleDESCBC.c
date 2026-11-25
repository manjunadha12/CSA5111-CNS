#include <stdio.h>
#include <stdint.h>
#define main des_demo_main
#include "33_DES_Block_Cipher.c"
#undef main
static uint64_t triple_des_encrypt(uint64_t x,uint64_t k1,uint64_t k2,uint64_t k3){
    x=des(x,k1,0); x=des(x,k2,1); return des(x,k3,0);
}
int main(void){
    unsigned long long a,b,c,iv,block,out,prev; int n,i;
    printf("Enter three 64-bit DES keys K1 K2 K3 (hex): ");
    if(scanf("%llx%llx%llx",&a,&b,&c)!=3)return 1;
    printf("Enter 64-bit IV (hex): "); if(scanf("%llx",&iv)!=1)return 1;
    printf("Number of 64-bit plaintext blocks (1-100): ");
    if(scanf("%d",&n)!=1||n<1||n>100)return puts("Invalid block count."),1;
    prev=iv;
    for(i=0;i<n;i++){
        printf("Plaintext block %d (hex): ",i+1);
        if(scanf("%llx",&block)!=1)return 1;
        out=triple_des_encrypt(((uint64_t)block)^((uint64_t)prev),a,b,c);
        printf("Ciphertext block %d: %016llX\n",i+1,out);
        prev=out;
    }
    puts("CBC with 3DES EDE (educational legacy algorithm; use AES-GCM for new systems).");
    return 0;
}