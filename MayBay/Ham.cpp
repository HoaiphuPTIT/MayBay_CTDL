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

void khungNhap() {
	Normal();
	gotoxy(COT + 25, DONGTD);
	cout << "NHAP MAY BAY";
	gotoxy(COT, DONGNHAP1);
	cout << "Nhap so hieu:";
	veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP1 + 1);
	gotoxy(COT, DONGNHAP2);
	cout << "Nhap loai may bay:";
	veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP2 + 1);
	gotoxy(COT, DONGNHAP3);
	cout << "Nhap so day:";
	veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP3 + 1);
	gotoxy(COT, DONGNHAP4);
	cout << "Nhap so dong:";
	veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP4 + 1);
}
maybay createMB(LIST_MB& lstMB, mayBay &mb) {
	khungNhap();

	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	cin.getline(mb.soHieuMayBay, 20);

	gotoxy(COT + 1, DONGNHAP2 + 2);
	rewind(stdin);
	cin.getline(mb.loaiMayBay, 45);

	gotoxy(COT + 1, DONGNHAP3 + 2);
	cin >> mb.soDay;

	gotoxy(COT + 1, DONGNHAP4 + 2);
	cin >> mb.soDong;

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

int delete_MB(LIST_MB& lstMB, int i){
	int j;
	if (empty(lstMB)) {
		return FALSE;
	}
	for (j = i + 1; j < lstMB.n; j++){
		lstMB.nodeMB[j - 1] = lstMB.nodeMB[j];
	}
	lstMB.n--;
	return TRUE;
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
	system("cls");
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
	system("cls");
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