#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    std::ifstream in("barang.txt");
    if (!in) {
        std::cerr << "\n[error] Gagal membuka file 'barang.txt'!\n";
        std::cerr << "Pastikan file 'barang.txt' sudah ada dan dapat diakses.\n";
        return 1;
    }

    std::string nama_barang, kode_barang, jumlah_barang, harga_barang;
    std::cout << " === Daftar Barang ===\n\n";
    while (std::getline(in, nama_barang) && std::getline(in, kode_barang) && std::getline(in, jumlah_barang) && std::getline(in, harga_barang)) {
        std::cout << "Nama_Barang: " << nama_barang << '\n';
        std::cout << "Kode_Barang: " << kode_barang << '\n';
        std::cout << "Jumlah_Barang: " << jumlah_barang << "\n\n";
        std::cout << "Harga_Barang: " << harga_barang << "\n\n";
    }
    in.close();
    return 0;
}    