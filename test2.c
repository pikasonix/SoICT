#include<stdio.h>
#include<ctype.h>
enum {SUCCESS, FAIL};
void read(char *inp){
	char str[1000];
	int sosp;
	double gia;
	while(fscanf(inp, "%d%s%lf", &sosp, str, &gia) != EOF){
		printf("%d	%s	%lf", sosp, str, gia);
	}
}
main(){
	FILE *fptr;
	char f[]="lab1.txt";
	fptr = fopen(f, "r");
	read(fptr);
	fclose(fptr);
}
