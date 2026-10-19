/*
 * function: isTrigger
 * address:  0x021CED30
 * packet:   pkt_ov016_021CED30
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      isTrigger (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021CEE10  0x021CEE10  arm  ov016
 *   DWCi_TPlCheckRepeat  0x021D69F4  arm  ov016
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 */

extern void func_021CEE10(int idx, void *r);
typedef unsigned short u16;
extern int DWCi_TPlCheckRepeat(u16 *a);
extern int DWCi_TPlCheckTrigger(u16 *a);

int isTrigger(void)
{
	int idx;
	int r[2];

	idx = 1;
	func_021CEE10(idx, r);
	if (DWCi_TPlCheckRepeat((u16 *)r))
		return idx;
	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, r);
		if (DWCi_TPlCheckRepeat((u16 *)r))
			return idx;
	}
	idx = 4;
	func_021CEE10(idx, r);
	if (!DWCi_TPlCheckTrigger((u16 *)r))
		idx = 0;
	return idx;
}
