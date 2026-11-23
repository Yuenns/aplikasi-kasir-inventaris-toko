#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    char nama[100], pembeli[100];
    int harga , stok, jumlah, total, jumtotal, jumbayar, kembalian;
    string input, kode;

    //inventaris
    ifstream in("barang.txt");
    if (!in) {
        cerr << "\n[error] Gagal membuka file 'barang.txt'!\n";
        cerr << "Pastikan file 'barang.txt' sudah ada dan dapat diakses.\n";
        return 1;
    }

    //Daftar menu, harga, dan stok
    cout << "========================================================================" << endl;
    cout << "                          UMSAMART                                        " << endl;
    cout << "========================================================================" << endl;
    cout << "Nama pembeli: ";
    cin >> pembeli;
    
    std::string nama_barang, kode_barang, jumlah_barang,harga_barang;
    cout << "Daftar Menu:\n";
    while (std::getline(in, nama_barang) && std::getline(in, kode_barang) && std::getline(in, jumlah_barang) && std::getline(in, harga_barang)) {
        cout << "Nama_Barang: " << nama_barang << '\n';
        cout << "Kode_Barang: " << kode_barang << '\n';
        cout << "Jumlah_Barang: " << jumlah_barang << "\n\n";
        cout << "Harga_Barang: " << harga_barang << "\n\n";
    }
    in.close();

    // Input kode menu dan jumlah pesanan
    cout << endl;
    cout << "Masukkan kode barang: ";
    cin >> kode;
    cout << "Masukkan jumlah pesanan: ";
    cin >> jumlah;
    if (jumlah <= 0 || jumlah > 20) {
        cout << "Jumlah pesanan tidak valid" << endl;
        return 0; // loop program jika jumlah pesanan kurang dari atau sama dengan 0
    }

    // menghitung total belanja
    total = std::stoi(harga_barang) * jumlah;
    cout << "Total belanja: Rp. " << total << endl;

    // uang yang dibayarkan
    cout << "Masukkan jumlah uang yang dibayarkan: Rp. ";
    cin >> jumbayar;
    if (jumbayar < total) {
        cout << "Uangmu kurang kocak" << endl;
        return 0; // loop program jika uang yang dibayarkan kurang dari total belanja
    }

    // menghitung kembalian
    kembalian = jumbayar - total;
    cout << "Kembalian: Rp. " << kembalian << endl;

    // menampilkan struk pembayaran
    cout << endl;
    cout << "======================================================================" << endl;
    cout << "                          STRUK PEMBAYARAN                             " << endl;
    cout << "======================================================================" << endl;
    cout << "Nama pembeli : " << pembeli << endl;
    cout << "Kode barang  : " << kode << endl;
    cout << "Jumlah       : " << jumlah << endl;
    cout << "Total        : Rp. " << total << endl;
    cout << "Uang bayar   : Rp. " << jumbayar << endl;
    cout << "Kembalian    : Rp. " << kembalian << endl;
    cout << "======================================================================" << endl;
    cout << "Terima kasih telah berbelanja HIHUUU" << endl;
    cout << "======================================================================" << endl;

    // apakah ingin melakukan transaksi lagi
    cout << "Apakah Anda ingin melakukan transaksi lagi? (y/Y): ";
    cin >> input;
    if (input == "y" || input == "Y") {
        main(); // memanggil fungsi main() untuk melakukan transaksi lagi
    }
}