#pragma once
#include "ThuVien.h"
#include "mylib.h"

//using namespace std;

//============ ham xu ly danh sach may bay ===============//
int empty(LIST_MB lstMB) {
	return lstMB.n == 0;
}

int full(LIST_MB lstMB) {
	return lstMB.n == MAXLIST;
}

maybay createMB(LIST_MB& lstMB, mayBay &mb) {
	khungNhap(NHAP_MB, "THEM MAY BAY", "So hieu may bay:", "Loai may bay:", "So day:", "So dong:");

	*mb.soHieuMayBay = '\0';
	*mb.loaiMayBay = '\0';

	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	NhapMA(mb.soHieuMayBay, 20);
	

	gotoxy(COT + 1, DONGNHAP2 + 2);
	rewind(stdin);
	NhapCHUOI_SO(mb.loaiMayBay, 45);

	gotoxy(COT + 1, DONGNHAP3 + 2);
	Nhap_SO(mb.soDay, 11);

	gotoxy(COT + 1, DONGNHAP4 + 2);
	Nhap_SO(mb.soDong, 11);

	return mb;
}

int insert_MB(LIST_MB& lstMB, mayBay mb) {
	NODEMAYBAY p = new nodeMB;
	p->data = mb;
	if (full(lstMB)){
		return FALSE;
	}
	lstMB.nodeMB[lstMB.n++] = p;
	return TRUE;
}

int search_MB(LIST_MB lstMB, char ma[]) {
	cout << ma;
	for (int i = 0; i < lstMB.n; i++) {
		if (stricmp(lstMB.nodeMB[i]->data.soHieuMayBay, ma) == 0) {
			return i;
		}
			
	}
	return -1;
}

int delete_MB(LIST_MB& lstMB, int i){
	int j;
	if (empty(lstMB)) {
		return FALSE;
	}
	if (i == -1)
		return FALSE;
	for (j = i + 1; j < lstMB.n; j++){
		lstMB.nodeMB[j - 1] = lstMB.nodeMB[j];
	}
	lstMB.n--;
	return TRUE;
}
char* gdTimMa(LIST_MB lstMB, int type, string title) {
	khungNhap(type, title);

	char temp[20] = { '\0' };
	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	NhapMA(temp, 20);
	return temp;
}

int hieuChinh_MB(LIST_MB& lstMB, int i) {
	khungNhap(SUA_MB, "HIEU CHINH MAY BAY", "So hieu may bay:", "Sua loai may bay:", "Sua so day:", "Sua so dong:");
	if (i == -1)
		return FALSE;
	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	cout << lstMB.nodeMB[i]->data.soHieuMayBay;

	*lstMB.nodeMB[i]->data.loaiMayBay = '\0';
	gotoxy(COT + 1, DONGNHAP2 + 2);
	rewind(stdin);
	NhapCHUOI_SO(lstMB.nodeMB[i]->data.loaiMayBay, 45);

	gotoxy(COT + 1, DONGNHAP3 + 2);
	Nhap_SO(lstMB.nodeMB[i]->data.soDay, 11);

	gotoxy(COT + 1, DONGNHAP4 + 2);
	Nhap_SO(lstMB.nodeMB[i]->data.soDong, 11);
	return TRUE;
}
void show_MB(LIST_MB lstMB) {
	veKhungDS(DONGDS_D - DONGDS_U, COTDS_R - COTDS_L, 5, 25, 70, 93);

	for (int i = 0; i < lstMB.n; i++) {
		//5, 25, 70, 93
		gotoxy(COTDS_L + 1, DONGDS_U + 3 + i);
		cout << i + 1;
		gotoxy(COTDS_L + 6, DONGDS_U + 3 + i);
		cout << lstMB.nodeMB[i]->data.soHieuMayBay;
		gotoxy(COTDS_L + 26, DONGDS_U + 3 + i);
		cout << lstMB.nodeMB[i]->data.loaiMayBay;
		gotoxy(COTDS_L + 71, DONGDS_U + 3 + i);
		cout << lstMB.nodeMB[i]->data.soDay;
		gotoxy(COTDS_L + 94, DONGDS_U + 3 + i);
		cout << lstMB.nodeMB[i]->data.soDong;
	}
	
}

// ============== ham xu ly danh sach chuyen bay ============//

CHUYENBAY createCB(PTRChuyenBay lstCB, CHUYENBAY cb, LIST_MB lstMB) {
	return cb;
}
//========== doc xuat file ===============
int loadMB(LIST_MB& mb) {
	fstream inFile;
	inFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/MayBay.txt", ios::in);
	string temp;
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			mb.nodeMB[mb.n] = new nodeMB;
			getline(inFile, temp);
			inFile.getline(mb.nodeMB[mb.n]->data.soHieuMayBay, 20);
			inFile.getline(mb.nodeMB[mb.n]->data.loaiMayBay, 45);
			inFile >> mb.nodeMB[mb.n]->data.soDay;
			inFile >> mb.nodeMB[mb.n]->data.soDong;
			mb.n++;
		}
	}
	else {
		return 0;
	}
	//mb.n--;
	inFile.close();
	return 1;
}
int saveMB(LIST_MB mb) {
	fstream outFile;
	outFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/MayBay.txt", ios::out);
	int i = 0;
	if (outFile.is_open()) {
		while (i < mb.n) {
			outFile << endl << mb.nodeMB[i]->data.soHieuMayBay;
			outFile << endl << mb.nodeMB[i]->data.loaiMayBay;
			outFile << endl << mb.nodeMB[i]->data.soDay;
			outFile << endl << mb.nodeMB[i]->data.soDong;
			i++;
		}
	}
	else {
		return 0;
	}
	outFile.close();
	return 1;
}

//========== xu ly nhap chuoi ===========
void NhapMA(char var[], int len) {
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(var);

	for (int i = 0; i < nhap.n; i++) {
		nhap.data[i] = new char;
		*nhap.data[i] = var[i];
	}
	while (true) {
		if (kbhit()) {
			char c = getch();
			if (!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122)
				&& !((int)c >= 48 && (int)c <= 57)) && nhap.n < maxInput) {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ' && c == ' ')
					continue;
				if (!(nhap.n == 0 && (int)c >= 48 && (int)c <= 57)) {
					c = toupper(c);
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}
				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		var[i] = *nhap.data[i];
	}
	var[nhap.n] = '\0';
}

void NhapCHUOI_SO(char var[], int len) {
	
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(var);
	
	for (int i = 0; i < nhap.n; i++) {
		nhap.data[i] = new char;
		*nhap.data[i] = var[i];
	}
	while (true) {
		if (kbhit()) {
			char c = getch();
			if (!kbhit() && !(!((int)c >= 65 && (int)c <= 90) && !((int)c >= 97 && (int)c <= 122)
				&& c != ' ' && !((int)c >= 48 && (int)c <= 57)) && nhap.n < maxInput) {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ' && c == ' ')
					continue;
				if (!(nhap.n == 0 && (c == ' ' || ((int)c >= 48 && (int)c <= 57)))) {
					if (nhap.n == 0)
						c = toupper(c);
					else {
						if (*nhap.data[nhap.n - 1] == ' ')
							c = toupper(c);
						else
							c = tolower(c);
					}
					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
			}
			if (c == '\r') {
				if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					if (nhap.n > 0)
						nhap.n--;
				}
				break;
			}
			if (c == BACKSPACE && nhap.n > 0) {
				gotoxy(wherex() - 1, wherey());
				cout << " ";
				gotoxy(wherex() - 1, wherey());
				nhap.n--;
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		var[i] = *nhap.data[i];
	}
	var[nhap.n] = '\0';
}

void Nhap_SO(int &var, int len) {
	char num[12] = { '\0' };
	int maxInput = len;
	if (maxInput == 0)
		maxInput = MAX_INPUT;
	
	rewind(stdin);
	NhapChuoi nhap;
	nhap.n = strlen(num);

	for (int i = 0; i < nhap.n; i++) {
		nhap.data[i] = new char;
		*nhap.data[i] = num[i];
	}
	while (true) {
		if (kbhit()) {
			char c = getch();
			if (nhap.n < 11) {
				if (!kbhit() && (int)c >= 48 && (int)c <= 57 && nhap.n < maxInput) {

					nhap.data[nhap.n] = new char;
					cout << c;
					*nhap.data[nhap.n] = c;
					nhap.n++;
				}
				if (c == '\r') {
					if (nhap.n > 0 && *nhap.data[nhap.n - 1] == ' ') {
						gotoxy(wherex() - 1, wherey());
						cout << " ";
						gotoxy(wherex() - 1, wherey());
						if (nhap.n > 0)
							nhap.n--;
					}
					break;
				}
				if (c == BACKSPACE && nhap.n > 0) {
					gotoxy(wherex() - 1, wherey());
					cout << " ";
					gotoxy(wherex() - 1, wherey());
					nhap.n--;
				}
			}
		}
	}
	for (int i = 0; i < nhap.n; i++) {
		num[i] = *nhap.data[i];
	}
	num[nhap.n] = '\0';
	var = atoi(num);
}
//========== giao dien =============

void veKhungGiaoDIen() {
	for (int i = 0; i < WIDTH; i++)	{
		gotoxy(i + 2, 0);
		cout << char(NGANG);
	}
	gotoxy(2, 0);
	cout << char(UPLEFT);
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(2, i + 1);
		cout << char(DOC);
	}
	gotoxy(WIDTH + 1, 0);
	cout << char(UPRIGHT);
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(WIDTH + 1, i + 1);
		cout << char(DOC);
	}
	for (int i = 0; i < WIDTH; i++) {
		gotoxy(i + 2, HEIGHT + 1);
		cout << char(NGANG);
	}
	gotoxy(2, HEIGHT + 1);
	cout << char(DOWNLEFT);
	gotoxy(WIDTH + 1, HEIGHT + 1);
	cout << char(DOWNRIGHT);

	gotoxy(2, 8);
	cout << char(BELEFT);
	for (int i = 0; i < MIDDLE_DOC; i++) {
		gotoxy(i + 3, 8);
		cout << char(NGANG);
	}
	gotoxy(MIDDLE_DOC + 3, 0);
	cout << char(BEUP);
	gotoxy(MIDDLE_DOC + 3, MIDDLE_NGANG + 1);
	cout << char(BERIGHT);
	for (int i = 0; i < MIDDLE_NGANG; i++) {
		gotoxy(MIDDLE_DOC + 3, i + 1);
		cout << char(DOC);
	}
	for (int i = 0; i < (HEIGHT - MIDDLE_NGANG) - 1; i++) {
		gotoxy(MIDDLE_DOC + 3, i + MIDDLE_NGANG + 2);
		cout << char(DOC);
	}
	gotoxy(MIDDLE_DOC + 3, HEIGHT + 1);
	cout << char(BEDOWN);
}

void veKhungNhap(int dai, int rong, int posx, int posy, string source)
{
	int len = source.length();
	if (dai == 0)
		dai = len + 2;
	for (int i = 0; i < dai; i++) // top
	{
		gotoxy(posx + i, posy);
		cout << char(196);
	}
	gotoxy(posx, posy);
	cout << char(218); // top-left
	gotoxy(posx + dai, posy);
	cout << char(191); // top-right
	for (int i = 1; i <= rong; i++) // right
	{
		gotoxy(posx + dai, posy + i);
		cout << char(179);
	}
	for (int i = 0; i < dai; i++) // bot
	{
		gotoxy(posx + i, posy + rong);
		cout << char(196);
	}
	gotoxy(posx + dai, posy + rong);
	cout << char(217);	// bot-right	
	for (int i = 1; i <= rong; i++) // left
	{
		gotoxy(posx, posy + i);
		cout << char(179);
	}
	gotoxy(posx, posy + rong);
	cout << char(192); // bot-left
	gotoxy(posx - len / 2 + dai / 2, posy + round(rong / 2));
	cout << source;
}

void veKhungDS(int rong, int dai, int colump1, int colump2, int colump3, int colump4,
	int colump5, int posx, int posy) {
	if (posx == 0 || posy == 0)
	{
		posx = COTDS_L;
		posy = DONGDS_U;
	}
	veKhungNhap(dai, rong, posx, posy);
	for (int v = 0; v < dai - 1; v++)
	{
		gotoxy(posx + 1 + v, posy + 2);
		cout << char(196);
	}

	for (int v = 0; v < rong - 1; v++) // colump 1 
	{
		gotoxy(posx + colump1, posy + v + 1);
		cout << char(179);
	}
	gotoxy(posx + colump1, posy + 2);
	cout << char(197);
	for (int v = 0; v < rong - 1; v++) // colump 2 
	{
		gotoxy(posx + colump2, posy + v + 1);
		cout << char(179);
	}
	gotoxy(posx + colump2, posy + 2);
	cout << char(197);
	for (int v = 0; v < rong - 1; v++) // colump 3
	{
		gotoxy(posx + colump3, posy + v + 1);
		cout << char(179);
	}
	gotoxy(posx + colump3, posy + 2);
	cout << char(197);
	for (int v = 0; v < rong - 1; v++) // colump 4
	{
		gotoxy(posx + colump4, posy + v + 1);
		cout << char(179);
	}
	gotoxy(posx + colump4, posy + 2);
	cout << char(197);
	if (colump5 != 0)
	{
		for (int v = 0; v < rong - 1; v++) // colump 5
		{
			gotoxy(posx + colump5, posy + v + 1);
			cout << char(179);
		}
		gotoxy(posx + colump5, posy + 2);
		cout << char(197);
	}
	//5, 25, 70, 93
	gotoxy(COTDS_L + 1, DONGDS_U + 1);
	cout << "STT";
	gotoxy(COTDS_L + 6, DONGDS_U + 1);
	cout << "SO HIEU MAY BAY";
	gotoxy(COTDS_L + 26, DONGDS_U + 1);
	cout << "LOAI MAY BAY";
	gotoxy(COTDS_L + 71, DONGDS_U + 1);
	cout << "SO DAY";
	gotoxy(COTDS_L + 94, DONGDS_U + 1);
	cout << "SO DONG";
}
void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void Highlight() {
	SetColor(15);
	SetBGColor(2);
}
int menuDong_Prim(char td[soItem_MenuChinh][100]) {
	Normal();
	//system("cls");
	veKhungGiaoDIen();
	int chon = 0;
	int i;
	for (int i = 0; i < soItem_MenuChinh; i++) {
		gotoxy(COT, DONG + i);
		cout << td[i];
	}
	Highlight();
	gotoxy(COT, DONG + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		switch (kytu){
		case UP:
			if (chon > 0) {
				Normal();
				gotoxy(COT, DONG + chon); cout << td[chon];
				chon--;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case DOWN:
			if (chon + 1 < soItem_MenuChinh) {
				Normal();
				gotoxy(COT, DONG + chon);	cout << td[chon];
				chon++;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case ENTER:
			return chon + 1;
		}
	} while (TRUE);
}

int menuDong_MayBay(char td[soItem_MenuMB][100]) {
	Normal();
	//system("cls");
	veKhungGiaoDIen();
	int chon = 0;
	int i;
	for (int i = 0; i < soItem_MenuMB; i++) {
		gotoxy(COT, DONG + i);
		cout << td[i];
	}
	Highlight();
	gotoxy(COT, DONG + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		switch (kytu) {
		case UP:
			if (chon > 0) {
				Normal();
				gotoxy(COT, DONG + chon); cout << td[chon];
				chon--;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case DOWN:
			if (chon + 1 < soItem_MenuMB) {
				Normal();
				gotoxy(COT, DONG + chon);	cout << td[chon];
				chon++;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case ENTER:
			return chon + 1;
		}
	} while (TRUE);
}

int menuDong_ChuyenBay(char td[soItem_MenuCB][100]) {
	Normal();
	//system("cls");
	veKhungGiaoDIen();
	int chon = 0;
	int i;
	for (int i = 0; i < soItem_MenuCB; i++) {
		gotoxy(COT, DONG + i);
		cout << td[i];
	}
	Highlight();
	gotoxy(COT, DONG + chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		switch (kytu) {
		case UP:
			if (chon > 0) {
				Normal();
				gotoxy(COT, DONG + chon); cout << td[chon];
				chon--;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case DOWN:
			if (chon + 1 < soItem_MenuCB) {
				Normal();
				gotoxy(COT, DONG + chon);	cout << td[chon];
				chon++;
				Highlight();
				gotoxy(COT, DONG + chon); 	cout << td[chon];
			}
			break;
		case ENTER:
			return chon + 1;
		}
	} while (TRUE);
}
void khungNhap(int type, string title, string s1, string s2, string s3, string s4,
	string s5, string s6, string s7, string s8, string s9) {
	Normal();
	
	if (type == XOA_MB || type == SUA_MB) {
		gotoxy(COT + 25, DONGTD);
		cout << title;
		gotoxy(COT, DONGNHAP1);
		cout << "Nhap so hieu can tim:";
		veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP1 + 1);
	}
	else {
		
		gotoxy(COT + 25, DONGTD);
		cout << title;

		gotoxy(COT, DONGNHAP1);
		cout << s1;
		veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP1 + 1);

		gotoxy(COT, DONGNHAP2);
		cout << s2;
		veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP2 + 1);
		
		gotoxy(COT, DONGNHAP3);
		cout << s3;
		veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP3 + 1);
		
		if (type == NHAP_CB) {
			// khung nhap ngay
			gotoxy(COT, DONGNHAP4);
			cout << s4;
			veKhungNhap(DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP4 + 1);

			gotoxy(COT + DAIKHUNGNHO, DONGNHAP4);
			veKhungNhap(DAIKHUNGNHO + DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP4 + 1);

			gotoxy(COT + DAIKHUNGNHO + DAIKHUNGNHO, DONGNHAP4);
			veKhungNhap(DAIKHUNGNHO + DAIKHUNGNHO + DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP4 + 1);

			// khung nhap gio
			gotoxy(COT, DONGNHAP5);
			cout << s5;
			veKhungNhap(DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP5 + 1);

			gotoxy(COT + DAIKHUNGNHO, DONGNHAP5);
			veKhungNhap(DAIKHUNGNHO + DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP5 + 1);
		}
		else {
			gotoxy(COT, DONGNHAP4);
			cout << s4;
			veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP4 + 1);
		}

	}
	
}