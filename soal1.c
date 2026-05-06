/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 4 , Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Isnaya Zalfa Kamila (13224028)
 *   Nama File           : nomor1.c
 *   Deskripsi           : Program mengelola antrian pasien di rumah sakit menggunakan linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Patient_MAX 100
#define Urutan_Patient 50

struct Node {
    char id; // ID pasien, diisi oleh pengguna
    int waktu_tunggu; // Waktu tunggu pasien, diisi oleh pengguna
    struct Node* next; // Pointer ke node berikutnya dalam linked list
};

void Urutan_Pasien (struct Node* head) { // Fungsi untuk mengurutkan pasien berdasarkan urutan kedatangan pasien 
    if (head == NULL) {
        return; // Jika linked list kosong, tidak perlu diurutkan
    }

    struct Node* current = head; // Pointer untuk iterasi melalui linked list
    struct Node* index = NULL; // Pointer untuk iterasi kedua dalam proses pengurutan
    int temp_id;
    int temp_waktu_tunggu;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->id > index->id) {
                // Tukar id
                temp_id = current->id;
                current->id = index->id;
                index->id = temp_id;

                // Tukar waktu_tunggu
                temp_waktu_tunggu = current->waktu_tunggu;
                current->waktu_tunggu = index->waktu_tunggu;
                index->waktu_tunggu = temp_waktu_tunggu;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void tampilkan_antrian(struct Node* head) { // Fungsi untuk menampilkan antrian pasien
    struct Node* current = head; // Pointer untuk iterasi melalui linked list

    printf("ORDER \n");
    while (current != NULL) {
        printf("ID: %c, Waktu Tunggu: %d\n", current->id, current);

        }
    }

void total_WAITING_TIME(struct Node* head, int current) { // Fungsi untuk menghitung total waktu tunggu pasien
    int total_waktu_tunggu = 0; // Variabel untuk menyimpan total waktu tunggu
    struct Node* current = head; // Pointer untuk iterasi melalui linked list

    while (current != NULL) {
        total_waktu_tunggu += current
    ->waktu_tunggu; // Menambahkan waktu tunggu pasien saat ini ke total
        current = current->next; // Pindah ke node berikutnya
    }
}

void tampilkan_waktu_tunggu(struct Node* head) { // Fungsi untuk menampilkan waktu tunggu pasien
    struct Node* current = head; // Pointer untuk iterasi melalui linked list

    printf("WAIT \n");
    while (current != NULL) {
        printf("ID: %c, Waktu Tunggu: %d\n", current->id, current->waktu_tunggu);
        current = current->next; // Pindah ke node berikutnya
    }
}

int main () {
    int N;
    struct Node* head = NULL; // Pointer untuk head linked list
    struct Node* tail = NULL; // Psointer untuk tail linked list

    scanf("%d", &N);    
    for (int i = 0; i < N; i++) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Alokasi memori untuk node baru
        scanf("%s", &new_node->id); // masukan ID pasien
        scanf("%d", &new_node->waktu_tunggu); // Input waktu tunggu pasien
        new_node->next = NULL; // Inisialisasi pointer next

        if (head == NULL) {
            head = new_node; // Jika linked list kosong, set head ke node baru
            tail = new_node; // Set tail ke node baru
        } else {
            tail->next = new_node; // Hubungkan node baru ke tail
            tail = new_node; // Update tail ke node baru
        }
    }
    Urutan_Pasien(head); // Panggil fungsi untuk mengurutkan pasien berdasarkan ID 
    total_WAITING_TIME(head); // Panggil fungsi untuk menghitung total waktu tunggu
    tampilkan_antrian(head); // Panggil fungsi untuk menampilkan antrian pasien
    tampilkan_waktu_tunggu(head); // Panggil fungsi untuk menampilkan waktu tung

}
