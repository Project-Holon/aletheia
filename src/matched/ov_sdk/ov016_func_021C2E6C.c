/*
 * function: func_021C2E6C
 * address:  0x021C2E6C
 * packet:   pkt_ov016_021C2E6C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_02058518  0x02058518  arm
 *   func_021BCB44  0x021BCB44  arm  ov016
 *   func_021C3130  0x021C3130  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5A8  0x021DE5A8  data
 *   func_021C2F14  0x021C2F14  arm  ov016
 */

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

extern signed char func_021BCB14(void);
extern void func_021CFFAC(unsigned int v);
extern void func_02058518(WiFiInfoT *buf);
extern void func_021BCB44(int idx);
extern void func_021C3130(void);
extern void func_021C0E40(void (*scene)());
extern void func_021C2F14(void);
extern FocusPosT g_021DE5A8;

void func_021C2E6C(void)
{
	WiFiInfoT info;

	switch (func_021BCB14()) {
	case 0:
		func_021CFFAC(7);
		break;
	case 1:
		func_02058518(&info);
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
	func_021C0E40(func_021C2F14);
}
