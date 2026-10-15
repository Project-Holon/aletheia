/*
 * function: WIFI_BSUBWAY_AsyncHasError
 * address: 0x021D7158
 * packet: pkt_ov116_021D7158
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj08047.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
int WIFI_BSUBWAY_AsyncHasError(u8 *p)
{
    if (((struct Obj08047 *)p)->f0 < 0) return 1;
    if (((struct Obj08047 *)p)->f4 != 0) return 1;
    if (((struct Obj08047 *)p)->fC != 0) return 1;
    if (((struct Obj08047 *)p)->f8 != 0) return 1;
    return 0;
}
