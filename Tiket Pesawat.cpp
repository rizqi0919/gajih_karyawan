//Librari untuk mengarahkan Compilator yang akan digunakan
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string.h>
//untuk memanggil class/object/fungsi yang terdapat di dalam namespace tersebut
using namespace std;
//Program dasar dalam penentuan koordinat
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//fungsi cetakc untuk mencetak ditengah layar
void cetakc(int a, char *teks)
{
	gotoxy(40-((strlen(teks)/2)),a);cout<<teks;
}
//fungsi cetak untuk mencetak pada koordinat tertentu
void cetak(int a, int b, char *teks)
{
	gotoxy(a,b);cout<<teks;
}
//bagian untuk menaruh fungsi yang akan dijalankan
void header();
void tabel();
void isi();
char tanya();
long hrgakls(char kelas);
long hrgadskon(char promo, long harga);
long tiketanak(long JumlahAnak,long harga,long discon);
long tiketdwsa(long harga,long discon,long jmlhDwasa);
long tothrg(long hganak,long hgdwasa);
long jmldwsa(long jmlhDwsa,long jmlhDwasa);
long jmlank(long jumlahAnak,long JumlahAnak);
long jmlHg(long jmlHgAnk,long hganak);
long jmlHgDws(long jmlHgDwsa,long hgdwasa);
long jmlTotl(long jumlahTot,long totlharga);
//Bagian fungsi (function) utama, fungsi yang akan dibaca oleh kompilator pertama kali secara otomatis,
int main ()
{
	header();
	tabel();
	getch();
	isi();
}
//Definisi fungsi tanpa nilai balik untuk mencetak bagian header
void header(){
	cetak(45,0, "REKAPITULASI PENJUALAN TIKET PESAWAT");
	cetak(50,1, "RAMAH TOUR & TREVEL");
	cetak(0,3, "BULAN : ");
	cetak(0,4, "TAHUN : ");
}
//Definisi fungsi tanpa nilai balik untuk mencetak bagian Tabel
void tabel(){
	cetak(0,5, "======================================================================================================================");
	cetak(0,6, "| No |  Pesawat     |Kelas|     Promo    |  Harga    |  Discon | Jmlh Dewasa| Jml Anak | Hg anak |HgDewasa|TotlHarga |");
	cetak(0,7, "======================================================================================================================");
	for(int i=1;i<=12;i++)
	{
	cetak(0,7+i, "|    |              |     |              |           |         |            |          |         |        |          |");
	}
	cetak(0,20, "======================================================================================================================");
	cetak(0,21, "|                                                      Jumlah  |            |          |         |        |          |");
	cetak(0,22, "======================================================================================================================");
}
//Definisi fungsi tanpa nilai balik untuk mencetak bagian isi dari program yang akan dijalankan
void isi(){
	struct orang {
		int i=1;
    	char bulan[30],tahun[25], nama[45],jawab ,promo, kelas;
    	long harga, JumlahAnak ,discon,tunjAnak,jmlhDwasa,hganak, hgdwasa, totlharga,jmlhDwsa=0,jumlahAnak=0,jmlHgAnk=0,jmlHgDwsa=0,jumlahTot=0;
};
orang Input;
	gotoxy(8,3);cin>>Input.bulan;
	gotoxy(8,4);cin>>Input.tahun;
	do
	{
		gotoxy(2,7+Input.i);cout<<Input.i;
		gotoxy(7,7+Input.i);cin>>Input.nama;
		gotoxy(22,7+Input.i);cin>>Input.kelas;
		gotoxy(28,7+Input.i);cin>>Input.promo;
		gotoxy(65,7+Input.i);cin>>Input.jmlhDwasa;
		gotoxy(78,7+Input.i);cin>>Input.JumlahAnak;
		Input.harga=hrgakls(Input.kelas);
        gotoxy(43,7+Input.i);cout<<Input.harga;
        Input.discon=hrgadskon(Input.promo, Input.harga);
		gotoxy(55,7+Input.i);cout<<Input.discon;
		Input.hganak=tiketanak(Input.JumlahAnak,Input.harga,Input.discon);
		gotoxy(88,7+Input.i);cout<<Input.hganak;
		Input.hgdwasa=tiketdwsa(Input.harga,Input.discon,Input.jmlhDwasa);
		gotoxy(98,7+Input.i);cout<<Input.hgdwasa;
		Input.totlharga=tothrg(Input.hganak,Input.hgdwasa);
		gotoxy(107,7+Input.i);cout<<setw(10)<<Input.totlharga;
		Input.jmlhDwsa=jmldwsa(Input.jmlhDwsa,Input.jmlhDwasa);
	    gotoxy(62,21);cout<<setw(10)<<Input.jmlhDwsa;
	    Input.jumlahAnak=jmlank(Input.jumlahAnak,Input.JumlahAnak);
	    gotoxy(74,21);cout<<setw(10)<<Input.jumlahAnak;
	    Input.jmlHgAnk=jmlHg(Input.jmlHgAnk,Input.hganak);
	    gotoxy(85,21);cout<<setw(10)<<Input.jmlHgAnk;
	    Input.jmlHgDwsa=jmlHgDws(Input.jmlHgDwsa,Input.hgdwasa);
	    gotoxy(95,21);cout<<setw(10)<<Input.jmlHgDwsa;
	    Input.jumlahTot=jmlTotl(Input.jumlahTot,Input.totlharga);
	    gotoxy(105,21);cout<<setw(10)<<Input.jumlahTot;
	    Input.jawab=tanya();
		Input.i++;
		gotoxy(40,4);cout<<"                          ";
	}while(Input.jawab=='y'||Input.jawab=='Y');
}
//fungsi untuk menentukan apakah ingin lanjut programnya atau ingin berhenti
char tanya(){
	char jw;
	cetak(40,4, "Isi Data Lagi[Y/T] : ");
	cin>>jw;
	cetak(40,4, "                          ");
	return (jw);
}
//fungsi untuk menentukan harga tiket pesawat yang dibelli dengan perbedaan kelas yang diambil
long hrgakls(char kelas)
{
	 if (kelas == 'e') {
	            return(500000);
	        } else {
	            if (kelas == 'b') {
	                return(750000);
	            }
	        }
}
//fungsi untuk menghitung diskon yang didapatkan 
long hrgadskon(char promo, long harga)
{
	 if (promo == 'y') {
	            return((double) 25 / 100 * harga);
	        } else {
	            if (promo == 't') {
	                return((double) 0 / 100 * harga);
	            }
	        }
}
//fungsi menghitung harga tiket untuk anak anak
long tiketanak(long JumlahAnak,long harga,long discon)
{
	long tiktanak;
	tiktanak=JumlahAnak*(harga-discon)*50/100;
	return (tiktanak);
}
//fungsi menghitung total harga tiket orang dewasa
long tiketdwsa(long harga,long discon,long jmlhDwasa)
{
	long tiktdwasa;
	tiktdwasa=(harga-discon)*jmlhDwasa;
	return (tiktdwasa);
}
//fungsi menghitung total harga tiket anak anak
long tothrg(long hganak,long hgdwasa)
{
	long tothrga;
	tothrga=hganak+hgdwasa;
	return (tothrga);
}
//fungsi menghitung jumlah keseluruhan orang dewasa yang ikut penerbangan pesawat
long jmldwsa(long jmlhDwsa,long jmlhDwasa)
{
	long jmlhdewsa;
	jmlhdewsa=jmlhDwsa+jmlhDwasa;
	return (jmlhdewsa);
}
//fungsi jumlah keseluruhan anak yang ikut penerbangan pesawat
long jmlank(long jumlahAnak,long JumlahAnak)
{
	long jmlhank;
	jmlhank=jumlahAnak+JumlahAnak;
	return (jmlhank);
}
//fungsi jumlah harga keseluruhan penumpang anak anak
long jmlHg(long jmlHgAnk,long hganak)
{
	long jmlhHg;
	jmlhHg=jmlHgAnk+hganak;
	return (jmlhHg);
}
//fungsi jumlah harga keseluruhan penumpang dewasa
long jmlHgDws(long jmlHgDwsa,long hgdwasa)
{
	long jmlhHgDwsaa;
	jmlhHgDwsaa=jmlHgDwsa+hgdwasa;
	return (jmlhHgDwsaa);
}
//Fungsi total jumlah harga tiket penerbangan keseluruhan
long jmlTotl(long jumlahTot,long totlharga)
{
	long jmlhTot;
	jmlhTot=jumlahTot+totlharga;
	return (jmlhTot);
}

