#include "arb.h"
#include <stdlib.h>
int arb(int ref_len,int capability, int* refer_str){
	int** bit_arr = (int **) malloc(capability * sizeof(int)); // x*2 - matrix
	for (int k = 0; k < capability; k++) {                           
        bit_arr[k] = (int *) malloc(2 * sizeof(int));
	}
	int i,j;
	int min = 0;
	int pf = 0;
	int frame_len = 0;
	int DiskIO = 0;
	int interrupt = 0;
	for(i = 0;i < capability ;i++) {
       bit_arr[i][0]=-1;    //non-number
       bit_arr[i][1]=0x00;  // 00
	}
	for(i = 0;i < ref_len;i++) {
    int pos = 0;
    int in = false;
    min = bit_arr[0][1];
    for(j = 0;j < capability;j++) {
        bit_arr[j][1] = bit_arr[j][1]>>1;
    }
	for(j = 0;j < capability;j++) {     // correct
        if(refer_str[i]==bit_arr[j][0]) {
                in = true;
                pos = j;
                break;
        }
    }
	if(in == true) {
      	bit_arr[pos][1]=bit_arr[pos][1]|0x80; // most set to 1
    }
	else if((in != true) && (bit_arr[capability - 1][0] == -1)) { //not full
    	if(refer_str[i]>= 30 && refer_str[i] <= 100){
			DiskIO++;
			interrupt++;
		}
		bit_arr[frame_len][0] = refer_str[i];
        bit_arr[frame_len][1] = bit_arr[frame_len][1]|0x80;
        frame_len = (frame_len + 1) % capability;
		pf++;
    }
	else {
        for(j = 0;j < capability;j++) {  // find current min 8 bit num
            if(min > bit_arr[j][1]) {
                 min = bit_arr[j][1];
            }
        }
		for(j = 0;j < capability;j++) { // find current min 8 bit locate
            if(bit_arr[j][1] == min) {
                 pos=j;
                 break;
            }
        }
		if(refer_str[i]>= 30 && refer_str[i] <= 100){
			DiskIO++;
			interrupt++;
		}
		bit_arr[pos][0] = refer_str[i];
        bit_arr[pos][1] = 0x80; //128
		pf++;
		interrupt++;
	}
	//pf++;
	}
	free(bit_arr);
	return DiskIO;
}