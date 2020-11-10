#include "random.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
int* random(int &ref_len){
	int* ptr = (int*)malloc(sizeof(int) * ref_len);
	int size = 0;
	int len;
	srand(time(NULL));
    while(size < ref_len){
      int x = rand();
      len = (x % 25) + 1;
      int y = rand();
      int choose = (y % 800) + 1;
      while(choose + len > 800){  //over ,restart
         x = rand();
         len = (x % 25) + 1;
         y = rand();
         choose = (y % 800) + 1;
      }
    int* ptr2 = (int*)malloc(sizeof(int) * len);
    //size = size + len;
    for(int i = 0; i < len; i++){  //***
      ptr2[i] = choose + i;
    }
	for(int i = 0; i < len; i++){
		ptr[size + i] = ptr2[i];
	}
	size = size + len;
	}
	
	return ptr;
}