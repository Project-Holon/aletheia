/*
 * function: func_021C2D74
 * address:  0x021C2D74
 * packet:   pkt_ov016_021C2D74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      input (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   func_021D696C  0x021D696C  arm  ov016
 *   func_021BCB28  0x021BCB28  arm  ov016
 *   func_021BD4C8  0x021BD4C8  arm  ov016
 *   func_021D6824  0x021D6824  arm  ov016
 *   func_021D6864  0x021D6864  arm  ov016
 *   func_021C30AC  0x021C30AC  arm  ov016
 *   g_021DA4B8  0x021DA4B8  data
 *   g_021DA4D0  0x021DA4D0  data
 *   g_021DA4D4  0x021DA4D4  data
 *   g_021DA4D2  0x021DA4D2  data
 *   g_021DA4D6  0x021DA4D6  data
 *   g_021DE5A8  0x021DE5A8  data
 */

typedef struct {
	unsigned short l;
	unsigned short t;
	unsigned short r;
	unsigned short b;
} RectT;

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

typedef unsigned short u16;
extern int func_021D696C(u16 *a);
extern void func_021BCB28(signed char v);
extern void func_021BD4C8(int x0, int x1, int y0, int y1);
extern int func_021D6824(unsigned int f);
extern int func_021D6864(unsigned int f);
extern void func_021C30AC(int dir);
extern RectT g_021DA4B8[3];
extern RectT g_021DA4D0[3];
extern FocusPosT g_021DE5A8;

void func_021C2D74(void)
{
	unsigned i;

	for (i = 0; i < 3; i++) {
		if (func_021D696C((u16 *)(&g_021DA4B8[i]))) {
			func_021BCB28(1);
			g_021DE5A8.idx = i;
			func_021BD4C8(g_021DA4D0[g_021DE5A8.idx].l, g_021DA4D0[g_021DE5A8.idx].r,
				g_021DA4D0[g_021DE5A8.idx].t, g_021DA4D0[g_021DE5A8.idx].b);
			return;
		}
	}
	if (func_021D6824(1)) {
		func_021BCB28(1);
		return;
	}
	if (func_021D6824(2)) {
		func_021BCB28(0);
		return;
	}
	if (func_021D6864(0x40)) {
		func_021C30AC(1);
		return;
	}
	if (func_021D6864(0x80))
		func_021C30AC(3);
}
