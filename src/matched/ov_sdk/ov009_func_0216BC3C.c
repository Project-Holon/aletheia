/*
 * function: func_0216BC3C
 * address:  0x0216BC3C
 * packet:   pkt_ov009_0216BC3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 *
 * symbols:
 *   func_02195E78  0x02195E78  arm  ov009
 *   g_021AA8A0  0x021AA8A0  data
 */

typedef struct ConnData {
	unsigned char pad0;
	unsigned char aid;
} ConnData;

extern ConnData *func_02195E78(void *connection);
extern void *g_021AA8A0[];

int func_0216BC3C(unsigned char aid)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (g_021AA8A0[i] != 0) {
			if (aid == func_02195E78(g_021AA8A0[i])->aid)
				return 1;
		}
	}
	return 0;
}
