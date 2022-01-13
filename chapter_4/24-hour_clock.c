#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  int curr_time = atoi(argv[1]);
  int plus = atoi(argv[2]);
  return (curr_time+plus) % 24; 
}
