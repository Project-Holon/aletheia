/*
 * function: func_0200ED14
 * address:  0x0200ED14
 * packet:   pkt_0200ED14
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200EC98   0x0200EC98  thumb
 *
 * An unlabelled accessor (its bytes print as a `.word` run after the pool
 * of func_0200ECF0): the header of ring entry `count - 1 - idx`, a tail call
 * to sub_0200EC98 through a pool word. Same shape as sub_0200ECD0 in
 * unit_0200ECB4.c. Its only caller is ov171 func_021DCCC8.
 */
typedef unsigned char u8;

extern void sub_0200EC98(const u8 *o, void *out);

void func_0200ED14(u8 *o, int idx, void *out)
{
    int n = *(int *)(o + 0x1554) - 1 - idx;

    if (n < 0)
        n += 0xf;
    sub_0200EC98(o + n * 0x16c, out);
}
