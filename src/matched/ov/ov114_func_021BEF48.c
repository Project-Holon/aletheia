/*
 * function: NHTTPi_GetReqInfoP
 * address:  0x021BEF48
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Field accessor: base + 0x30.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void *NHTTPi_GetReqInfoP(int p)
{
    return (void *)((char *)p + 0x30);
}
