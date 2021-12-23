/*
	Jody Yuantoro ( 2021-147 )
	Informatics Engineering, Faculty of Engineering
	University of Muhammadiyah Malang
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int pil_menu, jmlh_mhs, list;
char nim[99]; char db_nim[99]; char db_nama[99]; char nama_blkng[99]; char db_kelas[99]; char db_dosen[99];
FILE *db_main, *db_main_r, *db_main_w;
bool duplicate, available, sc;

void uppercase(char *db){
    for(int i = 0; db[i]!='\0'; i++){
        if(db[i] >= 'a' && db[i] <= 'z'){
            db[i] = db[i] -32;
        }
    }
}

void check_special_char(char *db){
    char str, db_check[99];
    sc = false;
    strcpy(db_check, db);
    for(int i = 0, j = 0; str = db_check[i] = db_check[j]; j++){
        if(str >= 32 && str <= 47 ||  str >= 58 && str <= 63){
            i++;
            sc = true;
        }
    }
}

int main(){

	system("cls");
    printf("\n\n\n\nSistem Pendataan Akun I-Lab Infotech");
	printf("\n\nLoading");
	Sleep(500); printf(" _"); Sleep(500); printf("_"); Sleep(500); printf("___"); Sleep(500); printf("_______"); Sleep(500); printf("___");

    menu:
    system("cls");
    time_t localtime;
	time(&localtime);
    printf("\n Sistem Pendataan Akun I-Lab Infotech");
    printf("\n Database Time : %s\n", ctime(&localtime));
    printf(" === Pilihan Menu ===\n\n");
    printf(" 1. Create Data.\n 2. Show Data.\n 3. Update Data.\n 4. Delete Data.\n 5. Search Data.\n 6. Exit.");
    printf("\n\n Masukkan Pilihan : "); scanf("%d" ,&pil_menu); 
    switch (pil_menu){
    case 1:
        system("cls");

        db_main = fopen("mhs.db", "a");
        db_main_r = fopen("mhs.db", "r");
        duplicate = false;

        printf(" === Create Data ===\n");
        printf("\n Input NIM Praktikan\t\t\t: "); fflush(stdin); scanf("%[^\n]" , nim);
        
        while(fscanf(db_main_r, "%[^;];%[^;];%[^;];%[^\n]\n", db_nim, db_nama, db_kelas, db_dosen) != EOF){
            if(strcmp(db_nim, nim) == 0){
                duplicate = true;
            } else {
                check_special_char(nim);
            }
        }

        if(sc == false){
            if(duplicate == false){
                strcpy(db_nim, nim);
                printf("\n Input Nama Depan Praktikan\t\t: "); fflush(stdin); scanf("%[^\n]", db_nama);
                printf("\n Input Nama Belakang Praktikan\t\t: "); fflush(stdin); scanf("%[^\n]", nama_blkng); strcat(db_nama, nama_blkng);
                printf("\n Input Kelas Pemrograman Dasar\t\t: "); fflush(stdin); scanf("%[^\n]" , db_kelas); uppercase(db_kelas);
                printf("\n Input Nama Dosen Pengampu\t\t: "); fflush(stdin); scanf("%[^\n]" , db_dosen);
            
                fprintf(db_main,"%s;", db_nim);
                fprintf(db_main,"%s;", db_nama);
                fprintf(db_main,"%s;", db_kelas);
                fprintf(db_main,"%s\n", db_dosen);      
                printf("\n --------------------\n");
                printf("\n Data Berhasil di Tambah.\n");
                printf("\n --------------------\n");
            } else {
                printf("\n --------------------\n");
                printf("\n Inputan NIM Terdeteksi Duplikat.\n");
                printf("\n --------------------\n");
            }
        } else {
            printf("\n --------------------\n");
            printf("\n Inputan NIM tidak diperbolehkan\n");
            printf(  " menggunakan simbol.\n");
            printf("\n --------------------\n");
        }

        fclose(db_main); fclose(db_main_r);
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 2:
        system("cls");
        
        int no_urut = 0;
        db_main_r = fopen("mhs.db", "r");

        printf("\n === List Data ===\n\n");
        while (fscanf(db_main_r, "%[^;];%[^;];%[^;];%[^\n]\n", db_nim, db_nama, db_kelas, db_dosen) != EOF){
            no_urut++;
            printf(" == %d ==", no_urut);
            printf("\n\n NIM Praktikan\t\t\t: %s", db_nim);
            printf("\n\n Nama Praktikan\t\t\t: %s", db_nama);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas);
            printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen);
            printf("\n\n --------------------------------------------------------\n\n");
        }

        fclose(db_main_r);
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 3:
        system("cls");

        db_main_r = fopen("mhs.db", "r");
        db_main_w = fopen("mhs_temp.db", "w");
        available = false;

        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",nim);
        while(fscanf(db_main_r, "%[^;];%[^;];%[^;];%[^\n]\n", db_nim, db_nama, db_kelas, db_dosen) != EOF){
            if(strcmp(db_nim, nim) == 0){
                available = true;
                printf("\n Nama Depan Baru\t\t\t: "); fflush(stdin); scanf("%[^\n]", db_nama);
                printf("\n Nama Belakang Baru\t\t\t: "); fflush(stdin); scanf("%[^\n]", nama_blkng); strcat(db_nama, nama_blkng);
                printf("\n Kelas Baru\t\t\t: "); fflush(stdin); scanf("%[^\n]", db_kelas); uppercase(db_kelas);
                printf("\n Dosen Pengampu Baru\t\t: "); fflush(stdin); scanf("%[^\n]", db_dosen);

                fprintf(db_main_w,"%s;", db_nim);
                fprintf(db_main_w,"%s;", db_nama);
                fprintf(db_main_w,"%s;", db_kelas);
                fprintf(db_main_w,"%s\n", db_dosen);  
                
                printf("\n --------------------\n");
                printf("\n Data Berhasil di Edit.\n");
                printf("\n --------------------\n");
            
            } else {
                fprintf(db_main_w,"%s;", db_nim);
                fprintf(db_main_w,"%s;", db_nama);
                fprintf(db_main_w,"%s;", db_kelas);
                fprintf(db_main_w,"%s\n", db_dosen);
            }
        }

        if(available == false){
            printf("\n --------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------\n");
        }

        fclose(db_main_r); fclose(db_main_w);
        remove("mhs.db");
        rename("mhs_temp.db", "mhs.db");
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 4:
        system("cls");

        db_main_r = fopen("mhs.db", "r");
        db_main_w = fopen("mhs_temp.db", "w");
        available = false;

        printf(" === Delete Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        while(fscanf(db_main_r, "%[^;];%[^;];%[^;];%[^\n]\n", db_nim, db_nama, db_kelas, db_dosen) != EOF){
            if(strcmp(db_nim, nim) != 0){
                fprintf(db_main_w,"%s;", db_nim);
                fprintf(db_main_w,"%s;", db_nama);
                fprintf(db_main_w,"%s;", db_kelas);
                fprintf(db_main_w,"%s\n", db_dosen);
            } else {
            }
        }

        fclose(db_main_r); fclose(db_main_w);
        remove("mhs.db");
        rename("mhs_temp.db", "mhs.db");
        printf("\n\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 5:
        system("cls");

        db_main_r = fopen("mhs.db", "r");
        available = false;

        printf(" === Search Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        while(fscanf(db_main_r, "%[^;];%[^;];%[^;];%[^\n]\n", db_nim, db_nama, db_kelas, db_dosen) != EOF){
            if(strcmp(db_nim, nim) == 0){
                available = true;
                printf("\n\n NIM Praktikan\t\t\t: %s", db_nim);
                printf("\n\n Nama Praktikan\t\t\t: %s", db_nama);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas);
                printf("\n\n Dosen Pengampu\t\t\t: %s\n", db_dosen);
            }
        }

        if(available == false){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        }

        fclose(db_main_r);
        printf("\n\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 6:
        return(0);
    default:
        system("cls");
        printf(" Inputan anda salah...\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;
    }
}