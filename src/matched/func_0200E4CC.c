/*
 * function: func_0200E4CC
 * address:  0x0200E4CC
 * packet:   pkt_0200E4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two tells on the source, both four bytes each.  The base has to be taken as
 * a pointer (`p = a0 + 0x3c` then `p[off]`) rather than as one subscript
 * `a0[off + 0x3c]`: the original adds the 0x3c to the object pointer and then
 * indexes off against that, not the other way round.  And the guard is
 * written `a3 + v`, not `v + a3`: the add is commutative but this front end
 * keeps the source order in the encoding, and `v + a3` emits `adds r1, r2,
 * r4` where the original has `adds r1, r4, r2`.  The fourth parameter is
 * signed (the guard is `ble`, not `bls`).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0200E488(u32 a1, u32 a2);

void func_0200E4CC(u8 *a0, u32 a1, u32 a2, int a3)
{
    u8 *p;
    u32 off;
    u8 v;

    if (a2 == 0)
        return;
    off = func_0200E488(a1, a2);
    p = a0 + 0x3c;
    v = p[off];
    if (a3 + v > 0x63) {
        p[off] = 0x63;
        return;
    }
    p[off] = v + (u8)a3;
}
