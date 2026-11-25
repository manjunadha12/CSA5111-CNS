#include <stdio.h>
#include <stdint.h>
#include <string.h>
/* Educational CBC structure using a reversible 64-bit XOR block primitive.
   Replace block_enc with a vetted 3DES library for real security. */
uint64_t block_enc(uint64_t x,uint64_t k){return x^k;}
int main(void){uint64_t iv,k,p[20],c,prev;int n,i;printf("Enter 64-bit key (hex): ");scanf("%llx",(unsigned long long*)&k);printf("Enter 64-bit IV (hex): ");scanf("%llx",(unsigned long long*)&iv);printf("Number of 64-bit plaintext blocks (1-20): ");scanf("%d",&n);if(n<1||n>20)return puts("Invalid block count."),1;prev=iv;for(i=0;i<n;i++){printf("Block %d (hex): ",i+1);scanf("%llx",(unsigned long long*)&p[i]);c=block_enc(p[i]^prev,k);printf("Cipher block %d: %016llX\n",i+1,(unsigned long long)c);prev=c;}puts("Demo only: XOR is not 3DES and provides no cryptographic security.");return 0;}