#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include "password.h" //Library sendiri dengan fungsi program password() didalamnya
//Library yang digunakan

void mainmenu();
void submenu1();
void submenu2();
void tambah();
void absensi();
void hapus();
void edit();
void search();
void view();
void viewabsence();
void hapusabsen();
void kembali();
void Password();
void keluar();
int getdata();
int checknpm(int npm2);
int waktu();
int help();
int pilihan;
char cari;
char log[30];
FILE *fp,*ft,*fs;
COORD coord = {0, 0};

void gotoxy (int x, int y){
		coord.X = x; coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		} //gotoxy digunakan untuk menempatkan output pada kordinat x dan y agar hasil pada terminal lebih rapi dan tak perlu menggunakan \t atau \n

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock(); //setting time delay menggunakan milisecond
    while (goal > clock()); //delay (ada pada library time.h) digunakan memberikan sedikit waktu tunggu pada saat transisi
}

typedef struct kelas{
	int npm; //deklarasi npm
	char name[50]; //deklarasi name
	int contact; //deklarasi kontak
} kelas; //untuk membuat struktur data kelas, yang terdiri dari npm,nama,kontak

kelas data;

int getdata(){
	int npm2; //deklarasi npm2
	gotoxy(21,3); //menampilkan output print dibawah pada kordinat x=21 dan y=3
	printf("Masukkan Data:"); //print tulisan berupa -Masukan data:-
	gotoxy(21,5); //menampilkan output print dibawah pada kordinat x=21 dan y=5
	printf("NPM\t:"); //print tulisan berupa -NPM-
	scanf("%d",&npm2); //meminta masukan berupa npm

	if(checknpm(npm2) == 0){ //membandingkan apakah npm telah digunakan atau belum, apabila sudah maka menampilkan NPM telah dipakai dan kembali ke mainmenu()
		gotoxy(21,13); //menampilkan output print dibawah pada kordinat x=21 dan y=13
		printf("\aNPM sudah dipakai\a"); //mengeluarkan tulisan berupa -NPM sudah dipakai-
		getch(); //getch() digunakan untuk memberikan waktu pada user untuk menekan tombol apapun untuk transisi
		mainmenu(); //kembali ke mainmenu()
		return 0;
	}//apabila npm belum digunakan maka, akan diambil data sesuai struktur data yaitu: nama,kontak dan npm
	data.npm=npm2; //npm yang dimasukan sebelumnya akan menjadi data npm
	gotoxy(21,7); //menampilkan output print dibawah pada kordinat x=21 dan y=7
	printf("Nama\t:"); //mengeluarkan tulisan berupa -Nama :-
	gotoxy(35,7); //menampilkan scanf dibawah pada kordinat x=35 dan y=7
	scanf("%s", &data.name); //meminta inputan nama dalam string dan disimpan dalam data.name
	gotoxy(21,9); //menampilkan output print dibawah pada kordinat x=21 dan y=9
	printf("Kontak\t:"); //mengeluarkan tulisan berupa -Kontak-
	gotoxy(35,9); //menampilkan scanf dibawah pada kordinat x=35 dan y=9
	scanf("%d",&data.contact); //meminta inputan kontak dan disimpan dalam data.contact
	gotoxy(31,10); //menampilkan output print dibawah pada kordinat x=35 dan y=10
	return 1;
}

int checknpm(int npm2){
	rewind(fp);
	while(fread(&data,sizeof(data),1,fp)==1){ //membaca dokumen
		if(data.npm==npm2){ //dan membandingkannya pada npm2
			return 0;
		}
	}
	return 1;
}

void mainmenu(){
	system("cls"); //clearscreen
	gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
    printf("\=============== MENU UTAMA"); //mengeluarkan tulisan berupa -Menu Utama-
    printf(" ==============="); //agar user interfacenya terlihat rapi dan bagus
    gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
    printf("===== 1. DATA"); //mengeluarkan tulisan berupa -1. Data-
    gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
    printf("===== 2. ABSENSI"); //mengeluarkan tulisan berupa -2. Absensi-
    gotoxy(20,17); //menampilkan output print dibawah pada kordinat x=20 dan y=17
    printf("===== 9. Kembali ke Menu Awal"); //mengeluarkan tulisan berupa -9. Kembali ke menu awal-
    gotoxy(20,19); //menampilkan output print dibawah pada kordinat x=20 dan y=19
    printf("===== 0. Keluar Aplikasi"); //mengeluarkan tulisan berupa -0. Keluar Aplikasi-
    gotoxy(20,22); //menampilkan output print dibawah pada kordinat x=20 dan y=22
    printf("------------------------------------------"); // agar user interfacenya bagus dan memisahkan tampilan pilihan dengan tampilan waktu
    gotoxy(20,23); //menampilkan output print dibawah pada kordinat x=20 dan y=23
    waktu(); //menampilkan waktu sekarang (tanggal dan waktu)
    gotoxy(20,21); //menampilkan output print dibawah pada kordinat x=20 dan y=21
    printf("Pilihan: ");  //mengeluarkan tulisan berupa -Pilihan :-
    switch(getch()){ //meminta inputan apapun dari user
    	case '1': //apabila user memilih 1
			submenu1(); //akan menjalankan program submenu1()
			break;
		case '2': //apabila user memilih 2
			submenu2(); //akan menjalankan program submenu2()
			break;
		case '9': //apabila user memilih 9
			main(); //akan menjalankan program main()
			break;
		case '0': //apabila user memilih 0
			keluar(); //akan menjalankan program keluar()
        default:{ //apabila user memilih selain pilihan diatas
        	gotoxy(10,25); //menampilkan output print dibawah pada kordinat x=10 dan y=15
	        printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan salah!! Masukan pilihan yang tepat-
	        if(getch()) //menunggu user menekan tombol manapun untuk transisi
	        mainmenu(); //kembali menjalankan program mainmenu() dari awal
		}
	}
}

void submenu1(){
	Password(); //menjalankan program password, yang terletak pada program.h
	system("cls"); //clearscreen
	gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
    printf("============== DATA"); //mengeluarkan tulisan berupa -Data-
    printf(" =============="); //agar user interfacenya terlihat bagus dan rapi
    gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
    printf("===== 1. Tambah Data");//mengeluarkan tulisan berupa -1. Tambah Data-
	gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
	printf("===== 2. Lihat Data"); //mengeluarkan tulisan berupa -2. Lihat Data-
    gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
    printf("===== 3. Cari Data"); //mengeluarkan tulisan berupa -3. Cari Data-
    gotoxy(20,11); //menampilkan output print dibawah pada kordinat x=20 dan y=11
    printf("===== 4. Ubah Data"); //mengeluarkan tulisan berupa -4. Ubah Data-
    gotoxy(20,17); //menampilkan output print dibawah pada kordinat x=20 dan y=17
    printf("===== 5. Kembali ke menu utama"); //mengeluarkan tulisan berupa -4. Kembali ke menu utama-
    gotoxy(20,20); //menampilkan output print dibawah pada kordinat x=20 dan y=20
    printf("------------------------------------------"); //agar user interfacenya telihat bagus
    gotoxy(20,22); //menampilkan output print dibawah pada kordinat x=20 dan y=22
    waktu(); //menampilkan waktu sekarang (tanggal dan waktu)
    gotoxy(20,19); //menampilkan output print dibawah pada kordinat x=20 dan y=19
    printf("Pilihan:"); //mengeluarkan tulisan berupa -Pilihan :-
    switch(getch()){ //meminta user untuk memasukan pilihan dengan menekan tombol manapun
		case '1': //apabila user memilih 1
			tambah(); //akan langsung menjalankan program tambah()
			break;
		case '2': //apabila user memilih 2
			view(); //akan langsung menjalankan program view()
			break;
		case '3': //apabila user memilih 3
			search(); //akan langsung  menjalankan program search()
			break;
		case '4':{ //apabila user memilih 4
			Password(); //akan menjalankan program password() yang terdapat di library password.h
			system("cls"); //clearscreen
			gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
			printf("===== 1. Hapus Data"); //mengeluarkan tulisan berupa -1. Hapus Data-
			gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
			printf("===== 2. Edit Data"); //mengeluarkan tulisan berupa -2. Edit Data-
			gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
			printf("===== 3. Kembali ke menu utama"); //mengeluarkan tulisan berupa -3.Kembali ke menu utama-
			gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
			printf("Pilihan:"); //mengeluarkan tulisan berupa -Pilihan :-
			switch(getch()){ //menunggu user memasukan inputan apapun
				case '1': //apabila user memilih 1
				hapus(); //akan langsung menjalankan program hapus()
				break;
				case '2': //apabila user memilih 2
				edit(); //akan langsung menjalankan program edit()
				break;
				case '3': //apabila user memilih 3
				mainmenu(); //akan langsung menjalankan program mainmenu()
				default:{ //apabila user memilih selain 1-3
					gotoxy(10,23); //menampilkan output print dibawah pada kordinat x=10 dan y=23
					printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan Salah!!-
					if(getch()){ //menunggu user memasukan pilihan
					    Password(); //akan menjalankan program password() yang terdapat di library password.h
					}
		        }
			}
			break;
		}
		case '5': //apabila user memilih 5
			mainmenu(); //akan langsung menjalankan program mainmenu()
			break;
		default:{ //apabila user memilih selain 1-5
			gotoxy(10,24);//menampilkan output print dibawah pada kordinat x=10 dan y=24
			printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan Salah!!-
			if(getch()){ //menunggu user memasukan pilihan
				submenu1(); //akan langsung menjalankan program submenu1()
			}
		}
	}
}

void submenu2(){
	system("cls"); //Clearscreen untuk transisi UI
	gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
    printf("============== ABSENSI"); //mengeluarkan tulisan berupa -Absensi-
    printf(" =============="); //Agar UI lebih bagus dan rapi
    gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
    printf("===== 1. Absensi"); //mengeluarkan tulisan berupa -1. Absensi-
    gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
    printf("===== 2. Lihat Absen"); //mengeluarkan tulisan berupa -2. Lihat Absen-
    gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
    printf("===== 3. Hapus Absensi"); //mengeluarkan tulisan berupa -3. Hapus Absen-
    gotoxy(20,17); //menampilkan output print dibawah pada kordinat x=20 dan y=17
    printf("===== 4. Kembali ke menu utama"); //mengeluarkan tulisan berupa -4. Kembali ke menu utama-
    gotoxy(20,20); //menampilkan output print dibawah pada kordinat x=20 dan y=20
    printf("------------------------------------------"); //Agar UI lebih rapi
    gotoxy(20,21); //menampilkan output waktu dibawah pada kordinat x=20 dan y=21
    waktu(); //menampilkan waktu berupa (tanggal dan waktu sekarang)
    gotoxy(20,19); //menampilkan output print dibawah pada kordinat x=20 dan y=19
    printf("Pilihan:"); //mengeluarkan tulisan berupa -Pilihan :-
    switch(getch()){
        case '1': //apabila user memilih 1
			absensi(); //akan langsung menjalankan program absensi()
        	break;
    	case '2': //apabila user memilih 2
        	viewabsence(); //akan langsung menjalankan program viewabsence()
        	break;
        case '3': //apabila user memilih 3
        	hapusabsen(); //akan langsung menjalankan program hapusabsen()
        	break;
        case '4': //apabila user memilih 4
			mainmenu(); //akan langsung menjalankan program mainmenu()
			break;
        default:{ //apabila user memilih selain 1-4
	        gotoxy(10,23); //menampilkan output print dibawah pada kordinat x=10 dan y=23
	        printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan Salah!! Masukan pilihan yang tepat-
	        if(getch()){
	        	submenu2(); //akan langsung menjalankan program submenu2()
			}
        }
	}
}

void tambah(){
	system("cls"); //clearscreen untuk transisi UI
	gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
	printf("*******  Pilih Kategori: "); //mengeluarkan tulisan berupa -Pilih kategori-
	gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
	printf("===== 1. Tambah Data Kelas"); //mengeluarkan tulisan berupa -1. Tambah data kelas-
	gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
	printf("===== 9. Kembali ke Menu"); //mengeluarkan tulisan berupa -9. Kembali ke menu-
	gotoxy(20,15); //menampilkan output print dibawah pada kordinat x=20 dan y=15
	printf("Pilihan:"); //mengeluarkan tulisan berupa -Pilihan :-
	switch(getch()){
	case '9': //apabila user memilih 9
		submenu1(); //akan langsung menjalankan program submenu1()
		break;

	 case '1': //apabila user memilih 1
	system("cls"); //Clearscreen untuk transisi UI
	fp=fopen("stf.dat","ab+"); //membuka dokumen stf.dat

	if(getdata()==1){
		fseek(fp,0,SEEK_END); //meletakan pointer pada akhir file
		fwrite(&data,sizeof(data),1,fp); //menulis atau menambahkan data pada dokumen
		fclose(fp); //menutup dokumen
		gotoxy(21,14); //menampilkan output print dibawah pada kordinat x=21 dan y=14
		printf("Data tersimpan"); //mengeluarkan tulisan berupa -Data tersimpan-
		gotoxy(21,15); //menampilkan output print dibawah pada kordinat x=21 dan y=15
		printf("Ingin tambah lagi?(y=Ya, lainnya=tidak):"); //mengeluarkan tulisan berupa -Ingin tambah lagi? y=ya, lainnya=tidak-

		if(getch()=='y'){
			system("cls"); //clearscreen untuk transisi UI
			tambah(); //akan langsung menjalankan program tambah()
		}
		else{
			submenu1(); //akan langsung menjalankan program submenu1()
		}
	}
	break;
	default:{ //apabila user memilih selain 1 dan 9
	        gotoxy(10,23); //menampilkan output print dibawah pada kordinat x=10 dan y=23
	        printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan Salah!!Masukkan pilihan yang tepat!"-
	        if(getch()){ //menunggu user memasukkan input apapun untuk berpindah ke program selanjutnya
	        	tambah(); //akan langsung menjalankan program tambah()
			}
	}
}
}

void view(){
	int j=8, i=0, k, n, npmtemp, conttemp;
	char nametemp[50];
	system("cls"); //Clearscreen untuk transisi UI
	gotoxy(20, 5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
	printf("============================== List Data Kelas =============================="); //mengeluarkan tulisan berupa -List data kelas-
	gotoxy(30, 8); //menampilkan output print dibawah pada kordinat x=30 dan y=8
	printf("===== 1. Urut Waktu Input"); //mengeluarkan tulisan berupa -1. urut waktu input-
	gotoxy(30, 11); //menampilkan output print dibawah pada kordinat x=30 dan y=11
	fp=fopen("stf.dat","rb"); //membuka dokumen
	printf("Pilihan: "); //mengeluarkan tulisan berupa -Pilihan :-
	switch(getch()){
		case '1':
			system("cls"); //Clearscreen untuk transisi UI
			gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
			printf(" ============================== List Data Kelas =============================="); //mengeluarkan tulisan berupa -List data kelas- dengan sedikit tambahan agar terlihat bagus
			gotoxy(30, 7); //menampilkan output print dibawah pada kordinat x=30 dan y=7
			printf("NPM =================== NAMA ================== KONTAK"); //mengeluarkan tulisan berupa -NPM NAMA KONTAK- dalam 1 baris dengan tujuan agar mirip tabel
			while(fread(&data,sizeof(data),1,fp)==1){
				gotoxy(30,j); //menampilkan output print dibawah pada kordinat x=30 dan y=j
				printf("%d",data.npm); //Menampilkan npm yang diambil dari data.npm
				gotoxy(50,j); //menampilkan output print dibawah pada kordinat x=50 dan y=j
				printf("%s",data.name); //menampilkan nama mahasiswa diambil dari data.name
				gotoxy(78,j); //menampilkan output print dibawah pada kordinat x=78 dan y=j
				printf("%d",data.contact);//menampilkan kontak diambil dari data.contact
				gotoxy(80,j); //menampilkan output print dibawah pada kordinat x=80 dan y=j (struktur data npm,nama,kontak dibuat dlam 1 baris)
				printf("\n\n"); //memberi 2x spasi
				j++; //memasukan data selanjutnya ke baris baru
			}
			fclose(fp); //menutup dokumen fp
			break;
		}
		gotoxy(35,25); //menampilkan output print dibawah pada kordinat x=35 dan y=25
		kembali(); //akan langsung menjalankan program kembali()
}

void search(){
	system("cls"); //clearscreen untuk transisi UI
	int npm3; //Deklarasi npm3
	gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
	printf("============================== Cari Data =============================="); //mengeluarkan tulisan berupa -Cari Data- dengan sedikit tambahan agar telihat bagis
	gotoxy(20,10); //menampilkan output print dibawah pada kordinat x=20 dan y=10
	printf("1. Cari berdasarkan NPM"); //mengeluarkan tulisan berupa -1. Cari Berdasarkan NPM-
	gotoxy(20,14); //menampilkan output print dibawah pada kordinat x=20 dan y=14
	printf("2. Cari berdasarkan Nama"); //mengeluarkan tulisan berupa -2. Cari Berdasarkan Nama-
	gotoxy( 15,20); //menampilkan output print dibawah pada kordinat x=15 dan y=20
	printf("Pilihan: "); //mengeluarkan tulisan berupa -Pilihan :-
	fp=fopen("stf.dat","rb+"); //membuka dokumen stf.dat
	rewind(fp);
	switch(getch()){
		case '1':{
			system("cls"); //Clearscreen untuk transisi UI
			gotoxy(25,4); //menampilkan output print dibawah pada kordinat x=25 dan y=4
			printf("===== Cari berdasarkan NPM ====="); //mengeluarkan tulisan berupa -Cari berdasarkan NPM-
			gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
			printf("Masukkan NPM: "); //mengeluarkan tulisan berupa -Masukan NPM :-
			scanf("%d",&npm3); //meminta user untuk memasukan nilai npm3
			gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
			while(fread(&data,sizeof(data),1,fp)==1){ //membaca data pada dokumen yang telah dibuka
				if(data.npm==npm3){ //bila data.npm sama dengan npm3 maka
					Sleep(2);
					gotoxy(20,6); //menampilkan output print dibawah pada kordinat x=20 dan y=6
					printf("Data ditemukan\n"); //mengeluarkan tulisan berupa -Data ditemukan- lalu ditambahkan spasi
					gotoxy(20,8); //menampilkan output print dibawah pada kordinat x=20 dan y=8
					printf("NPM:%d",data.npm); //menampilkan NPM : "no.NPM" diambil dari data.npm
					gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
					printf("Nama:%s",data.name); //menampilkan Nama : "nama mahasiswa" diambil dari data.name
					gotoxy(20,10); //menampilkan output print dibawah pada kordinat x=20 dan y=10
					printf("Kontak:%d ",data.contact); //menampilkan Kontak : "kontak mahasiswa" diambil dari data.contact
					cari='t';
				}
			}
			if(cari!='t'){
				gotoxy(20,6); //menampilkan output print dibawah pada kordinat x=20 dan y=6
				printf("\aData tidak ditemukan"); //mengeluarkan tulisan berupa -Data tak ditemukan-
			}
			gotoxy(20,17); //menampilkan output print dibawah pada kordinat x=20 dan y=17
			printf("Ingin mencari lagi?(y=Ya, lainnya=tidak)"); //mengeluarkan tulisan berupa -Ingin mencari lagi?(y=Ya, lainnya=tidak)-
			if(getch()=='y'){
				search(); //akan langsung menjalankan program search()
			}
			else{
				mainmenu(); //akan langsung menjalankan program mainmenu()
			}
			break;
		}
		case '2':{
			char nama[50]; //array nama dengan maksimum 50 nama
			system("cls"); //Clearscreen untuk transisi UI
			gotoxy(25,4); //menampilkan output print dibawah pada kordinat x=25 dan y=4
			printf("===== Cari berdasarkan Nama ====="); //mengeluarkan tulisan berupa -Cari Berdasarkan Nama-
			gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
			printf("Masukkan Nama: "); //mengeluarkan tulisan berupa -Masukan Nama :-
			scanf("%s",nama); //meminta user memasukan input (string) nama mahasiswa

			int d=0; //deklarasi d yang akan digunakan untuk membantu kordinat y
			while(fread(&data,sizeof(data),1,fp)==1){
				if(strcmp(data.name,(nama))==0){ //stringcompare membanding string dari data pada data.name dengan nama mahasiswa
					gotoxy(20,d+7); //menampilkan output print dibawah pada kordinat x=20 dan y=d+7
					printf("Data ditemukan\n"); //mengeluarkan tulisan berupa -Data ditemukan-
					gotoxy(20,d+8); //menampilkan output print dibawah pada kordinat x=20 dan y=d+8
					printf("NPM:%d",data.npm); //menampilkan NPM : "no.NPM" diambil dari data.npm
					gotoxy(20,d+10); //menampilkan output print dibawah pada kordinat x=20 dan y=d+10
					printf("Nama:%s",data.name); //menampilkan Nama : "nama mahasiswa" diambil dari data.name
					gotoxy(20,d+11); //menampilkan output print dibawah pada kordinat x=20 dan y=d+11
					printf("Kontak:%d ",data.contact); //menampilkan Kontak : "kontak mahasiswa" diambil dari data.contact
					gotoxy(20,d+14); //menampilkan output print dibawah pada kordinat x=20 dan y=d+14
					getch();
					d+=6;
				}
			}
			if(d==0){
				printf("\aData tidak ditemukan"); //mengeluarkan tulisan berupa -Data tak ditemukan-
			}
			gotoxy(20,d+11); //menampilkan output print dibawah pada kordinat x=20 dan y=d+11
			printf("Ingin mencari lagi?(y=Ya, lainnya=tidak)"); //mengeluarkan tulisan berupa -Ingin mencari lagi?(y=Ya, lainnya=tidak)-
			if(getch()=='y'){
				search(); //akan langsung menjalankan program search()
			}
			else{
				mainmenu(); //akan langsung menjalankan program mainmenu()
			}
			break;
		}
		default :{
			printf("Pilihan salah, masukkan pilihan yang tepat"); //mengeluarkan tulisan berupa -Pilihan salah, masukkan pilihan yang tepat-
			getch(); //menunggu user memasukan input apapun untuk berpindah ke program selanjutnya
			search(); //akan langsung menjalankan program search()
		}
	}
	fclose(fp); //menutup dokumen
}


void hapus(){
	int npm4; //deklarasi npm4 sebagai data
	char hapus = 'y';
	while(hapus=='y'){
		system("cls");//Clearscreen untuk transisi UI
		gotoxy(10,5); //menampilkan output print dibawah pada kordinat x=10 dan y=5
		printf("NPM yang akan dihapus:"); //mengeluarkan tulisan berupa -NPM yang akan dihapus-
		scanf("%d",&npm4); //meminta user untuk memasukan input dan dijadikan sebagai nilai dari &npm4
		fp=fopen("stf.dat","rb+"); //membuka dokumen stf.dat
		rewind(fp);
		while(fread(&data,sizeof(data),1,fp)==1){
			if(data.npm==npm4){
				gotoxy(10,7); //menampilkan output print dibawah pada kordinat x=10 dan y=7
				printf("Data NPM ditemukan"); //mengeluarkan tulisan berupa -Data NPM ditemukan-
				gotoxy(10,8); //menampilkan output print dibawah pada kordinat x=10 dan y=8
				printf("Nama: %s",data.name); //menampilkan Nama : "nama mahasiswa" diambil dari data.name
				gotoxy(10,9); //menampilkan output print dibawah pada kordinat x=10 dan y=9
				cari='t';
			}
		}
		if(cari!='t'){
			gotoxy(10,10); //menampilkan output print dibawah pada kordinat x=10 dan y=10
			printf("Data NPM tidak ditemukan"); //mengeluarkan tulisan berupa -Data NPM tidak ditemukan-
			if(getch()){
				submenu1(); //akan langsung menjalankan program submenu1()
			}
		}
		if(cari=='t'){
			gotoxy(10,10); //menampilkan output print dibawah pada kordinat x=10 dan y=10
			printf("Hapus data NPM ?(y=Ya, lainnya=tidak)"); //mengeluarkan tulisan berupa -Hapus data NPM ?(y=Ya, lainnya=tidak)-
			gotoxy(10,11); //menampilkan output print dibawah pada kordinat x=10 dan y=11
			printf("Pilihan: "); //mengeluarkan tulisan berupa -Pilihan :-
			if(getch()=='y'){
				ft=fopen("dlt.dat","wb+"); //membuka dlt.dat dan dapat write di dokumen tersebut
				rewind(fp);
				while(fread(&data,sizeof(data),1,fp)==1){
					if(data.npm!=npm4){
						fseek(ft,0,SEEK_CUR); //meletakkan pointer tanpa merubah posisinya
						fwrite(&data,sizeof(data),1,ft);
					}
				}
				fclose(ft); //menutup dokumen dlt.dat
				fclose(fp); //menutup dokumen stf.dat
				remove("stf.dat"); //meremove stf.dat
				rename("dlt.dat","stf.dat");//mengganti namanya menjadi file dlt.dat
				fp=fopen("stf.dat","rb+"); //membuka stf.dat
				gotoxy(10,11); //menampilkan output print dibawah pada kordinat x=10 dan y=11
				printf("Data telah dihapus"); //mengeluarkan tulisan berupa -Data telah dihapus-
				gotoxy(10,15); //menampilkan output print dibawah pada kordinat x=10 dan y=15
				printf("Hapus data lainnya? (y=Ya, lainnya=tidak)"); //mengeluarkan tulisan berupa -Hapus data NPM ?(y=Ya, lainnya=tidak)-
				gotoxy(10,16); //menampilkan output print dibawah pada kordinat x=10 dan y=16
				printf("Pilihan: "); //mengeluarkan tulisan berupa -Pilihan :-
				hapus=getch();
			}
			else{
				mainmenu(); //akan langsung menjalankan program mainmenu()
				fflush(stdin);
				hapus=getch();
			}
		}
	}
	gotoxy(10,15); //menampilkan output print dibawah pada kordinat x=10 dan y=15
	mainmenu(); //akan langsung menjalankan program mainmenu()
}

void edit(){
	system("cls"); //Clearscreen untuk transisi UI
	int c=0; //deklarasi nilia c=0
	int npm5,e; //deklarasi npm5 dan 3
	gotoxy(20,4); //menampilkan output print dibawah pada kordinat x=20 dan y=4
	printf("===== Edit Data ====="); //mengeluarkan tulisan berupa -Edit Data-
	system("cls"); //Clearscreen untuk transisi UI
	gotoxy(15,6); //menampilkan output print dibawah pada kordinat x=15 dan y=6
	printf("NPM data yang ingin diedit:"); //mengeluarkan tulisan berupa -NPM data yang ingin diedit:-
	scanf("%d",&npm5); //meminta user memasukan input yang akan dijadikan nilai npm5
	fp=fopen("stf.dat","rb+"); //untuk membuka dokumen stf.dat dan dapat membaca dan menulis di dokumen tersebut
	while(fread(&data,sizeof(data),1,fp)==1){
		if(checknpm(npm5)==0){
			gotoxy(15,7); //menampilkan output print dibawah pada kordinat x=15 dan y=7
			printf("Data NPM ditemukan"); //mengeluarkan tulisan berupa -Data NPM ditemukan-
			gotoxy(15,8); //menampilkan output print dibawah pada kordinat x=15 dan y=8
			printf("NPM:%d",data.npm); //meminta data berupa npm dan disimpan dalam &data.npm
			gotoxy(15,9); //menampilkan output print dibawah pada kordinat x=15 dan y=9
			printf("Nama Baru:"); //mengeluarkan tulisan berupa -Nama Baru-
			scanf("%s",data.name); //meminta data berupa nama dan disimpan dalam &data.name
			gotoxy(15,10); //menampilkan output print dibawah pada kordinat x=15 dan y=10
			printf("Kontak Baru:"); //mengeluarkan tulisan berupa -Kontak Baru:-
			scanf("%d",&data.contact); //meminta data berupa kontak dan disimpan dalam &data.contact
			gotoxy(15,12); //menampilkan output print dibawah pada kordinat x=15 dan y=12
			printf("Data telah diubah"); //mengeluarkan tulisan berupa -Data telah diubah-
			fseek(fp,ftell(fp)-sizeof(data),0);//meletakkan pointer pada file
			fwrite(&data,sizeof(data),1,fp);//print data pada file
			fclose(fp);//menutup file
			c=1;
		}
		if(c==0){
			gotoxy(15,9); //menampilkan output print dibawah pada kordinat x=15 dan y=9
			printf("Data NPM tidak ditemukan"); //mengeluarkan tulisan berupa -Data NPM tidak ditemukan-
		}
	}
	fflush(stdin);//bila input tidak sesuai permintaan
	getch() ; //menunggu user untuk memberi input apapun untuk berpindah ke program selanjutnya
	kembali(); //akan langsung menjalankan program kembali()
}

void absensi(){
	system("cls"); //clearscreen untuk transisi UI
	int d, k; //deklari d dan k
	gotoxy(20,3); //menampilkan output print dibawah pada kordinat x=20 dan y=3
	printf("============================== ABSENSI ==============================");
	gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=120 dan y=5
	printf("Masukkan NPM: "); //mengeluarkan tulisan berupa -Masukan NPM:-
	fp=fopen("stf.dat","rb+"); //untuk membuka dokumen stf.dat dan rb+ digunakan untuk dapat membaca/read dokumen
	scanf("%d",&d); //meminta user untuk memasukan npm untuk absen
	time_t t;
	time(&t);
	strcpy(log,ctime(&t));
	gotoxy(20,7); //menampilkan output print dibawah pada kordinat x=20 dan y=7
	while(fread(&data,sizeof(data),1,fp)==1){
		if(data.npm==d){
			Sleep(2);
			gotoxy(20,8); //menampilkan output print dibawah pada kordinat x=20 dan y=8
			printf("Absensi telah dicatat\n"); //mengeluarkan tulisan berupa -Absensi telah dicatat:- dan tambahkan spasi
			gotoxy(20,10); //menampilkan output print dibawah pada kordinat x=20 dan y=10
			printf("Nama: %s",data.name); //Menampilkan nama mahasiswa diambil dari data.name
			gotoxy(20,12); //menampilkan output print dibawah pada kordinat x=20 dan y=12
			printf("Date and time: %s\n",log); //menampilkan data tanggal dan waktu absen
			fs=fopen("abs.dat", "ab+"); //membuka dokumen abs.dat dan ab+ dapat membaca, mengambil dan overwrite data
			k = 1;
			fseek(fs,0,SEEK_END);//meletakkan pointer pada akhir file
			fwrite(&data,sizeof(data),1,fs);
			fseek(fs,10,SEEK_CUR);//menggeser pointer sebanyak 10 bit ke kanan
			fwrite(log,sizeof(log),1,fs);//menulis waktu dan tanggal pada file
			fclose(fs); //menutup dokumen
			getch(); //menunggu user memasukan input untuk berpindah ke program selanjutnya
		}
	}
	if(k != 1){
		gotoxy(20, 10); //menampilkan output print dibawah pada kordinat x=20 dan y=10
		printf("\aNPM tidak ditemukan"); //mengeluarkan tulisan berupa -NPM tidak ditemukan-
		getch();
	}
	fclose(fp);
	submenu2(); //akan langsung menjalankan program submenu2()
}

void viewabsence(){
	int j=9; //baris dengan nilai kordinat j atau y = 9
	system("cls"); //Clearscreen untuk transisi UI
	gotoxy(10,5); //menampilkan output print dibawah pada kordinat x=10 dan y=5
	printf("=================================== List Absensi ==================================="); //mengeluarkan tulisan berupa -List Absensi-
	gotoxy(15,8); //menampilkan output print dibawah pada kordinat x=15 dan y=8
	printf("NPM =================== NAMA ================== KONTAK ============ WAKTU ============"); //mengeluarkan tulisan berupa -NPM,NAMA,Kontak,WAKTU- dalam 1 baris
	fs=fopen("abs.dat","rb");
	while(fread(&data,sizeof(data),1,fs)==1){
		gotoxy(15,j); //menampilkan output print dibawah pada kordinat x=15 dan y=j(satu baris)
		printf("%d",data.npm); //menampilkan npm diambil data.npm
		gotoxy(35,j); //menampilkan output print dibawah pada kordinat x=35 dan y=j(satu baris)
		printf("%s",data.name); //menampilkan nama diambil data.nama
		gotoxy(63,j); //menampilkan output print dibawah pada kordinat x=63 dan y=j(satu baris)
		printf("%d",data.contact); //menampilkan kontak diambil data.contact
		gotoxy(75,j);//menampilkan output print dibawah pada kordinat x=75 dan y=j(satu baris)
		fread(log,sizeof(log),1,fs); //membaca data tanggal dan waktu
		printf("%s",log); //menampilkan waktu absen
		gotoxy(85,j); //menampilkan output print dibawah pada kordinat x=85 dan y=j(satu baris)
		printf("\n\n"); //memberi 2x spasi
		j++; //menambahkan data selanjutnya pada baris baru
	}
	fclose(fs);
	kembali(); //akan langsung menjalankan program kembali()
}

void hapusabsen(){
	Password(); //akan menjalankan program password() yang terdapat di library password.h
	system("cls"); //Clearscreen untuk Transisi UI
	printf("\n\n ANDA YAKIN AKAN MENGHAPUS DATA ABSENSI?(y=Ya, lainnya=tidak)"); //memberi 2x spasi dan mengeluarkan tulisan berupa -ANDA YAKIN AKAN MENGHAPUS DATA ABSENSI?(y=Ya, lainnya=tidak)-
	printf("\n Pilihan: "); //memberi 1x spasi lalu mengeluarkan tulisan berupa -Pilihan:-
	if(getch()=='y'){
		remove("abs.dat");//menghapus data
		printf("\n\n Data telah terhapus"); //memberi 2x spasi dan mengeluarkan tulisan berupa -Data telah terhapus-
		getch();
		mainmenu(); //akan langsung menjalankan program mainmenu()
	}
	else{
		printf("\n\n :)");
		getch();
		submenu2(); //akan langsung menjalankan program submenu2()
	}
}

void kembali(){
	gotoxy(15,26); //menampilkan output print dibawah pada kordinat x=15 dan y=26
	printf("Tekan ENTER untuk kembali ke Menu Utama"); //mengeluarkan tulisan berupa -Tekan ENTER untuk kembali ke Menu Utama-
	a:
	if(getch()==13){ //untuk mendeteksi apakah user menekan enter atau tidak, apabila ya
		mainmenu(); //langsung menjalankan program mainmenu()
	}
	else{
		goto a;
	}
}

int waktu(){
	time_t t;
	time(&t);//meminta waktu realtime
	printf("Date and time: %s\n",ctime(&t)); //menampilkan waktu dan tanggal realtime
	return 0 ;
}

int help(){
	system("cls"); //clearscreen untuk transisi UI
	gotoxy(20,3);//menampilkan output print dibawah pada kordinat x=20 dan y=3
	printf("\t\tBANTUAN");
	gotoxy(20,4);//menampilkan output print dibawah pada kordinat x=20 dan y=4
	printf("==============================\n");
	gotoxy(14,5);//menampilkan output print dibawah pada kordinat x=14 dan y=5
	printf("Aplikasi ini berfungsi untuk absensi kelas\n\n");
	gotoxy(14,6);//menampilkan output print dibawah pada kordinat x=14 dan y=6
	printf("Cara Menggunakan:\n\n[1]Pilih Mulai\n[2]Pilih Menu:\n\n\t[1]DATA, untuk memasukkan data kelas\n\t[2]ABSENSI, untuk mengisi absensi\n");
	gotoxy(14,14);//menampilkan output print dibawah pada kordinat x=14 dan y=14
	printf("Menu DATA:\n\t\t[1]Tambah Data, untuk menambah data kelas\n\t\t[2]Lihat Data, untuk melihat daftar data kelas\n\t\t[3]Cari Data, untuk mencari info data kelas\n\t\t[4]Ubah Data, untuk menghapus maupun merubah informasi data kelas\n\t\t[5]Kembali ke menu utama");
	gotoxy(14,21);//menampilkan output print dibawah pada kordinat x=14 dan y=21
	printf("Menu ABSENSI:\n\t\t[1]Absensi, untuk mengisi absensi kelas\n\t\t[2]Lihat Absensi, untuk melihat daftar hadir kelas\n\t\t[3]Kembali ke menu utama");
	gotoxy(1,26);//menampilkan output print dibawah pada kordinat x=1 dan y=26
	printf("Format Nama = Namadepan_Namatengah_Namabelakang");
	gotoxy(1,27);//menampilkan output print dibawah pada kordinat x=1 dan y=27
	printf("Contoh: Joseph_Elroy_Manurung");
	getch(); //memberi waktu user untuk membaca petunjuk dengan menunggu user untuk memasukan input dan lanjut ke program selanjutnya
	system("cls"); //Clearscreen untuk transisi UI
	return main(); //kembali ke program main()
}

void keluar(){
	system("cls"); //clearscreen untuk transisi UI
	gotoxy(16,3); //menampilkan output print dibawah pada kordinat x=16 dan y=3
    printf("Terimakasih Sudah menggunakan Program ini"); //mengeluarkan tulisan berupa -Terimakasih Sudah menggunakan Program ini-
	gotoxy(16,7); //menampilkan output print dibawah pada kordinat x=16 dan y=7
	printf("Keluar dalam 5 detik........>"); //mengeluarkan tulisan berupa -keluar dalam 5 detik-
	delay(5000); //memberi waktu delay atau tunggu sebelum masuk ke program exit()
	exit(0); //keluar dari program
}

int main(){
	system("cls"); //Clearscreen untuk transisi UI
	system("color f0"); //memberi warna putih pada terminal
    char pilihan;
        gotoxy(20,5); //menampilkan output print dibawah pada kordinat x=20 dan y=5
	    printf("============== Sistem Absensi Kelas"); //mengeluarkan tulisan berupa -Sistem Absensi kelas-
	    printf(" =============="); //agar UI terlihat lebih rapi dan bagus
	    gotoxy(20,9); //menampilkan output print dibawah pada kordinat x=20 dan y=9
	    printf("===== 1. Start"); //mengeluarkan tulisan berupa -1. Start-
	    gotoxy(20,14); //menampilkan output print dibawah pada kordinat x=20 dan y=14
	    printf("===== 9. Help"); //mengeluarkan tulisan berupa -9. Help-
	    gotoxy(20,16); //menampilkan output print dibawah pada kordinat x=20 dan y=16
	    printf("===== 0. Keluar Aplikasi"); //mengeluarkan tulisan berupa -0. Keluar Aplikasi-
	    gotoxy(20,18); //menampilkan output print dibawah pada kordinat x=20 dan y=18
        printf("Pilihan: "); //mengeluarkan tulisan berupa -Pilihan: -
        switch(getch()){
		case '1': //apabila user memilih 1
			mainmenu(); //akan langsung menjalankan program mainmenu()
		break;
		case '9': //apabila user memilih 9
            help(); //akan langsung menjalankan program help()
        break;
        case '0': //apabila user memilih 0
        	keluar(); //akan langsung menjalankan program keluar()
        	break;
        default:{ //apabila user memilih selain 1,9 dan 0
        	gotoxy(10,23); //menampilkan output print dibawah pada kordinat x=10 dan y=23
	        printf("\aPilihan Salah!!Masukkan pilihan yang tepat!"); //mengeluarkan tulisan berupa -Pilihan Salah!!Masukkan pilihan yang tepat!-
	        if(getch()) //menunggu user untuk memberikan input dan lanjut ke program pada baris selanjutnya
	        system("cls"); //clearscreen untuk transisi UI
	        main(); //kembali menjalankan program main
        }
    }
    return 0;
}
