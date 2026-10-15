/*
 * function: UI_ClearKeepAwakeFlagsGlobal
 * address:  0x02034FB8
 * packet:   pkt_02034FB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   UI_ClearKeepAwakeFlags 0x02034FA0  arm
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern void UI_ClearKeepAwakeFlags(void *p, u32 v);

void UI_ClearKeepAwakeFlagsGlobal(u32 v)
{
    UI_ClearKeepAwakeFlags((void *)d_021469BC[0], v);
}
