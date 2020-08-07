#pragma once
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>
#include <math.h>

#define MAXLIST 300
#define MAX_INPUT 255
#define HUYCHUYEN 0
#define CONVE 1
#define HETVE 2
#define HOANTAT 3
#define NAM 0
#define NU 1

using namespace std;
// 1800 <  NAM < 9999
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;
const int MAX_DAY = 9;
const int MAX_DONG = 15;
// cau truc thoi gian
struct ThoiGian
{
	int gio;
	int phut;

	int ngay;
	int thang;
	int nam;
};
typedef struct ThoiGian THOI_GIAN;

// cau truc may bay
struct maybay {
	char soHieuMayBay[20];
	char loaiMayBay[45];
	int soDay;
	int soDong;
};
typedef struct maybay mayBay;

struct NodeMayBay {
	mayBay data;
};
typedef struct NodeMayBay nodeMB;
typedef struct NodeMayBay* NODEMAYBAY;

struct ListMayBay {
	int n = 0;
	NODEMAYBAY nodeMB[MAXLIST];
};
typedef ListMayBay LIST_MB;

// cac ham xu ly ds may bay
int emptyMB(LIST_MB lstMB);
int fullMB(LIST_MB lstMB);
mayBay createMB(LIST_MB& lstMB, mayBay& mb);
int insert_MB(LIST_MB& lstMB, mayBay mb);
int delete_MB(LIST_MB& lstMB, int i);
void show_MB(LIST_MB lstMB);
int search_MB(LIST_MB lstMB, char ma[]);
mayBay getMB(LIST_MB lstMB, char ma[]);
int hieuChinh_MB(LIST_MB& lstMB, int i);
void show_1_MB(LIST_MB lstMB, int chon, bool type);
// cau truc ve
struct VeMayBay{
	char soVe[5];
	char CMND[12];
};
typedef VeMayBay VeMB;
struct nodeVeMayBay {
	VeMB data;
};
typedef nodeVeMayBay nodeVeMB;
//typedef nodeVe* NODEVEMB;
struct ListVe {
	int n = 0;
	int soDay;
	int soDong;
	nodeVeMB *nodeVe;
};
typedef ListVe LIST_VE;
//======= ham xu ly ve =====
int emptyVe(LIST_VE lstVe);
int fullVe(LIST_VE lstVe, mayBay mb);
int getSLVe(mayBay mb);
void insertVe(LIST_VE& lstVe, int vitri, char cmnd[]);
int createDsVe(mayBay mb, LIST_VE &lstVe);
int cancleVe(LIST_VE& lstVe, int vitri);

// cau truc chuyen bay
struct ChuyenBay {
	char maChuyenBay[20];
	THOI_GIAN tgKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	LIST_VE dsVe;
};
typedef ChuyenBay CHUYENBAY;

typedef struct NodeChuyenBay {
	CHUYENBAY data;
	struct NodeChuyenBay* next;
};
typedef struct NodeChuyenBay* PTRChuyenBay;

//============ cac ham xu ly chuyen bay ===============//
void initCB(PTRChuyenBay &lstCB);
int empty_CB(PTRChuyenBay lstCB);
CHUYENBAY createCB(PTRChuyenBay lstCB, CHUYENBAY cb, LIST_MB lstMB);
void insert_OrderNodeCB(PTRChuyenBay & lstCB, CHUYENBAY cb);
int insertNodeCB(PTRChuyenBay& lstCB, CHUYENBAY cb);
PTRChuyenBay searchBin_CB(PTRChuyenBay lstCB, char ma[]);
int hieuChinh_CB(PTRChuyenBay& lstCB, PTRChuyenBay p, LIST_MB lstMB);
int xoa_CB(PTRChuyenBay& lstCB, char ma[]);
int huy_CB(PTRChuyenBay& lstCB, char ma[]);
void showCB(PTRChuyenBay lstCB);
void show_1_CB(CHUYENBAY* cb, int chon);
void chuyenMang(PTRChuyenBay lstCB, CHUYENBAY* cb[], int &n);
// cau truc hanh khach
struct HanhKhach {
	char CMND[12];
	char ho[50];
	char ten[10];
	int phai;
};
typedef HanhKhach HANHKHACH;

struct nodeHanhKhach {
	HANHKHACH data;
	struct nodeHanhKhach* Left;
	struct nodeHanhKhach* Right;
};
typedef struct nodeHanhKhach NodeHanhKhach;
typedef struct nodeHanhKhach* TREEHanhKhach;
//============= cac ham xu ly hanh khach ===================//
void init_HK(TREEHanhKhach& lstHK);
int empty_HK(TREEHanhKhach lstHK);
int timTrung_HK(TREEHanhKhach lstHK, char soCMND[]);
TREEHanhKhach timKiem_HK(TREEHanhKhach lstHK, char cmnd[]);
void insertNode_HK(TREEHanhKhach& lstHK, HANHKHACH p);
HANHKHACH create_HK(TREEHanhKhach& lstHK);
void xuat_HK(TREEHanhKhach lstHK, int& stt); // theo thu tu NLR
void timNodeTheMang(TREEHanhKhach& lstHK, TREEHanhKhach& r);
void remove_HK(TREEHanhKhach& lstHK, char soCMND[]);
void hieuChinh_HK(TREEHanhKhach& lstHK, char soCMND[]);

struct NhapChuoi {
	int n = 0;
	char* data[MAX_INPUT];
};
//============= doc xuat file ================//
int loadMB(LIST_MB &mb);
int saveMB(LIST_MB mb);
int loadCB(PTRChuyenBay& lstCB, LIST_MB mb);
int saveCB(PTRChuyenBay lstCB);
int loadHK(TREEHanhKhach& lstHK);
void duyetCay(TREEHanhKhach lstHK, fstream& file);
int saveHK(TREEHanhKhach lstHK);
//========= cac ham xu ly nhap chuoi ==========//
void NhapMA(char var[], int len);
void NhapCHUOI_SO(char var[], int len);
void Nhap_SO(int &var, int len);
int rangBuocThoiGian(THOI_GIAN tg);
int rangBuocGio(THOI_GIAN h);
void catChuoi(string chuoi, char splitChar, int &vtri, char cmnd[]);
char* stringToChar(string chuoi);
//============= Xu ly Giao dien ==============//
const int soItem_MenuChinh = 7;
const int soItem_MenuMB = 4;
const int soItem_MenuCB = 5;
const int soItem_MenuDV = 3;

char* gdTimMa(int type, string title);
void khungGiaoDien();
void veKhungNhap(int dai, int rong, int posx, int posy, string source = "");
void khungNhapThongTin(int type, string title = "", string s1 = "", string s2 = "", string s3 = "", string s4 = "",
	string s5 = "", string s6 = "", string s7 = "", string s8 = "", string s9 = "");

void khungXuatDS(int type, int rong, int dai, int colump1 = 0, int colump2 = 0, int colump3 = 0, int colump4 = 0, 
	int colump5 = 0, int posx = 0, int posy = 0);
void xoaKhungDS();

void khungThongBao();
void hienThongBao(string notif);
void hienHuongDan();

void Normal();
void Highlight();
void Red_Highlight();
int menuDong_Prim(char td[soItem_MenuChinh][100]);
int menuDong_MayBay(char td[soItem_MenuMB][100]);
int menuDong_ChuyenBay(char td[soItem_MenuCB][100]);
mayBay ChonMB(LIST_MB lstMB);
mayBay menuDong_ChonMB(LIST_MB lstMB, int& chonMB);
PTRChuyenBay menuDong_ChonCB(PTRChuyenBay lstCB, int& chonCB);
PTRChuyenBay ChonCB(PTRChuyenBay lstCB, int& chonCB);
void show_1_Ve(LIST_VE lstVe, int cot, int dong, int chon, int kc);
int chonVe(PTRChuyenBay& lstCB);

void QLMB(LIST_MB& lstMB, char tdMayBay[soItem_MenuMB][100]);
void QLCB(PTRChuyenBay& lstCB, char tdChuyenBay[soItem_MenuCB][100], LIST_MB& lstMB);
void DatHuyVe(PTRChuyenBay& lstCB, LIST_MB lstMB, TREEHanhKhach& lstHK);
int confirm(string chose1, string chose2, bool huyCB);