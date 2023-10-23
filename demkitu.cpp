#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]){
	if(argc != 4){
		printf("Error\n");
		return 0;
	}
	int c12 = strcmp(argv[1], argv[2]);
	int c13 = strcmp(argv[1], argv[3]);
	int c23 = strcmp(argv[2], argv[3]);
	if(c12 != 0 && c13 != 0 && c23 != 0){
		printf("1. %s %s %s", argv[1], argv[2], argv[3]);	
		printf("\n2. %s %s %s", argv[1], argv[3], argv[2]);
		printf("\n3. %s %s %s", argv[2], argv[1], argv[3]);
		printf("\n4. %s %s %s", argv[2], argv[3], argv[1]);
		printf("\n5. %s %s %s", argv[3], argv[2], argv[1]);
		printf("\n6. %s %s %s\n", argv[3], argv[1], argv[2]);
		return 0;
	}
	if (c12 ==0 && c13==0)
	{
		printf("Error\n");
		return 0;
	}
	if (c12==0)
	{
		printf("%s %s",argv[1],argv[3]);
		printf("%s %s",argv[3],argv[1]);

		return 0;
	}
	if (c13==0)
	{
		printf("%s %s",argv[1],argv[2]);
		printf("%s %s",argv[2],argv[1]);
		return 0;
	}
	if (c23==0)
	{
		printf("%s %s",argv[1],argv[2]);
		printf("%s %s",argv[2],argv[1]);
		return 0;
	}
	return 0;
}

