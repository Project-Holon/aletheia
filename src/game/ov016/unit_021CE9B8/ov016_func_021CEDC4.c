/*
 * function: func_021CEDC4
 * address:  0x021CEDC4
 * packet:   pkt_ov016_021CEDC4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      isTouch (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021CEE10  0x021CEE10  arm  ov016
 *   func_021D68E4  0x021D68E4  arm  ov016
 */

extern void func_021CEE10(int idx, void *r);
typedef unsigned short u16;
extern int func_021D68E4(u16 *a);

int func_021CEDC4(int a)
{
	int idx;
	int r[2];

	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, r);
		if (func_021D68E4((u16 *)r))
			return idx;
	}
	return 0;
}
