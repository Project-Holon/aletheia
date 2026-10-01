/*
 * function: func_021CFD88
 * address:  0x021CFD88
 * packet:   pkt_ov021_021CFD88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021CFD88(int a, u32 b, u32 c, int d, int e)
{
    int off;

    if (e != 0) {
        off = 4;
    } else {
        off = 0x44;
    }
    if (c < 5) {
        off += c * 0xc;
    }
    if (a != 0) {
        off += 6;
    }
    if (d == 0) {
        off++; off += b % 5;
    }
    return off;
}
