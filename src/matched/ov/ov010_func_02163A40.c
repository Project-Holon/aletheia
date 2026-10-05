/*
 * function: func_02163A40
 * address:  0x02163A40
 * packet:   pkt_ov010_02163A40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tests whether two rectangles (s16 x0, y0, x1, y1) overlap: per axis the
 * longer interval comes first, then either end of the shorter one must lie
 * inside it. Leaf, no calls. EXACT* only for the 2-byte pad after the
 * function (174 of 176).
 *
 * Key: each axis is a block with its own locals, and the second block
 * declares them in a different order (big0, big1, sm0, sm1, lo1, hi1, lo2,
 * hi2, d1, d2). Declaration order sets the colouring order of the second
 * axis (d1 after lo2); the first block keeps d1, d2, lo1, ... order.
 * Earlier 15 B residue (shared locals) was only the d1/lo2 register swap.
 */
typedef short s16;
int func_02163A40(s16 *a, s16 *b)
{
    {
        s16 d1, d2, lo1, hi1, lo2, hi2, big0, big1, sm0, sm1;
        lo1 = a[0]; hi1 = a[2]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[0]; hi2 = b[2]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    {
        s16 big0, big1, sm0, sm1, lo1, hi1, lo2, hi2, d1, d2;
        lo1 = a[1]; hi1 = a[3]; d1 = hi1 - lo1; if (d1 < 0) { d1 = -d1; }
        lo2 = b[1]; hi2 = b[3]; d2 = hi2 - lo2; if (d2 < 0) { d2 = -d2; }
        if (d1 > d2) { big0 = lo1; big1 = hi1; sm0 = lo2; sm1 = hi2; }
        else { big0 = lo2; big1 = hi2; sm0 = lo1; sm1 = hi1; }
        if (!((big0 <= sm0 && big1 >= sm0) || (big0 <= sm1 && big1 >= sm1))) goto fail;
    }
    return 1;
fail:
    return 0;
}
