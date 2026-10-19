/*
 * function: UI_SetFrameRate
 * address:  0x02035614
 * packet:   pkt_02035614
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   func_020355F8 0x020355F8  arm
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern void func_020355F8(void *p, u32 v);

void UI_SetFrameRate(int v)
{
    func_020355F8((void *)d_021469BC[0], v);
}
