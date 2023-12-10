/* Judul        : Program Menemukan_Solusi_Masalah_Subset_Sum            */
/* Deskripsi    : Program untuk mencetak solusi untuk masalah Subset Sum */
/*                berupa himpunan bilangan yang memenuhi telah target    */
/* Developer    : I Kadek Rai Pramana (2105551094)                       */
/* Tanggal      : 08 November 2021                                       */
/* Versi        : 1.0                                                    */

#include <stdio.h>
#include <stdlib.h>

// deklarasi variabel global untuk jumlah solusi
int hitung_solusi;

/* fungsi pembanding fungsi qsort */
int pembanding(const void *bilangan1, const void *bilangan2){
	int *b1 = bilangan1;
	int *b2 = bilangan2;

	return *b1 - *b2;
}/* <0 = elemen yang ditunjuk oleh b1 nilainya lebih rendah dari elemen yang ditunjuk oleh b2
    0  = elemen yang ditunjuk oleh b1 sama besar dengan elemen yang ditunjuk oleh b2
    >0 = elemen yang ditunjuk oleh b1 nilainya lebih tinggi dari elemen yang ditunjuk oleh b2  */

/* fungsi print subset (solusi) */
void printSubset(int solusi[], int total_solusi){
    // deklarasi variabel lokal
    int i;

    printf("\nSolusi ke-%d    : ", ++hitung_solusi);

	for(i = 0; i < total_solusi; i++){
		printf(" %d ", solusi[i]);
	}
	printf("\n");
}

/* fungsi untuk mencari solusi Subset Sum */
void subset_sum(int bilangan[], int total_bil, int solusi[], int i_solusi, int jumlah, int posisi, int target){
    // deklarasi variabel lokal
    int i_bil;

    // base case fungsi rekursif
	if(jumlah == target){               // cek apakah jumlah == target
		printSubset(solusi, i_solusi);  // panggil fungsi printSubset untuk mencetak setiap solusi

		// cek bilangan yang tersisa dan jumlah saat ini (tanpa bilangan saat ini) + bilangan berikutnya <= target
		if(posisi + 1 < total_bil && jumlah - bilangan[posisi] + bilangan[posisi+1] <= target){
            // memanggil fungsi rekursif
			// kecualikan bilangan yang ditambahkan sebelumnya dan pertimbangkan bilangan berikutnya
			subset_sum(bilangan, total_bil, solusi, i_solusi - 1, jumlah - bilangan[posisi], posisi + 1, target);
		}
		return;
		// backtraking ke level posisi sebelumnya
	}else{
		// cek bilangan yang tersisa dan jumlah saat ini + bilangan saat ini <= target
		if(posisi < total_bil && jumlah + bilangan[posisi] <= target){
			// menghasilkan kandidat solusi (bilangan) di sepanjang kedalaman pada suatu level posisi
			for(i_bil = posisi; i_bil < total_bil; i_bil++){
				solusi[i_solusi] = bilangan[i_bil];// menambahkan kandidat solusi dengan kandidat bilangan
                // cek jumlah saat ini + kandidat bilangan <= target
				if(jumlah + bilangan[i_bil] <= target){
					// memanggil fungsi rekursif
					// pertimbangkan level posisi berikutnya di sepanjang kedalaman
					subset_sum(bilangan, total_bil, solusi, i_solusi + 1, jumlah + bilangan[i_bil], i_bil + 1, target);
				}
			}
		}
	}
	return;
}/* jika masih ada bilangan tersisa dan tidak berada di posisi lv.0 maka backtracking ke posisi sebelumnya */
 /* jika tidak ada bilangan tersisa dan berada di posisi lv.0 maka menuju program utama */


/* program utama */
int main(){
    // deklarasi variabel lokal
    int total_bil, i, target, jumlah;

	// meminta input total_bil
    printf("Masukkan total bilangan: ");
    scanf("%d", &total_bil);
    printf("\n");

    // deklarasi array bilangan
    int bilangan[total_bil];

    for(i = 0; i < total_bil; i++){
        // meminta input bilangan
        printf("Masukkan bilangan ke-%d : ", i+1);
        scanf("%d", &bilangan[i]);
    }

    // meminta input target
    printf("\nMasukkan target: ");
    scanf("%d", &target);

    // alokasi memori dinamis untuk array solusi
    /* void * malloc (size_t size) --> fungsi malloc mengembalikan pointer kosong
       maka perlu mengubah tipe data pointer berdasarkan kebutuhan kita */
    // (type_data*)malloc(total_elemen * size_setiap_elemen)
    int *ukuran_solusi = (int*)malloc(total_bil * sizeof(int));
    /* Alokasi memori adalah prosedur menetapkan memori komputer untuk pelaksanaan program dan proses.
       Menggunakan teknik alokasi dinamis ketika tidak diketahui berapa banyak ruang memori yang dibutuhkan
       untuk program dan proses. Memori hanya dialokasikan ketika diperlukan. */

    /* mengurutkan bilangan dengan qsort(array_yang_diurutkan, 
	   size_array, size_setiap_elemen, fungsi_perbandingan) */
	qsort(bilangan, total_bil, sizeof(int), pembanding);

	/*
    // mencetak hasil pengurutan bilangan
    printf("\nUrutkan        : ");
	for(i = 0; i < total_bil; i++){
        printf("%d ", bilangan[i]);
	}
    printf("\n");
    */

	// hitung jumlah semua bilangan
	for(i = 0; i < total_bil; i++){
		jumlah += bilangan[i];
	}

	// cek bilangan terkecil <= target dan jumlah semua bilangan >= target
    if(bilangan[0] <= target && jumlah >= target){
        // memanggil fungsi subset_sum
        subset_sum(bilangan, total_bil, ukuran_solusi, 0, 0, 0, target);
	}else{
        printf("\nSolusi tidak ditemukan\n");
		// aksi yang dilakukan jika tidak memungkinkan menghasilkan solusi
	}

	free(ukuran_solusi);// membebaskan memori yang dialokasikan
	/* fungsi ini untuk menghindari adanya pemborosan memori
       maka harus melakukan dealokasi terhadap ruang-ruang
	   memori yang dialokasikan sebelumnya */

	return 0;
}
