/*
 * function: UI_ClearSoftResetInhibitGlobal
 * address:  0x020351A0
 * packet:   pkt_020351A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021469BC   0x021469BC  data  a4
 *   UI_ClearSoftResetInhibit 0x02035188  arm
 */

typedef unsigned int u32;

extern u32 d_021469BC[];
extern int UI_ClearSoftResetInhibit(void *p, u32 v);

int UI_ClearSoftResetInhibitGlobal(u32 v)
{
    return UI_ClearSoftResetInhibit((void *)d_021469BC[0], v);
}
