#include "esc.h"
#include <stdlib.h>

int esc(int ref_len,int capability, int* refer_str ){
	// 20 ~ 100 write,else read
	//int refer_bit[100] = {0}; // reference bit
	//int dirty_bit[100] = {0}; // dirty bit
	int frame_len = 0;
	//int frame[100] = {0} ;
	int *frame = (int*)malloc(sizeof(int) * ref_len); 
	int *refer_bit = (int*)malloc(sizeof(int) * ref_len); 
	int *dirty_bit = (int*)malloc(sizeof(int) * ref_len); 
	int i,j;
	int pf = 0;
	int DiskIO = 0;
	int interrupt = 0;
	for(i = 0; i <= capability; i++){       
		frame[i] = 0;
		refer_bit[i] = 0;
		dirty_bit[i] = 0;
	}
	for(i = 0; i < ref_len ;i++){//correct
	 int in = false;
	  for(j = 0; j <= frame_len; j++ ){
		if(frame[j] == refer_str[i]){
			in = true;
			refer_bit[j] = 1; //reference = 1
			break;
	    }
	  }
	  if(in == false){
	  if((refer_str[i] >= 30)&&(refer_str[i] <= 100)){ //20~100 write
				DiskIO++;
				interrupt++;
				dirty_bit[frame_len] = 1;
			}
		if(frame_len < capability){
			frame[frame_len] = refer_str[i];
			refer_bit[frame_len] = 1;
			frame_len++;
			
			
		}
		else{  //reference and dirty
			int done = false;
			int top = 0;
			int temp = top;
			for(j = 0; j < capability; j++){
				if(refer_bit[top] == 0 && dirty_bit[top] == 0){
					done = true;
					break;
				}
				top = (top + 1) % capability;
			}
			if(done == false){
				top = temp;
				for(j = 0;j < capability; j++){
					if( refer_bit[top] == 0 && dirty_bit[top] == 1 ){
                         done = 1;
                         break;
                    }
                    if( refer_bit[top] == 1 ){
                        refer_bit[top] = 0;
                    }
                    top = (top+1)%(capability);
                }
            }
			 if( done == 0 ){
                top = temp;
             for( j = 0; j < capability; j++ ){
              if( refer_bit[top] == 0 && dirty_bit[top] == 0 ){
                  done = 1;
                  break;
              }
              top = (top+1)%(capability);
             }
           }
            if( done == 0 ){
                top = temp;
            for( j = 0; j < capability; j++ ){
            if( refer_bit[top] == 0 && dirty_bit[top] == 1 ){
              break;
            }
            top = (top+1)%(capability);
          }
        }
        frame[top] = refer_str[i];
		refer_bit[top] = 1;
		if((refer_str[i] >= 20)&&(refer_str[i] <= 100)){
			dirty_bit[frame_len] = 1;
		}
	    top = (top + 1) % capability;
		}
		pf++;
		interrupt++;
	  }
   }
   return DiskIO;

}