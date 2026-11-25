#include <stdio.h>
#define main sdes_cbc_demo_main
#include "22_SDES_CBC.c"
#undef main
int main(void){
    int key,counter,n,i,p,stream,c;
    printf("Enter 10-bit S-DES key (0-1023): ");
    if(scanf("%d",&key)!=1||key<0||key>1023)return puts("Invalid key."),1;
    printf("Starting 8-bit counter (0-255): ");
    if(scanf("%d",&counter)!=1||counter<0||counter>255)return puts("Invalid counter."),1;
    printf("Number of bytes (1-100): ");
    if(scanf("%d",&n)!=1||n<1||n>100)return puts("Invalid length."),1;
    for(i=0;i<n;i++){
        printf("Plaintext byte %d (0-255): ",i+1);
        if(scanf("%d",&p)!=1||p<0||p>255)return puts("Invalid byte."),1;
        stream=enc((counter+i)&255,key);
        c=p^stream;
        printf("Counter %d keystream=%02X ciphertext=%02X\n",(counter+i)&255,stream,c);
    }
    puts("CTR decryption uses the same keystream and XOR operation.");
    return 0;
}