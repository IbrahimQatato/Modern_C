#include <stdio.h>

int main(int argc, char* argv[]){
   char arg = 'm';
    switch(arg){
        case 'm': puts("this is a magpie");
        case 'r': puts("this is a raven");
        default: puts("this is an unknown corvid");
    } 
}
