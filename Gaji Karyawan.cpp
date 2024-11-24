#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main ()
{
	gotoxy(0,0);cout<<"REKAPITULASI GAJI KARYAWAN";
	gotoxy(0,1);cout<<"PT. MAJU JAYA";
	gotoxy(0,3);cout<<"BULAN : ";
	gotoxy(0,4);cout<<"TAHUN : ";
	gotoxy(0,5);cout<<"======================================================================================================================";
	gotoxy(0,6);cout<<"| No |     Nama     | Gol | Status Nikah | Jmlh Anak |  Gapok  | Tunj Istri | TunjAnak |  Gakot  |  Pajak |  Gaber   |";
	gotoxy(0,7);cout<<"======================================================================================================================";
	for(int i=1;i<=12;i++)
	{
	gotoxy(0,7+i);
				cout<<"|    |              |     |              |           |         |            |          |         |        |          |";
	}
	gotoxy(0,20);cout<<"======================================================================================================================";
	gotoxy(0,21);cout<<"|                                              TOTAL |         |            |          |         |        |          |";
	gotoxy(0,22);cout<<"======================================================================================================================";
	int i=1, gol;
	string status;
	char jw, bulan[30],tahun[30] , nama[30];
	long gapok, jmlhAnak ,tunjIstri,tunjAnak,gakot, pajak, gaber, total1=0,total2=0,total3=0,total4=0,total5=0,total=0;
	gotoxy(8,3);cin>>bulan;
	gotoxy(8,4);cin>>tahun;
	do
	{
		gotoxy(2,7+i);cout<<i;
		gotoxy(7,7+i);cin>>nama;
		gotoxy(22,7+i);cin>>gol;
		gotoxy(28,7+i);cin>>status;
		gotoxy(43,7+i);cin>>jmlhAnak;
		 if (gol == 1) {
	            gapok = 750000;
	        } else {
	            if (gol == 2) {
	                gapok = 1000000;
	            } else {
	                if (gol == 3) {
	                    gapok = 1250000;
	                } else {
	                    if (gol == 4) {
	                        gapok = 1500000;
	                    }
	                }
	            }
	        }
        gotoxy(55,7+i);cout<<gapok;
         if (status == "n") {
            tunjIstri = (double) 20 / 100 * gapok;
        } else {
            if (status == "b") {
                tunjIstri = 0;
            } else {
                tunjIstri = 0;
            }
        }
		gotoxy(65,7+i);cout<<tunjIstri;
		if (status == "n") {
            if (jmlhAnak > 2) {
                gotoxy(77,7+i);cout << "harus<=2" << endl;
            } else {
                tunjAnak = (double) (jmlhAnak * 5) / 100 * gapok;
            }
        } else {
            if (status == "b") {
                tunjAnak = 0;
            } else {
                if (jmlhAnak > 2) {
                    gotoxy(77,7+i);cout << "harus<=2" << endl;
                } else {
                    tunjAnak = (double) (jmlhAnak * 5) / 100 * gapok;
                }
            }
        }
		gotoxy(77,7+i);cout<<tunjAnak;
		gakot=gapok+tunjIstri+tunjAnak;
		gotoxy(88,7+i);cout<<gakot;
		if (status == "n") {
            gakot = gapok + tunjAnak + tunjIstri;
            if (gakot >= 1000000) {
                pajak = (double) 5 / 100 * gakot;
            } else {
                pajak = (double) 3 / 100 * gakot;
            }
        } else {
            if (status == "b") {
                gakot = gapok;
                if (gakot >= 1000000) {
                    pajak = (double) 5 / 100 * gakot;
                } else {
                    pajak = (double) 3 / 100 * gakot;
                }
            } else {
                gakot = gapok + tunjAnak;
                if (gakot >= 1000000) {
                    pajak = (double) 5 / 100 * gakot;
                } else {
                    pajak = (double) 3 / 100 * gakot;
                }
            }
        }
		gotoxy(98,7+i);cout<<pajak;
		gaber=gakot-pajak;
		gotoxy(107,7+i);cout<<gaber;
		total1=total1+gapok;
		gotoxy(54,21);cout<<total1;
		total2=total2+tunjIstri;
	    gotoxy(65,21);cout<<total2;
	    total3=total3+tunjAnak;
	    gotoxy(77,21);cout<<total3;
	    total4=total4+gakot;
	    gotoxy(88,21);cout<<total4;
	    total5=total5+pajak;
	    gotoxy(98,21);cout<<total5;
	    total=total+gaber;
	    gotoxy(107,21);cout<<total;
		gotoxy(40,4);cout<<"Isi Data Lagi[Y/T] : ";
		cin>>jw;
		i++;
		gotoxy(40,4);cout<<"                          ";
	}while(jw=='y'||jw=='Y');
	getch();
}
