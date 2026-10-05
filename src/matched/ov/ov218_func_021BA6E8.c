/*
 * function: func_021BA6E8
 * address:  0x021BA6E8
 * packet:   pkt_ov218_021BA6E8
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 (wD6 lane15): EXACT. base = p + K and n = 7 written in each arm (tail merging
 *   rebuilds the shared movs r5,#7; adds r7,r0,r1 join); declaring base before space gives base r7, space r6.
 *
 * symbols:
 *   func_021BA720 0x021BA720 thumb ov218
 */
typedef unsigned int u32;
extern int func_021BA720(u32 base, u32 i, u32 space, int y);
void func_021BA6E8(u32 p, int sel, int y)
{
    u32 base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = p + 0x294;
        n = 7;
    } else {
        space = 1;
        base = p + 0x2B0;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}
