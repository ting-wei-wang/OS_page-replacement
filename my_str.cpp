#include "my_str.h"
#include <stdlib.h>
#include <time.h>
int* mystr(int &len){
	int i;
	srand(time(NULL));
    int* ptr = (int*)malloc(sizeof(int) * len);
	for(i = 0; i < (len/2); i++){
		ptr[i] = rand()%100 + 1;
	}
	for(i = (len/2 + 1); i < len; i++){
		ptr[i] = rand()%100 + 700;
	}
	return ptr;
}