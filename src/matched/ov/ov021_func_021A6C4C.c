/*
 * function: func_021A6C4C
 * address:  0x021A6C4C
 * packet:   pkt_ov021_021A6C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */

typedef unsigned char u8;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    int f4;
} T;

int func_021A6C4C(T *t, int x)
{
    int r;
    if (t->b2) {
        return 1;
    }
    r = t->f4;
    if (r == 9) {
        r = x;
    }
    return r;
}
