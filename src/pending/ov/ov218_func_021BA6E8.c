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
 * note (2026-10-04, wD2 lane07): n assigned 7 in BOTH arms (not after them) keeps the bound in r5 with the
 *   `cmp r5,#0; ble` guard, matching the original. Residue now: base = p + off is not hoisted (p spilled, add redone in the loop,
 *   off/space in r6/r7 live through the loop; original frees off in r1 and holds base in r7). Same output for base var, p += off,
 *   off + p, u8 * types, static inline add(). Constant n after the arms or an enum n folds/reloads 7.
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
    int n;
    if (sel) {
        off = 0x294;
        space = 0;
        n = 7;
    } else {
        off = 0x2B0;
        space = 1;
        n = 7;
    }
    base = p + off;
    i = 0;
    for (; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}
