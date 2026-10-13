/*
 * function: NHTTPi_GetSystemInfoP
 * address:  0x021BEF08
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
 *   NHTTPi_InitSystemInfo  0x021BEEC4  arm  ov114
 *
 *
 * Lazily instantiates the overlay's singleton module object.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 gNHTTPModuleGlobals[];
extern u8 gNHTTPSystemInfo[];
extern void NHTTPi_InitSystemInfo(u8 *);

u8 *NHTTPi_GetSystemInfoP(void)
{
    u8 *p = *(u8 **)(gNHTTPModuleGlobals + 4);
    if (p == 0) {
        p = gNHTTPSystemInfo;
        *(u8 **)(gNHTTPModuleGlobals + 4) = p;
        NHTTPi_InitSystemInfo(p);
    }
    return p;
}
