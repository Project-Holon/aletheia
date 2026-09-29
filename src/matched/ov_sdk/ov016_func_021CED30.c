/*
 * function: func_021CED30
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
 *   func_021D69F4  0x021D69F4  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 */

extern void func_021CEE10(int idx, void *r);
extern int func_021D69F4(void *r);
extern int func_021D696C(void *r);

int func_021CED30(void)
{
	int idx;
	int r[2];

	idx = 1;
	func_021CEE10(idx, r);
	if (func_021D69F4(r))
		return idx;
	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, r);
		if (func_021D69F4(r))
			return idx;
	}
	idx = 4;
	func_021CEE10(idx, r);
	if (!func_021D696C(r))
		idx = 0;
	return idx;
}
