//
//  main.c
//  2048playmode
//
//  Created by Joyce Chin on 2017/12/18.
//  Copyright © 2017年 Joyce Chin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    int flag=0;
    int matrix[10][10]={0};
    char x;
    scanf("%d",&n);
    while(n--){
        for(i=1;i<5;i++){
            for(j=1;j<5;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        scanf(" %c",&x);
        ////////////////////////////////////////////////////////////////////
        if(x=='a'){
            for(i=1;i<5;i++){
                for(j=3;j>=1;j--){
                    if(matrix[i][j]==0){
                        k=j;
                        while(k+1<=4){
                            matrix[i][k]=matrix[i][k+1];
                            k++;
                        }
                        matrix[i][4]=0;
                    }
                }
            }
            for(i=1;i<5;i++){
                for(j=1;j<4;j++){
                    if(matrix[i][j]==matrix[i][j+1]){
                        matrix[i][j]=matrix[i][j+1]+matrix[i][j];
                        matrix[i][j+1]=0;
                    }
                }
            }
            for(i=1;i<5;i++){
                for(j=1;j<4;j++){
                    if(matrix[i][j]==0){
                        k=j;
                        while(k+1<=5){
                            matrix[i][k]=matrix[i][k+1];
                            k++;
                        }
                        matrix[i][4]=0;
                    }
                }
            }
        }
        //////////////////////////////////////////////////////////////////////
        else if(x=='d'){
            for(i=1;i<5;i++){
                for(j=2;j<=4;j++){
                    if(matrix[i][j]==0){
                        k=j;
                        while(k-1>=1){
                            matrix[i][k]=matrix[i][k-1];
                            k--;
                        }
                        matrix[i][1]=0;
                    }
                }
            }
            for(i=1;i<5;i++){
                for(j=4;j>1;j--){
                    if(matrix[i][j]==matrix[i][j-1]){
                        matrix[i][j]=matrix[i][j-1]+matrix[i][j];
                        matrix[i][j-1]=0;
                    }
                }
            }
            for(i=1;i<5;i++){
                for(j=4;j>1;j--){
                    if(matrix[i][j]==0){
                        k=j;
                        while(k-1>=1){
                            matrix[i][k]=matrix[i][k-1];
                            k--;
                        }
                        matrix[i][1]=0;
                    }
                }
            }
        }
        ///////////////////////////////////////////////////////////////////
        else if(x=='s'){
            for(j=1;j<5;j++){
                for(i=2;i<=4;i++){
                    if(matrix[i][j]==0){
                        k=i;
                        while(k-1>=1){
                            matrix[k][j]=matrix[k-1][j];
                            k--;
                        }
                        matrix[1][j]=0;
                    }
                }
            }
            for(j=1;j<5;j++){
                for(i=4;i>1;i--){
                    if(matrix[i-1][j]==matrix[i][j]){
                        matrix[i][j]=matrix[i-1][j]+matrix[i][j];
                        matrix[i-1][j]=0;
                    }
                }
            }
            for(j=1;j<5;j++){
                for(i=4;i>1;i--){
                    if(matrix[i][j]==0){
                        k=i;
                        while(k-1>=1){
                            matrix[k][j]=matrix[k-1][j];
                            k--;
                        }
                        matrix[1][j]=0;
                    }
                }
            }
        }
        ///////////////////////////////////////////////////////////////////
        if(x=='w'){
            for(j=1;j<5;j++){
                for(i=3;i>=1;i--){
                    if(matrix[i][j]==0){
                        k=i;
                        while(k+1<=4){
                            matrix[k][j]=matrix[k+1][j];
                            k++;
                        }
                        matrix[4][j]=0;
                    }
                }
            }
            for(j=1;j<5;j++){
                for(i=1;i<4;i++){
                    if(matrix[i][j]==matrix[i+1][j]){
                        matrix[i][j]=matrix[i+1][j]+matrix[i][j];
                        matrix[i+1][j]=0;
                    }
                }
            }
            for(j=1;j<5;j++){
                for(i=1;i<4;i++){
                    if(matrix[i][j]==0){
                        k=i;
                        while(k+1<=4){
                            matrix[k][j]=matrix[k+1][j];
                            k++;
                        }
                        matrix[4][j]=0;
                    }
                }
            }
        }
        //////////////////////////////////////////////////////////////////////
        for(i=1;i<5;i++){
            for(j=1;j<5;j++){
                if(j==1) printf("%2d",matrix[i][j]);
                else printf(" %2d",matrix[i][j]);
            }
            printf("\n");
        }
        flag=0;
        for(i=1;i<5;i++){
            for(j=1;j<5;j++){
                if(matrix[i][j]==64){
                    printf("You win\n");
                    flag=1;
                    break;
                }
                else if(matrix[i][j]==matrix[i-1][j] || matrix[i][j]==matrix[i+1][j] ||
                        matrix[i][j]==matrix[i][j-1] || matrix[i][j]==matrix[i][j+1]){
                    flag=1;
                    break;
                }
                else if(matrix[i][j]==0 && matrix[i][j]!=64){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            printf("Game over\n");
        }
        if(n!=0) printf("\n");
    }
    
    return 0;
}


