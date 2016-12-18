// Nomor Kelompok		: 03
// Nama file			: 2048_03.c
// Deskripsi			: Merupakan kumpulan algoritma dari program utama yang merepresentasikan sebuah game 2048

#include "2048_03.h"

bool IsEmpty (List L)
// I.S. Sembarang
// F.S. Bernilai true jika list kosong, yaitu First(L) = Nil
    {
        return(First(L) == Nil);
    }

Address Allocation (int X)
// I.S. Sembarang
// F.S. X teralokasi menjadi sebuah address
    {
        // KAMUS LOKAL
        Address P; // variabel pointer

        // ALGORITMA
        P = (Address) malloc (sizeof(ElmtList));
        if(P != Nil) {
            // pendefinisian elemen
            Info(P) = X;
            Right(P) = Nil;
            Left(P) = Nil;
            Up(P) = Nil;
            Down(P) = Nil;
         }
         return (P);
    }

void Deallocation (Address *P)
// I.S. P adalah hasil alokasi, P <> Nil
// F.S. Alamat P didealokasi, dikembalikan ke sistem
    {
        // ALGORITMA
        free(*P);
    }

List Pointer (List L1, List L2, List L3, List L4)
// I.S. List terdefinisi, masih terbagi-bagi dalam 4 bagian
// F.S. List sudah saling menunjuk membentuk list 4x4
    {
        // KAMUS LOKAL
        Address P1, P2, P3, P4;

        // ALGORITMA

        // proses penggabungan list pertama dan kedua
        P1 = First(L1);
        P2 = First(L2);
        do {
            Down(P1) = P2;
            Up(P2) = P1;
            P1 = Right(P1);
            P2 = Right(P2);
        } while (P1 != Nil);

        // proses penggabungan list kedua dan ketiga
        P2 = First(L2);
        P3 = First(L3);
        do {
            Down(P2) = P3;
            Up(P3) = P2;
            P2 = Right(P2);
            P3 = Right(P3);
        } while (P2 != Nil);

        // proses penggabungan list ketiga dan keempat
        P3 = First(L3);
        P4 = First(L4);
        do {
            Down(P3) = P4;
            Up(P4) = P3;
            P3 = Right(P3);
            P4 = Right(P4);
        } while (P3 != Nil);

        return L1;
    }

void CreateEmpty (List *L)
// I.S. Sembarang
// F.S. Terbentuk list kosong dengan First(L) = Nil
    {
        // ALGORITMA
        First(*L) = Nil;
    }

void InsertFirst (List *L, int X)
// I.S. List L mungkin kosong
// F.S. X dialokasi dan menjadi elemen pertama list
    {
        // KAMUS LOKAL
        Address P;

        // ALGORITMA
        P = Allocation(X); // proses alokasi
        if (P != Nil) {
            if (!(IsEmpty(*L))) {
                Right(P) = First(*L); // proses penyisipan
                Left(First(*L)) = P;
            }
            First(*L) = P;
        }
    }

void CreateEmptyList(List *L)
// I.S. Sembarang
// F.S. List terbentuk berukuran 4x4 bernilai 0 pada semua bagian
    {
        // KAMUS LOKAL
        List L1, L2, L3, L4, Ltemp; // variabel list
        Address P1, P2, P3, P4; // 4 pointer langsung menunjuk ke empat list
        int i; // variabel iterasi

        // ALGORITMA

        // proses pembuatan list masing-masing bagian
        CreateEmpty(&L1);
        CreateEmpty(&L2);
        CreateEmpty(&L3);
        CreateEmpty(&L4);

        // proses pengisian list yang terbentuk dengan list kosong
        for (i=1; i<=4; i++){
            InsertFirst(&L1, BLANK);
            InsertFirst(&L2, BLANK);
            InsertFirst(&L3, BLANK);
            InsertFirst(&L4, BLANK);
        }

        // proses menyambungkan keempat bagian list tersebut
        Ltemp = Pointer(L1, L2, L3, L4);
        *L = Ltemp;
    }

void StartGame (List *L)
// I.S. List kosong
// F.S. List dengan dua elemen sebagai permulaan permainan RndPos dilakukan sebanyak dua kali
    {
        // ALGORITMA

        // proses random angka 2 atau 4 maupun posisi
        RndPos(L);
        RndPos(L);
    }

void Color(Address P, int *x)
// I.S. P menunjuk pada sebuah elemen list
// F.S. Menghasilkan x sebagai kode warna sesuai info(P) yang ditunjuk
    {
        // ALGORITMA

        // proses membandingkan Info(P)
        switch (Info(P)) {
            case 2 : {
                *x = 112;
                break;
            }
            case 4 : {
                *x = 240;
                break;
            }
            case 8 : {
                *x = 79;
                break;
            }
            case 16 : {
                *x = 31;
                break;
            }
            case 32 : {
                *x = 47;
                break;
            }
            case 64 : {
                *x = 207;
                break;
            }
            case 128 : {
                *x = 159;
                break;
            }
            case 256 : {
                *x = 175;
                break;
            }
            case 512 : {
                *x = 223;
                break;
            }
            case 1024 : {
                *x = 111;
                break;
            }
            case 2048 : {
                *x = 239;
                break;
            }
            case 4096 : {
                *x = 15;
                break;
            }
            default : {
                *x = 143;
            }
        }
    }

void PrintGame1(Address P, int *i)
// I.S. P menunjuk pada sebuah elemen list
// F.S. Akan mengiterasi dan mencetak list per bagian serta mengeluarkan posisi i sebagai
//      tempat mencetak list selanjutnya
    {
        // KAMUS LOKAL
        Address P1, P2, P3, P4; // variabel pointer
        int a,b,c,d,e,i2,j2; // variabel identifier

        // ALGORITMA

        // pendefinisian pointer untuk tiap elemen
        P1 = P;
        P2 = Right(P);
        P3 = Right(Right(P));
        P4 = Right(Right(Right(P)));

        // identifikasi warna yang akan digunakan pada tiap elemen
        Color(P1,&a);
        Color(P2,&b);
        Color(P3,&c);
        Color(P4,&d);

        // pencetakan board per bagian (per baris)
        // warna yang keluar sesuai dengan Info(P) dari masing-masing elemen list
        gotoxy(50,12 + *i);
        setcolor(55);
        printf(" ");
        setcolor(a);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(b);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(c);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(d);
        printf("\t\t");
        setcolor(55);
        printf(" ");

        gotoxy(50,13 + *i);
        setcolor(55);
        printf(" ");
        setcolor(a);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(b);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(c);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(d);
        printf("\t\t");
        setcolor(55);
        printf(" ");

        gotoxy(50,14 + *i);
        setcolor(55);
        printf(" ");
        // iterasi untuk mengakses seluruh elemen pada list
        do {
            // pemeriksaan nilai Info(P)
            if (Info(P) != BLANK){
                Color(P,&e);
                setcolor(e);
                printf("       %d", Info(P));
                printf("\t");
            }
            else {
            // jika kosong maka warna akan kembali ke warna default
                setcolor(143);
                printf("         ");
                printf("\t");
            }
            P = Right(P);
            setcolor(c);
            setcolor(55);
            printf(" ");
        } while (P != Nil);

        gotoxy(50,15 + *i);
        setcolor(55);
        printf(" ");
        setcolor(a);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(b);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(c);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(d);
        printf("\t\t");
        setcolor(55);
        printf(" ");

        gotoxy(50,16 + *i);
        setcolor(55);
        printf(" ");
        setcolor(a);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(b);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(c);
        printf("\t\t");
        setcolor(55);
        printf(" ");
        setcolor(d);
        printf("\t\t");
        setcolor(55);
        printf(" ");

        gotoxy(50,11 + *i);
        printf("\t\t\t\t\t\t\t\t ");
        setcolor(55);
        gotoxy(50,35);
        printf("\t\t\t\t\t\t\t\t ");
        setcolor(55);

        // iterasi untuk mengubah posisi baris berikutnya
        *i = *i + 6;
        setcolor(95);
        gotoxy(52,41);
        printf("Press U to undo");
        gotoxy(52,42);
        printf("Press Q to back to menu");
    }

void PrintGame (List L)
// I.S. List terdefenisi
// F.S. List tercetak di layar sesuai dengan warna
    {
        // KAMUS LOKAL
        int i;
        Address P;

        // ALGORITMA
        i = 0;
        P = First(L);

        system("Color 5F"); // mewarnai sistem
        PrintGame1(P,&i); // mencetak baris pertama
        P = Down(P);
        PrintGame1(P,&i); // mencetak baris kedua
        P = Down(P);
        PrintGame1(P,&i); // mencetak baris ketiga
        P = Down(P);
        PrintGame1(P,&i); // mencetak baris keempat
    }

int RND24()
// Mengacak kemunculan angka antara 2 dan 4
    {
        // ALGORITMA
        return (((rand() % 2) + 1) * 2);
    }

void RndPos(List *L)
// I.S. List terdefinisi
// F.S. List diperbarui dengan angka tambahan yang random antara 2 atau 4
//      Prosedur juga akan mengacak letak kemunculan dari angka random tersebut
    {
        // KAMUS LOKAL
        int X; int n; // variabel penyimpan
        Address P; Address Prec; // variabel pointer

        // ALGORITMA
        do {
            P = First(*L); // inisialisasi pointer
            X = RND24(); // angka 2 atau 4 disimpan dalam X

            n = ((rand())%16 + 1); // posisi elemen tujuan diacak kemudian disimpan hasilnya
            // melakukan iterasi hingga ke posisi yang ditunjukkan oleh n
            while (n>1){
                Prec = P;
                while((Right(P) != Nil) && (n>1)){
                    P = Right(P);
                    n--;
                }
                if (n != 1){
                    P = Prec;
                    P = Down(P);
                    n--;
                }
            }
        } while (Info(P) != BLANK); // terminasi, saat n yang ditunjukkan Info(P) = BLANK, jika tidak proses diulang
        Info(P) = X; // nilai X dimasukkan
    }

void Proses(List *L1, List *L2, int *skor, int *Pskor, int *cplay)
// I.S. List terdefinisi. Uppercase W A S D U Q
// F.S. Permainan akan bergerak ke kiri, kanan, atas, bawah atau keluar dari game maupun undo sesuai masukan pengguna
    {
        // KAMUS LOKAL
        Address P,Pt,Pd,Prec; // variabel pointer
        List temp; int temp1; // variabel sementara
        int i,j,j2,i2; // variabel iterasi
        char CC; // variabel input
        char pil; // variabel input

        // ALGORITMA
        gotoxy(0,0);
        // membuat list sementara
        CreateEmptyList(&temp);
        // menngisi list sementara tersebut dengan kondisi awal game board (keperluan undo)
        PrecList(*L2, &temp);
        // masukkan pilihan untuk memulai proses
        CC = getch();
        CC = toupper(CC);
        // melakukan penyimpanan skor maupun penyalinan game board ke list sementara jika user
        // tidak memilih undo
        if (CC != 'U'){
            temp1 = *skor;
            PrecList(*L1, &temp);
        }

        switch (CC)
        {
            // pergerakan ke kiri, melakukan penjumlahan jika angka sama, melakukan pemindahan saja jika angka berbeda
            // tidak akan melakukan pergerakan jika memang tidak dapa digerakkan
            case 'A' :
                {
                    setcolor(87);
                    gotoxy(70,48);
                    printf("               ");
                    P = First(*L1);
                    do {
                        Prec = P;
                        Pt = Right(P);

                        // proses penjumlahan ke kiri
                        do {
                            if (Info(P) != BLANK){
                                if (Info(Pt) != BLANK){
                                    if (Info(P) == Info(Pt)){
                                        Info(P) = Info(P) + Info(Pt);
                                        *skor = *skor + Info(P);
                                        Info(Pt) = BLANK;
                                    }
                                    P = Pt;
                                    Pt = Right(P);
                                }
                                else{
                                    Pt = Right(Pt);
                                }
                            }
                            else{
                                P = Pt;
                                Pt = Right(P);
                            }
                        } while (Pt != Nil);

                        // proses pemindahan posisi ke kiri
                        P = Right(Prec);
                        do {
                            Pd = P;
                            do {
                                if (Left(P) != Nil) {
                                    if (Info(Left(P)) == BLANK){
                                        Info(Left(P)) = Info(P);
                                        Info(P) = BLANK;
                                    }
                                }
                                P = Left(P);
                            } while ((Left(P) != Nil));
                            P = Right(Pd);
                        } while (P != Nil);

                        P = Prec;
                        P = Down(P);
                    } while (P != Nil);
                    break;
                }

            // pergerakan ke kanan, melakukan penjumlahan jika angka sama, melakukan pemindahan saja jika angka berbeda
            // tidak akan melakukan pergerakan jika memang tidak dapa digerakkan
            case 'D' :
                {
                    setcolor(87);
                    gotoxy(70,48);
                    printf("               ");
                    P = First(*L1);

                    // pemindahan pointer awal ke ujung kanan atas
                    do
                    {
                        P = Right(P);
                    } while (Right(P) != Nil);

                    do {
                        Prec = P;
                        Pt = Left(P);

                        // proses penjumlahan ke kanan
                        do {
                            if (Info(P) != BLANK){
                                if (Info(Pt) != BLANK){
                                    if (Info(P) == Info(Pt)){
                                        Info(P) = Info(P) + Info(Pt);
                                        *skor = *skor + Info(P);
                                        Info(Pt) = BLANK;
                                    }
                                    P = Pt;
                                    Pt = Left(P);
                                }
                                else{
                                    Pt = Left(Pt);
                                }
                            }
                            else{
                                P = Pt;
                                Pt = Left(P);
                            }
                        } while (Pt != Nil);

                        // proses pemindahan posisi ke kanan
                        P = Left(Prec);
                        do {
                            Pd = P;
                            do {
                                if (Right(P) != Nil) {
                                    if (Info(Right(P)) == BLANK){
                                        Info(Right(P)) = Info(P);
                                        Info(P) = BLANK;
                                    }
                                }
                                P = Right(P);
                            } while ((Right(P) != Nil));
                            P = Left(Pd);
                        } while (P != Nil);

                        P = Prec;
                        P = Down(P);
                    } while (P != Nil);
                    break;
                }

            // pergerakan ke atas, melakukan penjumlahan jika angka sama, melakukan pemindahan saja jika angka berbeda
            // tidak akan melakukan pergerakan jika memang tidak dapa digerakkan
            case 'W' :
                {
                    setcolor(87);
                    gotoxy(70,48);
                    printf("               ");
                    P = First(*L1);

                    do {
                        Prec = P;
                        Pt = Down(P);

                        // proses penjumlahan ke atas
                        do {
                            if (Info(P) != BLANK){
                                if (Info(Pt) != BLANK){
                                    if (Info(P) == Info(Pt)){
                                        Info(P) = Info(P) + Info(Pt);
                                        *skor = *skor + Info(P);
                                        Info(Pt) = BLANK;
                                    }
                                    P = Pt;
                                    Pt = Down(P);
                                }
                                else{
                                    Pt = Down(Pt);
                                }
                            }
                            else{
                                P = Pt;
                                Pt = Down(P);
                            }
                        } while (Pt != Nil);

                        // proses pemindahan posisi ke atas
                        P = Down(Prec);
                        do {
                            Pd = P;
                            do {
                                if (Up(P) != Nil) {
                                    if (Info(Up(P)) == BLANK){
                                        Info(Up(P)) = Info(P);
                                        Info(P) = BLANK;
                                    }
                                }
                                P = Up(P);
                            } while ((Up(P) != Nil));
                            P = Down(Pd);
                        } while (P != Nil);

                        P = Prec;
                        P = Right(P);
                    } while (P != Nil);
                    break;
                }

            // pergerakan ke atas, melakukan penjumlahan jika angka sama, melakukan pemindahan saja jika angka berbeda
            // tidak akan melakukan pergerakan jika memang tidak dapa digerakkan
            case 'S' :
                {
                    setcolor(87);
                    gotoxy(70,48);
                    printf("               ");
                    P = First(*L1);

                    // pemindahan pointer ke ujung kiri bawah
                    do
                    {
                        P = Down(P);
                    } while (Down(P) != Nil);

                    do {
                        Prec = P;
                        Pt = Up(P);

                        // proses penjumlahan ke bawah
                        do {
                            if (Info(P) != BLANK){
                                if (Info(Pt) != BLANK){
                                    if (Info(P) == Info(Pt)){
                                        Info(P) = Info(P) + Info(Pt);
                                        *skor = *skor + Info(P);
                                        Info(Pt) = BLANK;
                                    }
                                    P = Pt;
                                    Pt = Up(P);
                                }
                                else{
                                    Pt = Up(Pt);
                                }
                            }
                            else{
                                P = Pt;
                                Pt = Up(P);
                            }
                        } while (Pt != Nil);

                        // proses pemindahan posisi ke bawah
                        P = Up(Prec);
                        do {
                            Pd = P;
                            do {
                                if (Down(P) != Nil) {
                                    if (Info(Down(P)) == BLANK){
                                        Info(Down(P)) = Info(P);
                                        Info(P) = BLANK;
                                    }
                                }
                                P = Down(P);
                            } while ((Down(P) != Nil));
                            P = Up(Pd);
                        } while (P != Nil);

                        P = Prec;
                        P = Right(P);
                    } while (P != Nil);
                    break;
                }

            // pilihan untuk keluar pada tengah permainan, akan terdapat pilihan untuk menyimpan game board
            // yang sedang berjalan
            case 'Q' :
                {
                    *cplay = 1;
                    setcolor(87);
                    gotoxy(70,48);
                    printf("               ");
                    for (j2=50;j2<=114;j2++){
                        for (i2=37;i2<=39;i2++){
                            gotoxy(j2,i2);
                            setcolor(243);
                            printf(" ");
                        }
                    }

                    // memunculkan pilihan untuk menyimpan permainan
                    gotoxy(52,37);
                    printf("Do you want to save your game? (Y/N)\a");
                    gotoxy(52,38);
                    do {
                        sleep(1);
                        for (j2=50;j2<=114;j2++){
                            gotoxy(j2,39);
                            setcolor(243);
                            printf(" ");
                        }
                        gotoxy(52,38);
                        pil = getch();
                        for (j2=50;j2<=114;j2++){
                            gotoxy(j2,39);
                            setcolor(63);
                            printf(" ");
                        }
                        // pesan kesalahan apabila masukan salah
                        gotoxy(52,39);
                        printf("Wrong input! Please Check Your Caps Lock and Try Again");
                        gotoxy(52,38);
                    } while ((pil != 'Y') && (pil != 'N'));

                    if (pil == 'Y') {
                        *cplay = 2;
                    }
                    break;
                }

            // pilihan untuk melakukan undo pada permainan
            case 'U' :
                {
                    PrecList(*L2, L1);
                    *skor = *Pskor;
                    break;
                }
        }

        // memeriksa apakah game board sekarang sama dengan keadaan sebelumya, jika tidak sama
        // maka permainan dilanjutkan dengan menambah angka pada posisi yang acak
        if (!IsSimilar(*L1, temp)){
            *Pskor = temp1;
            PrecList(temp, L2);
            RndPos(L1);
        }
    }

bool IsFull (List L)
// Mengembalikan True jika list penuh
    {
        // KAMUS LOKAL
        bool full; // variabel boolean
        Address P; Address Prec; // variabel pointer
        int i; int j; // variabel iterasi

        // ALGORITMA
        full = 1;
        P = First(L);

        // melakukan iterasi ke seluruh elemen, jika ditemukan elemen yang kosong maka akan keluar
        // dari loop tersebut
        while ((P != Nil) && (full)) {
            Prec = P;
            while ((P != Nil) && (full)) {
                if (Info(P) == BLANK){
                    full = 0;
                }
                else {
                    P = Right(P);
                }
            }
            if (full == 1){
                P = Prec;
                P = Down(P);
            }
        }
        return full;
    }

bool Kalah (Matriks M)
// I.S. IsFull bernilai true
// F.S. Menentukan apakah kalah atau tidak, seluruh address dari sebuah elemen yang sudah tidak dapat bergerak
//      akan disimpan ke dalam matriks
    {
        // KAMUS LOKAL
        int i, j, unlink; // variabel iterasi
        bool lose; // variabel boolean

        // ALGORITMA
        i = 1;
        lose = true;

        // memeriksa apakah di dalam matriks yang berisi address tersebut terdapat address yang masih bisa bergerak
        while ((i <= 4) && (lose))
        {
            j = 1;
            while ((j <= 4) && (lose))
            {
                // memeriksa apakah address bisa digerakkan di sebelahnya
                if (j <= 3)
                {
                    if (Info(M.Mem[i][j]) == Info(M.Mem[i][j+1]))
                    {
                        lose = false;
                    }
                }
                // memeriksa apakah address bisa digerakkan di atas bawahnya
                if (i <= 3)
                {
                    if (Info(M.Mem[i][j]) == Info(M.Mem[i+1][j]))
                    {
                        lose = false;
                    }
                }
                j++;
            }
            i++;
        }
        return lose;
    }

bool IsSimilar (List L1, List L2)
// Memeriksa apakah 2 buah list berisi angka yang sama atau tidak
    {
        // KAMUS LOKAL
            bool status; // variabel boolean
            Address P1, P2, Prec1, Prec2; // variabel pointer

        // ALGORITMA
            P1 = First(L1); // inisialisasi list 1
            P2 = First(L2); // inisialisasi list 2

            status = 1;

            // melakukan iterasi ke setiap elemen list 1 dan list 2 untuk memeriksa apakah setiap elemen
            // memiliki nilai yang sama
            do {
                Prec1 = P1;
                Prec2 = P2;
                do {
                    if (Info(P1) == Info(P2)) {
                        P1 = Right(P1);
                        P2 = Right(P2);
                    }
                    else {
                        status = 0;
                    }
                } while ((P1 != Nil) && (status));
                P1 = Prec1;
                P1 = Down(P1);
                P2 = Prec2;
                P2 = Down(P2);
            } while ((P1 != Nil) && (status));
            return status;
    }

bool IsWin (List L)
// Memeriksa apakah List tersebut berisi 2048 sebagai tanda bahwa pemain telah memenangkan permainan
    {
        // KAMUS LOKAL
        Address P; Address Prec; // variabel pointer
        int count; // variabel counter
        bool win; // variabel boolean

        // ALGORITMA
        count = 0;
        P = First(L);

        // melakukan traversal untuk mencari Info(P) yang bernilai 2048
        while (P != Nil){
            Prec = P;
            while (P != Nil){
                if (Info(P) == 2048){
                    count++;
                }
                P = Right(P);
            }
            P = Prec;
            P = Down(P);
        }

        // jika Info(P) terdeteksi hanya 1, maka kondisi menang akan dimunculkan
        if (count == 1){
            win = 1;
        }
        else{
            win = 0;
        }

        return win;
    }

void PrecList (List L1, List *L2)
// I.S. List pertama terdefinisi
// F.S. List kedua merupakan hasil copy dari list pertama
    {
        // KAMUS LOKAL
        Address P1, P2, Prec1, Prec2;

        // ALGORITMA
        P1 = First(L1); // inisialisasi list 1
        P2 = First(*L2); // inisialisasi list 2

        // melakukan iterasi untuk menyalin list 1 dan 2
        do {
            Prec1 = P1;
            Prec2 = P2;
            do {
                Info(P2) = Info(P1);
                P1 = Right(P1);
                P2 = Right(P2);
            } while (P1 != Nil);
            P1 = Prec1;
            P1 = Down(P1);
            P2 = Prec2;
            P2 = Down(P2);
        } while (P1 != Nil);
    }

void MakeMatriks (List L, Matriks *M)
// I.S. List terdefinisi
// F.S. Menyalin isi list ke dalam matriks
    {
        // KAMUS LOKAL
        Address P, Prec; // variabel pointer
        int i, j; // variabel iterasi

        // ALGORITMA
        i = 1;
        P = First(L);
        // memulai proses traversal ke seluruh list untuk menyalin elemennya pada matriks
        while (P != Nil)
        {
            Prec = P;
            j = 1;
            while (P != Nil)
            {
                (*M).Mem[i][j] = P;
                P = Right(P);
                j++;
            }
            P = Prec;
            P = Down(P);
            i++;
        }
    }

void bacaSkor (int skor, char nama[8])
// I.S. Skor dan nama terdefinisi terdefinisi
// F.S. Prosedur akan menyimpan skor dan nama pada akhir pertandingan ke dalam file eksternal
    {
        // ALGORITMA
        // proses penulisan pada file eksternal
        fileku = fopen("bismillah.txt","a");
        retval = fprintf(fileku,"%s %d\n", nama, skor);
        fclose(fileku);
    }

void tulisSkor ()
// I.S. File eksternal terdefinisi
// F.S. Prosedur akan menuliskan nama maupun skor yang didapat oleh user
    {
        // KAMUS LOKAL
        data HS[100]; // variabel array
        int i,j,k; // variabel iterasi
        int temp; // variabel sementara
        int count; // variabel counter
        int jmax; // variabel penyimpan
        char uname[30]; // variabel penyimpan

        // ALGORITMA
        // proses pembacaan pada file eksternal, file eksternal dibuka
        fileku = fopen("bismillah.txt", "r");
        count = 0;
        i = 1;

        // file eksternal dibaca isinya dan dipindahkan pada array
        retval = fscanf(fileku, "%s %d\n", HS[i].nama, &HS[i].skor);
        while(retval != EOF) {
            i++;
            count++;
            retval = fscanf(fileku, "%s %d\n", HS[i].nama, &HS[i].skor);
        }

        // melakukan proses pengurutan pada highscore tertinggi
        for (j = 1; j <= count-1; j++) {
        jmax =  j;
            for (k = j+1; k <= count; k++) {
                if (HS[k].skor > HS[jmax].skor) {
                    jmax = k;
                }
            }
        temp = HS[jmax].skor;
        strcpy(uname, HS[jmax].nama);

        HS[jmax].skor = HS[j].skor;
        strcpy(HS[jmax].nama, HS[j].nama);

        HS[j].skor = temp;
        strcpy(HS[j].nama, uname);
        }

        if (count > 10) {
            count = 10;
        }

        // mencetak highscore pada layar
        for (j = 1; j <= count; j++) {
            gotoxy(75,23 + j);
            printf("%s", HS[j].nama);
            gotoxy(91,23 + j);
            printf("%d", HS[j].skor);
        }

        for (j = 1; j <= count; j++) {
            gotoxy(71,23 + j);
            printf("%d.", j);
        }
        fclose(fileku);
    }

void saveList(List L, string x, int skor)
// I.S. List, nama maupun skor dari user terdefinisi
// F.S. Prosedur akan menyimpan username, skor maupun kondisi game board pada saat user akan
//      keluar dan memilih untuk menyimpan keadaan tersebut ke dalam file eksternal
    {
        // KAMUS LOKAL
        Address P,Prec; // variabel pointer

        // ALGORITMA
        // menyimpan nama, skor maupun keadaan game board pada saat user keluar
        fileku = fopen("save.txt","a");

        // melakukan penyimpanan nama dan skor
        retval = fprintf(fileku, "%s %d ", x.name, skor);

        // melakukan penyimpanan isi elemen list
        P = First(L);
        do {
            Prec = P;
            do {
                retval = fprintf(fileku,"%d ", Info(P));
                P = Right(P);
            } while (P != Nil);
            P = Prec;
            P = Down(P);
        } while (Down(P) != Nil);

        do {
            retval = fprintf(fileku,"%d ", Info(P));
            P = Right(P);
        } while (Right(P) != Nil);

        retval = fprintf(fileku,"%d\n", Info(P));

        fclose(fileku);
    }

void loadList(List *L, int *skor, string *x)
// I.S. File Eksternal terdefinisi
// F.S. Prosedur akan membaca file eksternal yang berisi data dari user kemudian mengeluarkan
//      username, skor maupun keadaan gameboard dari user yang dipilih
    {
        // KAMUS LOKAL
        Address P,Prec; // variabel pointer
        int i,j,k,l,g; // variabel iterasi
        int count; // variabel counter
        TabCom T; // variabel array
        bool found; // variabel boolean
        char pil; // variabel input

        // ALGORITMA
        gotoxy(50,25);

        fileku = fopen("save.txt","r");

        i = 1;
        count = 0;

        // melakukan pemindahan isi file eksternal ke dalam array
        retval = fscanf(fileku, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", T.TX[i].name,
                        &T.TX[i].TI[1], &T.TX[i].TI[2], &T.TX[i].TI[3], &T.TX[i].TI[4], &T.TX[i].TI[5], &T.TX[i].TI[6],
                        &T.TX[i].TI[7], &T.TX[i].TI[8], &T.TX[i].TI[9], &T.TX[i].TI[10], &T.TX[i].TI[11], &T.TX[i].TI[12],
                        &T.TX[i].TI[13], &T.TX[i].TI[14], &T.TX[i].TI[15], &T.TX[i].TI[16], &T.TX[i].TI[17]);
        while(retval != EOF) {
            i++;
            count++;
            retval = fscanf(fileku, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", T.TX[i].name,
                            &T.TX[i].TI[1], &T.TX[i].TI[2], &T.TX[i].TI[3], &T.TX[i].TI[4], &T.TX[i].TI[5], &T.TX[i].TI[6],
                            &T.TX[i].TI[7], &T.TX[i].TI[8], &T.TX[i].TI[9], &T.TX[i].TI[10], &T.TX[i].TI[11], &T.TX[i].TI[12],
                            &T.TX[i].TI[13], &T.TX[i].TI[14], &T.TX[i].TI[15], &T.TX[i].TI[16], &T.TX[i].TI[17]);
        }

        // pembatasan jumlah user yang akan ditampilkan
        if (count > 10) {
            i = count - 9;
        }
        else {
            i = 1;
        }

        // menampilkan jumlah user yang available untuk di-load
        j = 1;
        do {
            gotoxy(50,15+i);
            printf("%d. %s\n", j, T.TX[i].name);
            i++;
            j++;
        } while (i <= count);

        // memasukkan user yang akan di-load
        gotoxy(50,15+i);
        printf("Username yang dipilih : ");
        scanf("%d", &k);

        l = 1;
        // memasukkan username maupun skor yang dipilih ke dalam sebuah variabel
        *skor = T.TX[k].TI[l];
        strcpy((*x).name,T.TX[k].name);
        P = First(*L);

        // melakukan iterasi untuk memasukkan setiap elemen ke dalam list (load)
        do {
            Prec = P;
            do {
                l++;
                Info(P) = T.TX[k].TI[l];
                P = Right(P);
            } while (P != Nil);
            P = Prec;
            P = Down(P);
        } while (P != Nil);

        // menampilkan kembali user
        gotoxy(50,10);
        setcolor(95);
        printf("Hi, %s!", (*x).name);
        gotoxy(105,10);
        printf("Score : %d\n", *skor);
    }

void setcolor(unsigned short color)
// I.S. Kode terdefinisi
// F.S. Prosedur akan memberi warna pada layar sesuai kode warna yang dimasukkan
    {
        // ALGORITMA
        HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon,color);
    }

void gotoxy(int x, int y)
// I.S. Koordinat x, y terdefinisi
// F.S. Prosedur akan mengubah posisi kursor sesuai dengan koordinat yang dimasukkan
    {
        // ALGORITMA
        HANDLE hConsoleOutput;
        COORD dwCursorPosition;
        dwCursorPosition.X = x;
        dwCursorPosition.Y = y;
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
    }

void tampilan()
// I.S. Sembarang
// F.S. Prosedur akan menampilkan angka 2048 dalam ukuran besar sebagai tampilan awal
    {
        setcolor(2);
            gotoxy(55,2);
            printf("        ****       ****        ****       ****\n");
            gotoxy(55,3);
            printf("           ***   **    **     ***       **    **\n");
            gotoxy(55,4);
            printf("          **     **    **    **   **    **    **\n");
            gotoxy(55,5);
            printf("         **      **    **    *******      ****\n");
            gotoxy(55,6);
            printf("        **       **    **         **    **    **\n");
            gotoxy(55,7);
            printf("       ***       **    **         **    **    **\n");
            gotoxy(55,8);
            printf("       *******     ****           **      ****\n");
    }

void playgame()
// I.S. User memilih pilihan 1
// F.S. Prosedur akan menjalankan permainan 2048
    {
        // KAMUS LOKAL
        int i2, j2, skor, Pskor, cplay, count; // variabel penyimpan
        Matriks M; // variabel matriks
        char pil2; // variabel pilihan
        List L1, L2; // variabel list
        string x; // variabel string

        // ALGORITMA
        // menampilkan efek slideshow
        system("cls");
        for (i2=24;i2<=40;i2++) {
            for (j2=40;j2<=126;j2++){
                gotoxy(j2,i2);
                setcolor(243);
                printf(" ");
            }
        }
        // menampilkan apakah user akan melakukan load atau tidak
        gotoxy(50,25);
        printf("Do you want to Load your Game? (Y/N)\a");
        do {
            sleep(1);
            for (j2=40;j2<=126;j2++){
                gotoxy(j2,27);
                setcolor(243);
                printf(" ");
            }
            gotoxy(50,26);
            pil2 = getch();
            for (j2=40;j2<=126;j2++){
                gotoxy(j2,27);
                setcolor(63);
                printf(" ");
            }
            // pesan kesalahan jika user melakukan kesalahan input
            gotoxy(50,27);
            printf("Wrong input! Please Try Again");
            gotoxy(50,26);
        } while ((pil2 != 'Y') && (pil2 != 'N'));

        // membuat list kosong
        CreateEmptyList(&L1);
        CreateEmptyList(&L2);

        // melakukan load jika user memilih iya, tidak melakukan load jika user tidak memilih
        if (pil2 == 'Y') {
            system("cls");
            loadList(&L1, &skor, &x);
        }
        else {
            // memasukkan username sebagai user baru
            system("cls");
            system("Color 5F");
            for (i2=24;i2<=40;i2++) {
                for (j2=40;j2<=126;j2++){
                    gotoxy(j2,i2);
                    setcolor(208);
                    printf(" ");
                }
            }
            gotoxy(50,25);
            printf("Username : ");
            scanf("%s", x.name);
            StartGame(&L1);
            skor = 0;
        }

        cplay = 0;
        count = 0;
        // memulai permainan dengan menampilkan nama, skor awal dan game board
        system("cls");
        gotoxy(50,10);
        printf("Hi, %s!", x.name);
        gotoxy(105,10);
        printf("Score : %d\n", skor);
        if ((IsWin(L1))&&(count==0)) {
            gotoxy(70,48);
            printf("YOU WIN!");
            count++;
        }
        PrintGame(L1);

        // melakukan proses permainan sampai kondisi kalah atau keluar terpenuhi
        do {
            // menjalankan loop hingga gameboard full
            do{
                gotoxy(50,10);
                printf("Hi, %s!", x.name);
                gotoxy(70,12);
                Proses(&L1, &L2, &skor, &Pskor, &cplay);
                gotoxy(105,10);
                printf("Score : %d\n", skor);
                if ((IsWin(L1))&&(count==0)) {
                    gotoxy(70,48);
                    printf("YOU WIN!");
                    count++;
                }
                PrintGame(L1);
                gotoxy(105,45);
            } while(!(IsFull(L1)) && (cplay == 0));
            MakeMatriks(L1, &M);
        } while (!(Kalah(M)) && (cplay == 0));

        // jika keluar karena sudah melewati kondisi kalah, maka akan menyimpan username dan
        // skor ke dalam file eksternal
        if (cplay == 0){
            bacaSkor(skor, x.name);
            gotoxy(50,10);
            printf("Hi, %s!", x.name);
            gotoxy(80,37);
            printf("Game Over");
            gotoxy(77,38);
            printf("Your score: %d", skor);
            gotoxy(74,39);
            printf("Press any key to menu");
            getche();
            sleep(3);
        }
        // melakukan save jika user keluar karena quit
        else if (cplay == 2) {
            saveList(L1, x, skor);
        }
        system("cls");
    }

void showhighscore()
// I.S. User memilih pilihan 2
// F.S. Prosedur akan menampilkan highscore yang tersimpan pada file eksternal
    {
        // KAMUS LOKAL
        int g; // variabel iterasi

        // ALGORITMA
        system("cls");
        // mencetak template pencetakan highscore pada layar
        for (g=21;g<=34;g++){
            gotoxy(40,g);
            printf ("*");
            gotoxy(126,g);
            printf ("*");
        }
        gotoxy(40,35);
        printf ("***************************************************************************************");
        gotoxy(79,22);
        printf ("Highscore");
        gotoxy(79,23);
        printf ("*********");
        // proses pencetakan highscore
        tulisSkor();
    }

void howtoplay()
// I.S. User memilih pilihan 3
// F.S. Prosedur akan menampilkan cara permainan tersebut bekerja
    {
        // KAMUS LOKAL
        int g; // variabel iterasi

        // ALGORITMA
        // mencetak template dari cara bermain yang akan dicetak ke layar
        system("cls");
        for (g=21;g<=34;g++){
            gotoxy(40,g);
            printf ("*");
            gotoxy(126,g);
            printf ("*");
        }
        gotoxy(79,22);
        printf("How To Play");
        gotoxy(79,23);
        printf("***********");
        gotoxy(50,25);
        printf("Press W to move all tiles up");
        gotoxy(50,26);
        printf("Press A to move all tiles left");
        gotoxy(50,27);
        printf("Press S to move all tiles down");
        gotoxy(50,28);
        printf("Press D to move all tiles right");
        gotoxy(50,29);
        printf("Press U to Undo");
        gotoxy(50,30);
        printf("Press Q to Quit");
        gotoxy(50,32);
        printf("Good Luck :)");
        gotoxy(40,34);
        printf ("***************************************************************************************");
    }

void aboutus()
// I.S. User memilih pilihan 4
// F.S. Prosedur akan menampilkan keterangan pembuat program
    {
        // KAMUS LOKAL
        int g; // variabel iterasi

        // ALGORITMA
        // mencetak template dari pembuat game yang akan dicetak ke layar
        system("cls");
        for (g=21;g<=33;g++){
            gotoxy(40,g);
            printf ("*");
            gotoxy(126,g);
            printf ("*");
        }
        gotoxy(81,22);
        printf("ABOUT");
        gotoxy(81,23);
        printf("*****");
        gotoxy(50,25);
        printf("2048 by ArogantRed");
        gotoxy(50,27);
        printf("18214009 - Veby Regina Milano");
        gotoxy(50,28);
        printf("18214018 - Mahbub Haq Al Farisi");
        gotoxy(50,29);
        printf("18214027 - Ahmad Idham Taufano Lubis");
        gotoxy(50,30);
        printf("18214054 - Edvin William Handoko");
        gotoxy(50,32);
        printf("Copyright 2015 - All Rights Reserved");
        gotoxy(40,34);
        printf ("***************************************************************************************");
    }

void wronginput()
// I.S. User memilih pilihan yang salah
// F.S. Prosedur akan memunculkan pesan kesalahan
    {
        // KAMUS
        int j2; // variabel iterasi

        // ALGORITMA
        // mencetak pesan kesalahan pada menu
        for (j2=40;j2<=126;j2++){
            gotoxy(j2,36);
            setcolor(143);
            printf(" ");
        }
        gotoxy(70,36);
        printf("Wrong Input! Please Try Again \a");
        gotoxy(70,19);
        sleep(1);
        gotoxy(70,36);
        printf("                                ");
    }

void quitgame()
// I.S. User memilih pilihan 5
// F.S. Prosedur akan mengeluarkan user pada permainan
    {
        // KAMUS
        int i2, j2; // varibel iterasi

        // ALGORITMA
        // mengeluarkan pesan sebelum game keluar
        system("cls");
        system("color 3B");
        for (i2=27;i2<=33;i2++) {
            for (j2=60;j2<=112;j2++){
                gotoxy(j2,i2);
                setcolor(143);
                printf(" ");
            }
        }
        gotoxy(75,29);
        printf("Thank you for playing");
        gotoxy(76,30);
        printf("2048 by ArogantRed");
        gotoxy(84,31);
        printf("3");
        sleep(1);
        gotoxy(84,31);
        printf("2");
        sleep(1);
        gotoxy(84,31);
        printf("1");
        sleep(1);
        system("cls");
        system("color 07");
    }

void showmenu()
// I.S. Sembarang
// F.S. Prosedur akan menampilkan menu yang tersedia
    {
        // KAMUS LOKAL
        int i1; // variabel iterasi

        // ALGORITMA
        // menampilkan menu dari game tersebut
        system("Color 3B");
        gotoxy(81,11);
        printf ("Menu");
        gotoxy(81,12);
        printf ("****");
        gotoxy(40,10);
        printf ("***************************************************************************************");
        for (i1=11;i1<=20;i1++) {
            gotoxy(40,i1);
            printf ("*");
            gotoxy(126,i1);
            printf ("*");
        }
        system("Color 3B");
        gotoxy(50,13);
        printf ("1. Play");
        gotoxy(50,14);
        printf ("2. High Score");
        gotoxy(50,15);
        printf ("3. How To Play");
        gotoxy(50,16);
        printf ("4. About");
        gotoxy(50,17);
        printf ("5. Quit");
        gotoxy(50,19);
        printf ("Press the number: ");
        gotoxy(40,21);
        printf ("***************************************************************************************");
        gotoxy(70,19);
    }
