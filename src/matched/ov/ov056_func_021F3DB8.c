/*
 * function: func_021F3DB8
 * address:  0x021F3DB8
 * packet:   pkt_ov056_021F3DB8
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F40A0  0x021F40A0  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021F40A0(int *p);

int func_021F3DB8(int **pp)
{
    int r = 1;

    if (*pp != 0) {
        r = func_021F40A0(*pp);
    }
    return r;
}
