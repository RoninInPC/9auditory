#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>
char* settime(struct tm* u)
{
	char s[40];
	char* tmp;
	for (int i = 0; i < 40; i++) s[i] = 0;
	int length = strftime(s, 40, "%d.%m.%Y", u);
	tmp = (char*)malloc(sizeof(s));
	strcpy(tmp, s);
	return(tmp);
}
int main() {
	char buffer[267];
	DWORD size;
	size = sizeof(buffer);
	GetUserName(&buffer, &size);
	printf("Username : ");
	for (int i = 0; i < 267; i++) {
		if (buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i] >= 'A' && buffer[i] <= 'Z' || buffer[i]>='0' && buffer[i]<='9' || buffer[i] == '-') {
			printf("%c", buffer[i]);
		}
	}
	printf("\n");
	char buffer1[267];
	DWORD size1;
	size1 = sizeof(buffer1);
	GetComputerName(&buffer1, &size1);
	printf("Computername : ");
	for (int i = 0; i < 267; i++) {
		if (buffer1[i] >= 'a' && buffer1[i] <= 'z' || buffer1[i] >= 'A' && buffer1[i] <= 'Z' || buffer1[i] >= '0' && buffer1[i] <= '9' || buffer1[i] =='-') {
			printf("%c", buffer1[i]);
		}
	}
	printf("\n");
	long ttime;
	ttime = time(NULL);
	ttime = ttime - (ttime / 365 / 24 / 3600)*365*24*3600;
	ttime = ttime - (ttime / 24 / 3600) * 24 * 3600;
	printf("Time : %d:%d\n", ttime/3600+5, (ttime-ttime/3600*3600)/60);// за счёт висакосных годов накопилось 5 выпавших часов
	const time_t timer = time(NULL);
	struct tm* u;
	char* f;
	u = localtime(&timer);
	f = settime(u);
	printf("Date : %s", f);
	return 0;
}