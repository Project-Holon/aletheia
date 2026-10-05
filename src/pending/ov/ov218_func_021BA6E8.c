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
 *
 * note: 2026-10-05 (wD5 lane17): still DIFF. New tests: p + off written inline in the call argument, u8/char * p with a (u32) cast, a block-local copy of base in the loop, a guarded do-while loop, and both off and space as ternaries with n = 7 declared (54 bytes, but the add still sinks into the loop and p is held in r7). The join add of the image is never kept as a hoisted base.
 * note (2026-10-04): DIFF, 44 bytes. Original keeps p in r0 until the join and does adds r7,r0,r1 (offset in r1 from movs/lsls in each arm, space in r6 per arm, y spilled with str r2,[sp] and reloaded per call, bound 7 in r5). Compiled copies p to r7 at entry. Tried per-arm base, off+join, u8* types, bound as local n, ternary base.
 *
 * note (2026-10-04, wD2 lane07): n assigned 7 in BOTH arms (not after them) keeps the bound in r5 with the
 *   `cmp r5,#0; ble` guard, matching the original. Residue now: base = p + off is not hoisted (p spilled, add redone in the loop,
 *   off/space in r6/r7 live through the loop; original frees off in r1 and holds base in r7). Same output for base var, p += off,
 *   off + p, u8 * types, static inline add(). Constant n after the arms or an enum n folds/reloads 7.
 *
 * note 2026-10-05 (D4-14): still DIFF. New tests: constant held in a local (k=0xA5; k<<=2) only exposes the lsls, p still spilled and the add stays in the loop;
 *   base written per arm (u32 *)p + 0xA5 / V16 *p + 0x2B and base += per arm both hoist base and give the right loop (43 bytes differ, 58 bytes) but put the add in
 *   each arm; n=7,i=0,base in arms keeps cmp/ble only when i=0 is written in the for. Original has the arms ending movs r1,movs r6,lsls,b and a shared join
 *   movs r5,#7; adds r7,r0,r1; movs r4,#0. Need the join add that is not sunk into the loop (base is single-use and mwcc sinks it). Nothing found.
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
