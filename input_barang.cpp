#include <iostream>
#include <fstream>
#include <string>
int main() {
    std::string nama_barang, kode_barang, jumlah_barang, harga_barang;

    std::cout << " === Input Data Barang ===\n\n";

    std::cout << "Masukkan nama barang: ";
    std::getline(std::cin, nama_barang);

    std::cout << "Masukkan kode barang: ";
    std::getline(std::cin, kode_barang);

    std::cout << "Masukkan jumlah barang: ";
    std::getline(std::cin, jumlah_barang);

    std::cout << "Masukkan harga barang: ";
    std::getline(std::cin, harga_barang);

    std::ofstream out("barang.txt",std::ios::app);

    if (!out) {
        std::cerr << "\n[error] Gagal membuka/membuat file 'barang.txt'!\n";
        return 1;
    
    }
    out << nama_barang << '\n' << kode_barang << '\n' << jumlah_barang << '\n' << harga_barang << '\n';
    out.close();
    
    std::cout << "\nData berhasil ditambahkan ke 'barang.txt'.\n";
    return 0;
}