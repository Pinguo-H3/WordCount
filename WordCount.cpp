#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int CountWord(FILE *fp) {
	char buffer[1000];
	int bufferlen;
	int ans = 0;
	int flag = 0;
	int i = 0;
	while(fgets(buffer,1000,fp) != NULL) {
		while(buffer[i] != '\0') {
			if(flag == 0 ) {
				if(buffer[i] != ' ') {
					ans++;
					flag = 1;
					}
				}
				else {
					if(buffer[i] == ' ') {
						flag = 0;
					}
				}
				i++;
			}
		}
	return ans;
} 

int CountChar(FILE *fp) {
	char buffer[1000];
	int ans = 0;
	int i = 0;
	while(fgets(buffer,1000,fp) != NULL) {
		for(; i < strlen(buffer); i++) {
			if(buffer[i] == ' ') {
				continue;
			} else {
				ans++;
			}
		}

	}
	return ans;
	
}

 
int main(int argc, char* argv[]) {
	FILE *fp = NULL;
	//ѡ��
	char *c = argv[1];
	//�ļ�·�� 
	char *txt = argv[2];
	
	fp = fopen(txt, "r");
	if(fp == NULL) {
		printf("���ļ�Ϊ��");
		return 0; 
	} else {

		if(!strcmp(c, "-w")) {
			printf("������: %d",CountWord(fp));
		} else if(!strcmp(c, "-c")){
			printf("�ַ���: %d",CountChar(fp));
		}
	}
	
	return 0;
}
