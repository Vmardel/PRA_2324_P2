#include "cambio.h"
#include <limits>
#include <algorithm>
#include <iostream> 
using namespace std;

int cambio(int N, int* v, int M){

	int infinito = numeric_limits<int>::max();
	int** matrix = new int*[N];
	for(int i=0; i<= N;i++){
		matrix[i] = new int[1+M];
		matrix[i][0] = 0;
		for(int x=1;x<=M;x++){
			matrix[i][x] = -1;			
		}	
	}

 	int mini= 0;
	for(int  i = 0; i < N; i++){
		for(int j = 1; j<= M ; j++ ) {
			if( M == 0){
				return 0;
			}else if( i ==0 && v[0] > M){
				return infinito;
			}else if( i==0 && v[0] <= M){
				matrix[i][j] = 1 + matrix[0][j-v[0]];
			}else if( i >0 && v[i] > j > 0){
				matrix[i][j] = matrix[i-1][j];
			}else{
				matrix[i][j] = min( matrix[i-1][j] , 1 + matrix[i][j-v[i]]); 
			}
		}
	}

	for(int x = 0; x< N ; x++){
	    cout<< v[x]<<"  ";
            for(int y = 0; y<= M; y++){
                 cout << matrix[x][y]<<"    ";
              }
               
               cout << endl;
       }

	for(int c = 0; c<N ; c++){
		if(mini ==0 || mini > matrix[c][M]){	
			mini = matrix[c][M];
		}
	}
	
return mini;
}

int* cambio_vector(int N, int* v, int M){
	int infinito = numeric_limits<int>::max();
	int** matrix = new int*[N];
	for(int i=0; i<= N;i++){
		matrix[i] = new int[1+M];
		matrix[i][0] = 0;
		for(int x=1;x<=M;x++){
			matrix[i][x] = -1;			
		}	
	}

 	int mini= 0;
	for(int  i = 0; i < N; i++){
		for(int j = 1; j<= M ; j++ ) {
			if( M == 0){
				return 0;
			}else if( i ==0 && v[0] > M){
				return {};
			}else if( i==0 && v[0] <= M){
				matrix[i][j] = 1 + matrix[0][j-v[0]];
			}else if( i >0 && v[i] > j > 0){
				matrix[i][j] = matrix[i-1][j];
			}else{
				matrix[i][j] = min( matrix[i-1][j] , 1 + matrix[i][j-v[i]]); 
			}
		}
	}

	for(int x = 0; x< N ; x++){
	    cout<< v[x]<<"  ";
            for(int y = 0; y<= M; y++){
                 cout << matrix[x][y]<<"    ";
              }
               cout << endl;
        }

	int fila,columna;
	for(int c = 0; c < N ; c++){
		if(mini ==0 || mini > matrix[c][M]){
			mini = matrix[c][M];
			fila = M;
			columna =  c;
		}
	}

	int* resultante = new int[N];
	while(columna >= 0 && fila >= 0){
		if(matrix[columna][fila] ==( 1 +matrix[columna][fila-v[columna]])){	
			resultante[columna] += 1;
			fila-=v[columna];		
		}else {
			columna-=1;
		} 
	}
	
return resultante;
}

