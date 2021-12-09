#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

int pil_menu, jmlh_mhs, list;
char nim_jmlh_inpt, nim[99], db_nim['0'][99], db_nama['0'][99], db_kelas['0'][99], db_dosen['0'][99];
bool duplicate, found;

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
        printf(" === Create Data ===\n");
        printf("\n Input NIM Praktikan\t\t\t: "); scanf(" %[^\n]s" , nim);
        duplicate = false;
        for(int i = 0; i < jmlh_mhs; i++){
            if(strcmp(db_nim[i], nim) == 0){
                duplicate = true;
            }
        }
        if (strlen(nim) > 10){
            printf("\n --------------------\n");
            printf("\n Inputan NIM tidak boleh melebihi 10 karakter.\n");
            printf("\n --------------------\n");
            printf(" Tekan enter untuk kembali ke menu...");
            getch(); goto menu;
        }
        if(duplicate == false){
            printf("\n Input Nama Praktikan\t\t\t: "); scanf(" %[^\n]s", &db_nama[jmlh_mhs]);
            printf("\n Input Kelas Pemrograman Dasar\t\t: "); scanf(" %[^\n]s" , &db_kelas[jmlh_mhs]);
            printf("\n Input Nama Dosen Pengampu\t\t: "); scanf(" %[^\n]s" , &db_dosen[jmlh_mhs]);
            strcpy(db_nim[jmlh_mhs], nim); jmlh_mhs++;
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Tambah.\n");
            printf("\n --------------------\n");
        } else {
            printf("\n --------------------\n");
            printf("\n Inputan NIM Terdeteksi Duplikat.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 2:
        system("cls");
        printf("\n === List Data ===\n\n");
        if( jmlh_mhs >= 1){
            for(list = 0; list < jmlh_mhs; list++){
                printf(" == %d ==", list + 1);
                printf("\n\n NIM Praktikan\t\t\t: %s", db_nim[list]);
                printf("\n\n Nama Praktikan\t\t\t: %s", db_nama[list]);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas[list]);
                printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen[list]);
                printf("\n\n --------------------\n\n");
            }
        } else {
            printf(" --------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 3:
        system("cls");
        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",nim);
        list=0; found = false;
        while(list < jmlh_mhs && found == false){
            if(strcmp(nim,db_nim[list]) == 0){
                found = true;
            }   list++;
        }
        if(found == false){
            printf("\n --------------------\n");
            printf("\n Data yang akan di update tidak tersedia\n");
            printf("\n --------------------\n");
        } else {
            list--;
            printf("\n Nama Baru\t\t\t: "); scanf(" %[^\n]s", db_nama[list]);
            printf("\n Kelas Baru\t\t\t: "); scanf(" %[^\n]s", db_kelas[list]);
            printf("\n Dosen Pengampu Baru\t\t: "); scanf(" %[^\n]s", db_dosen[list]);
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Edit.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;

    case 4:
        system("cls");
        printf(" === Delete Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Delete Data nya : "); scanf("%s",nim);
        found = false; list = 0;
        while(list < jmlh_mhs && found == false){
            if(strcmp(nim,db_nim[list]) == 0){
                found = true;
            }   list++;
        }
        if(found == false){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        } else {
            list--;
            for(list = list; list <= jmlh_mhs; list++){
                strcpy(db_nim[list], db_nim[list+1]);
                strcpy(db_nama[list],db_nama[list+1]);
                strcpy(db_kelas[list],db_kelas[list+1]);
                strcpy(db_dosen[list],db_dosen[list+1]);
            }
            list--; strcpy(db_nim[list],""); jmlh_mhs--;
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Hapus.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 5:
        system("cls");
        printf(" === Search Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        found = false; list = 0;
        while(list < jmlh_mhs && found == false){
            if(strcmp(nim,db_nim[list]) == 0){
                found = true;
            }   list++;
        }
        if(found == false){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        } else {
            list--;
            printf("\n Nama Praktikan\t\t\t: %s", db_nama[list]);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas[list]);
            printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen[list]);
            printf("\n\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 6:
        return(0);
    default:
        system("cls");
        printf(" Inputan anda salah...\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;
    }
}