#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

int pil_menu;
int jmlh_mhs, list, d;
char nim_jmlh_inpt, pil_update[10];
char nim[99];
bool duplicate = false;
struct db_mhs{
    char nim[99];
    char nama[99];
    char kelas[99];
    char dosen[99];
}; 

int main(){
    struct db_mhs db_main[99];
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
            if(strcmp(db_main[i].nim, nim) == 0){
                duplicate = true;
            }
        }
        if(duplicate == false){
            strcpy(db_main[jmlh_mhs].nim, nim);
            printf("\n Input Nama Praktikan\t\t\t: "); scanf(" %[^\n]s", &db_main[jmlh_mhs].nama);
            printf("\n Input Kelas Pemrograman Dasar\t\t: "); scanf(" %[^\n]s" , &db_main[jmlh_mhs].kelas);
            printf("\n Input Nama Dosen Pengampu\t\t: "); scanf(" %[^\n]s" , &db_main[jmlh_mhs].dosen);
            jmlh_mhs++;
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Tambah.\n");
            printf("\n --------------------\n");
        } else if (duplicate == true){
            printf("\n --------------------\n");
            printf("\n Inputan NIM Terdeteksi Duplikat.\n");
            printf("\n --------------------\n");
        } else if (strlen(db_main[jmlh_mhs].nim) >= 10){
            printf("\n --------------------\n");
            printf("\n Inputan NIM tidak boleh melebihi 10 karakter.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;        
        break;
    case 2:
        system("cls");
        printf("\n === List Data ===\n\n");
        if( jmlh_mhs >= 1){
            for(list = 0; list < jmlh_mhs; list++){
                printf(" == %d ==", list + 1);
                printf("\n\n NIM Praktikan\t\t\t: %s", db_main[list].nim);
                printf("\n\n Nama Praktikan\t\t\t: %s", db_main[list].nama);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", db_main[list].kelas);
                printf("\n\n Dosen Pengampu\t\t\t: %s", db_main[list].dosen);
                printf("\n\n --------------------\n\n");
            }
        } else {
            printf("\n --------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
        break;
    case 3:
        system("cls");
        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",pil_update);
        list=0; d=0;
        while(list < jmlh_mhs && d == 0){
            if(strcmp(pil_update,db_main[list].nim) == 0){
                d++;
            }
            list++;
        }
        if(d < 1){
            printf("\n --------------------\n");
            printf("\n Data yang akan di update tidak tersedia\n");
            printf("\n --------------------\n");
            
        } else {
            list--;
            printf("\n Nama Baru\t\t\t: "); scanf(" %[^\n]s", db_main[list].nama);
            printf("\n Kelas Baru\t\t\t: "); scanf(" %[^\n]s", db_main[list].kelas);
            printf("\n Dosen Pengampu Baru\t\t: "); scanf(" %[^\n]s", db_main[list].dosen);
            printf("\n --------------------\n");
            printf("\n Data Berhasil di Edit.\n");
            printf("\n --------------------\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;

    case 4:
        system("cls");
        printf(" === Delete Data ===\n\n");
        printf("\n\n Masukkan NIM Praktikan yang Ingin di Delete Data nya : "); scanf("%s",pil_update);
        d=0; list=0;
        while(list < jmlh_mhs && d ==0){
            if(strcmp(pil_update,db_main[list].nim) == 0){
                d++;
            }
            list++;
        }
        
        if(d < 1){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        } else {
            list--;
            for(list = list; list <= jmlh_mhs; list++){
                strcpy(db_main[list].nim, db_main[list+1].nim);
                strcpy(db_main[list].nama,db_main[list+1].nama);
                strcpy(db_main[list].kelas,db_main[list+1].kelas);
                strcpy(db_main[list].dosen,db_main[list+1].dosen);
            }
            list--;
            strcpy(db_main[list].nim,""); jmlh_mhs--;
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
        d=0; list=0;
        while(list <= jmlh_mhs && d == 0){
            if(strcmp(pil_update,db_main[list].nim) == 0){
                d++;
            }
            list++;
        }
        
        if(d < 1){
            printf("\n --------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------\n");
        } else {
            list--;
            printf("\n Nama Praktikan\t\t\t: %s", db_main[list].nama);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_main[list].kelas);
            printf("\n\n Dosen Pengampu\t\t\t: %s", db_main[list].dosen);
            printf("\n\n");
        }
        printf(" Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
        break;
    case 6:
        return(0);
    default:
        system("cls");
        printf(" Inputan anda salah...\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu;
        break;
    }

}