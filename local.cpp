#include "local.h"
#include <stdlib.h>
#include <time.h>
int* local(int &len){
	/*int min = 15;
	int max = 25;
	//len = 20;
	srand(time(NULL));
	int x = rand() % (max - min + 1) + min;
	int ReferenceStart = rand() % (800 - x) + 1;
	int ReferenceEnd = ReferenceStart + x ;
	int* ptr = (int*)malloc(sizeof(int) * len);
	int i;
	for(i = 0; i < len; i++){  //initialize
		ptr[i] = 0;
	}
	for(i = 0; i < len ; i++){
		ptr[i] = rand() % (ReferenceEnd - ReferenceStart + 1) + ReferenceStart;
	}
	return ptr;*/
	int min = 15;
    int max = 25;
    int size = 0;
    //len = 20;
    srand(time(NULL));
    int* ptr = (int*)malloc(sizeof(int) * len);
    while(size < len){
	  int x = rand() % (max - min + 1) + min;
      int ReferenceStart = rand() % (800 - x) + 1;
      int ReferenceEnd = ReferenceStart + x ;
      int* ptr2 = (int*)malloc(sizeof(int) * x);
      int i;
      for(i = 0; i < x; i++){  //initialize
        ptr2[i] = 0;
      }
      for(i = 0; i < x ; i++){
        ptr2[i] = rand() % (ReferenceEnd - ReferenceStart + 1) + ReferenceStart;
      }
      for(i = 0; i < x ; i++){
        ptr[size + i] = ptr2[i]; 
      }
      size = size + x;
}
 return ptr;

}

