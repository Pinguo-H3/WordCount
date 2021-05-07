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

 
int main() {
	FILE *fp = NULL;
	//读取输入 
	char str[10];
	
	fp = fopen("E:\\test.txt", "r");
	if(fp == NULL) {
		printf("该文件为空");
		return 0; 
	} else {
		scanf("%s",str);
		char c =  str[1];
		if(c == 'w') {
			printf("单词数: %d",CountWord(fp));
		} else if(c == 'c'){
			printf("字符数: %d",CountChar(fp));
		}
	}
	
	return 0;
}
