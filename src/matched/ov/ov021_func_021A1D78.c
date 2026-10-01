/*
 * function: func_021A1D78
 * address:  0x021A1D78
 * packet:   pkt_ov021_021A1D78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

int func_021A1D78(u16 a, u16 b)
{
    int r = 0;

    switch (a) {
    case 1:
        if ((u16)(b + 0xFFFC) <= 1)
            r = 1;
        break;
    case 4:
        if (b == 1 || b == 5)
            r = 1;
        break;
    case 5:
        if (b == 4 || b == 1)
            r = 1;
        break;
    }
    return r;
}
