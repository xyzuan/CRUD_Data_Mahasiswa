#include <stdio.h>

#include <string.h>

#include <stdbool.h>



int main() {

    int n;

    printf("~Input Data Mahasiswa~\n\n\n");

    printf("Masukkan total jumlah mahasiswa yang ingin diinputkan : ");

    scanf("%d",&n);



    char nim[n][10];

    char nama[n][40];

    char asal[n][30];

    printf("\n\n\n---------------------\n");

    for(int i=0;i<n;i++){

        printf("Masukkan NIM mahasiswa ke - %d : ",i+1);

        scanf("%s",nim[i]);

        printf("Masukkan Nama mahasiswa ke - %d : ",i+1);

        scanf("%s",nama[i]);

        printf("Masukkan Asal mahasiswa ke - %d : ",i+1);

        scanf("%s",asal[i]);

        printf("---------------------\n");

    }

    char cari[10];

    printf("Cari data Mahasiswa : \n");

    scanf("%s",cari);

    bool k=false;

    for(int j=0;j<n;j++){

        if(strcmp(cari,nim[j])==0){

            printf("NIM mahasiswa ke - %d : %s\n",j,nim[j]);

            printf("Nama mahasiswa ke - %d : %s\n",j,nama[j]);

            printf("Asal mahasiswa ke - %d : %s\n",j,asal[j]);

            printf("---------------------\n");

            k=true;

        }

    }



    if(!k){

        printf("Data tidak ditemukan");

    }



    nim[0][10] = "";

    strcpy(nim[0],"");



}