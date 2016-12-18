// Nomor Kelompok		: 03
// Nama file			: 2048_03.h
// Deskripsi			: Merupakan file header dari program yang merepresentasikan sebuah game 2048

// Library Default
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

// Inisialisasi Warna
#define BROWN BACKGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY
#define YELLOW BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define PURPLE BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define GREEN BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define BLUE BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXTBLUE FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY
#define TEXTPURPLE FOREGROUND_RED|FOREGROUND_BLUE
#define TEXTYELLOW FOREGROUND_GREEN|FOREGROUND_RED

// Konstanta yang akan digunakan
#define Nil NULL
#define BLANK 0

// Definisi BOOLEAN
#define bool unsigned char
#define true 1
#define false 0

// Tipe baru integer
typedef int Infotype;

// Tipe Bentukan List
typedef struct TElmtList *Address;
typedef struct TElmtList {
	Infotype 	info;
	Address 	nextRight;
	Address 	nextUp;
	Address 	nextDown;
	Address 	nextLeft;
} ElmtList;
typedef struct {
	Address	First;
} List;

// Tipe bentukan string (array of character)
typedef struct {
	unsigned char name[8];
} string;

// Tipe bentukan Matriks bertipe address
typedef struct
{
	Address Mem[5][5];
} Matriks;

// Tipe bentukan berisi array dan string
typedef struct
{
    int TI[18];
    unsigned char name[8];
} Tab;

// Tipe bentukan array yang berisi array of integer dan string
typedef struct
{
    Tab TX[100];
} TabCom;

#define First(L) (L).First
#define Right(P) (P)->nextRight
#define Left(P) (P)->nextLeft
#define Up(P) (P)->nextUp
#define Down(P) (P)->nextDown
#define Info(P) (P)->info

// FIle Eksternal
int retval;
FILE *fileku;
	typedef struct {
			char nama[8];
			int skor;
			} data;
data HS[100];
data user;

bool IsEmpty (List L);
// I.S. Sembarang
// F.S. Bernilai true jika list kosong, yaitu First(L) = Nil

Address Allocation (int X);
// I.S. Sembarang
// F.S. X teralokasi menjadi sebuah address

void Deallocation (Address *P);
// I.S. P adalah hasil alokasi, P <> Nil
// F.S. Alamat P didealokasi, dikembalikan ke sistem

List Pointer (List L1, List L2, List L3, List L4);
// I.S. List terdefinisi, masih terbagi-bagi dalam 4 bagian
// F.S. List sudah saling menunjuk membentuk list 4x4

void CreateEmpty (List *L);
// I.S. Sembarang
// F.S. Terbentuk list kosong dengan First(L) = Nil

void InsertFirst (List *L, int X);
// I.S. List L mungkin kosong
// F.S. X dialokasi dan menjadi elemen pertama list

void CreateEmptyList(List *L);
// I.S. Sembarang
// F.S. List terbentuk berukuran 4x4 bernilai 0 pada semua bagian

void StartGame (List *L);
// I.S. List kosong
// F.S. List dengan dua elemen sebagai permulaan permainan RndPos dilakukan sebanyak dua kali

void Color(Address P, int *x);
// I.S. P menunjuk pada sebuah elemen list
// F.S. Menghasilkan x sebagai kode warna sesuai info(P) yang ditunjuk

void PrintGame1(Address P, int *i);
// I.S. P menunjuk pada sebuah elemen list
// F.S. Akan mengiterasi dan mencetak list per bagian serta mengeluarkan posisi i sebagai
//      tempat mencetak list selanjutnya

void PrintGame (List L);
// I.S. List terdefenisi
// F.S. List tercetak di layar sesuai dengan warna

int RND24();
// Mengacak kemunculan angka antara 2 dan 4

void RndPos(List *L);
// I.S. List terdefinisi
// F.S. List diperbarui dengan angka tambahan yang random antara 2 atau 4
//      Prosedur juga akan mengacak letak kemunculan dari angka random tersebut

void Proses (List *L1, List *L2, int *skor, int *Pskor, int *cplay);
// I.S. List terdefinisi. Uppercase W A S D U Q
// F.S. Permainan akan bergerak ke kiri, kanan, atas, bawah atau keluar dari game maupun undo sesuai masukan pengguna

bool IsFull(List L);
// Mengembalikan True jika list penuh

bool Kalah (Matriks M);
// I.S. IsFull bernilai true
// F.S. Menentukan apakah kalah atau tidak, seluruh address dari sebuah elemen yang sudah tidak dapat bergerak
//      akan disimpan ke dalam matriks

bool IsSimilar (List L1, List L2);
// Memeriksa apakah 2 buah list berisi angka yang sama atau tidak

bool IsWin (List L);
// Memeriksa apakah List tersebut berisi 2048 sebagai tanda bahwa pemain telah memenangkan permainan

void PrecList (List L1, List *L2);
// I.S. List pertama terdefinisi
// F.S. List kedua merupakan hasil copy dari list pertama

void MakeMatriks (List L, Matriks *M);
// I.S. List terdefinisi
// F.S. Menyalin isi list ke dalam matriks

void bacaSkor (int skor, char nama[8]);
// I.S. Skor dan nama terdefinisi terdefinisi
// F.S. Prosedur akan menyimpan skor dan nama pada akhir pertandingan ke dalam file eksternal

void tulisSkor ();
// I.S. File eksternal terdefinisi
// F.S. Prosedur akan menuliskan nama maupun skor yang didapat oleh user

void saveList(List L, string x, int skor);
// I.S. List, nama maupun skor dari user terdefinisi
// F.S. Prosedur akan menyimpan username, skor maupun kondisi game board pada saat user akan
//      keluar dan memilih untuk menyimpan keadaan tersebut ke dalam file eksternal

void loadList(List *L, int *skor, string *x);
// I.S. File Eksternal terdefinisi
// F.S. Prosedur akan membaca file eksternal yang berisi data dari user kemudian mengeluarkan
//      username, skor maupun keadaan gameboard dari user yang dipilih

void setcolor(unsigned short color);
// I.S. Kode terdefinisi
// F.S. Prosedur akan memberi warna pada layar sesuai kode warna yang dimasukkan

void gotoxy(int x, int y);
// I.S. Koordinat x, y terdefinisi
// F.S. Prosedur akan mengubah posisi kursor sesuai dengan koordinat yang dimasukkan

void tampilan();
// I.S. Sembarang
// F.S. Prosedur akan menampilkan angka 2048 dalam ukuran besar sebagai tampilan awal

void playgame();
// I.S. User memilih pilihan 1
// F.S. Prosedur akan menjalankan permainan 2048

void showhighscore();
// I.S. User memilih pilihan 2
// F.S. Prosedur akan menampilkan highscore yang tersimpan pada file eksternal

void howtoplay();
// I.S. User memilih pilihan 3
// F.S. Prosedur akan menampilkan cara permainan tersebut bekerja

void aboutus();
// I.S. User memilih pilihan 4
// F.S. Prosedur akan menampilkan keterangan pembuat program

void wronginput();
// I.S. User memilih pilihan yang salah
// F.S. Prosedur akan memunculkan pesan kesalahan

void quitgame();
// I.S. User memilih pilihan 5
// F.S. Prosedur akan mengeluarkan user pada permainan

void showmenu();
// I.S. Sembarang
// F.S. Prosedur akan menampilkan menu yang tersedia
