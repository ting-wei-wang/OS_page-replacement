#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "fifo.h"
#include "arb.h"
#include "esc.h"
#include "my.h"
#include "random.h"
#include "local.h"
#include "my_str.h"
#include <fstream>
using namespace std;

//int num_frame = 20;

int main(){
	fstream file1,file2,file3,file4;
	int len = 200000;
	int ans[4][10];
	int frame_num[10] = {10,20,30,40,50,60,70,80,90,100};
	int i,j;
	
	int* refer = mystr(len);
	/*for(int i = 0; i<len;i++){
		cout << refer[i] << ",";
	}*/
	file1.open("FIFO.txt", ios::out);      //¶}±ÒÀÉ®×
	file2.open("ARB.txt", ios::out);
	file3.open("ESC.txt", ios::out);
	file4.open("my.txt", ios::out);
	for(i = 0; i < 10 ;i++){
		ans[0][i] = fifo(len, frame_num[i],refer);
		file1 << frame_num[i] <<" "<< ans[0][i] << endl;
	}
	for(i = 0; i < 10 ;i++){
		ans[1][i] = arb(len, frame_num[i],refer);
		file2 << frame_num[i] <<" "<< ans[1][i] << endl;
	}
	for(i = 0; i < 10 ;i++){
		ans[2][i] = esc(len, frame_num[i],refer);
		file3 << frame_num[i] <<" "<< ans[2][i] << endl;
	}
	for(i = 0; i < 10 ;i++){
		ans[3][i] = my(len, frame_num[i],refer);
		file4 << frame_num[i] <<" "<< ans[3][i] << endl;
	}
	/*ans[0] = fifo(1000,20,refer);
	ans[1] = arb(1000,20,refer);
	ans[2] = esc(1000,20,refer);
	ans[3] = my(1000,20,refer);
	for(int i = 0; i < 4; i++){
       cout << ans[i] << " ";
	}*/
	cout <<"file complete~"<< endl;
	system("pause");
}
