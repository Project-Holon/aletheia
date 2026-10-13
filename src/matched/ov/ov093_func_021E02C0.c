/*
 * function: func_021E02C0
 * address:  0x021E02C0
 * packet:   pkt_ov093_021E02C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);

void func_021E02C0(int a, int b, int c, int *d)
{
    if (c == BTL_EVENT_GetVar(3) && *d == 1)
        *d = 2;
}
