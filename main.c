#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

int pil_menu;
int jmlh_mhs, list, d;
char nim_jmlh_inpt, pil_update[10];
char db_nim['0'][99], db_nama['0'][99], db_kelas['0'][99], db_dosen['0'][99];
bool unavailable = false;

int main(){

    menu:
    system("cls");
    printf(" Sistem Pendataan Akun I-Lab Infotech\n\n");
    printf(" === Pilihan Menu ===\n\n");
    printf(" 1. Create Data.\n 2. Show Data.\n 3. Update Data.\n 4. Delete Data.\n 5. Search Data.\n 6. Exit.");
    printf("\n\n Masukkan Pilihan : "); scanf("%d" ,&pil_menu); 
    switch (pil_menu){
    case 1:
        system("cls");
        jmlh_mhs = jmlh_mhs + 1;
        printf(" === Create Data ===\n");
        printf("\n Input NIM Praktikan\t\t\t: "); scanf(" %[^\n]s" ,db_nim[jmlh_mhs]);
        printf("\n Input Nama Praktikan\t\t\t: "); scanf(" %[^\n]s", db_nama[jmlh_mhs]);
        printf("\n Input Kelas Pemrograman Dasar\t\t: "); scanf(" %[^\n]s" ,db_kelas[jmlh_mhs]);
        printf("\n Input Nama Dosen Pengampu\t\t: "); scanf(" %[^\n]s" ,db_dosen[jmlh_mhs]);
        printf("\n --------------------\n");
        printf("\n Data Berhasil di Tambah.\n");
        printf("\n --------------------\n");
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;        
        break;
    case 2:
        system("cls");
        printf("\n === List Data ===\n\n");
        if( jmlh_mhs < 1){
            printf(" Data Tidak Tersedia.");
        } else {
            list = 1;
            while(list<=jmlh_mhs){
                printf(" == %d ==", list);
                printf("\n\n NIM Praktikan\t\t\t: %s", db_nim[list]);
                printf("\n\n Nama Praktikan\t\t\t: %s", db_nama[list]);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas[list]);
                printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen[list]);
                printf("\n\n --------------------\n\n");
                list++;
            }
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
        break;
    case 3:
        system("cls");
        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",pil_update);
        list=1; d=0;
        while(list<=jmlh_mhs && d==0){
            if(strcmp(pil_update,db_nim[list])==0){
                d++;
            }
            list++;
        }
        if(d<1){
            printf(" Data yang akan anda update mungkin tidak ada");
        }else{
            list--;
            printf("\n Nama Baru\t\t\t: "); scanf(" %[^\n]s", db_nama[list]);
            printf("\n Kelas Baru\t\t\t: "); scanf(" %[^\n]s", db_kelas[list]);
            printf("\n Dosen Pengampu Baru\t\t: "); scanf(" %[^\n]s", db_dosen[list]);
        }
        printf("\n --------------------\n");
        printf("\n Data Berhasil di Edit.\n");
        printf("\n --------------------\n");
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;

    case 4:
        system("cls");
        printf(" === Delete Data ===\n\n");
        printf("\n\n Masukkan NIM Praktikan yang Ingin di Delete Data nya : "); scanf("%s",pil_update);
        list=1; d=0;
        while(list<=jmlh_mhs && d==0){
            if(strcmp(pil_update,db_nim[list])==0){
                d++;
            }
            list++;
        }
        if(d<1){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        }else{
            list--;
            while(list<=jmlh_mhs){
                strcpy(db_nim[list],db_nim[list+1]);
                strcpy(db_nama[list],db_nama[list+1]);
                strcpy(db_kelas[list],db_kelas[list+1]);
                strcpy(db_dosen[list],db_dosen[list+1]);
                list++;
            } 
            list--;
            strcpy(db_nim[list],""); jmlh_mhs--;
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Hapus.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
    case 5:
        system("cls");
        printf(" === Search Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", pil_update);
        while(list <= jmlh_mhs && d == 0){
            if(strcmp(pil_update,db_nim[list]) == 0){
                d++;
            }
            list++;
        }
        if( d < 1 ){
            printf(" Data Tidak Ditemukan");
        } else {
            list--;
            printf("\n\n Nama Praktikan\t\t\t: %s", db_nama[list]);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas[list]);
            printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen[list]);
        }
        printf("\n\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
        break;
    default:
        break;
    }

}