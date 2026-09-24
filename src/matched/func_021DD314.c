/*
 * function: func_021DD314
 * address:  0x021DD314
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */

extern void func_02007664(int, int, int);
extern void func_0201A9C8(int, int);

void func_021DD314(char **p, int a, unsigned b)
{
    if (b < 0x1eU)
        func_02007664(*(int *)(*p + 4), a, b);
    else
        func_0201A9C8(*(int *)(*p + 8), b - 0x1eU);
}
