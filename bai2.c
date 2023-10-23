#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len 256
typedef struct Profile {
	char name[len];
	char email[len];
	struct Profile* next;
}Profile;
Profile *first=NULL, *last=NULL;

Profile *makeProfile(char *name, char *email)
{
	Profile* node = (Profile*) malloc(sizeof(Profile));
	strcpy(node->name, name);
	strcpy(node->email,email);
	node->next = NULL;
	return node;
}

int empt()
{
	return first ==NULL && last ==NULL;
}

void printlist()
{
	for(Profile *p=first; p!=NULL;p=p->next )
	{
		printf("%s %s\n", p->name, p->email);
	}
}

void insertLast(char *name, char *email)
{
	Profile *p = makeProfile(name,email);
	if(empt()) {
		first = p;
		last = p;
	}
	else{
		last ->next = p;
		last = p;
	}
}

Profile* removeProfile(Profile *f, char *name)
{
	if(empt()) return NULL;
	if(strcmp(f->name,name) ==0)
	{
		Profile* tmp = f->next;
		free(f);
		if(tmp == NULL) last = NULL;
		return tmp;
 	}
 	else {
 		f->next = removeProfile(f->next, name);
 		return f;
	 }
}

void load (char *filename)
{
	FILE *f =fopen(filename, "r");
	if(f==NULL) printf("Load data -> file not found\n");
	while(!feof(f))
	{
		char name[len];
		char email[len];
		fscanf(f,"%s%s",name,email);
		insertLast(name,email);
	}
	fclose(f);
}

void processFind ()
{
	char name[256];
	scanf("%s",name);
	Profile *profile=NULL;
	for(Profile *p=first; p!=NULL;p=p->next)
	{
		if(strcmp(p->name,name)==0)
		{
			profile=p;
			break;
		}
	}
	if(profile == NULL) printf("NOT FOUND profile %s\n",name);
	else printf("FOUND profile %s\n",profile->name,profile->email);
}

void processLoad()
{
	char filename[256];
	scanf("%s",filename);
	load(filename);
}

void processStore()
{
	char filename[256];
	scanf("%s",filename);
	FILE *f= fopen(filename,"w");
	for(Profile *p=first;p!=NULL;p=p->next )
	{
		fprintf(f,"%s %s",p->name, p->email);
		if(p->next != NULL ) fprintf(f,"\n");
	}
	fclose(f);
}


int main ()
{
	
}
