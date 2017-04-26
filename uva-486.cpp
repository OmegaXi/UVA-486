#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char buf[20][10];

char number[32][10] = {
	"negative", "zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve", 
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
	"eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", 
	"sixty", "seventy", "eighty", "ninety", "hundred", 
	"thousand", "million"}; 

int value[32] = {
	-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
	20,30,40,50,60,70,80,90,100,1000,1000000};
	
int find(char *str)
{
	for (int i = 1 ; i < 29 ; ++ i)
		if (!strcmp(str, number[i]))
			return value[i];
	return -1;
}

int dfs(int a, int b)
{
	if (a > b) return 0;
	if (a == b) return find(buf[a]);
	else {
		int million = 0,thousand = 0,hundred = 0,sum = 0;
		for (int i = a ; i <= b ; ++ i) {
			if (!strcmp(buf[i], "million")) million = i;
			if (!strcmp(buf[i], "thousand")) thousand = i;
			if (!strcmp(buf[i], "hundred")) hundred = i;
			sum += find(buf[i]);
		}
		if (million) return dfs(a, million-1)*1000000+dfs(million+1, b);	
		if (thousand) return dfs(a, thousand-1)*1000+dfs(thousand+1, b);
		if (hundred) return dfs(a, hundred-1)*100+dfs(hundred+1, b);
		return sum;
	}
}

int main()
{
	int count = 0;
	while (scanf("%s",buf[count ++]) != EOF) {
		while (getchar() != '\n')
			scanf("%s",buf[count ++]);
		
		if (!strcmp(buf[0], "negative"))
			printf("-%d\n",dfs(1, count-1));
		else printf("%d\n",dfs(0, count-1));
		count = 0;
	}
    return 0;
}
