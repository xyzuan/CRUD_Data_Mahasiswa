#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int pil_menu;
int loop = 1;
char nim_loop;
char db_nim[][10], db_nama[][20], db_kelas[][20], db_dosen[][20];

void main(){

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
        printf("\n Input NIM Praktikan\t\t\t: "); scanf("%s" ,db_nim[loop]);
        printf("\n Input Nama Praktikan\t\t\t: "); scanf("%s", db_nama[loop]);
        printf("\n Input Kelas Pemrograman Dasar\t\t: "); scanf("%s" ,db_kelas[loop]);
        printf("\n Input Nama Dosen Pengampu\t\t: "); scanf("%s" ,db_dosen[loop]);
        loop = loop + 1;

        printf("\n --------------------\n");
        printf(" Data Berhasil Di Tambah.\n");
        printf("\n --------------------\n");

        goto menu;
        break;
    case 2:
        system("cls");
        printf(" === List Data ===\n\n");
        for(int list = 1; list < loop; list++){
            printf(" == %d ==", list);
            printf("\n\n NIM Praktikan\t\t\t: %s", db_nim[list]);
            printf("\n\n Nama Praktikan\t\t\t: %s", db_nama[list]);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas[list]);
            printf("\n\n Dosen Pengampu\t\t\t: %s", db_dosen[list]);
            printf("\n\n --------------------\n\n");
        }
        break;
    case 3:
        system("cls");
        printf(" === Update Data ===\n\n");
        break;
    case 4:
        system("cls");
        int inpt_del;
        printf(" === Delete Data ===\n\n");
        printf("\n\n Masukkan NIM Praktikan yang Ingin di Delete Data nya : "); scanf("%s", inpt_del);
        for()

        break;
    case 5:
        system("cls");
        printf(" === Search Data ===\n\n");
        break;
    default:
        break;
    }

}