/*Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){

        char temp;
        int index =0;
        char * buffer = (char *)malloc(1000);
        while(1){
                read(0, &temp, 1);
                if(temp == '~')
                        break;
                buffer[index++] = temp;
        }

        printf("\n");
        write(1, buffer, index);
        return 0;
}

