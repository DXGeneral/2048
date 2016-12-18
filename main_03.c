// Nomor Kelompok		: 03
// Nama file			: main_03.c
// Deskripsi			: Merupakan program utama dari program yang merepresentasikan sebuah game 2048

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "2048_03.c"
#include <windows.h>

int main() {

// KAMUS
	srand(time(NULL));
	char pil;
	int cplay;

// ALGORITMA
	system("cls");
	cplay=0;
	do {
        tampilan();
        showmenu(); // Menu
		pil = getch();
		switch (pil) {
			case '1' : { // Play
				playgame();
				break;
			}
			case '2' : { // High Score Board
			    showhighscore();
				break;
			}
			case '3' : { // How To Play
				howtoplay();
				break;
			}
			case '4' : { // About
			    aboutus();
				break;
			}
			case '5' : {
				break;
			}
			default : {
				wronginput(); // Pesan Kesalahan
				break;
			}
		}
	} while (pil != '5');
	quitgame(); // Keluar dari Permainan
	return 0;
}
