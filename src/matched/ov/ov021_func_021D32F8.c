/*
 * function: FLD_VREQ_ApplyBlendBrightness
 * address:  0x021D32F8
 * packet:   pkt_ov021_021D32F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0207D658(u32 addr, int plane, int brightness);

void FLD_VREQ_ApplyBlendBrightness(u32 *p, int main)
{
    if (main) {
        func_0207D658(0x04000050, p[0], p[1]);
    } else {
        func_0207D658(0x04001050, p[0], p[1]);
    }
}
