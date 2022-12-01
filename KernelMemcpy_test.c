#include <stdio.h>
#include <stdlin.h>
#include <unistd.h>
#include <sys/syscall.h>

#define _GNU_SOURCE
#define SYS_kern_2D_memcpy 451

int main(){
    float inp[4][3] = {{1.0,1.5,2.5},{3.0,2.2,1.7},{4.2,3.8,1.6},{2.7,1.8,2.4}};
    float out[4][3];
    printf("Initially the original matrixis:\n");
    for(int i =0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("%f ",inp[i][j]);
        }
        printf("\n");
    }
    printf("System calling:\n ");
    int ans = syscall(SYS_kern_2D_memcpy,inp,out,4,3);
    printf("Final copied Matrix is:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("%f ",out[i][j]);
        }
        printf("\n");
    }
    return ans;
}
