/*
	Jody Yuantoro ( 2021-147 )
	Informatics Engineering, Faculty of Engineering
	University of Muhammadiyah Malang
*/

char rev[99] = "rev2.0_demo";

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int pil_menu, jmlh_mhs, list;
char nim[99], db_nim[99], db_nama[99], nama_blkng[99], db_kelas[99];
FILE *db_main, *db_main_r, *db_main_w;
bool duplicate, available, sc, sc_space;

void uppercase(char *db){
    for(int i = 0; db[i]!='\0'; i++){
        if(db[i] >= 97 && db[i] <= 122){
            db[i] = db[i] -32;
        }
    }
}

void check_special_char(char *db, int type){

    /* Usage : int type 0 = Avoid all special characters
               int type 1 = Only avoid space in strings
    */

    char str, db_check[99];
    sc = false; sc_space = false;
    strcpy(db_check, db);
    if(type == 0){
        for(int i = 0, j = 0; str = db_check[j]; j++){
            if((str >= 0x21 && str <= 0x2F) ||  (str >= 0x3A && str <= 0x40) ||
               (str >= 0x5B && str <= 0x60) ||  (str >= 0x7B && str <= 0x7E)){
                sc = true;
            }
        }
    } else if ( type == 1 ){
        for(int i = 0, j = 0; str = db_check[j]; j++){
            if(str == 0x20 ){
                sc_space = true;
            }
        }
    }
}

int main(){

	system("cls");
    printf("\n\n\n\n ========================================== ");
    printf("\n == Sistem Pendataan Akun I-Lab Infotech == ");
    printf("\n ========================================== ");
	printf("\n\n Loading");
	Sleep(500); printf(" _"); Sleep(500); printf("_"); Sleep(500); printf("___"); Sleep(500); printf("_______"); Sleep(500); printf("___");
    
    menu:
    system("cls");
    time_t localtime; time(&localtime);
    printf(  " ====================================================");
    printf("\n\n  Sistem Pendataan Akun I-Lab Infotech \n");
    printf(  "\n  Software revision\t: %s\n", rev);
    printf(    "  Database Time\t\t: %s\n", ctime(&localtime));
    printf(  " ====================================================");
    printf("\n\n === Pilihan Menu ===\n\n");
    printf(" 1. Create Data.\n 2. Show Data.\n 3. Update Data.\n 4. Delete Data.\n 5. Search Data.\n 6. Exit.");
    printf("\n\n Masukkan Pilihan : "); scanf("%d" ,&pil_menu);
    switch (pil_menu){
    case 1:
        system("cls");
        db_main = fopen("mhs.db", "a"); db_main_r = fopen("mhs.db", "r");
        duplicate = false;
        printf(" === Create Data ===\n");
        printf("\n Input NIM Praktikan\t\t\t: "); fflush(stdin); scanf("%[^\n]" , nim); check_special_char(nim, 0);
        while(fscanf(db_main_r, "%[^|]|%[^|]|%[^\n]\n", db_nim, db_nama, db_kelas) != EOF){
            if(strcmp(db_nim, nim) == 0){
                duplicate = true;
            }
        }
        if(strlen(nim) == 17){
            if(sc == false){
                if(duplicate == false){
                    strcpy(db_nim, nim);
                    input_nama:
                    printf("\n Input Nama Depan Praktikan\t\t: "); fflush(stdin); scanf("%[^\n]", db_nama);
                    printf("\n Input Nama Belakang Praktikan\t\t: "); fflush(stdin); scanf("%[^\n]", nama_blkng); strcat(db_nama, nama_blkng); 
                    check_special_char(db_nama, 1);
                    if(sc_space == false){
                        printf("\n Input Kelas Pemrograman Dasar\t\t: "); fflush(stdin); scanf("%[^\n]" , db_kelas); uppercase(db_kelas);
                        fprintf(db_main,"%s|%s|%s\n", db_nim, db_nama, db_kelas);  
                        printf("\n --------------------------------------------------------\n");
                        printf("\n Data Berhasil di Tambah.\n");
                        printf("\n --------------------------------------------------------\n");
                    } else {
                        printf("\n --------------------------------------------------------\n");
                        printf("\n Inputan Nama Tidak diperbolehkan\n");
                        printf(  " menggunakan spasi.\n");
                        printf("\n --------------------------------------------------------\n");
                    }
                } else {
                    printf("\n --------------------------------------------------------\n");
                    printf("\n Inputan NIM Terdeteksi Duplikat.\n");
                    printf("\n --------------------------------------------------------\n");
                }
            } else {
                printf("\n --------------------------------------------------------\n");
                printf("\n Inputan NIM tidak diperbolehkan\n");
                printf(  " menggunakan simbol.\n");
                printf("\n --------------------------------------------------------\n");
            }
        } else {
            printf("\n --------------------------------------------------------\n");
            printf("\n Inputan NIM harus lengkap\n");
            printf(  " terdiri dari 17 karakter.\n");
            printf("\n --------------------------------------------------------\n");
        }
        fclose(db_main); fclose(db_main_r);
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 2:
        system("cls");
        int no_urut = 0; available = false;
        db_main_r = fopen("mhs.db", "r");
        printf("\n === List Data ===\n\n");
        while (fscanf(db_main_r, "%[^|]|%[^|]|%[^\n]\n", db_nim, db_nama, db_kelas) != EOF){
            no_urut++; available = true;
            printf(" == %d ==", no_urut);
            printf("\n\n NIM Praktikan\t\t\t: %s", db_nim);
            printf("\n\n Nama Praktikan\t\t\t: %s", db_nama);
            printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas);
            printf("\n\n --------------------------------------------------------\n\n");
        }

        if(available == false){
            printf(" --------------------------------------------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------------------------------------------\n");
        }

        fclose(db_main_r);
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 3:
        system("cls");
        db_main_r = fopen("mhs.db", "r"); db_main_w = fopen("mhs_temp.db", "w");
        available = false;
        printf(" === Update Data ===\n\n");
        printf(" Masukkan NIM Praktikan yang Ingin di Edit Data nya : "); scanf("%s",nim);
        while(fscanf(db_main_r, "%[^|]|%[^|]|%[^\n]\n", db_nim, db_nama, db_kelas) != EOF){
            if(strcmp(db_nim, nim) == 0){
                available = true;
                update_nama:
                printf("\n Nama Depan Baru\t\t: "); fflush(stdin); scanf("%[^\n]", db_nama);
                printf("\n Nama Belakang Baru\t\t: "); fflush(stdin); scanf("%[^\n]", nama_blkng); strcat(db_nama, nama_blkng);
                check_special_char(db_nama, 1);
                if(sc_space == false){
                    printf("\n Kelas Baru\t\t\t: "); fflush(stdin); scanf("%[^\n]", db_kelas); uppercase(db_kelas);
                    fprintf(db_main_w,"%s|%s|%s\n", db_nim, db_nama, db_kelas);
                    printf("\n --------------------------------------------------------\n");
                    printf("\n Data Berhasil di Edit.\n");
                    printf("\n --------------------------------------------------------\n");
                } else {
                    system("cls");
                    printf(" === Update Data ===\n");
                    printf("\n --------------------------------------------------------\n");
                    printf("\n Inputan Nama Tidak diperbolehkan\n");
                    printf(  " menggunakan spasi.\n");
                    printf("\n --------------------------------------------------------\n");
                    goto update_nama;
                }
                
            } else {
                fprintf(db_main_w,"%s|%s|%s\n", db_nim, db_nama, db_kelas);
            }
        }
        if(available == false){
            printf("\n --------------------------------------------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------------------------------------------\n");
        }
        fclose(db_main_r); fclose(db_main_w);
        remove("mhs.db"); rename("mhs_temp.db", "mhs.db");
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 4:
        system("cls");
        db_main_r = fopen("mhs.db", "r"); db_main_w = fopen("mhs_temp.db", "w");
        available = false;
        printf(" === Delete Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        while(fscanf(db_main_r, "%[^|]|%[^|]|%[^\n]\n", db_nim, db_nama, db_kelas) != EOF){
            if(strcmp(db_nim, nim) != 0){
                fprintf(db_main_w,"%s|%s|%s\n", db_nim, db_nama, db_kelas);
            } else if (strcmp(db_nim, nim) != 1){
                available = true;
                printf("\n --------------------------------------------------------\n");
                printf("\n Data Berhasil di Hapus.\n");
                printf("\n --------------------------------------------------------\n");
            }
        }

        if(available == false){
            printf("\n --------------------------------------------------------\n");
            printf("\n Data Tidak Tersedia.\n");
            printf("\n --------------------------------------------------------\n");
        }

        fclose(db_main_r); fclose(db_main_w);
        remove("mhs.db"); rename("mhs_temp.db", "mhs.db");
        printf("\n Tekan enter untuk kembali ke menu...");
        getch(); goto menu; break;

    case 5:
        system("cls");
        db_main_r = fopen("mhs.db", "r");
        available = false;
        printf(" === Search Data ===\n\n");
        printf(" Masukkan NIM Praktikan : "); scanf("%s", nim);
        while(fscanf(db_main_r, "%[^|]|%[^|]|%[^\n]\n", db_nim, db_nama, db_kelas) != EOF){
            if(strcmp(db_nim, nim) == 0){
                available = true;
                printf("\n\n NIM Praktikan\t\t\t: %s", db_nim);
                printf("\n\n Nama Praktikan\t\t\t: %s", db_nama);
                printf("\n\n Kelas Pemrograman Dasar\t: %s", db_kelas);
            }
        }
        if(available == false){
            printf("\n --------------------------------------------------------\n");
            printf("\n Data Tidak di Temukan.\n");
            printf("\n --------------------------------------------------------");
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