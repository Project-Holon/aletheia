/*
 * function: func_021DF884
 * address:  0x021DF884
 * packet:   pkt_021DF884
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021E06DC  0x021E06DC  arm
 *   func_020923B0  0x020923B0  arm
 *
 * Activation probe: func_021E06DC reports on the owner, and a report is
 * returned as-is.  Otherwise clear the two 0x28-byte parameter blocks and
 * mark the owner live at +0x50.
 */

typedef int s32;
typedef unsigned int u32;

extern s32 func_021E06DC(char *p, u32 v);
extern void *func_020923B0(void *p, int c, u32 n);

s32 func_021DF884(char *p)
{
    s32 e = func_021E06DC(p, (u32)p);

    if (e != 0)
        return e;
    func_020923B0(p + 0x5c, 0, 0x28);
    func_020923B0(p + 0x84, 0, 0x28);
    *(u32 *)(p + 0x50) = 1;
    return 0;
}
