/*
 * function: func_021BA6E8
 * address:  0x021BA6E8
 * packet:   pkt_ov218_021BA6E8
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-04): DIFF, 44 bytes. Original keeps p in r0 until the join and does adds r7,r0,r1 (offset in r1 from movs/lsls in each arm, space in r6 per arm, y spilled with str r2,[sp] and reloaded per call, bound 7 in r5). Compiled copies p to r7 at entry. Tried per-arm base, off+join, u8* types, bound as local n, ternary base.
 *
 * symbols:
 *   func_021BA720 0x021BA720 thumb ov218
 */
typedef unsigned int u32;
extern int func_021BA720(u32 base, u32 i, u32 space, int y);
void func_021BA6E8(u32 p, int sel, int y)
{
    u32 off;
    u32 space;
    u32 base;
    int i;
    if (sel) {
        off = 0x294;
        space = 0;
    } else {
        off = 0x2B0;
        space = 1;
    }
    base = p + off;
    for (i = 0; i < 7; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}
