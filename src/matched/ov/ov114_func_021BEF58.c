/*
 * function: NHTTPi_GetMutexInfoP
 * address:  0x021BEF58
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Field accessor: base + 0x34.
 */

typedef unsigned char u8;
typedef unsigned int u32;
void *NHTTPi_GetMutexInfoP(int p)
{
    return (void *)((char *)p + 0x34);
}
