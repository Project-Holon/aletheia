/*
 * function: OEKAKI_GetRecvChunk
 * address: 0x0218454C
 * packet: pkt_ov023_0218454C
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov023/oekaki.c and filed here.
 */

typedef unsigned char u8;
u8 *OEKAKI_GetRecvChunk(int idx, u8 *base);

u8 *OEKAKI_GetRecvChunk(int idx, u8 *base)
{
    return base + 0x7EC0 + idx * 0x3F0;
}
