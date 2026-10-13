/*
 * function: BTL_REC_MakeSkipPacket
 * address:  0x021EE8D8
 * packet:   pkt_ov093_021EE8D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 *BTL_REC_MakeSkipPacket(u8 *p, u32 *out, int flag)
{
    p[4] = 4;
    p[5] = 0x20 | (((u8)flag & 1) << 7);
    *out = 2;
    return p + 4;
}
