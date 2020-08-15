#pragma once
#include "ThuVien.h"
#include "mylib.h"

//using namespace std;

//============ ham xu ly danh sach may bay ===============//
int emptyMB(LIST_MB lstMB) {
	return lstMB.n == 0;
}

int fullMB(LIST_MB lstMB) {
	return lstMB.n == MAXLIST;
}

maybay createMB(LIST_MB& lstMB, mayBay &mb) {
	khungNhapThongTin(NHAP_MB, "THEM MAY BAY", "So hieu may bay:", "Loai may bay:", "So day:", "So dong:");

	do {
		mb.soHieuMayBay[0] = '\0';
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP1 + 2);
		rewind(stdin);
		NhapMA(mb.soHieuMayBay, 20);
		int tontai = search_MB(lstMB, mb.soHieuMayBay);
		if (tontai != -1) {
			hienThongBao("So hieu may bay da ton tai!");
		}
		else {
			if (mb.soHieuMayBay[0] == '\0') {
				hienThongBao("Chua nhap thong tin!");
			}
			else break;
		}
	} while (true);

	do {
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                      ";
		mb.loaiMayBay[0] = '\0';
		gotoxy(COT + 1, DONGNHAP2 + 2);
		rewind(stdin);
		NhapCHUOI_SO(mb.loaiMayBay, 45);
		if (mb.loaiMayBay[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else break;
	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		Nhap_SO(mb.soDay, 11);
		if (mb.soDay == 0) {
			hienThongBao("Chua nhap thong tin!");
		}
		else {
			if (mb.soDay > MAX_DAY || mb.soDay < 0) {
				hienThongBao("So day phai < 9 va > 0");
			}
			else break;
		}
		
	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP4 + 2);
		Nhap_SO(mb.soDong, 11);
		if (mb.soDong == 0) {
			hienThongBao("Chua nhap thong tin!");
		}
		else {
			if (mb.soDong > MAX_DONG || mb.soDay < 0) {
				hienThongBao("So dong phai < 20 va > 0");
			}
			else break;
		}
	} while (true);

	return mb;
}

int insert_MB(LIST_MB& lstMB, mayBay mb) {
	NODEMAYBAY p = new nodeMB;
	p->data = mb;
	if (fullMB(lstMB)){
		return 0;
	}
	lstMB.nodeMB[lstMB.n++] = p;
	return 1;
}

int search_MB(LIST_MB lstMB, char ma[]) {
	for (int i = 0; i < lstMB.n; i++) {
		if (stricmp(lstMB.nodeMB[i]->data.soHieuMayBay, ma) == 0) {
			return i;
		}
			
	}
	return -1;
}

mayBay getMB(LIST_MB lstMB, char ma[]) {
	for (int i = 0; i < lstMB.n; i++) {
		if (stricmp(lstMB.nodeMB[i]->data.soHieuMayBay, ma) == 0) {
			return lstMB.nodeMB[i]->data;
		}
	}
}

int delete_MB(LIST_MB& lstMB, int i){
	int j;
	if (emptyMB(lstMB)) {
		return 0;
	}
	if (i == -1)
		return 0;
	for (j = i + 1; j < lstMB.n; j++){
		lstMB.nodeMB[j - 1] = lstMB.nodeMB[j];
	}
	lstMB.n--;
	return 1;
}

char* gdTimMa(int type, string title) {
	khungNhapThongTin(type, title);

	char temp[20] = { '\0' };
	gotoxy(COT + 1, DONGNHAP1 + 2);
	cout << "                          ";
	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	NhapMA(temp, 20);
	return temp;
}

int hieuChinh_MB(LIST_MB& lstMB, int i) {
	khungNhapThongTin(SUA_MB, "HIEU CHINH MAY BAY", "So hieu may bay:", "Sua loai may bay:", "Sua so day:", "Sua so dong:");
	
	if (i == -1)
		return 0;
	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	cout << lstMB.nodeMB[i]->data.soHieuMayBay;

	do {
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                      ";
		lstMB.nodeMB[i]->data.loaiMayBay[0] = '\0';
		gotoxy(COT + 1, DONGNHAP2 + 2);
		rewind(stdin);
		NhapCHUOI_SO(lstMB.nodeMB[i]->data.loaiMayBay, 45);
		if (lstMB.nodeMB[i]->data.loaiMayBay[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else break;
	} while (true);
	
	do
	{
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		Nhap_SO(lstMB.nodeMB[i]->data.soDay, 11);
		if (lstMB.nodeMB[i]->data.soDay == 0) {
			hienThongBao("Chua nhap thong tin!");
		}
		else {
			if (lstMB.nodeMB[i]->data.soDay > MAX_DAY || lstMB.nodeMB[i]->data.soDay < 0) {
				hienThongBao("So day phai < 9 va > 0");
			}
			else break;
		}

	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP4 + 2);
		Nhap_SO(lstMB.nodeMB[i]->data.soDong, 11);
		if (lstMB.nodeMB[i]->data.soDong == 0) {
			hienThongBao("Chua nhap thong tin!");
		}
		else {
			if (lstMB.nodeMB[i]->data.soDong > MAX_DONG || lstMB.nodeMB[i]->data.soDong < 0) {
				hienThongBao("So day phai < 20 va > 0");
			}
			else break;
		}
	} while (true);

	
	return 1;
}

void show_1_MB(LIST_MB lstMB, int chon, bool type) {
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + chon);
	cout << "                                                                                                                 ";
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + chon);
	cout << chon + 1;

	gotoxy(COTDS_L + 6, DONGDS_U + 3 + chon);
	cout << lstMB.nodeMB[chon]->data.soHieuMayBay;
	gotoxy(COTDS_L + 5, DONGDS_U + 3 + chon);
	cout << char(DOC);

	gotoxy(COTDS_L + 26, DONGDS_U + 3 + chon);
	cout << lstMB.nodeMB[chon]->data.loaiMayBay;
	gotoxy(COTDS_L + 25, DONGDS_U + 3 + chon);
	cout << char(DOC);

	gotoxy(COTDS_L + 71, DONGDS_U + 3 + chon);
	cout << lstMB.nodeMB[chon]->data.soDay;
	gotoxy(COTDS_L + 70, DONGDS_U + 3 + chon);
	cout << char(DOC);

	gotoxy(COTDS_L + 94, DONGDS_U + 3 + chon);
	cout << lstMB.nodeMB[chon]->data.soDong;
	gotoxy(COTDS_L + 93, DONGDS_U + 3 + chon);
	cout << char(DOC);

	Normal();
	if (type == true) {
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << lstMB.nodeMB[chon]->data.soHieuMayBay;
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << lstMB.nodeMB[chon]->data.loaiMayBay;
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << lstMB.nodeMB[chon]->data.soDay;
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << "                      ";
		gotoxy(COT + 1, DONGNHAP4 + 2);
		cout << lstMB.nodeMB[chon]->data.soDong;
	}
	
}

void show_MB(LIST_MB lstMB) {
	khungXuatDS(NHAP_MB, DONGDS_D - DONGDS_U, COTDS_R - COTDS_L, 5, 25, 70, 93);

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

//============= ham xu ly danh sach ve ================//
int emptyVe(LIST_VE lstVe) {
	return lstVe.n == 0;
}

int fullVe(LIST_VE lstVe, mayBay mb) {
	int tmpSoDay = mb.soDay;
	int tmpSoDong = mb.soDong;
	int soVe = tmpSoDay * tmpSoDong;
	return lstVe.n == soVe;
}

int getSLVe(mayBay mb) {
	int tmpSoDay = mb.soDay;
	int tmpSoDong = mb.soDong;
	return tmpSoDay * tmpSoDong;
}

void insertVe(LIST_VE& lstVe, int vitri, char cmnd[]) {
	strcpy(lstVe.nodeVe[vitri].data.CMND, cmnd);
}

int createDsVe(mayBay mb, LIST_VE &lstVe) {
	if (fullVe(lstVe, mb)) {
		return 0;
	}
	char day[] = "ABCDEFGHIJKLMNO";
	char temp[5] = "";
	char tmpCMND[12] = { '\0' };
	int slVe = getSLVe(mb);
	lstVe.nodeVe = new nodeVeMB[slVe];
	lstVe.soDay = mb.soDay;
	lstVe.soDong = mb.soDong;

	for (int i = 0; i < mb.soDay; i++) {
		temp[0] = '\0';
		temp[0] = day[i];
		for (int j = 1; j <= mb.soDong; j++) {
			if (j < 10) {
				
				char array[3];
				temp[1] = '\0';
				strcat(temp, "0");
				itoa(j, array, 10);
				strcat(temp, array);
			}
			else {

				char array[3];
				temp[1] = '\0';
				itoa(j, array, 10);
				strcat(temp, array);
			}
			strcpy(lstVe.nodeVe[lstVe.n].data.soVe, temp);
			insertVe(lstVe, lstVe.n, tmpCMND);
			lstVe.n++;
		}
	}
	return 1;
}

int demSoVe(LIST_VE lstVe) {
	int dem = 0;
	for (int i = 0; i < lstVe.n; i++) {
		if (stricmp(lstVe.nodeVe[i].data.CMND, "") != 0)
			dem++;
	}
	return dem;
}

int cancelVe(LIST_VE& lstVe, int vitri) {
	if (emptyVe(lstVe))
		return 0;
	for (int i = vitri + 1; i < lstVe.n; i++) {
		lstVe.nodeVe[i - 1] = lstVe.nodeVe[i];
	}
	lstVe.n--;
	return 1;
}
// ============== ham xu ly danh sach chuyen bay ============//
void initCB(PTRChuyenBay& lstCB) {
	lstCB = NULL;
}

int empty_CB(PTRChuyenBay lstCB) {
	return (lstCB == NULL);
}

PTRChuyenBay searchBin_CB(PTRChuyenBay lstCB, char ma[]) {
	PTRChuyenBay p;
	for (p = lstCB; p != NULL; p = p->next) {
		if (stricmp(p->data.maChuyenBay, ma) == 0)
			return p;
	}
	return NULL;

}

CHUYENBAY createCB(PTRChuyenBay lstCB, CHUYENBAY cb, LIST_MB lstMB) {
	khungNhapThongTin(NHAP_CB, "THEM CHUYEN BAY", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");

	PTRChuyenBay p;
	do
	{
		cb.maChuyenBay[0] = { '\0' };
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << "                            ";
		gotoxy(COT + 1, DONGNHAP1 + 2);
		rewind(stdin);
		NhapMA(cb.maChuyenBay, 20);
		p = searchBin_CB(lstCB, cb.maChuyenBay);
		if (p != NULL) {
			hienThongBao("Ma chuyen bay da ton tai!");
		}
		else {
			if (cb.maChuyenBay[0] == '\0') {
				hienThongBao("Chua nhap thong tin!");
			}
			else break;
		}
	} while (true);

	mayBay chonMB;
	do
	{
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                           ";
		chonMB = ChonMB(lstMB);
		strcpy(cb.soHieuMayBay, chonMB.soHieuMayBay);
		if (chonMB.soHieuMayBay[0] == '\0') {
			cb.soHieuMayBay[0] = { '\0' };
			gotoxy(COT + 1, DONGNHAP2 + 2);
			rewind(stdin);
			NhapMA(cb.soHieuMayBay, 20);
			int tontai = search_MB(lstMB, cb.soHieuMayBay);
			if (tontai == -1) {
				hienThongBao("Khong co may bay nao mang so hieu nay!");
			}
			else if (cb.soHieuMayBay[0] == '\0') {
				hienThongBao("Chua nhap thong tin!");
			}
			else break;
		}
		else {
			gotoxy(COT + 1, DONGNHAP2 + 2);
			cout << cb.soHieuMayBay;
			break;
		}
		
	} while (true);
	
	do
	{
		cb.sanBayDen[0] = { '\0' };
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                                     ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		NhapCHUOI_SO(cb.sanBayDen, 50);
		if (cb.sanBayDen[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else
			break;
	} while (true);
	
	do
	{
		gotoxy(COT + 1, DONGNHAP4 + 2);
		Nhap_SO(cb.tgKhoiHanh.ngay, 2);

		gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
		Nhap_SO(cb.tgKhoiHanh.thang, 2);

		gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
		Nhap_SO(cb.tgKhoiHanh.nam, 4);
		
		if (rangBuocThoiGian(cb.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
			cout << "    ";
		}
	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP5 + 2);
		Nhap_SO(cb.tgKhoiHanh.gio, 2);

		gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
		Nhap_SO(cb.tgKhoiHanh.phut, 2);

		if (rangBuocGio(cb.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP5 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
			cout << "  ";
		}
	} while (true);

	int taoDSVe = createDsVe(chonMB, cb.dsVe);
	if (taoDSVe == 1)
		cb.trangThai = CONVE;

	return cb;
}

void insert_OrderNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb) {
	PTRChuyenBay p, t, s;
	p = new NodeChuyenBay;
	p->data = cb;
	t = new NodeChuyenBay;
	for (s = lstCB; s != NULL && stricmp(s->data.maChuyenBay, cb.maChuyenBay) < 0; t = s, s = s->next);
	if (s == lstCB) {
		p->next = lstCB;
		lstCB = p;
	}
	else {
		p->next = s;
		t->next = p;
	}
}

int insertNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb) {
	PTRChuyenBay p = new NodeChuyenBay;
	p->data = cb;
	p->next = NULL;
	if (lstCB == NULL)
		lstCB = p;
	else {
		PTRChuyenBay last;
		for (last = lstCB; last->next != NULL; last = last->next);
		last->next = p;
	}
	return 1;
}

int hieuChinh_CB(PTRChuyenBay& lstCB, PTRChuyenBay p, LIST_MB lstMB) {
	khungNhapThongTin(NHAP_CB, "HIEU CHINH CHUYEN BAY", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");

	if (p == NULL)
	{
		return 0;
	}

	gotoxy(COT + 1, DONGNHAP1 + 2);
	rewind(stdin);
	cout << p->data.maChuyenBay;

	mayBay chonMB;
	do
	{
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                           ";
		chonMB = ChonMB(lstMB);
		strcpy(p->data.soHieuMayBay, chonMB.soHieuMayBay);
		if (chonMB.soHieuMayBay[0] == '\0') {
			p->data.soHieuMayBay[0] = { '\0' };
			gotoxy(COT + 1, DONGNHAP2 + 2);
			rewind(stdin);
			NhapMA(p->data.soHieuMayBay, 20);
			int tontai = search_MB(lstMB, p->data.soHieuMayBay);
			if (tontai == -1) {
				hienThongBao("Khong co may bay nao mang so hieu nay!");
			}
			else if (p->data.soHieuMayBay[0] == '\0') {
				hienThongBao("Chua nhap thong tin!");
			}
			else break;
		}
		else {
			gotoxy(COT + 1, DONGNHAP2 + 2);
			cout << p->data.soHieuMayBay;
			break;
		}

	} while (true);

	do
	{
		p->data.sanBayDen[0] = { '\0' };
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                                     ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		NhapCHUOI_SO(p->data.sanBayDen, 50);
		if (p->data.sanBayDen[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else
			break;
	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP4 + 2);
		Nhap_SO(p->data.tgKhoiHanh.ngay, 2);

		gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
		Nhap_SO(p->data.tgKhoiHanh.thang, 2);

		gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
		Nhap_SO(p->data.tgKhoiHanh.nam, 4);

		if (rangBuocThoiGian(p->data.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
			cout << "    ";
		}
	} while (true);

	do
	{
		gotoxy(COT + 1, DONGNHAP5 + 2);
		Nhap_SO(p->data.tgKhoiHanh.gio, 2);

		gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
		Nhap_SO(p->data.tgKhoiHanh.phut, 2);

		if (rangBuocGio(p->data.tgKhoiHanh) == -1)
		{
			break;
		}
		else
		{
			gotoxy(COT + 1, DONGNHAP5 + 2);
			cout << "  ";
			gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
			cout << "  ";
		}
	} while (true);

	return 1;
}

int xoa_CB(PTRChuyenBay& lstCB, char ma[]) {
	PTRChuyenBay p = lstCB;
	if (empty_CB(lstCB))
		return 0;
	if (stricmp(lstCB->data.maChuyenBay, ma) == 0) {
		p = lstCB;
		lstCB = p->next;
		delete p;
		return 1;
	}
	else {
		for (p = lstCB; p->next != NULL && stricmp(p->next->data.maChuyenBay, ma) != 0; p = p->next);
		if (p->next != NULL) {
			PTRChuyenBay q = p->next;
			p->next = q->next;
			delete q;
			return 1;
		}
		else return 0;
	}
	
}

int huy_CB(PTRChuyenBay& lstCB, char ma[]) {
	PTRChuyenBay p = lstCB;
	if (empty_CB(lstCB))
		return 0;
	else {
		if (lstCB->data.trangThai == HETVE || lstCB->data.trangThai == HOANTAT)
			hienThongBao("Khong the huy chuyen bay nay!");
		else {
			lstCB->data.trangThai = HUYCHUYEN;
		}
	}
}

void showCB(PTRChuyenBay lstCB) {
	khungXuatDS(NHAP_CB, DONGDS_D - DONGDS_U, COTDS_R - COTDS_L, 5, 25, 45, 80, 100);

	int i = 0;
	for (PTRChuyenBay p = lstCB; p != NULL; p = p->next) {
		gotoxy(COTDS_L + 1, DONGDS_U + 3 + i);
		cout << i + 1;
		gotoxy(COTDS_L + 6, DONGDS_U + 3 + i);
		cout << p->data.maChuyenBay;
		gotoxy(COTDS_L + 26, DONGDS_U + 3 + i);
		cout << p->data.soHieuMayBay;
		gotoxy(COTDS_L + 46, DONGDS_U + 3 + i);
		cout << p->data.sanBayDen;
		gotoxy(COTDS_L + 81, DONGDS_U + 3 + i);
		cout << p->data.tgKhoiHanh.ngay << "/" << p->data.tgKhoiHanh.thang << "/" << p->data.tgKhoiHanh.nam
			<< " " << p->data.tgKhoiHanh.gio << ":" << p->data.tgKhoiHanh.phut;
		gotoxy(COTDS_L + 101, DONGDS_U + 3 + i);
		if(p->data.trangThai == 0)
			cout << "Da huy";
		else if (p->data.trangThai == 1)
			cout << "Con ve";
		else if (p->data.trangThai == 2)
			cout << "Het ve";
		else if (p->data.trangThai == 3)
			cout << "Hoan tat";
		i++;
	}
	
}
void show_1_CB(CHUYENBAY *cb, int chon) {
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + chon);
	cout << "                                                                                                                 ";
	gotoxy(COTDS_L + 1, DONGDS_U + 3 + chon);
	cout << chon + 1;
	gotoxy(COTDS_L + 5, DONGDS_U + 3 + chon);
	cout << char(DOC);
	gotoxy(COTDS_L + 6, DONGDS_U + 3 + chon);
	cout << cb->maChuyenBay;
	gotoxy(COTDS_L + 25, DONGDS_U + 3 + chon);
	cout << char(DOC);
	gotoxy(COTDS_L + 26, DONGDS_U + 3 + chon);
	cout << cb->soHieuMayBay;
	gotoxy(COTDS_L + 45, DONGDS_U + 3 + chon);
	cout << char(DOC);
	gotoxy(COTDS_L + 46, DONGDS_U + 3 + chon);
	cout << cb->sanBayDen;
	gotoxy(COTDS_L + 80, DONGDS_U + 3 + chon);
	cout << char(DOC);
	gotoxy(COTDS_L + 81, DONGDS_U + 3 + chon);
	cout << cb->tgKhoiHanh.ngay << "/" << cb->tgKhoiHanh.thang << "/" << cb->tgKhoiHanh.nam
		<< " " << cb->tgKhoiHanh.gio << ":" << cb->tgKhoiHanh.phut;
	gotoxy(COTDS_L + 100, DONGDS_U + 3 + chon);
	cout << char(DOC);
	gotoxy(COTDS_L + 101, DONGDS_U + 3 + chon);
	if (cb->trangThai == 0)
		cout << "Da huy";
	else if (cb->trangThai == 1)
		cout << "Con ve";
	else if (cb->trangThai == 2)
		cout << "Het ve";
	else if (cb->trangThai == 3)
		cout << "Hoan tat";
	
	Normal();

	gotoxy(COT + 1, DONGNHAP1 + 2);
	cout << "                                     ";
	gotoxy(COT + 1, DONGNHAP1 + 2);
	cout << cb->maChuyenBay;
	gotoxy(COT + 1, DONGNHAP2 + 2);
	cout << "                                     ";
	gotoxy(COT + 1, DONGNHAP2 + 2);
	cout << cb->soHieuMayBay;
	gotoxy(COT + 1, DONGNHAP3 + 2);
	cout << "                                     ";
	gotoxy(COT + 1, DONGNHAP3 + 2);
	cout << cb->sanBayDen;
	gotoxy(COT + 1, DONGNHAP4 + 2);
	cout << "    ";
	gotoxy(COT + 1, DONGNHAP4 + 2);
	cout << cb->tgKhoiHanh.ngay;
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
	cout << "    ";
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
	cout << cb->tgKhoiHanh.thang;
	gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
	cout << "    ";
	gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
	cout << cb->tgKhoiHanh.nam;
	gotoxy(COT + 1, DONGNHAP5 + 2);
	cout << "    ";
	gotoxy(COT + 1, DONGNHAP5 + 2);
	cout << cb->tgKhoiHanh.gio;
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
	cout << "    ";
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
	cout << cb->tgKhoiHanh.phut;
}

//============== cac ham xu ly hanh khach ===================//
void init_HK(TREEHanhKhach& lstHK) {
	lstHK = NULL;
}

int empty_HK(TREEHanhKhach lstHK) {
	return lstHK == NULL;
}

int timTrung_HK(TREEHanhKhach lstHK, char soCMND[]) {
	if (lstHK == NULL)
		return 0;
	if (lstHK != NULL)
	{
		if (stricmp(lstHK->data.CMND, soCMND) == 0) // neu so CMND ton tai trong cay
		{
			return 1;
		}
		else if (stricmp(lstHK->data.CMND, soCMND) > 0)
		{
			timTrung_HK(lstHK->Left, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) < 0)
		{
			timTrung_HK(lstHK->Right, soCMND);
		}
	}
}

TREEHanhKhach timKiem_HK(TREEHanhKhach lstHK, char cmnd[]) {
	TREEHanhKhach p;
	p = lstHK;
	
	while (p != NULL && stricmp(p->data.CMND, cmnd) != 0)
	{
		if (stricmp(p->data.CMND, cmnd) > 0)
		{
			p = p->Left;
		}
		else if (stricmp(p->data.CMND, cmnd) < 0)
		{
			p = p->Right;
		}
	}
	
	return p;
}

void insertNode_HK(TREEHanhKhach& lstHK, HANHKHACH p) {
	if (lstHK == NULL)
	{
		lstHK = new NodeHanhKhach;
		lstHK->data = p;
		lstHK->Left = NULL;
		lstHK->Right = NULL;
	}
	else
	{
		if (stricmp(lstHK->data.CMND, p.CMND) > 0)
		{
			insertNode_HK(lstHK->Left, p);
		}
		else if (stricmp(lstHK->data.CMND, p.CMND) < 0)
		{
			insertNode_HK(lstHK->Right, p);
		}
	}
}

HANHKHACH create_HK(TREEHanhKhach& lstHK) {
	khungNhapThongTin(NHAP_HK, "NHAP THONG TIN HANH KHACH", "Nhap CMND", "Nhap ho", "Nhap ten", "Chon phai");
	HANHKHACH hk;
	do
	{
		hk.CMND[0] = '\0';
		gotoxy(COT + 1, DONGNHAP1 + 2);
		cout << "                            ";
		gotoxy(COT + 1, DONGNHAP1 + 2);
		rewind(stdin);
		NhapCHUOI_SO(hk.CMND, 12);
		if (timTrung_HK(lstHK, hk.CMND) == 1) {
			/* ham kiem tra dat ve tren cung 1 chuyen bay hay khong */
			hienThongBao("Khach hang da co trong csdl");
		}
		else {
			if (hk.CMND[0] == '\0') {
				hienThongBao("Chua nhap thong tin!");
			}
			else break;
		}
	} while (true);

	do
	{
		hk.ho[0] = '\0';
		gotoxy(COT + 1, DONGNHAP2 + 2);
		cout << "                           ";
		gotoxy(COT + 1, DONGNHAP2 + 2);
		NhapCHUOI_SO(hk.ho, 50);
		if (hk.ho[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else
			break;
	} while (true);

	do
	{
		hk.ten[0] = { '\0' };
		gotoxy(COT + 1, DONGNHAP3 + 2);
		cout << "                                     ";
		gotoxy(COT + 1, DONGNHAP3 + 2);
		NhapCHUOI_SO(hk.ten, 10);
		if (hk.ten[0] == '\0') {
			hienThongBao("Chua nhap thong tin!");
		}
		else
			break;
	} while (true);

	
	int chon = confirm("NAM", "NU", false);
	if (chon == 2)
		hk.phai = 1; // nu
	if (chon == 3)
		hk.phai = 0; // nam
	return hk;
}

void xuat_HK(TREEHanhKhach lstHK, int& stt) {
}

void timNodeTheMang(TREEHanhKhach& lstHK, TREEHanhKhach& r) {
	if (r->Left != NULL)
	{
		timNodeTheMang(lstHK, r->Left);
	}
	else
	{
		lstHK->data = r->data;
		lstHK = r;
		r = r->Right;
	}

}

void remove_HK(TREEHanhKhach& lstHK, char soCMND[]) {
	if (lstHK != NULL)
	{
		if (stricmp(lstHK->data.CMND, soCMND) > 0)
		{
			remove_HK(lstHK->Left, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) < 0)
		{
			remove_HK(lstHK->Right, soCMND);
		}
		else if (stricmp(lstHK->data.CMND, soCMND) == 0)
		{
			TREEHanhKhach q;
			q = lstHK;
			if (lstHK->Left == NULL) // truong hop khong co cay con ben trai
			{
				lstHK = lstHK->Right;
			}
			else if (lstHK->Right == NULL) // truong hop khong co cay con ben phai
			{
				lstHK = lstHK->Left;
			}
			else // truong hop co cay con 2 ben
			{
				timNodeTheMang(q, lstHK->Right);
			}
			delete q;
		}
	}
}

void xuatHK_1_CB(CHUYENBAY *cb, TREEHanhKhach lstHK, int page) {
	int j = page, pageHK = page, dem = 0;
	for (j, pageHK; pageHK < cb->dsVe.n; pageHK++, j++) {
		if (stricmp(cb->dsVe.nodeVe[j].data.CMND, "") != 0) {
			TREEHanhKhach t = timKiem_HK(lstHK, cb->dsVe.nodeVe[j].data.CMND);

			gotoxy(COTDS_L + 1, DONGDS_U + 27 + dem);
			cout << dem + 1;
			gotoxy(COTDS_L + 6, DONGDS_U + 27 + dem);
			cout << cb->dsVe.nodeVe[j].data.soVe;
			gotoxy(COTDS_L + 26, DONGDS_U + 27 + dem);
			cout << t->data.CMND;
			gotoxy(COTDS_L + 46, DONGDS_U + 27 + dem);
			cout << t->data.ho << " " << t->data.ten;
			gotoxy(COTDS_L + 94, DONGDS_U + 27 + dem);
			cout << (t->data.phai == NAM ? "Nam" : "Nu");
			dem++;
		}

		if (dem == MAX_PAGE_SMALL) {
			break;
		}

	}
}

void hieuChinh_HK(TREEHanhKhach& lstHK, char soCMND[]) {

}

void count_HK(TREEHanhKhach lstHK, int& dem) {
	if (lstHK != NULL)
	{
		dem++;
		count_HK(lstHK->Left, dem);
		count_HK(lstHK->Right, dem);
	}
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
int loadCB(PTRChuyenBay& lstCB, LIST_MB lstMB) {
	//ChuyenBay cb;
	fstream inFile;
	inFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/ChuyenBay.txt", ios::in);
	string temp;
	string temp1 = "";
	string ve;
	int slCB;
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			ChuyenBay cb;
			getline(inFile, temp);
			if (temp == "") {
				
				inFile.getline(cb.maChuyenBay, 20);
				inFile.getline(cb.soHieuMayBay, 20);
				inFile.getline(cb.sanBayDen, 50);
				inFile >> cb.tgKhoiHanh.ngay;
				inFile >> cb.tgKhoiHanh.thang;
				inFile >> cb.tgKhoiHanh.nam;
				inFile >> cb.tgKhoiHanh.gio;
				inFile >> cb.tgKhoiHanh.phut;
				inFile >> cb.trangThai;

				mayBay mb = getMB(lstMB, cb.soHieuMayBay);
				int dsve = createDsVe(mb, cb.dsVe);
				
				getline(inFile, temp1);
				getline(inFile, temp1);
				while (temp1 != "") {
					int vitri;
					char cmnd[12] = { '\0' };
					catChuoi(temp1, '-', vitri, cmnd);
					insertVe(cb.dsVe, vitri, cmnd);
						
					getline(inFile, temp1);
				}
				

				insertNodeCB(lstCB, cb);
			}
		}
	}
	else {
		return 0;
	}
	inFile.close();
	return 1;
}
int saveCB(PTRChuyenBay lstCB) {
	ChuyenBay cb;
	fstream outFile;
	outFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/ChuyenBay.txt", ios::out);
	
	if (outFile.is_open()) {
		for (PTRChuyenBay p = lstCB; p != NULL; p = p->next) {
			outFile << endl << p->data.maChuyenBay;
			outFile << endl << p->data.soHieuMayBay;
			outFile << endl << p->data.sanBayDen;
			outFile << endl << p->data.tgKhoiHanh.ngay;
			outFile << endl << p->data.tgKhoiHanh.thang;
			outFile << endl << p->data.tgKhoiHanh.nam;
			outFile << endl << p->data.tgKhoiHanh.gio;
			outFile << endl << p->data.tgKhoiHanh.phut;
			outFile << endl << p->data.trangThai;
			for (int i = 0; i < p->data.dsVe.n; i++) {
				if(stricmp(p->data.dsVe.nodeVe[i].data.CMND, "") != 0)
					outFile << endl << p->data.dsVe.nodeVe[i].data.soVe << "," << i << "-" << p->data.dsVe.nodeVe[i].data.CMND;
			}
			if (p->next != NULL) {
				outFile << endl;
				outFile << endl;
			}
			
		}
	}
	else
		return 0;
	outFile.close();
	return 1;
}

int loadHK(TREEHanhKhach& lstHK) {
	fstream inFile;
	inFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/HanhKhach.txt", ios::in);
	HANHKHACH hk;
	string temp;
	char phai[4];
	if (!inFile.fail()) {
		while (!inFile.eof())
		{
			getline(inFile, temp);
			inFile.getline(hk.CMND, 12);
			inFile.getline(hk.ho, 50);
			inFile.getline(hk.ten, 10);
			inFile.getline(phai, 4);
			if (stricmp(phai, "Nam") == 0) {
				hk.phai = NAM;
			}
			else if (stricmp(phai, "Nu") == 0) {
				hk.phai = NU;
			}
			insertNode_HK(lstHK, hk);
		}
	}
	else {
		return 0;
	}
	inFile.close();
	return 1;
}
void duyetCay(TREEHanhKhach lstHK, fstream& file) {
	if (lstHK != NULL) {
		file << endl << lstHK->data.CMND;
		file << endl << lstHK->data.ho;
		file << endl << lstHK->data.ten;
		if (lstHK->data.phai == NAM)
			file << endl << "Nam";
		else if (lstHK->data.phai == NU)
			file << endl << "Nu";
		file << endl;
		duyetCay(lstHK->Left, file);
		duyetCay(lstHK->Right, file);
	}
}
int saveHK(TREEHanhKhach lstHK) {
	fstream outFile;
	outFile.open("C:/Users/lamho/source/repos/MayBay/MayBay/DATA/HanhKhach.txt", ios::out);
	if (!outFile.fail()) {
		duyetCay(lstHK, outFile);
	}
	else
		return 0;
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

int rangBuocThoiGian(THOI_GIAN tg) {
	
	time_t baygio = time(0);
	tm* ltm = localtime(&baygio);
	if (tg.ngay < ltm->tm_mday || tg.thang < 1 + ltm->tm_mon || tg.nam < 1900 + ltm->tm_year)
	{
		if (tg.thang <= 1 + ltm->tm_mon || tg.nam < 1900 + ltm->tm_year)
		{
			if (tg.nam <= 1900 + ltm->tm_year)
			{
				char nam[5];
				itoa(1900 + ltm->tm_year, nam, 10);
				char thang[3];
				itoa(ltm->tm_mon + 1, thang, 10);
				char ngay[50];
				itoa(ltm->tm_mday, ngay, 10);
				char thongbao[70] = "Hom nay la ";
				strcat(ngay, "/");
				strcat(ngay, thang);
				strcat(ngay, "/");
				strcat(ngay, nam);
				strcat(ngay, ". Lap chuyen bay sau ngay hien tai!");
				strcat(thongbao, ngay);
				hienThongBao(thongbao);
				return 1;
			}
		}
	}
	if (tg.ngay == 31 && (tg.thang == 4 || tg.thang == 6 || tg.thang == 9 || tg.thang == 11))
	{

		char month[50];
		itoa(tg.thang, month, 10);
		char thongbao[50] = "Thang ";
		strcat(month, " chi co 30 ngay!");
		strcat(thongbao, month);
		hienThongBao(thongbao);
		return 1;
	}
	if ((tg.ngay == 30 || tg.ngay == 31) && tg.thang == 2)
	{

		char month[50];
		itoa(tg.thang, month, 10);
		char thongbao[50] = "Thang ";
		strcat(month, " chi co 29 ngay!");
		strcat(thongbao, month);
		hienThongBao(thongbao);
		return 1;
	}
	if (!((tg.nam % 4 == 0 && tg.nam % 100 != 0) || tg.nam % 400 == 0) && tg.ngay == 29 && tg.thang == 2) // kiem tra nam nhuan
	{	
		char year[100];
		itoa(tg.nam, year, 10);
		strcat(year, " la nam khong nhuan nen thang 2 chi co 28 ngay!");
		hienThongBao(year);
				
		return 1;
	}
	
	return -1;
}

int rangBuocGio(THOI_GIAN h)
{

	if (h.gio > 23 || h.gio < 0)
	{
		hienThongBao("Gio bat dau tu 0h den 23h. Vui long nhap gio hop le!");
		return 1;
	}
	if (h.phut > 59 || h.phut < 0)
	{
		hienThongBao("Phut bat dau tu 0 den 59 phut. Vui long nhap phut hop le!");
		return 1;
	}
	return -1;
}

void catChuoi(string chuoi, char splitChar, int &vtri, char cmnd[]) {
	int len = chuoi.length();
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (chuoi.at(i) == splitChar) {
			vtri = atoi(chuoi.substr(4, i).c_str());
			for (int j = i + 1; j < len; j++) {
				cmnd[k] = chuoi[j];
				k++;
			}
			cmnd[k + 1] = '\0';
			break;
		}
	}
}


char* stringToChar(string chuoi) {
	char *tmp;
	int len = chuoi.length();
	tmp = new char[len];
	for (int i = 0; i < len; i++) {
		tmp[i] = chuoi[i];
	}
	tmp[len] = '\0';
	return tmp;
}
//========== giao dien =============

void khungGiaoDien() {
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
	khungThongBao();
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

void khungXuatDS(int type, int rong, int dai, int colump1, int colump2, int colump3, int colump4,
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
	if (type == NHAP_MB) {
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
	else if (type == NHAP_CB) {
		// 5, 25, 45, 80, 100
		gotoxy(COTDS_L + 1, DONGDS_U + 1);
		cout << "STT";
		gotoxy(COTDS_L + 6, DONGDS_U + 1);
		cout << "MA CHUYEN BAY";
		gotoxy(COTDS_L + 26, DONGDS_U + 1);
		cout << "SO HIEU MAY BAY";
		gotoxy(COTDS_L + 46, DONGDS_U + 1);
		cout << "SAN BAY DEN";
		gotoxy(COTDS_L + 81, DONGDS_U + 1);
		cout << "NGAY GIO KHOI HANH";
		gotoxy(COTDS_L + 101, DONGDS_U + 1);
		cout << "TRANG THAI";
	}
	else if (type == NHAP_HK) {
		//5, 25, 45, 93
		gotoxy(COTDS_L + 1, DONGDS_U + 25);
		cout << "STT";
		gotoxy(COTDS_L + 6, DONGDS_U + 25);
		cout << "SO VE";
		gotoxy(COTDS_L + 26, DONGDS_U + 25);
		cout << "SO CMND";
		gotoxy(COTDS_L + 46, DONGDS_U + 25);
		cout << "HO TEN";
		gotoxy(COTDS_L + 94, DONGDS_U + 25);
		cout << "GIOI TINH";
	}
}
void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void Highlight() {
	SetColor(8);
	SetBGColor(7);
}

void Red_Highlight() {
	SetColor(7);
	SetBGColor(12);
}

void khungNhapThongTin(int type, string title, string s1, string s2, string s3, string s4,
	string s5, string s6, string s7, string s8, string s9) {
	Normal();
	//========xoa thong tin cu============
	gotoxy(COT + 1, DONGNHAP1 + 2);
	cout << "                                    ";
	gotoxy(COT + 1, DONGNHAP2 + 2);
	cout << "                                    ";
	gotoxy(COT + 1, DONGNHAP3 + 2);
	cout << "                                    ";
	gotoxy(COT + 1, DONGNHAP4 + 2);
	cout << "  ";
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP4 + 2);
	cout << "  ";
	gotoxy(COT + DAIKHUNGNHO * 2 + 1, DONGNHAP4 + 2);
	cout << "    ";
	gotoxy(COT + 1, DONGNHAP5 + 2);
	cout << "  ";
	gotoxy(COT + DAIKHUNGNHO + 1, DONGNHAP5 + 2);
	cout << "  ";
	//==========================
	if (type == TIM_MA) {
		gotoxy(COT + 25, DONGTD);
		cout << "                                    ";
		gotoxy(COT + 25, DONGTD);
		cout << title;
		gotoxy(COT, DONGNHAP1);
		cout << "Nhap so hieu can tim:";
		veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP1 + 1);
		return;
	}
	else {

		gotoxy(COT + 25, DONGTD);
		cout << title;
		gotoxy(COT, DONGNHAP1);
		cout << "                      ";
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
			veKhungNhap(DAIKHUNGNHO + DAIKHUNGNHO * 2, RONGKHUNG, COT, DONGNHAP4 + 1);

			// khung nhap gio
			gotoxy(COT, DONGNHAP5);
			cout << s5;
			veKhungNhap(DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP5 + 1);

			gotoxy(COT + DAIKHUNGNHO, DONGNHAP5);
			veKhungNhap(DAIKHUNGNHO + DAIKHUNGNHO, RONGKHUNG, COT, DONGNHAP5 + 1);
		}
		else if (type == NHAP_HK) {
			gotoxy(COT, DONGNHAP4);
			cout << s4;
		}
		else {
			gotoxy(COT, DONGNHAP4);
			cout << s4;
			veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGNHAP4 + 1);
		}

	}

}

void khungThongBao() {
	gotoxy(COT, DONGDS_D - 3);
	cout << "Thong bao";
	veKhungNhap(DAIKHUNG, RONGKHUNG, COT, DONGDS_D - 2);


}

void hienThongBao(string notif) {
	gotoxy(COT + 1, DONGDS_D - 1);
	cout << notif;
	Sleep(1000);
	gotoxy(COT + 1, DONGDS_D - 1);
	cout << "                                                         ";
}

void hienHuongDan() {
	gotoxy(COT, DONG);
	cout << "F2: Them";
	gotoxy(COT, DONG + 1);
	cout << "F3: Tim";
	gotoxy(COT, DONG + 2);
	cout << "ENTER: Chon";
	gotoxy(COT, DONG + 3);
	cout << "DELETE: Xoa";
	gotoxy(COT, DONG + 4);
	cout << "ESC: Huy/Tro ve";
}

void xoaKhungDS() {
	for (int i = 0; i < DONGDS_D - 2; i++) {
		gotoxy(COTDS_L, DONGDS_U + i);
		cout << "                                                                                                                   ";
	}
}

void xoaThongTin(int type) {
	if (type == NHAP_MB) {

	}
	else if (type == NHAP_CB) {

	}
	else if (type == NHAP_HK) {
		for (int i = 0; i < 15; i++) {
			// 5, 25, 45, 80, 100
			gotoxy(COTDS_L + 1, DONGDS_U + 3 + i);
			cout << "    ";
			gotoxy(COTDS_L + 5, DONGDS_U + 3 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 6, DONGDS_U + 3 + i);
			cout << "                   ";
			gotoxy(COTDS_L + 25, DONGDS_U + 3 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 26, DONGDS_U + 3 + i);
			cout << "                   ";
			gotoxy(COTDS_L + 45, DONGDS_U + 3 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 46, DONGDS_U + 3 + i);
			cout << "                                  ";
			gotoxy(COTDS_L + 80, DONGDS_U + 3 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 81, DONGDS_U + 3 + i);
			cout << "                   ";
			gotoxy(COTDS_L + 100, DONGDS_U + 3 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 101, DONGDS_U + 3 + i);
			cout << "             ";
		}
		
	}
	else if (type == SUA_HK) {
		for (int i = 0; i < 15; i++) {
			gotoxy(COTDS_L + 1, DONGDS_U + 27 + i);
			cout << "    ";
			gotoxy(COTDS_L + 5, DONGDS_U + 27 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 6, DONGDS_U + 27 + i);
			cout << "                   ";
			gotoxy(COTDS_L + 25, DONGDS_U + 27 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 26, DONGDS_U + 27 + i);
			cout << "                   ";
			gotoxy(COTDS_L + 45, DONGDS_U + 27 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 46, DONGDS_U + 27 + i);
			cout << "                                   ";
			gotoxy(COTDS_L + 93, DONGDS_U + 27 + i);
			cout << char(DOC);
			gotoxy(COTDS_L + 94, DONGDS_U + 27 + i);
			cout << "   ";
		}
	}
}

int menuDong_Prim(char td[soItem_MenuChinh][100]) {
	Normal();
	//system("cls");
	khungGiaoDien();
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

mayBay ChonMB(LIST_MB lstMB) {
	xoaKhungDS();
	mayBay tmp;
	Normal();
	int chon = 0;
	int i;
	show_MB(lstMB);
	Highlight();
	show_1_MB(lstMB, chon, false);
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		switch (kytu)
		{
		case UP:
			if (chon > 0) {
				Normal();
				show_1_MB(lstMB, chon, false);

				chon--;
				Highlight();
				show_1_MB(lstMB, chon, false);
			}
			break;
		case DOWN:
			if (chon + 1 < lstMB.n) {
				Normal();
				show_1_MB(lstMB, chon, false);
				chon++;
				Highlight();
				show_1_MB(lstMB, chon, false);
			}
			break;
		case ESC:
		{
			Normal();
			tmp.soHieuMayBay[0] = '\0';
			return tmp;
		}

		case ENTER:
			Normal();
			return lstMB.nodeMB[chon]->data;
		}
	} while (true);
}

int menuDong_MayBay(char td[soItem_MenuMB][100]) {
	Normal();
	//system("cls");
	khungGiaoDien();
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
	khungGiaoDien();
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

mayBay menuDong_ChonMB(LIST_MB lstMB, int& chonMB) {
	xoaKhungDS();
	mayBay tmp;
	Normal();
	khungGiaoDien();
	khungNhapThongTin(NHAP_MB, "THEM MAY BAY", "So hieu may bay:", "Loai may bay:", "So day:", "So dong:");
	hienHuongDan();
	int chon = 0;
	int i;
	show_MB(lstMB);
	Highlight();
	show_1_MB(lstMB, chon, true);
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case UP:
			if (chon > 0) {
				Normal();
				show_1_MB(lstMB, chon, true);

				chon--;
				Highlight();
				show_1_MB(lstMB, chon, true);
			}
			break;
		case DOWN:
			if (chon + 1 < lstMB.n) {
				Normal();
				show_1_MB(lstMB, chon, true);

				chon++;
				Highlight();
				show_1_MB(lstMB, chon, true);
			}
			break;
		case F2:
			chonMB = 1;
			tmp.soHieuMayBay[0] = '\0';
			return tmp;
		case F3:
		{
			tmp.soHieuMayBay[0] =  '\0';
			int tontai = -1;
			do
			{
				strcpy(tmp.soHieuMayBay, gdTimMa(0, "TIM MAY BAY"));
				tontai = search_MB(lstMB, tmp.soHieuMayBay);
				if (tontai == -1) {
					hienThongBao("Khong tim thay so hieu nay!");
					
				}
				else break;
			} while (true);
			chonMB = confirm("HIEU CHINH", "XOA", false);
			if (chonMB == 0)
				break;
			Normal();
			return tmp;
			
		}
			
		case ESC:
		{
			Normal();
			tmp.soHieuMayBay[0] = '\0';
			chonMB = soItem_MenuMB;
			return tmp;
		}
			
		case ENTER:   
			Normal();
			chonMB = confirm("HIEU CHINH", "XOA", false);
			if (chonMB == 0)
				break;
			return lstMB.nodeMB[chon]->data;
		}
	} while (true);
}

void chuyenMang(PTRChuyenBay lstCB, CHUYENBAY* cb[], int &n, LIST_MB lstMB, int trangThai) {
	PTRChuyenBay p = lstCB;
	if (trangThai == 0) {
		for (p; p != NULL; p = p->next) {
			cb[n] = new CHUYENBAY;
			strcpy(cb[n]->maChuyenBay, p->data.maChuyenBay);
			strcpy(cb[n]->soHieuMayBay, p->data.soHieuMayBay);
			strcpy(cb[n]->sanBayDen, p->data.sanBayDen);
			cb[n]->tgKhoiHanh.ngay = p->data.tgKhoiHanh.ngay;
			cb[n]->tgKhoiHanh.thang = p->data.tgKhoiHanh.thang;
			cb[n]->tgKhoiHanh.nam = p->data.tgKhoiHanh.nam;
			cb[n]->tgKhoiHanh.gio = p->data.tgKhoiHanh.gio;
			cb[n]->tgKhoiHanh.phut = p->data.tgKhoiHanh.phut;
			cb[n]->trangThai = p->data.trangThai;
			
			mayBay mb = getMB(lstMB, cb[n]->soHieuMayBay);
			int dsve = createDsVe(mb, cb[n]->dsVe);
			for (int k = 0; k < cb[n]->dsVe.n; k++) {
			//	hienThongBao(string(cb[n]->dsVe.nodeVe[k].data.CMND));
				if (stricmp(p->data.dsVe.nodeVe[k].data.CMND, "") != 0) {
					strcpy(cb[n]->dsVe.nodeVe[k].data.CMND, p->data.dsVe.nodeVe[k].data.CMND);
					insertVe(cb[n]->dsVe, k, cb[n]->dsVe.nodeVe[k].data.CMND);
				}
				
			}

			n++;
		}
	}
	else if (trangThai == CONVE) {
		for (p; p != NULL; p = p->next) {
			if (p->data.trangThai == CONVE) {
				cb[n] = new CHUYENBAY;
				strcpy(cb[n]->maChuyenBay, p->data.maChuyenBay);
				strcpy(cb[n]->soHieuMayBay, p->data.soHieuMayBay);
				strcpy(cb[n]->sanBayDen, p->data.sanBayDen);
				cb[n]->tgKhoiHanh.ngay = p->data.tgKhoiHanh.ngay;
				cb[n]->tgKhoiHanh.thang = p->data.tgKhoiHanh.thang;
				cb[n]->tgKhoiHanh.nam = p->data.tgKhoiHanh.nam;
				cb[n]->tgKhoiHanh.gio = p->data.tgKhoiHanh.gio;
				cb[n]->tgKhoiHanh.phut = p->data.tgKhoiHanh.phut;
				cb[n]->trangThai = p->data.trangThai;
				
				n++;
			}
		}
	}
}

PTRChuyenBay menuDong_ChonCB(PTRChuyenBay lstCB, LIST_MB lstMB, int& chonCB) {
	
	Normal();
	khungGiaoDien();
	khungNhapThongTin(NHAP_CB, "THEM CHUYEN BAY", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");
	hienHuongDan();
	int chon = 0;
	int i = 0;
	showCB(lstCB);

	CHUYENBAY* tmpCB[300];
	chuyenMang(lstCB, tmpCB, i, lstMB, 0);
	
	PTRChuyenBay q = new NodeChuyenBay;
	Highlight();
	show_1_CB(tmpCB[chon], chon);
	char tmp[20];
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case UP:
			if (chon > 0) {
				Normal();
				show_1_CB(tmpCB[chon], chon);

				chon--;
				Highlight();
				show_1_CB(tmpCB[chon], chon);
			}
			break;
		case DOWN:
			if (chon + 1 < i) {
				Normal();
				show_1_CB(tmpCB[chon], chon);

				chon++;
				Highlight();
				show_1_CB(tmpCB[chon], chon);
			}
			break;
		case F2:
			chonCB = 1;
			tmp[0] = '\0';
			strcpy(q->data.maChuyenBay, tmp);
			return q;
		case F3:
		{
			tmp[0] = '\0';
			do
			{
				strcpy(tmp, gdTimMa(0, "TIM CHUYEN BAY"));
				q = searchBin_CB(lstCB, tmp);
				if (q == NULL)
					hienThongBao("Khong tim thay chuyen bay nay!");
				else break;
			} while (true);
			chonCB = confirm("HIEU CHINH", "XOA", false);
			if (chonCB == 0)
				break;
			Normal();
			return q;
		}
		case DELETE:
		{
			q = searchBin_CB(lstCB, tmpCB[chon]->maChuyenBay);
			if (q != NULL) {
				int chon = confirm("CO", "KHONG", false);
				if (chon == 3) {
					chonCB = 2;
					Normal();
					return q;
				}
				else
					break;
			}
		}
		case ESC:
		{
			Normal();
			tmp[0] = '\0';
			strcpy(q->data.maChuyenBay, tmp);
			chonCB = soItem_MenuCB;
			return q;
		}

		case ENTER:
			chonCB = confirm("HIEU CHINH", "HUY CHUYEN", true);
			if (chonCB == 0)
				break;
			q = searchBin_CB(lstCB, tmpCB[chon]->maChuyenBay);
			Normal();
			return q;
		}
	} while (true);
}

PTRChuyenBay ChonCB(PTRChuyenBay lstCB, int &chonCB, LIST_MB lstMB) {

	Normal();
	khungGiaoDien();
	khungNhapThongTin(NHAP_CB, "", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");
	hienHuongDan();
	int chon = 0;
	int i = 0;
	
	showCB(lstCB);
	CHUYENBAY* tmpCB[300];
	chuyenMang(lstCB, tmpCB, i, lstMB, CONVE);
	PTRChuyenBay q = new NodeChuyenBay;
	
	Highlight();
	show_1_CB(tmpCB[chon], chon);
	char tmp[20];
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case UP:
			if (chon > 0) {
				Normal();
				show_1_CB(tmpCB[chon], chon);

				chon--;
				Highlight();
				show_1_CB(tmpCB[chon], chon);
			}
			break;
		case DOWN:
			if (chon + 1 < i) {
				Normal();
				show_1_CB(tmpCB[chon], chon);

				chon++;
				Highlight();
				show_1_CB(tmpCB[chon], chon);
			}
			break;
		case F3:
		{
			tmp[0] = '\0';
			do
			{
				strcpy(tmp, gdTimMa(0, "TIM CHUYEN BAY"));
				q = searchBin_CB(lstCB, tmp);
				if (q == NULL)
					hienThongBao("Khong tim thay chuyen bay nay!");
				else break;
			} while (true);
			chonCB = confirm("DAT VE", "TRO VE", false);
			if (chonCB == 0)
				break;
			Normal();
			return q;
		}
		case ESC:
		{
			Normal();
			tmp[0] = '\0';
			strcpy(q->data.maChuyenBay, tmp);
			chonCB = soItem_MenuCB;
			return q;
		}

		case ENTER:
			Normal();
			int luachon = confirm("DAT VE", "HUY VE", false);
			if (luachon == 3)
				chonCB = 1;
			else if (luachon == 2)
				chonCB = 2;
			q = searchBin_CB(lstCB, tmpCB[chon]->maChuyenBay);
			Normal();
			return q;
		}
	} while (true);
}

void xuatALL_HK_1_CB(CHUYENBAY* cb, TREEHanhKhach lstHK) {
	Normal();
	int page = 0;
	if (cb->dsVe.n < 15)
		page = cb->dsVe.n;
	int max_HK = demSoVe(cb->dsVe);
	char kytu;
	bool max = false;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case LEFT:
			if (page >= MAX_PAGE_SMALL) {

				page -= MAX_PAGE_SMALL;

				xoaThongTin(SUA_HK);
				xuatHK_1_CB(cb, lstHK, page);
			}
			break;
		case RIGHT:
			if (page < max_HK) {
				
				page += MAX_PAGE_SMALL;
				if (page >= max_HK) {
					page -= MAX_PAGE_SMALL;
					break;
				}

				xoaThongTin(SUA_HK);
				xuatHK_1_CB(cb, lstHK, page);
				
			}
			break;
		case ESC:
			return;
		}
		
	} while (true);
}

PTRChuyenBay ChonCB_Xuat_DSHK(PTRChuyenBay lstCB, int& chonCB, LIST_MB lstMB, TREEHanhKhach lstHK) {

	Normal();
	khungGiaoDien();
	khungNhapThongTin(NHAP_CB, "", "Ma chuyen bay:", "So hieu may bay:", "San bay den:", "Ngay khoi hanh:", "Gio khoi hanh:");
	hienHuongDan();
	int chon = 0;
	int i = 0;
	int pageCB = 0;
	int pageHK = 0;
	int dem = 0;
	CHUYENBAY* tmpCB[300];
	chuyenMang(lstCB, tmpCB, i, lstMB, 0);
	PTRChuyenBay q = new NodeChuyenBay;
	for (pageCB; pageCB < i; pageCB++) {
		show_1_CB(tmpCB[pageCB], pageCB);
		
		if (dem == MAX_PAGE_SMALL - 1) {
			break;
		}
		dem++;
	}
	dem = 0;

	xuatHK_1_CB(tmpCB[chon], lstHK, 0);
	Highlight();
	show_1_CB(tmpCB[chon], chon);
	
	dem = 0;
	char tmp[20];
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case UP:
			if (chon > 0 && dem > 0) {
				Normal();
				show_1_CB(tmpCB[chon], chon);
				xoaThongTin(SUA_HK);
				chon--;
				dem--;
				Highlight();
				show_1_CB(tmpCB[chon], dem);
				xuatHK_1_CB(tmpCB[chon], lstHK, 0);
			}
			break;
		case DOWN:
			if (chon + 1 < i && dem + 1 < MAX_PAGE_SMALL) {
				Normal();
				show_1_CB(tmpCB[chon], dem);
				xoaThongTin(SUA_HK);
				chon++;
				dem++;
				Highlight();
				show_1_CB(tmpCB[chon], dem);
				xuatHK_1_CB(tmpCB[chon], lstHK, 0);
			}
			break;
		case LEFT:
			
			if (pageCB > MAX_PAGE_SMALL) {
				Normal();
				xoaThongTin(NHAP_HK);
				xoaThongTin(SUA_HK);
				pageCB -= MAX_PAGE_SMALL*2;
				chon = pageCB;
				dem = 0;
				
				for (pageCB; pageCB < i; pageCB++) {
					show_1_CB(tmpCB[pageCB], dem);
					
					if (dem == MAX_PAGE_SMALL - 1) {
						break;
					}
					dem++;
				}
				dem = 0;
				Highlight();
				show_1_CB(tmpCB[chon], dem);
				xuatHK_1_CB(tmpCB[chon], lstHK, 0);
			}
			break;
		case RIGHT:
			if (pageCB < i) {
				Normal();
				xoaThongTin(NHAP_HK);
				xoaThongTin(SUA_HK);
				pageCB ++;
				chon = pageCB;
				dem = 0;
				
				for (pageCB; pageCB < i; pageCB++) {
					show_1_CB(tmpCB[pageCB], dem);
					
					if (dem == MAX_PAGE_SMALL - 1) {
						
						break;
					}
					dem++;
				}
				pageCB += MAX_PAGE_SMALL - dem;
				dem = 0;
				Highlight();
				show_1_CB(tmpCB[chon], dem);
				xuatHK_1_CB(tmpCB[chon], lstHK, 0);
			}
			break;
		case F3:
		{
			tmp[0] = '\0';
			do
			{
				strcpy(tmp, gdTimMa(0, "TIM CHUYEN BAY"));
				q = searchBin_CB(lstCB, tmp);
				if (q == NULL)
					hienThongBao("Khong tim thay chuyen bay nay!");
				else break;
			} while (true);
			chonCB = confirm("DAT VE", "TRO VE", false);
			if (chonCB == 0)
				break;
			Normal();
			return q;
		}
		case ESC:
		{
			Normal();
			tmp[0] = '\0';
			strcpy(q->data.maChuyenBay, tmp);
			chonCB = soItem_MenuCB;
			return q;
		}

		case ENTER:
			Normal();
			xuatALL_HK_1_CB(tmpCB[chon], lstHK);
			break;
		}
	} while (true);
}


void show_1_Ve(LIST_VE lstVe, int cot, int dong, int chon, int kc) {
	//int kc = 3;
	gotoxy(COTDS_L + cot + kc, DONGDS_U + dong);
	cout << lstVe.nodeVe[chon].data.soVe;
}

int chonVe(PTRChuyenBay& lstCB) {
	int chon = 0;
	int kc = 3;
	int n = 0;
	for (int i = 0; i < lstCB->data.dsVe.soDay; i++) {
		for (int j = 0; j < lstCB->data.dsVe.soDong; j++) {
			if (stricmp(lstCB->data.dsVe.nodeVe[n].data.CMND, "") != 0)
				Red_Highlight();
			show_1_Ve(lstCB->data.dsVe, i, j, n, kc);
			Normal();
			n++;
		}
		kc += 3;
	}
	int cot = 0;
	int dong = 0;
	kc = 3;
	if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0)
		Red_Highlight();
	Highlight();
	show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
	char kytu;
	do
	{
		kytu = getch();
		if (kytu == -32)
			kytu = getch();
		if (kytu == 0)
			kytu = getch();
		switch (kytu)
		{
		case UP:
		{
			if (dong > 0) {
				Normal();
				if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0)
					Red_Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
				chon--;
				dong--;
				
				Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
			}
			break;
		}
		case DOWN:
		{
			if (dong + 1 < lstCB->data.dsVe.soDong) {
				Normal();
				if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0)
					Red_Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
				chon++;
				dong++;
				Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
			}
			break;
		}
		case LEFT:
		{
			if (cot > 0) {
				Normal();
				if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0)
					Red_Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
				chon -= lstCB->data.dsVe.soDong;
				cot--;
				kc -= 3;
				Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
			}
			break;
		}
		case RIGHT:
		{
			if (cot + 1 < lstCB->data.dsVe.soDay) {
				Normal();
				if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0)
					Red_Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
				chon += lstCB->data.dsVe.soDong;
				cot++;
				kc += 3;
				Highlight();
				show_1_Ve(lstCB->data.dsVe, cot, dong, chon, kc);
			}
			break;
		}
		case DELETE:
		{
			Normal();
			if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") == 0) {
				hienThongBao("Chua dat ve nay, khong the huy!");
				break;
			}
			int xacNhan = confirm("DONG Y", "TRO VE", false);
			if (xacNhan == 2 || xacNhan == 0)
				break;
			xoaKhungDS();
			return chon;
		}
		case ENTER:
			Normal();
			if (stricmp(lstCB->data.dsVe.nodeVe[chon].data.CMND, "") != 0) {
				hienThongBao("Ve nay da co nguoi dat!");
				break;
			}
			xoaKhungDS();
			return chon;
		}
	} while (true);
	return -1;
}

void dsHK_1_CB(PTRChuyenBay lstCB, TREEHanhKhach lstHK, LIST_MB lstMB) {
	Normal();
	system("cls");
	khungXuatDS(NHAP_CB, DONGDS_D - DONGDS_U - 24, COTDS_R - COTDS_L, 5, 25, 45, 80, 100);
	khungXuatDS(NHAP_HK, DONGDS_D - DONGDS_U - 24, COTDS_R - COTDS_L, 5, 25, 45, 93, 0, COTDS_L, DONGDS_U + 24);
	int chon;
	int exit = 1;
	int vitri;

	while (exit)
	{
		chon = 0;
		PTRChuyenBay p = ChonCB_Xuat_DSHK(lstCB, chon, lstMB, lstHK);
		
		switch (chon)
		{
		case soItem_MenuCB:
			exit = 0;
			break;
		}
	}
}

void QLMB(LIST_MB &lstMB, char tdMayBay[soItem_MenuMB][100]) {
	int chonMB;
	int exit1 = 1;
	Normal();
	system("cls");
	mayBay tmp;
	while (exit1) {
		show_MB(lstMB);
		//chonMB = menuDong_MayBay(tdMayBay);
		chonMB = 0;
		tmp = menuDong_ChonMB(lstMB, chonMB);
		switch (chonMB)
		{
		case 1:
		{
			mayBay mb = createMB(lstMB, mb);
			int a = insert_MB(lstMB, mb);
			if (a == 1) {
				hienThongBao("Them thanh cong!");
				int save = saveMB(lstMB);
			}
			Normal();
			system("cls");
			break;

		}
		case 2:
		{
			int tontai = -1;
			tontai = search_MB(lstMB, tmp.soHieuMayBay);

			int xoa = delete_MB(lstMB, tontai);
			if (xoa == 1) {
				hienThongBao("Xoa thanh cong!");
				int save = saveMB(lstMB);
			}
			else {
				hienThongBao("Xoa that bai!");
			}
			Normal();
			system("cls");
			break;

		}
		case 3:
		{
			int tontai = -1;
			tontai = search_MB(lstMB, tmp.soHieuMayBay);
				
			int sua = hieuChinh_MB(lstMB, tontai);
			if (sua == 1) {
				hienThongBao("Hieu chinh thanh cong!");
				int save = saveMB(lstMB);
			}
			else {
				hienThongBao("Hieu chinh that bai!");
			}
			Normal();
			system("cls");
			break;

		}
		case soItem_MenuMB:
		{
			exit1 = 0;
			break;
		}
		}
	}
}

void QLCB(PTRChuyenBay& lstCB, char tdChuyenBay[soItem_MenuCB][100], LIST_MB& lstMB) {
	int chonCB;
	int exit2 = 1;
	Normal();
	system("cls");
	while (exit2)
	{
		//showCB(lstCB);
		//chonCB = menuDong_ChuyenBay(tdChuyenBay);
		chonCB = 0;
		PTRChuyenBay p = menuDong_ChonCB(lstCB, lstMB, chonCB);
		switch (chonCB)
		{
		case 1:
		{
			CHUYENBAY cb;
			cb = createCB(lstCB, cb, lstMB);
			insert_OrderNodeCB(lstCB, cb);
			hienThongBao("Them thanh cong!");
			int save = saveCB(lstCB);

			Normal();
			system("cls");

			break;
		}
		case 2:
		{
			int xoa = xoa_CB(lstCB, p->data.maChuyenBay);
			if (xoa == 1) {
				hienThongBao("Xoa thanh cong!");
				int save = saveCB(lstCB);
			}
			else
				hienThongBao("Xoa that bai!");
			Normal();
			system("cls");
			break;
		}
			
		case 3:
		{
			int fix = hieuChinh_CB(lstCB, p, lstMB);
			if (fix == 1)
			{
				hienThongBao("Hieu chinh thanh cong!");
				int save = saveCB(lstCB);
			}
			else
			{
				hienThongBao("Hieu chinh that bai!");
			}
			Normal();
			system("cls");
			break;
		}
		case 4:
		{

			break;
		}
		case soItem_MenuCB:
		{
			exit2 = 0;
			break;
		}
		}
	}
}

void DatHuyVe(PTRChuyenBay& lstCB, LIST_MB lstMB, TREEHanhKhach& lstHK) {
	int chon;
	int exit = 1;
	int vitri;
	Normal();
	system("cls");
	
	while (exit)
	{
		chon = 0;
		PTRChuyenBay p = ChonCB(lstCB, chon, lstMB);
		
		switch (chon)
		{
		case 1:
		{
			xoaKhungDS();
			vitri = chonVe(p);
			HANHKHACH hk = create_HK(lstHK);
			insertNode_HK(lstHK, hk);
			
			insertVe(p->data.dsVe, vitri, hk.CMND);
			hienThongBao("Dat ve thanh cong!");
			int savehk = saveHK(lstHK);
			int savecb = saveCB(lstCB);
			break;
		}
		case 2:
		{
			xoaKhungDS();
			vitri = chonVe(p);
			int cancle = cancelVe(p->data.dsVe, vitri);
			if (cancle == 1) {
				hienThongBao("Huy ve thanh cong!");
				int save = saveCB(lstCB);
			}
		}
		case soItem_MenuCB:
			exit = 0;
			break;
		}
	}
}

int confirm(string chose1, string chose2, bool huyCB) {
	char key;
	int chon = 3;
	
	Highlight();
	gotoxy(COT + 10, DONGNHAP7);
	cout << chose1;
	Normal();
	gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
	cout << chose2;
	do
	{
		key = getch();
		if (key == -32)
			key = getch();
		switch (key)
		{
		case LEFT:
			Normal();
			gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
			cout << chose2;
			Highlight();
			gotoxy(COT + 10, DONGNHAP7);
			cout << chose1;
			chon = 3;
			break;
		case RIGHT:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << chose1;
			Highlight();
			gotoxy(COT + DAIKHUNGNHO + 28, DONGNHAP7);
			cout << chose2;
			if (huyCB == true)
				chon = 4;
			else 
				chon = 2;
			break;
		case ENTER:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << "                                       ";
			return chon;
		case ESC:
			Normal();
			gotoxy(COT + 10, DONGNHAP7);
			cout << "                                       ";
			return 0;
		}
		
	} while (true);
}