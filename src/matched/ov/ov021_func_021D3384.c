/*
 * function: func_021D3384
 * address:  0x021D3384
 * packet:   pkt_ov021_021D3384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D6C0  0x0207D6C0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D6C0(u32 reg, u32 a1);

void func_021D3384(u32 *p, int main)
{
    if (main) {
        func_0207D6C0(0x04000050, p[0]);
    } else {
        func_0207D6C0(0x04001050, p[0]);
    }
}
