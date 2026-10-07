/*
 * file:     unit_021C2E6C.c
 * unit:     yes
 * function: func_021C2E6C, func_021C2F14, func_021C2F34, func_021C2FA0, func_021C30AC, func_021C3130
 * address:  0x021C2E6C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_02058518  0x02058518  arm
 *   func_021BCB44  0x021BCB44  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5A8  0x021DE5A8  data
 *   func_021BCB9C  0x021BCB9C  arm  ov016
 *   func_021D5790  0x021D5790  arm  ov016
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021BCAE4  0x021BCAE4  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021BCB58 0x021BCB58 arm ov016
 *   func_021D6F38 0x021D6F38 arm ov016
 *   func_021BD5A8 0x021BD5A8 arm ov016
 *   func_021BD138 0x021BD138 arm ov016
 *   func_021D4C68 0x021D4C68 arm ov016
 *   func_021D6090 0x021D6090 arm ov016
 *   func_021C0E50 0x021C0E50 arm ov016
 *   func_021C1984 0x021C1984 arm ov016
 *   func_021C255C 0x021C255C arm ov016
 *   func_021C1F1C 0x021C1F1C arm ov016
 *   func_021C3824 0x021C3824 arm ov016
 *   func_0207C994  0x0207C994  arm
 *   func_021BD4C8  0x021BD4C8  arm
 *   d_021DA4D0     0x021DA4D0  data
 *   d_021DA4D2     0x021DA4D2  data
 *   d_021DA4D4     0x021DA4D4  data
 *   d_021DA4D6     0x021DA4D6  data
 *   g_021DA4B0  0x021DA4B0  data
 *   func_021CE7B0  0x021CE7B0  arm  ov016
 */
#include "../../matched/include/G_FocusPosT.h"

struct tagDWCWiFiInfo;
typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

typedef struct {
	unsigned long long a;
	int c[3];
} WiFiInfoT;

typedef unsigned char u8;

typedef unsigned short u16;

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_02058518(struct tagDWCWiFiInfo *buf);
extern void func_021BCB44(int idx);
extern void func_021C0E40(unsigned int v);
extern void func_021BCB9C(void);
extern int func_021D5790(int frame);
extern int func_021D5580(int lcd);
extern void func_021BCAE4(void);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern int func_021BCB58(void);
extern void func_021D6F38(unsigned int *obj);
extern void func_021BD5A8(void);
extern int func_021BD138(void);
extern void func_021D4C68(void *file);
extern void func_021D6090(int lcd, int plane);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C1984();
extern void func_021C255C();
extern void func_021C1F1C();
extern void func_021C3824();
extern int  func_0207C994(int a, int b);
extern void func_021BD4C8(int a, int b, int c, int d);
extern void func_021CE7B0(void *p, int a, int b);
void func_021C2E6C(void);
void func_021C2F14(void);
void func_021C2F34(void);
void func_021C2FA0(void);
void func_021C30AC(int a);
void func_021C3130(void);
extern struct FocusPosT g_021DE5A8;
extern u16 d_021DA4D0[][4];
extern u16 d_021DA4D2[][4];
extern u16 d_021DA4D4[][4];
extern u16 d_021DA4D6[][4];
extern unsigned char g_021DA4B0[3];


void func_021C2E6C(void)
{
	WiFiInfoT info;

	switch (func_021BCB14()) {
	case 0:
		func_021CFFAC(7);
		break;
	case 1:
		func_02058518((struct tagDWCWiFiInfo *)(&info));
		if (g_021DE5A8.idx != 0 && info.a == 0) {
			func_021CFFAC(9);
			func_021BCB44(-1);
			return;
		}
		func_021CFFAC(6);
		func_021C3130();
		g_021DE5A8.flag = 1;
		break;
	default:
		return;
	}
	func_021C0E40((unsigned int)func_021C2F14);
}


void func_021C2F14(void)
{
	func_021BCB9C();
	func_021D5790(8);
	func_021C0E40((unsigned int)func_021C2F34);
}


/*
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
void func_021C2F34(void)
{
	if (func_021D5580(1))
		return;
	if (g_021DE5A8.flag)
		func_021BCAE4();
	func_021D55A4(3, 1, 1, 8);
	func_021D55A4(3, 0, 0x14, 8);
	func_021C0E40((unsigned int)func_021C2FA0);
}


/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
void func_021C2FA0(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    if (!func_021BCB58())
        return;
    func_021D6F38(g_021DE5A8.obj);
    func_021BD5A8();
    func_021BD138();
    func_021D4C68(g_021DE5A8.ptr);
    func_021D6090(1, 1);
    func_021D6090(0, 0x14);
    if (g_021DE5A8.flag == 0) {
        func_021C0E50(0, 0);
        func_021C0E40((unsigned int)func_021C1984);
        return;
    }
    switch (g_021DE5A8.idx) {
    case 0:
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021C255C);
        return;
    case 1:
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021C1F1C);
        return;
    case 2:
        func_021C0E50(0, (unsigned int)((void *)1));
        func_021C0E40((unsigned int)func_021C3824);
        return;
    }
}


/*
 * Advances the flag byte g_021DE5A8.f0 and dispatches the indexed record.
 */
void func_021C30AC(int a)
{
    u8 i;

    if (a == 1)
        g_021DE5A8.idx = (u8)func_0207C994(g_021DE5A8.idx + 2, 3);
    else
        g_021DE5A8.idx = (u8)func_0207C994(g_021DE5A8.idx + 1, 3);
    func_021CFFAC(8);
    i = g_021DE5A8.idx;
    func_021BD4C8(d_021DA4D0[i][0], d_021DA4D4[i][0],
                  d_021DA4D2[i][0], d_021DA4D6[i][0]);
}


/*
 * sdk:      dispPush (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 */
void func_021C3130(void)
{
	int n = g_021DA4B0[g_021DE5A8.idx];
	func_021CE7B0(g_021DE5A8.ptr, n, n);
}
