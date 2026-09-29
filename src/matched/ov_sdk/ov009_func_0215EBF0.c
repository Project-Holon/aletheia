/*
 * function: func_0215EBF0
 * address:  0x0215EBF0
 * packet:   pkt_ov009_0215EBF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Cleanup (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   func_0215ED60  0x0215ED60  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_0215CDD0  0x0215CDD0  arm  ov009
 *   func_0215EC90  0x0215EC90  arm  ov009
 *   func_0215F0D4  0x0215F0D4  arm  ov009
 *   g_021AA444     0x021AA444  data
 *   g_021A82BC     0x021A82BC  data
 *   g_021A1CD8     0x021A1CD8  data
 *   g_021AA450     0x021AA450  data
 */

typedef struct {
	unsigned char pad0[0x1c];
	unsigned long field1c;
} CPSConfig;

typedef struct {
	unsigned char pad0[0x1c];
	void (*func1c)(unsigned long);
	unsigned char pad1[0x08];
	int flag28;
} SOCConfig;

extern int func_0215ED60(void);
extern void func_02085A38(unsigned long msec);
extern int func_0215CDD0(void);
extern void func_0215EC90(void);
extern void func_0215F0D4(void);
extern unsigned long g_021AA444;
extern unsigned long g_021A82BC;
extern SOCConfig *g_021A1CD8;
extern CPSConfig g_021AA450;

int func_0215EBF0(void)
{
	int result;

	if (g_021AA444 == 0) {
		g_021AA444 = g_021A82BC;
	}
	result = func_0215ED60();
	while (result == -26) {
		func_02085A38(100);
		result = func_0215ED60();
	}
	result = func_0215CDD0();
	if (result >= 0) {
		func_0215EC90();
		if (g_021A1CD8->flag28 == 0) {
			g_021A1CD8->func1c(g_021AA450.field1c);
		}
		g_021A1CD8 = 0;
		func_0215F0D4();
	}
	return result;
}
