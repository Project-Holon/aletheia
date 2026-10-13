/*
 * function: NHTTPi_GetConnectionListLength
 * address:  0x021BEC48
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNHTTPModuleGlobals  0x021CF984  data
 *   gNHTTPStaticResource  0x021CF98C  data
 *   gNHTTPSystemInfo  0x021CF9C0  data
 *   gNHTTPSslSeed  0x021CF964  data
 *
 *
 * Counts the entries on the +0x20 list hanging off the module object.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gNHTTPModuleGlobals[];

u32 NHTTPi_GetConnectionListLength(void)
{
    u32 n = 0;
    u8 *p = *(u8 **)gNHTTPModuleGlobals;
    while (p != 0) {
        p = *(u8 **)(p + 0x20);
        n++;
    }
    return n;
}
