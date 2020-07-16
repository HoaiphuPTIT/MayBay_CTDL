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

#define TRUE 1
#define FALSE 0
#define MAXLIST 300
#define MAX_INPUT 255
using namespace std;
// 1800 <  NAM < 9999
const int MAX_NAM = 9999;
const int MIN_NAM = 1800;
// cau truc thoi gian
struct ThoiGian
{
	int gio;
	int phut;
	int giay;

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
int empty(LIST_MB lstMB);
int full(LIST_MB lstMB);
mayBay createMB(LIST_MB& lstMB, mayBay& mb);
int insert_MB(LIST_MB& lstMB, mayBay mb);
int delete_MB(LIST_MB& lstMB, int i);
void show_MB(LIST_MB lstMB);
int search_MB(LIST_MB lstMB, char ma[]);
int hieuChinh_MB(LIST_MB& lstMB, int i);
// cau truc ve
struct VeMayBay{
	char soVe[5];
	char CMND[12];
};
typedef VeMayBay VeMB;
struct nodeVe {
	VeMB data;
};
typedef nodeVe nodeVeMB;
typedef nodeVe* NODEVEMB;
struct ListVe {
	int n = 0;
	NODEVEMB nodeVeMB;
};
typedef ListVe lstVEMB;

// cau truc chuyen bay
struct ChuyenBay {
	char maChuyenBay[20];
	THOI_GIAN tgKhoiHanh;
	char sanBayDen[50];
	int trangThai;
	char soHieuMayBay[20];
	lstVEMB dsVe;
};
typedef ChuyenBay CHUYENBAY;

typedef struct NodeChuyenBay {
	CHUYENBAY data;
	struct NodeChuyenBay* next;
};
typedef struct NodeChuyenBay* PTRChuyenBay;


// cau truc hanh khach
struct HanhKhach {
	int CMND;
	char ho[8];
	char tendem[8];
	char ten[8];
	int phai;
};
typedef HanhKhach HANHKHACH;

struct NodeHanhKhach {
	HANHKHACH data;
	struct NodeHanhKhach* Left;
	struct NodeHanhKhach* Right;
};
typedef NodeHanhKhach NodeHanhKhach;

struct NhapChuoi {
	int n = 0;
	char* data[MAX_INPUT];
};
//============= doc xuat file ================//
int loadMB(LIST_MB &mb);
int saveMB(LIST_MB mb);
//========= cac ham xu ly nhap chuoi ==========//
void NhapMA(char var[], int len);
void NhapCHUOI_SO(char var[], int len);
void Nhap_SO(int &var, int len);
//============= Xu ly Giao dien ==============//
const int soItem_MenuChinh = 7;
const int soItem_MenuMB = 4;
const int soItem_MenuCB = 4;
const int soItem_MenuDV = 3;

char* gdXoaMayBay(LIST_MB lstMB);
void veKhungGiaoDIen();
void khungNhap(int type);
void veKhungNhap(int dai, int rong, int posx, int posy, string source = "");
void veKhungDS(int rong, int dai, int colump1 = 0, int colump2 = 0, int colump3 = 0, int colump4 = 0, 
	int colump5 = 0, int posx = 0, int posy = 0);
void Normal();
void Highlight();
int menuDong_Prim(char td[soItem_MenuChinh][100]);
int menuDong_MayBay(char td[soItem_MenuMB][100]);