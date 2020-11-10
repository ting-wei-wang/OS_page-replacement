#include "my.h"
#include <stdlib.h>

int my(int ref_len,int capability, int* refer_str){
	int** str_test = (int **) malloc(800 * sizeof(int)); // times
	int i,j,k,temp;
	int min = 0;
	int pf = 0;
	int DiskIO = 0;
	int interrupt = 0;
	int frame_len = 0;
	int *frame = (int*)malloc(sizeof(int) * ref_len); ;
	for ( k = 0; k < 800; k++) {                           
        str_test[k] = (int *) malloc(2 * sizeof(int));
	}
	for( k = 0; k < 800 ; k++){
		str_test[k][0] = k ;
	}
	for( k = 0; k < 800 ; k++){
		str_test[k][1] = 0;
	}
	for( i = 0; i < ref_len ; i++){    //count
		for(j = 0; j < 800; j++){
			if(refer_str[i] == str_test[j][0]){
				str_test[j][1]++;
			}
		}
    }
	for(i = 0; i < ref_len ;i++){
		int in = false;
		int pos = 0;
	  for(j = 0; j < capability; j++ ){
		if(frame[j] == refer_str[i]){
			in = true;
			break;
	    }
	  }
	   if(in == false){
        if(refer_str[i]>= 30 && refer_str[i] <= 100){
			DiskIO++;
			interrupt++;
		}
		if(frame_len < capability){          // not full
			frame[frame_len] = refer_str[i];
			frame_len++;
			pf++;
		}
		else{
			for(j = 0;j < capability;j++) {  // find current min count num
            if(min > str_test[frame[j]][1]) {
                 min = str_test[frame[j]][1];
            }
        }
		for(j = 0;j < capability;j++) { // find current min  locate
            if(str_test[frame[j]][1] == min) {
                 pos=j;
                 break;
            }
		}
		frame[j] = refer_str[i]; 
		pf++;
		interrupt++;
	  }
   }
	}
	free(str_test);
	return DiskIO;
}