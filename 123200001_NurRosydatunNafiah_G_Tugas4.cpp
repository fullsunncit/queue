#include <iostream>
#include <malloc.h>
#define max 15
#define True 1
#define False 0

using namespace std;

struct typequeue{ //mendefinisikan strust typequeue yang berisi int belakang dan elemen[max] dgn max =12
	int belakang;
	int elemen[max];
};
typequeue queue; 

struct ada{ // mendefinisikan struct ada berisi int jumlah dan total, string nama
	string nama;
	int jumlah;
	int total;
};
ada data[max]; //struct ada berisi data[max] dn max=12

int harga; 
void s(); // fungsi s untuk menentukan harga dari stok yg ada
void kirim(); // fungsi kirim perhiasan
void buatqueue(); //mendefinisikan fungsi buatqueue dgn inisialisasi queue.belakang = 0
void cetakqueue(); // fungsi cetak daftar transaksi
void enqueue(int IB); // fungsi enqueue dgn parameter IB untuk menyisipkan antrian
void dequeue(); //fungsi dequeque untuk menghapus data pada saat membatalkan kiriman
int queuekosong(); //fungsi queuekosong untuk mengecek apakah antrian kosong
int queuepenuh(); // fungsi queuepenyh untuk mengecek apakah antrian penuh
int pilihan, byk, j;
char back;
int stok = 15; //menginisialisasi stok = 15


int main(){
	buatqueue(); //memanggil fungsi buat queue
	do{
		system("cls");
		cout<<"Nama  : Nur Rosydatun Nafiah\n";
		cout<<"NIM   : 123200001\n";
		cout<<"Kelas : Praktikum Struktur Data - G\n\n";
		
		cout<<"~~~< Pre-Order Premium Jewelry >~~~\n\n";
		cout<<"0. Lihat Stock\n";
		cout<<"1. Beli Barang\n";
		cout<<"2. Lihat Daftar Transaksi\n";
		cout<<"3. Batalkan Pesanan\n";
		cout<<"4. Kirim Pesanan\n";
		cout<<"5. Exit\n\n";
		cout<<"   Pilih = "; cin>>pilihan;//input pilihan
		cout<<"\n";
		s(); //memanggil fungsi s untuk mengecek jumlah stok dan harga
		if(pilihan == 0){
			cout<<"Stok Perhiasan Saat Ini : "<<stok<<"\n";
			if(stok == 0){ // jika stok kosong
				cout<<"Maaf, Stok Sudah HABIS!!\n";
			}
			else{//jika stok tidak kosong
				cout<<"Dengan Harga "<<harga<<" juta rupiah per satuannya\n";
			}
		}
		else if(pilihan == 1){
			cout<<"Masukkan banyak data pembeli : "; cin>>byk;//input byk data
			cout<<"\n";
			for(int i=1; i <= byk; i++){
				cout<<"Pembeli "<<i<<"\n";
				cout<<"   Nama    = "; cin>>data[i].nama;//input data nama
				cout<<"   Jumlah  = "; cin>>data[i].jumlah;//input data jumlah
				if(stok >= data[i].jumlah){ //jika stok melebihi atau sama dengan input data jumlah
					s();//memanggil fungsi s untuk mngecek jumlah stok dan harganya
					data[i].total = harga * data[i].jumlah;// rumus data total = harga * data jumlah
					cout<<"   Total Pembelian seharga "<<data[i].total<<".000.000 rupiah.\n";//output data total
					stok = stok - data[i].jumlah;// stok dikurangi data jumlah
					enqueue(i);//memangil fungsi enqueue dengan parameter int i
				}
				else{//jika stok tidak cukup
					cout<<"   Maaf stok perhiasan tidak cukup!!!\n";
				}
				cout<<"\n";	
			}			
		}
		else if(pilihan == 2){
			cetakqueue();//panggil fungsi cetakqueue untuk menyetak daftar transaksi
		}
		else if(pilihan == 3){
			dequeue(); //panggil fungsi dequeue untuk menahpus pesanan yg dibatalkan
		}
		else if(pilihan == 4){
			kirim(); // pangil fungsi kirim untuk mengirim perhiasan
		}
		else if(pilihan == 5){
			exit(0); //keluar
		}
		else{//jika pilihan < 0 dan > 5
			cout<<"\nPilihan Anda Tidak Ada!!\nSilahkan Ulangi Kembali!\n\n";
			system("pause");
			main();//kembali ke fungsi main
		}
		cout<<"\n--> Kembali ke Menu(y/n)? = "; cin>>back;//input back untuk mengulang atau exit
	}while(back == 'y' || back == 'Y');
}
void s(){
	if(stok <= 15 && stok >= 11){ //jika stok <=15 dan >=11 maka harganya 15
		harga = 15;
	}
	else if(stok <= 10 && stok >= 7){ //jika stok <=10 dan >=7 maka harganya 18
		harga = 18;
	}
	else if(stok <= 6 && stok >= 4){ //jika stok <=6 dan >=4 maka harganya 23
		harga = 23;
	}
	else if(stok <= 3 && stok > 0){ //jika stok <=3 dan >0 maka harganya 30
		harga = 30;
	}
}

void buatqueue(){ 
 	queue.belakang=0; //inisialisasi queue.belakang = 0
}

int queuekosong(){ 
 	if(queue.belakang==0) //jika queue belakang null maka return true, jika tidak retur false
		return(True);
 	else
		return(False); 
}

int queuepenuh(){
	if(queue.belakang==max)//jika queue.belakan = 15 maka return true jika tidak return false
		return(True);
 	else
		return(False); 
}

void enqueue(int IB){//input
	if(queuepenuh())//cek apakah queue penuh
		cout << "queue overflow\n";
 	else{
	 	queue.belakang++;//queue.belakang menjadi queue.belakang + 1
 		queue.elemen[queue.belakang]=IB; //queue.elemen[queue.belakang] samadengan IB 
	}
}

void dequeue(){//hapus
	int ID, i;
 	if(queuekosong()) //cek apakah queue kosong
		cout << "Belum Ada Daftar Transaksi!!\n";
 	else{
	 	ID=queue.elemen[1]; // mengisi ID dari queue.elemen[1]
	 	cout<<"Pemesanan atas nama "<<data[ID].nama<<" berhasil dibatalkan\nTerima Kasih!\n";//output data nama y dibatalkan
	 	stok = stok + data[ID].jumlah; //menambah stok dengan data[ID].jumlah karena pesanan dibatalkan
 		for (i=1; i<queue.belakang; i++){ //perulangan for diawali i=1 dengan batas i<queuebelakang dan i++
 			queue.elemen[i]=queue.elemen[i+1]; // mengisi queue.elemen[i] menjadi queue.elemen[i+1] 
		}
 		queue.belakang--; // queue.belakang menjadi queue.belakang-1
		}
}

void cetakqueue(){
	if(queue.belakang != 0){ //cek jika queue.belakang tidak 0 atau ada isinya
		int i=1;//inisialisasi i =1
		while(i<=queue.belakang){ //perulangan while jika i <= queue.belakang
			cout<<"Pelanggan ke-"<<queue.elemen[i]<<"\n"; //output queue.elemen[i]
			cout<<"     Nama   = "<<data[queue.elemen[i]].nama<<"\n"; // output data nama dengan index queue.elemen[i]
			cout<<"     Jumlah = "<<data[queue.elemen[i]].jumlah<<"\n\n"; // output data jumlah dgn index queue.elemen[i]
			i++; //i = i + 1
		}
	}
	else{//jika dftar kosong/queue.belakang=0
		cout<<"Belum Ada Daftar Transaksi!!\n";
	}
}

void hapus(){//hapus stelah kirim perhiasan
	int ID, i;
	ID=queue.elemen[1]; //mengisi ID dari queue.elemen[1]
 	for (i=1; i<queue.belakang; i++){//prulangan for diawali i =1, batas i<queue.belakang dan i++
 		queue.elemen[i]=queue.elemen[i+1]; // mengisi queue.elemen[i] menjadi queue.elemen[i+1] 
	}
 	queue.belakang--;// queue.belakang menjadi queue.belakang-1
}

void kirim(){
	if(queue.belakang != 0){//cek jika queue.belakang tidak 0
		j = 1;//inisialisasi j=1
		cout<<"Perhiasan dengan data berikut berhasil dikirimkan : \n";
		cout<<"   - Nama   = "<<data[queue.elemen[j]].nama<<"\n";//output data nama dgn index queue.elemen[1]
		cout<<"     Jumlah = "<<data[queue.elemen[j]].jumlah<<"\n\n";//output data jumlah dgn index queue.elemen[1]
		hapus(); // panggil fungsi hapus antrian karena perhiasan berhasil dikirimkan
		if(queue.belakang != 0){ // cek apakah daftar transaksi tidak kosong
			cout<<"Perhiasan dengan data berikut belum dikirim : \n";
			j=1; // inisialisasi j = 1
			while(j<=queue.belakang){//perulangan while jika i <= queue.belakang
				cout<<"   - Nama   = "<<data[queue.elemen[j]].nama<<"\n";// output data nama dengan index queue.elemen[i]
				cout<<"     Jumlah = "<<data[queue.elemen[j]].jumlah<<"\n\n";// output data jumlah dengan index queue.elemen[i]
				j++; // j = j + 1
			}
		}
		else{//jika daftar transaksi kosong
			cout<<"Semua Data Sudah Berhasil Dikirimkan\n";
		}
	}
	else{//jika daftar transaksi kosong
		cout<<"Belum Ada Daftar Transaksi!!\n";
	}
}
