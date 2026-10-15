/*
 * function: WIFI_BSUBWAY_TickUploadTimeout
 * address: 0x021D7260
 * packet: pkt_ov116_021D7260
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj06417.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
void WIFI_BSUBWAY_TickUploadTimeout(u8 *p)
{
    (((struct Obj06417 *)p)->fA)++;
    if (((struct Obj06417 *)p)->fA == 3600) ((struct Obj06417 *)p)->f8 = 1;
}
