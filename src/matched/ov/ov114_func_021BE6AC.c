/*
 * function: NHTTP_GetError
 * address:  0x021BE6AC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NHTTPi_GetError  0x021BAA14  arm  ov114
 *   NHTTPi_GetSystemInfoP  0x021BEF08  arm  ov114
 *
 *
 * Module +0x14 field read: the +0x14 word of the singleton module object.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *NHTTPi_GetSystemInfoP(void);
extern u32 NHTTPi_GetError(u8 *);

u32 NHTTP_GetError(void)
{
    return NHTTPi_GetError(NHTTPi_GetSystemInfoP());
}
