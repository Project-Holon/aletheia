/*
 * function: func_021BA0CC
 * address:  0x021BA0CC
 * packet:   pkt_ov071_021BA0CC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf following func_021BA01C inside its listing extent.
 */

typedef unsigned char u8;

int func_021BA0CC(u8 *p, int d)
{
    int lim;
    int old;

    old = *(int *)(p + 0x2d8);
    lim = p[0x27c] * 32 - 8;
    if (lim <= 0xc0) {
        return 0;
    }
    *(int *)(p + 0x2d8) = old + d;
    if (*(int *)(p + 0x2d8) < 0x800) {
        *(int *)(p + 0x2d8) = 0x800;
    } else if (*(int *)(p + 0x2d8) > (lim - 0xc0) << 8) {
        *(int *)(p + 0x2d8) = (lim - 0xc0) << 8;
    }
    if ((*(int *)(p + 0x2d8) >> 8) != (old >> 8)) {
        return 1;
    }
    return 0;
}
