#include "mochila.h"
#include <algorithm>

int mochila(int e,int p[], int b[], int M){
	int** x = new int*[e];
	for(int i=0; i<e; i++){
    		x[i] = new int[M+1];
	}

	for(int i=0; i<e;i++){
		x[i][0] = 0;	
	}

	for(int i=0; i<e; i++){
		for(int j=1; j<M+1;j++){
			if(i==0 && p[0] > j){
				x[i][j] = 0;
			}else if(i == 0 && p[0] <=j){
				x[i][j] = b[0];
			}else if(i>0 && p[i] > j){
				x[i][j]=x[i-1][j];
			}else if(i>0 && p[i] <= j){
				x[i][j] = std::max(x[i-1][j], b[i] + x[i-1][j-p[i]]);
			}
		}
	}
	return x[e-1][M];
}
