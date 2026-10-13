/*
 * function: NHTTPi_isRecvBufFull
 * address:  0x021BB2FC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * 1 when field +0x1c is <= v (unsigned).
 */

typedef unsigned char u8;
typedef unsigned int u32;
int NHTTPi_isRecvBufFull(u8 *p, u32 v)
{
    return *(u32 *)(p + 0x1c) <= v;
}
