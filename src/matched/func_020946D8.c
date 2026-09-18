/*
 * function: func_020946D8
 * address:  0x020946D8
 * packet:   pkt_02094488
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int u32;

int func_020946D8(u32 *p, u32 a1, u32 a2)
{
    switch (a2) {
    case 0: {
        u8 *q = (u8 *)*p;
        u8 c = *q;

        if (c == 0) {
            p[1] = 1;
            return -1;
        }
        *p = (u32)(q + 1);
        return c;
    }
    case 1:
        if (p[1] == 0)
            p[0] = p[0] - 1;
        else
            p[1] = 0;
        return (int)a1;
    case 2:
        return (int)p[1];
    default:
        return 0;
    }
}
