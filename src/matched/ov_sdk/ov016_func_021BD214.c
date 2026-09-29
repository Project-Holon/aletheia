/*
 * function: func_021BD214
 * address:  0x021BD214
 * packet:   pkt_ov016_021BD214
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CMNlStep (libdwcutil.TWL.HYB.a(common.o))
 *
 * symbols:
 *   func_021C0E64  0x021c0e64  arm  ov016
 *   func_021D0040  0x021d0040  arm  ov016
 *   func_021D05BC  0x021d05bc  arm  ov016
 */

extern void func_021C0E64(void **param0, void **param1);
extern void func_021D0040(int step);
extern void func_021D05BC(int step);

void func_021BD214(int step)
{
    int prm;

    func_021C0E64((void **)&prm, 0);
    if (prm == 1)
        func_021D0040(step);
    else if (prm == 2)
        func_021D05BC(step);
}
