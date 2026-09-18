/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200ECB4
 * packet:   pkt_0200EA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200ECB4, sub_0200ECC4, sub_0200ECD0
 *
 * symbols:
 *   sub_0200EC14   0x0200EC14  thumb
 *
 * The tail of this packet: three unlabelled accessors of the object
 * func_0200EBD0 and func_0200EC2C work on (their bytes print as `.word`
 * runs because none of them saves lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  The byte range here is
 * 0x0200ECB4..0x0200ECF0, its two leading pad bytes belong to
 * sub_0200EC98 (which is not part of this file), and the three pool words
 * between the functions are each function's own.
 *
 * sub_0200ECD0 is a tail call through a pool word to
 * src/matched/func_0200EC14.c, and the pool word is the only reference to
 * 0x0200EC14 anywhere in the image, so that entry is what makes this file
 * verifiable at all (the `matched` class).
 */

typedef unsigned int u32;

extern int sub_0200EC14(char *o);

u32 sub_0200ECB4(char *o)
{
    u32 v = *(u32 *)(o + 0x1558);

    if (v >= 0xf)
        v = 0xf;
    return v;
}

u32 sub_0200ECC4(char *o, u32 n)
{
    return *(u32 *)(o + 0x1558) - n;
}

void sub_0200ECD0(char *o, int idx)
{
    int n = *(int *)(o + 0x1554) - 1 - idx;

    if (n < 0)
        n += 0xf;
    sub_0200EC14(o + n * 0x16c);
}
