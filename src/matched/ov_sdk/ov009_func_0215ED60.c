/*
 * function: func_0215ED60
 * address:  0x0215ED60
 * packet:   pkt_ov009_0215ED60
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_CalmDown (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   func_0215ECB8  0x0215ECB8  arm  ov009
 *   func_0215E84C  0x0215E84C  arm  ov009
 *   func_0215E794  0x0215E794  arm  ov009
 *   func_0215EBB4  0x0215EBB4  arm  ov009
 *   func_021575DC  0x021575DC  arm  ov009
 *   func_02166424  0x02166424  arm  ov009
 *   g_021AA44C     0x021AA44C  data
 */

extern int func_0215ECB8(void);
extern int func_0215E84C(int s);
extern int func_0215E794(int s);
extern void func_0215EBB4(void);
extern int func_021575DC(void);
extern void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));
extern int g_021AA44C;

int func_0215ED60(void)
{
	int result;

	if (g_021AA44C) {
		result = func_0215ECB8();
		if (result == 0) {
			func_0215E84C(g_021AA44C);
			if (func_0215E794(g_021AA44C)) {
				g_021AA44C = 0;
			}
			result = -26;
		}
		func_0215EBB4();
	} else {
		if (func_021575DC() == 0) {
			result = -26;
		} else {
			result = 0;
			func_02166424(0);
		}
	}
	return result;
}
