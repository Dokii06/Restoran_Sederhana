#include <iostream>

using namespace std;

void garis(){
    cout << endl;
    for(int i = 0; i < 60; i++){
        cout << "=";
    }
    cout << endl;
}
void garisTipis(){
    for(int i = 0; i < 60; i++){
        cout << "-";
    }
    cout << endl;
}

struct menu {
    int kode;
    string nama;
    int harga;
};
struct pesanan {
    string namaMenu;
    int kuantitas;
    int totalHarga;
};

int hargaSementara, hargaKeseluruhan = 0, jumlahPesanan = 0;
const int maxPesanan = 2;
pesanan simpanPesanan[maxPesanan];
char lanjutPesan;

void isiMenuUtama();
void riwayatPesanan (string namaMenu, int kuantitas, int harga);
void tampilanMenuUtama();
void tampilanMenuAkhir();
void lanjutPemesanan(char pesanLagi);

void isiMenuMakanan();
void isiMenuMinuman();
void isiMenuLain();

int hitungTotalHarga();

int main(){
    tampilanMenuUtama();
}

void isiMenuUtama(){
    struct menuUtama {
        int kode;
        string nama;
    };
    const int jumlahMenuUtama = 4;
    menuUtama ar[4];

    ar[0].kode = 1;
    ar[0].nama = "Makanan";
    ar[1].kode = 2;
    ar[1].nama = "Minuman";
    ar[2].kode = 3;
    ar[2].nama = "Menu lain";
    ar[3].kode = 4;
    ar[3].nama = "Keluar";

    cout << "| No |\t\t\t   Menu \t\t\t|\n";
    for(int i = 0; i < jumlahMenuUtama; ++i){
        cout << "| "<< ar[i].kode << "  |\t\t\t " << ar[i].nama << " \t\t\t|";
        cout << endl;
    }
}

void riwayatPesanan (string namaMenu, int kuantitas, int harga){
    simpanPesanan[jumlahPesanan].namaMenu = namaMenu;
    simpanPesanan[jumlahPesanan].kuantitas = kuantitas;
    simpanPesanan[jumlahPesanan].totalHarga = harga;
    jumlahPesanan++;
    hargaKeseluruhan += harga;
}

void lanjutPemesanan(char pesanLagi){
    if (pesanLagi == 'y' || pesanLagi == 'Y') {
        system ("cls");
        tampilanMenuUtama();
        return;
    } else if (pesanLagi == 'n' || pesanLagi == 'N') {
        tampilanMenuAkhir();
        return;
    } else {
        cout << "Masukkan pilihan yang valid (y/n).\n";
    }
}

void isiMenuMakanan(){
    system ("cls");

    int pil,kuantitas;
    const int jumlahMenuMakanan = 3;
    menu makanan[3];

    makanan[0].kode = 1;
    makanan[0].nama = "Ayam Geprek";
    makanan[0].harga = 8000;
    makanan[1].kode = 2;
    makanan[1].nama = "Ayam Bakar";
    makanan[1].harga = 8000;
    makanan[2].kode = 3;
    makanan[2].nama = "Ayam Goreng";
    makanan[2].harga = 8000;

    garisTipis();
    cout << "| No |\t\t     Menu \t\t|  Harga  | \n";
    for(int i = 0; i < jumlahMenuMakanan; ++i){
        cout << "| "<< makanan[i].kode << "  |\t\t  " << makanan[i].nama << " \t\t| Rp." << makanan[i].harga << " |  ";
        cout << endl;
    }
    garisTipis();

    do{
        cout << "Silahkan Masukkan Pilihan : ";
        cin >> pil;

        switch (pil){
        case 1 :
            system ("cls");
            garis();
            cout << "\t\t\t Ayam Geprek \n\n";
            cout << "Jumlah porsi yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * makanan[0].harga;
            riwayatPesanan (makanan[0].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " porsi Ayam Geprek Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 2 :
            system ("cls");
            garis();
            cout << "\t\t\t Ayam Bakar \n\n";
            cout << "Jumlah porsi yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * makanan[1].harga;
            riwayatPesanan(makanan[1].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " porsi Ayam Bakar Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 3 :
            system ("cls");
            garis();
            cout << "\t\t\t Ayam Bakar \n\n";
            cout << "Jumlah porsi yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * makanan[2].harga;
            riwayatPesanan(makanan[2].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " porsi Ayam Bakar Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        default:
            cout << "Pilihan tidak valid. Silakan masukkan pilihan antara 1 hingga 3.\n";
            break;
        }

    } while (pil < 1 || pil > 3);
}

void isiMenuMinuman(){
    system ("cls");

    int pil,kuantitas;
    int suhu;
    const int jumlahMenuMinuman = 2;
    menu minuman[2];

    minuman[0].kode = 1;
    minuman[0].nama = "Teh Manis";
    minuman[0].harga = 4000;
    minuman[1].kode = 2;
    minuman[1].nama = "Lemon";
    minuman[1].harga = 5000;

    garisTipis();
    cout << "| No |\t\t     Menu \t\t|  Harga  | \n";
    for(int i = 0; i < jumlahMenuMinuman; ++i){
        cout << "| "<< minuman[i].kode << "  |\t\t  " << minuman[i].nama << " \t\t| Rp." << minuman[i].harga << " |  ";
        cout << endl;
    }
    garisTipis();

    do {
        cout << "Silahkan Masukkan Pilihan : ";
        cin >> pil;

        switch (pil){
        case 1 :
            system ("cls");
            do{
                garis();
                cout << "\t\t\t Teh Manis \n\n";
                cout << "[1] Hangat\n";
                cout << "[2] Dingin\n\n";

                cout << "Silahkan Masukkan Pilihan : ";
                cin >> suhu;

                if (suhu == 1){
                    suhu = 1;
                    break;
                }else if (suhu == 2){
                    suhu = 2;
                    break;
                }else{
                    cout << "Masukkan pilihan sesuai instruksi";
                }
            } while (suhu != 1 || suhu != 2);

            cout << "Jumlah yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * minuman[0].harga;
            riwayatPesanan(minuman[0].nama, kuantitas, hargaSementara);

            if (suhu == 2){
                cout << "Harga " << kuantitas << " Es Teh Manis Rp." << hargaSementara << endl;
            }else if (suhu == 1){
                cout << "Harga " << kuantitas << " Teh Manis Hangat Rp." << hargaSementara << endl;
            }
            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 2 :
            system ("cls");
            do{
                garis();
                cout << "\t\t\t Lemon \n\n";
                cout << "[1] Hangat\n";
                cout << "[2] Dingin\n\n";

                cout << "Silahkan Masukkan Pilihan : ";
                cin >> suhu;

                if (suhu == 1){
                    suhu = 1;
                    break;
                }else if (suhu == 2){
                    suhu = 2;
                    break;
                }else{
                    cout << "Masukkan pilihan sesuai instruksi";
                }
            } while (suhu != 1 || suhu != 2);

            cout << "Jumlah yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * minuman[1].harga;
            riwayatPesanan(minuman[1].nama, kuantitas, hargaSementara);

            if (suhu == 2){
                cout << "Harga " << kuantitas << " Es Lemon Tea Rp." << hargaSementara << endl;
            }else if (suhu == 1){
                cout << "Harga " << kuantitas << " Lemon Tea Hangat Rp." << hargaSementara << endl;
            }
            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        default:
            cout << "Pilihan tidak valid. Silakan masukan pilihan antara 1 hingga 2.\n";
            break;
        }
    } while (pil < 1 || pil > 2);
}

void isiMenuLain(){
    system ("cls");

    int pil,kuantitas,opsi;
    const int jumlahMenuLain = 5;
    menu lain[5];

    lain[0].kode = 1;
    lain[0].nama = "Nasi";
    lain[0].harga = 3000;
    lain[1].kode = 2;
    lain[1].nama = "Sambal";
    lain[1].harga = 2000;
    lain[2].kode = 3;
    lain[2].nama = "Lalapan";
    lain[2].harga = 1000;
    lain[3].kode = 4;
    lain[3].nama = "Tahu";
    lain[3].harga = 1000;
    lain[4].kode = 5;
    lain[4].nama = "Tempe";
    lain[4].harga = 1000;

    garisTipis();
    cout << "| No |\t\t     Menu \t\t|  Harga  | \n";
    for(int i = 0; i < jumlahMenuLain; ++i){
        cout << "| "<< lain[i].kode << "  |\t\t    " << lain[i].nama << " \t\t| Rp." << lain[i].harga << " |  ";
        cout << endl;
    }
    garisTipis();

    do{
        cout << "Silahkan Masukkan Pilihan : ";
        cin >> pil;

        switch (pil){
        case 1 :
            system ("cls");
            garis();
            cout << "\t\t\t Nasi Putih \n\n";
            cout << "Jumlah porsi yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * lain[0].harga;
            riwayatPesanan(lain[0].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " porsi Nasi Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 2 :
            system ("cls");

            do{
                garis();
                cout << "\t\t\t Sambal \n\n";

                cout << "[1] Sambal Bawang Putih \n";
                cout << "[2] Sambal Cabai Hijau \n\n";

                cout << "Silahkan Masukkan Pilihan : ";
                cin >> opsi;

                if (opsi == 1){
                    opsi = 1;
                    break;
                }else if (opsi == 2){
                    opsi = 2;
                    break;
                }else{
                    cout << "Masukkan pilihan sesuai instruksi";
                }

            } while (opsi != 1 || opsi != 2);

            cout << "Jumlah yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * lain[1].harga;
            riwayatPesanan(lain[1].nama, kuantitas, hargaSementara);

            if (opsi == 1){
                cout << "Harga " << kuantitas << " Sambal Bawang Putih Rp." << hargaSementara << endl;
            }else if (opsi == 2){
                cout << "Harga " << kuantitas << " Sambal Cabai Hijau Rp." << hargaSementara << endl;
            }
            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 3 :
            system ("cls");
            garis();
            cout << "\t\t\t Lalapan \n\n";
            cout << "Jumlah Lalapan yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * lain[2].harga;
            riwayatPesanan(lain[2].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " porsi Lalapan Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 4 :
            system ("cls");
            garis();
            cout << "\t\t\t Tahu \n\n";
            cout << "Jumlah Tahu yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * lain[3].harga;
            riwayatPesanan(lain[3].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " buah Tahu Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        case 5 :
            system ("cls");
            garis();
            cout << "\t\t\t Tempe \n\n";
            cout << "Jumlah Tempe yang ingin anda pesan : ";
            cin >> kuantitas;

            hargaSementara = kuantitas * lain[4].harga;
            riwayatPesanan(lain[0].nama, kuantitas, hargaSementara);

            cout << "Harga " << kuantitas << " buah Tempe Rp." << hargaSementara << endl;

            do{
                cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
                cin >> lanjutPesan;

                lanjutPemesanan(lanjutPesan);
                return;
            } while (true);

        default:
            cout << "Pilihan tidak valid. Silakan masukkan pilihan antara 1 hingga 5.\n";
            break;
        }

    } while (pil < 1 || pil > 5);
}

void tampilanMenuUtama() {
    int pil;

    do{
        garis();
        cout << "\t\t Selamat Datang Di Senowedari";
        garis();
        cout << "\t\t\tMau Pesen Apa?\n";
        garisTipis();
        isiMenuUtama();
        garisTipis();

        cout << "Silahkan Masukkan Pilihan : ";
        cin >> pil;

        int konfirmasi;
        switch (pil) {
            case 1:
                isiMenuMakanan();
                break;
            case 2:
                isiMenuMinuman();
                break;
            case 3:
                isiMenuLain();
                break;
            case 4:
                cout << "\nApakah anda yakin ingin mengakhiri program?\n";
                cout << "[1] Yakin\n";
                cout << "[2] Tidak\n";
                cin >> konfirmasi;
                if (konfirmasi == 1 ){
                    tampilanMenuAkhir();
                    return;
                }
                else {
                    system ("cls");
                    tampilanMenuUtama();
                    return;
                }
                break;
            default:
                system ("cls");
                cout << "Pilihan tidak valid. Silakan masukkan pilihan antara 1 hingga 3.\n";
                break;
        }
    } while (pil < 1 || pil > 4);
}

int hitungTotalHarga(){
    return hargaKeseluruhan;
}

void tampilanMenuAkhir() {
    system ("cls");
    garis();
    cout << "\nItem Yang Anda Pesan:\n";
    for (int i = 0; i < jumlahPesanan; ++i) {
        cout << "Pesanan " << i+1 << " | "<< simpanPesanan[i].namaMenu << " " << simpanPesanan[i].kuantitas << " porsi, Rp. " << simpanPesanan[i].totalHarga << endl;
    }
    cout << "\nTotal harga pesanan anda: Rp. " << hitungTotalHarga() << endl;
    garis();
    cout << "Terima kasih telah memesan di Senowedari. Selamat menikmati!\n";
    cout << "Jangan lupa datang kembali!";
    garis();

}
