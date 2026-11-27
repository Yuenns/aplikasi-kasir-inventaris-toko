#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string pembeli;
    std::string input, kode;

    //inventaris
    std::ifstream in("barang.txt");
    if (!in) {
        std::cerr << "\n[error] Gagal membuka file 'barang.txt'!\n";
        std::cerr << "Pastikan file 'barang.txt' sudah ada dan dapat diakses.\n";
        return 1;
    }

    //Daftar menu, harga, dan stok
    std::cout << "========================================================================" << std::endl;
    std::cout << "                          UMSAMART                                        " << std::endl;
    std::cout << "========================================================================" << std::endl;
    std::cout << "Nama pembeli: ";
    
    std::string nama_barang, kode_barang, jumlah_barang,harga_barang;
    std::cout << "Daftar Menu:\n";
    while (std::getline(in, nama_barang) && std::getline(in, kode_barang) && std::getline(in, jumlah_barang) && std::getline(in, harga_barang)) {
        std::cout << "Nama_Barang: " << nama_barang << '\n';
        std::cout << "Kode_Barang: " << kode_barang << '\n';
        std::cout << "Jumlah_Barang: " << jumlah_barang << "\n\n";
        std::cout << "Harga_Barang: " << harga_barang << "\n\n";
    }
    in.close();

    // Input kode menu dan jumlah pesanan
    std::cout << std::endl;
    std::cout << "Masukkan kode barang: ";
    std::cin >> kode;
    std::cout << "Masukkan jumlah pesanan: ";
    int jumlah;
    std::cin >> jumlah;

    if (jumlah <= 0 || jumlah > 20) {
        std::cout << "Jumlah pesanan tidak valid" << std::endl;
        return 0; 
    }

    std::ifstream file("barang.txt");
    bool found = false;
    while (std::getline(file, nama_barang) && std::getline(file, kode_barang) && std::getline(file, jumlah_barang) && std::getline(file, harga_barang)) {
        if (kode == kode_barang) {
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        std::cout << "Barang tidak ada / kode barang tidak valid!" << std::endl;
        return 0;
    }

    // menghitung total belanja
    int total = std::stoi(harga_barang) * jumlah;
    std::cout << "Total belanja: Rp. " << total << std::endl;

    // uang yang dibayarkan
    std::cout << "Masukkan jumlah uang yang dibayarkan: Rp. ";
    int jumbayar;
    std::cin >> jumbayar;
    if (jumbayar < total) {
        std::cout << "Uang yang dibayarkan kurang!" << std::endl; 
    }

    // menghitung kembalian
    double kembalian = jumbayar - total;
    std::cout << "Kembalian: Rp. " << kembalian << std::endl;
    int kembalian_rupiah = static_cast<int>(kembalian);

    // menampilkan struk pembayaran
    std::cout << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::cout << "                          STRUK PEMBAYARAN                             " << std::endl;
    std::cout << "======================================================================" << std::endl;
    std::cout << "Nama pembeli : " << pembeli << std::endl;
    std::cout << "Nama barang  : " << nama_barang << std::endl;
    std::cout << "Kode barang  : " << kode << std::endl;
    std::cout << "Harga        : Rp. " << harga_barang << std::endl;
    std::cout << "Jumlah       : " << jumlah << std::endl;
    std::cout << "Total        : Rp. " << total << std::endl;
    std::cout << "Uang bayar   : Rp. " << jumbayar << std::endl;
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
