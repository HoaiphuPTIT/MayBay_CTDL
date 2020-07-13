﻿#pragma once
#include "ThuVien.h"
//#include "mylib.h"

char tdChinh[soItem_MenuChinh][100] = { "1. Quan ly may bay                                     ",
										 "2. Quan ly chuyen bay                                 ",
										 "3. Dat ve/Huy ve                                      ",
										 "4. Danh sach hanh khach thuoc 1 chuyen bay            " ,
										 "5. Danh sach cac chuyen bay khoi hanh trong dd/mm/yyyy",
										 "6. Danh sach ve con trong cua chuyen bay X            ",
										 "7. Ket thuc"
};
char tdMayBay[soItem_MenuMB][100] = { "1. Them may bay",
										 "2. Xoa may bay",
										 "3. Hieu chinh may bay",
										 "4. Tro ve"
};

int main() {
	LIST_MB lstMB;

	int chon;
	int exit = 1;
	while (exit) {
		chon = menuDong_Prim(tdChinh);
		switch (chon) {
		case 1:
		{
			int x1;
			int exit1 = 1;
			while (exit1) {
				x1 = menuDong_MayBay(tdMayBay);
				switch (x1)
				{
				case 1:
				{
					mayBay mb = createMB(lstMB, mb);
					int a = insert_MB(lstMB, mb);
					if(a == TRUE)
						cout << "Them thanh cong!";
					char c = getch();
					if (c == 13)
						break;
					
				}
					
				case soItem_MenuMB:
				{
					cout << "hihi";
					exit1 = 0;
					break;
				}
					
				}
			}
			break;
		}
		case soItem_MenuChinh:
		{
			return 0;
		}
			
		}
	}
	return 0;
}