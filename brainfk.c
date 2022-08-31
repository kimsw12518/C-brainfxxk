#include<stdio.h>
#include<conio.h>

int main()
{
	char mem[32768]={0},str[10000];
	int ptr=0,i=0,j=0;
	scanf("%[^#]s",&str);
	for(i=0;str[i]!=0;i++){
//		printf("%d, '%c', %d: %d\n",i,str[i],ptr,mem[ptr]);
		switch(str[i]){
			case '>': ptr=(ptr+1)%32768;break;
			case '<': ptr=(ptr+32767)%32768;break;
			case '+': mem[ptr]++;break;
			case '-': mem[ptr]--;break;
			case '.': printf("%c",mem[ptr]);break;
			case ',': mem[ptr]=getch();break;
			case '[': if(mem[ptr]==0){
				j=1;
				while(j!=0){
					i++;
					switch(str[i]){
						case '[': j++;break;
						case ']': j--;break;
					}
				}
			}break;
			case ']': if(mem[ptr]!=0){
				j=-1;
				while(j!=0){
					i--;
					switch(str[i]){
						case '[': j++;break;
						case ']': j--;break;
					}
				}
			}
		}
	}
}

