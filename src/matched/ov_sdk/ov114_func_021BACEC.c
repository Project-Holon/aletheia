/*
 * function: NHTTPi_InitListInfo
 * address:  0x021BACEC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Clears the two leading words.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void NHTTPi_InitListInfo(u8 *p)
{
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 4) = 0;
}
