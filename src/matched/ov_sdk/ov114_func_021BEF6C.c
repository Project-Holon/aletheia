/*
 * function: NHTTPi_InitConnectionList
 * address:  0x021BEF6C
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
 *   NHTTPi_GetConnectionListLength  0x021BEC48  arm  ov114
 *
 *
 * Drains the module list, then empties the module head pointer.
 */

#include "../include/G_Conn.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern struct Conn *gNHTTPModuleGlobals;
extern u32 NHTTPi_GetConnectionListLength(void);

void NHTTPi_InitConnectionList(void)
{
    if ((*(u32 *)&gNHTTPModuleGlobals) != 0)
        NHTTPi_GetConnectionListLength();
    (*(u32 *)&gNHTTPModuleGlobals) = 0;
}
