#include "fifo.h"
#include <stdlib.h>
int fifo(int ref_len,int capability, int* refer_str){
	//int in = false;
	int frame_len = 0;
	int *frame = (int*)malloc(sizeof(int) * ref_len); //****
	int i,j;
	int top = 0;
	int pf = 0;
	int interrupt = 0;
	int diskIO = 0;
	for(i = 0; i <= capability; i++){
		frame[i] = 0;
	}
	for(i = 0; i < ref_len ;i++){
		int in = false;
	  for(j = 0; j <= frame_len; j++ ){
		if(frame[j] == refer_str[i]){
			in = true;
			break;
	    }
	  }
	  if(in == false){
        if(refer_str[i]>= 30 && refer_str[i] <= 100){
			diskIO++;
			interrupt++;
		}
		if(frame_len < capability){
			frame[frame_len] = refer_str[i];
			frame_len++;
		}
		else{
			frame[top] = refer_str[i];
			top = (top + 1) % capability;
		}
		pf++;
		interrupt++;
	  }
   }
	free(frame);
   return diskIO;
}