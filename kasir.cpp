#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream in("barang.txt");
    if (!in) {
        std::cerr << "\n[error] Gagal membuka file 'barang.txt'!\n";
        return 1;
    }

    std::string pembeli, input, Kode;                                   
    std::string Nama_barang, Kode_barang, Jumlah_barang, Harga_barang;  

    std::cout << "Nama pembeli: ";
    std::getline(std::cin >> std::ws,pembeli);

    //Daftar menu, harga, dan stok
    std::cout << "========================================================================" << std::endl;
    std::cout << "                          UMSAMART                                        " << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << "Nama pembeli: " << pembeli << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    std::cout << "                          DAFTAR BARANG       " << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
    while (std::getline(in, Nama_barang) && std::getline(in, Kode_barang)
            && std::getline(in, Jumlah_barang) && std::getline(in, Harga_barang)) {
        std::cout << "Nama_Barang: " << Nama_barang << '\n';
        std::cout << "Kode_Barang: " << Kode_barang << '\n';
        std::cout << "Jumlah_Barang: " << Jumlah_barang << '\n';
        std::cout << "Harga_Barang: " << Harga_barang << '\n';
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    }
    in.close();

    // Input Kode menu dan Jumlah pesanan
    std::cout << std::endl;
    std::cout << "Masukkan Kode barang: ";
    std::cin >> Kode;

    std::ifstream file("barang.txt");
    bool found = false;
    while (std::getline(file, Nama_barang) && std::getline(file, Kode_barang) && std::getline(file, Jumlah_barang) && std::getline(file, Harga_barang)) {
        if (Kode == Kode_barang) {
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        std::cout << "Barang tidak ada / Kode barang tidak valid!" << std::endl;
        return 0;
    }
    
    int stock = std::stoi(Jumlah_barang);

    std::cout << "Masukkan Jumlah pesanan: ";
    int Jumlah;
    std::cin >> Jumlah;

    if (Jumlah <= 0 || Jumlah > stock ) {
        std::cout << "Jumlah pesanan tidak valid" << std::endl;
        return 0; 
    }

    // menghitung total belanja
    int total = std::stoi(Harga_barang) * Jumlah;
    std::cout << "Total belanja: Rp. " << total << std::endl;

    // uang yang dibayarkan
    std::cout << "Masukkan Jumlah uang yang dibayarkan: Rp. ";
    int Jumbayar;
    std::cin >> Jumbayar;
    if (Jumbayar < total) {
        std::cout << "Uang yang dibayarkan kurang!" << std::endl; 
        return 0;   
    }

    // menghitung kembalian
    int kembalian = Jumbayar - total;
    std::cout << "Kembalian: Rp. " << kembalian << std::endl;

    // menampilkan struk pembayaran
    std::cout << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::cout << "                          STRUK PEMBAYARAN                             " << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::cout << "Nama pembeli : " << pembeli << std::endl;
    std::cout << "Nama barang  : " << Nama_barang << std::endl;
    std::cout << "Kode barang  : " << Kode_barang << std::endl;
    std::cout << "Harga        : Rp. " << Harga_barang << std::endl;
    std::cout << "Jumlah       : " << Jumlah << std::endl;
    std::cout << "Total        : Rp. " << total << std::endl;
    std::cout << "Uang bayar   : Rp. " << Jumbayar << std::endl;
    std::cout << "Kembalian    : Rp. " << kembalian << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::cout << "Terima kasih telah berbelanja di UMSAMART" << std::endl;
    std::cout << "======================================================================" << std::endl;

    // apakah ingin melakukan transaksi lagi
    std::cout << "Apakah Anda ingin melakukan transaksi lagi? (y/n): ";
    std::cin >> input;
        if (input == "y" || input == "Y") {
            main(); // memanggil fungsi main() untuk melakukan transaksi lagi
    }
    return 0;
}
