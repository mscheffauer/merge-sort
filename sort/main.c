#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


//arrays must be sorted first for this to work, returns length of output array
int Merge(int a1[], int a2[], int n1, int n2){
	int output[n1+n2];
	//a2 is smaller than a1 so it can go before
	if ((a1[0] >= a2[0]) && (a1[0] >= a2[n2-1])){
		for (int i=0; i<n2;i++ ){
			output[i] = a2[i];
		}
		for (int i=0; i<n1;i++ ){
			output[i+n2] = a1[i];
		}
	}
	//a2 is bigger than a1 so it can go after
	else if ((a2[0] >= a1[0]) && (a2[0] >= a1[n1-1])){
		for (int i=0; i<n1;i++ ){
			output[i] = a1[i];
		}
		for (int i=0; i<n2;i++ ){
			output[i+n1] = a2[i];
		}
		
	}	//the two overlap so merge individually
	else{
	
		int outputcnt = 0;
		int a1cnt = 0;
		int a2cnt = 0;

		while (outputcnt<n1+n2){

			if ((a1[a1cnt] < a2[a2cnt]) && (a1cnt <n1)){
				output[outputcnt] = a1[a1cnt];
				outputcnt++;
				a1cnt++;
			}else if ((a2[a2cnt] < a1[a1cnt]) && (a2cnt <n2)){
				output[outputcnt] = a2[a2cnt];
				outputcnt++;
				a2cnt++;
			}else if (a1cnt <n1){
				output[outputcnt] = a1[a1cnt];
				outputcnt++;
				a1cnt++;
			}else if (a2cnt <n2){
				output[outputcnt] = a2[a2cnt];
				outputcnt++;
				a2cnt++;
			}	
		}
		
	}
	
	for (int i=0; i<(n1+n2);i++ ){
		a1[i] = output[i];
    }
	return n1+n2;	
	
}

//first split until only arrays with one element are there then merge 
void MergeSort(int a[], int n) { /* code to sort a[0].. a[n - 1] using merge sort */ 

	int sizel=0; 
	int sizer=0;
	
	sizel = n/2;
	sizer = (n%2!=0) ? sizel+1 : sizel;
	
	if (sizel > 0)
	{
		MergeSort(a,sizel);
		MergeSort(a+sizel,sizer);
		Merge(a,a+sizel,sizel,sizer);
	}	
}


int main(int argc, char *argv[]) {

	int a[MAX];
	int maxindex = 0;
		
	//check if at least one array element is given
	if (argc < 2)
	{
		printf("bad number of arguments\n");
		return -1;
	}
	
	/* code to read a maximum of MAX values from argv into a and to set n to the actual number of values in a*/ 	
	//copy in array
	maxindex = ((argc-1) > MAX) ? MAX : argc-1;
	
	//convert to a numeric array
	for (int i=0; i<maxindex;i++ ){
		a[i] = atoi(argv[i+1]);
	}
	
	/* code to display unsorted array a */ 
	printf("the unsorted array:\n");
	for (int i=0; i<maxindex;i++ ){
		printf("a[%d] = %d\n",i,a[i]);
    }
	
	printf("\n");
	
	MergeSort(a, maxindex); 
	
	/* code to display sorted array a */ 
	printf("the sorted array:\n");
	for (int i=0; i<maxindex;i++ ){
		printf("a[%d] = %d\n",i,a[i]);
    }

	return 0; 

}

