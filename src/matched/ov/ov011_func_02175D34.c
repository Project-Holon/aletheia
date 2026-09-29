/*
 * function: func_02175D34
 * address:  0x02175D34
 * packet:   pkt_ov011_02175D34
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Rec {
    u32 w[11];
    u8  f2c;
    u8  pad2d[7];
} Rec;

void func_02175D34(void *unused, u8 *b)
{
    Rec *src;
    Rec *dst;

    src = (Rec *)(b + 0x78);
    dst = (Rec *)(b + 0xac);
    if (src->f2c != 4 && dst->f2c == 4) {
        *dst = *src;
        ((u8 *)dst)[0x37] = 1;
        b[0x19b] = 1;
        b[0x19c] = 0;
    }
}
