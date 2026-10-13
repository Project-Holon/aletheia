/*
 * function: FLD_VREQ_ApplyBlendAlpha
 * address:  0x021D32C4
 * packet:   pkt_ov021_021D32C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D63C(int, int, int, int, int);

void FLD_VREQ_ApplyBlendAlpha(int *p, int main)
{
    if (main) {
        func_0207D63C(0x04000050, p[0], p[1], p[2], p[3]);
    } else {
        func_0207D63C(0x04001050, p[0], p[1], p[2], p[3]);
    }
}
