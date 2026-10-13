/*
 * function: func_021C83DC
 * address:  0x021C83DC
 * packet:   pkt_ov111_021C83DC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void func_021C83DC(u8 *p, int value)
{
    if (p[5] == 0) {
        GFL_USE_PlaySeDefaultVolume(value > 0x210 ? 0x661 : 0x660);
        p[5] = 5;
    } else {
        p[5]--;
    }
}
