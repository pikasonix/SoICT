#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct student {
    char tensv[100];
    char email[100];
};
int main(){
	struct student students[100];
	int num =0;
	FILE *file = fopen("student.txt","w");
	if(file != NULL){
		while (fscanf(file, "%s %s", students[num].tensv, students[num].email) != EOF) {
    	num++;
	}
	fclose(file);
	}
	int choice;
	int i,j;
    while (1) {
        printf("Chon 1 chuc nang:\n");
        printf("1. In danh sach sv\n");
        printf("2. Them ho so sv\n");
        printf("3. Xoa ho so sv\n");
        printf("4. Tim kiem ho so sv\n");
        printf("5. Luu ho so vao file\n");
        printf("6. Thoat\n");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
    			exit(0);
    			break;
    		case 1:
    			printf("Danh sach sv:\n");
                for ( i= 0; i < num; i++) {
                    printf("Ten: %s, Email: %s\n", students[i].tensv, students[i].email);
                }
                break;
            
            case 2:
                if (i < 100) {
                    printf("Nhap ten sinh vien: ");
                    scanf("%s", students[num].tensv);
                    printf("Nhap email sinh vien: ");
                    scanf("%s", students[num].email);
                    num++;
                    printf("Da them ho so sinh vien.\n");
                } else {
                    printf("Danh sach da day, khong the them ho so moi.\n");
                }
                break;
            case 3:
                printf("Nhap ten sinh vien can xoa: ");
                char deleteName[100];
                scanf("%s", deleteName);
                for (i = 0; i < num; i++) {
                    if (strcmp(students[i].tensv, deleteName) == 0) {
                        for (j = i; j < num - 1; j++) {
                            strcpy(students[j].tensv, students[j + 1].tensv);
                            strcpy(students[j].email, students[j + 1].email);
                        }
                        num--;
                        printf("Da xoa ho so sinh vien.\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("Nhap ten sinh vien can tim kiem: ");
                char search[100];
                scanf("%s", search);
                int found = 0;
                for (i = 0; i < num; i++) {
                    if (strcmp(students[i].tensv, search) == 0) {
                        printf("Ho so sinh vien tim thay:\n");
                        printf("Ten: %s, Email: %s\n", students[i].tensv, students[i].email);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay ho so sv.\n");
                }
                break;
            case 5:
                file = fopen("students.txt", "w");
                for ( i= 0; i < num; i++) {
                    fprintf(file, "%s %s\n", students[i].tensv, students[i].email);
                }
                fclose(file);
                printf("Da luu ho so vao file.\n");
                break;
            default:
                printf("Chon lai.\n");
        }
    }
	
    return 0;
}

