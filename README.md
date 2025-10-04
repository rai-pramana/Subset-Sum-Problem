# Subset Sum Problem Solver

Program C untuk menyelesaikan masalah Subset Sum dengan menggunakan teknik backtracking. Program ini mencari semua kemungkinan himpunan bagian dari suatu kumpulan bilangan yang jumlahnya sama dengan target yang ditentukan.

## 📋 Deskripsi

Subset Sum Problem adalah masalah klasik dalam ilmu komputer yang termasuk dalam kategori NP-Complete. Masalah ini bertanya: "Diberikan sebuah himpunan bilangan bulat dan sebuah nilai target, apakah ada subset dari himpunan tersebut yang jumlahnya sama dengan target?"

Program ini tidak hanya menentukan apakah solusi ada, tetapi juga menampilkan semua kemungkinan solusi yang memenuhi target.

## 🔧 Fitur

-   **Pencarian Semua Solusi**: Menemukan dan menampilkan semua subset yang jumlahnya sama dengan target
-   **Algoritma Backtracking**: Menggunakan pendekatan rekursif untuk eksplorasi ruang solusi
-   **Optimasi Sorting**: Mengurutkan input untuk meningkatkan efisiensi algoritma
-   **Memory Management**: Menggunakan alokasi memori dinamis
-   **Input Validation**: Validasi input untuk memastikan solusi yang valid

## 🏗️ Struktur Program

### Fungsi Utama:

1. **`pembanding()`** - Fungsi komparator untuk sorting array
2. **`printSubset()`** - Mencetak subset yang merupakan solusi
3. **`subset_sum()`** - Fungsi rekursif utama untuk mencari solusi
4. **`main()`** - Program utama yang mengelola input/output

### Algoritma:

1. Input bilangan dan target dari user
2. Sort array bilangan secara ascending
3. Gunakan backtracking untuk mencari semua subset
4. Tampilkan semua solusi yang ditemukan

## 📊 Kompleksitas

-   **Time Complexity**: O(2^n) dalam worst case
-   **Space Complexity**: O(n) untuk recursive call stack

## 🚀 Cara Penggunaan

### Kompilasi:

```bash
gcc -o subsetsum subsetsum.c
```

### Menjalankan Program:

```bash
./subsetsum
```

### Contoh Input/Output:

```
Masukkan total bilangan: 4
Masukkan bilangan ke-1 : 3
Masukkan bilangan ke-2 : 34
Masukkan bilangan ke-3 : 4
Masukkan bilangan ke-4 : 12

Masukkan target: 9

Solusi ke-1    :  3  4
```

## 📚 Dokumentasi Visual

### Manual Solution (Penyelesaian Manual)

![Manual Solution 1](./By%20hand/1.jpg)
![Manual Solution 2](./By%20hand/2.jpg)

### Flowchart

#### Main Function Flow

![Main Function](./Flowchart/Subset%20Sum-main.drawio.png)

#### Subset Sum Algorithm Flow

![Subset Sum Function](./Flowchart/Subset%20Sum-subset_sum.drawio.png)

#### Comparison Function Flow

![Comparison Function](./Flowchart/Subset%20Sum-pembanding.drawio.png)

#### Print Subset Function Flow

![Print Function](./Flowchart/Subset%20Sum-printSubset.drawio.png)

## 🔬 Analisis Algoritma

### Pendekatan Backtracking:

-   Program menggunakan recursive backtracking untuk mengeksplorasi semua kemungkinan subset
-   Setiap elemen dapat dipilih atau tidak dipilih
-   Pruning dilakukan untuk menghindari eksplorasi yang tidak perlu

### Optimasi:

-   **Sorting**: Array diurutkan untuk memungkinkan early termination
-   **Pruning**: Jika jumlah sementara melebihi target, cabang tidak dieksplorasi
-   **Early Termination**: Jika bilangan terkecil > target atau jumlah total < target

## 🛠️ Requirements

-   **Compiler**: GCC atau compiler C lainnya
-   **OS**: Windows/Linux/MacOS
-   **Memory**: Minimal untuk menjalankan program C standar

## 👨‍💻 Pengembang

**I Kadek Rai Pramana (2105551094)**

-   Tanggal: 08 November 2021
-   Versi: 1.0

## 📝 Lisensi

Project ini dibuat untuk keperluan akademis.

## 🔍 Contoh Kasus

### Kasus 1: Ada Solusi

-   Input: [3, 34, 4, 12], Target: 9
-   Output: {3, 4}

### Kasus 2: Multiple Solusi

-   Input: [1, 2, 3, 4, 5], Target: 5
-   Output: {5}, {1, 4}, {2, 3}

### Kasus 3: Tidak Ada Solusi

-   Input: [2, 4, 6], Target: 5
-   Output: "Solusi tidak ditemukan"

## 🤝 Kontribusi

Untuk berkontribusi pada project ini:

1. Fork repository
2. Buat branch fitur baru
3. Commit perubahan
4. Push ke branch
5. Buat Pull Request
