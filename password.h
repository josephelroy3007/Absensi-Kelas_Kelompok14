#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

char password[10]={"qwerty"};//deklarasi password

void Password(){
	system("cls");

	char ch,pass[10];//deklarasi input
	int i=0,j;

	printf("\n\n\t\t\t\t\****************PASSWORD PROTECTED****************\n\n");
	printf("\t \n\n\n Password: ");
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("*");//agar tidak menapilkan input password melainkan '*'
			pass[i] = ch;
				i++;
		}
	}
	pass[i] = '\0';

	if(strcmp(pass,password)!=0){//jika input tidak sama dengan password
		printf("\n\n\n\t\t\aWarning!! \n\t   Password Salah");
		getch();
		mainmenu();//kembali ke menu utama
	}
}
