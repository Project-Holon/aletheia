/*
 * function: WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon
 * address: 0x021D81B4
 * packet: pkt_ov116_021D81B4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 */
#include "../include/Obj10345.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void TIME_ICON_Delete(u8 *);
void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p) { if(*(u8 * *)&((struct Obj10345 *)p)->f98C!=0) { TIME_ICON_Delete(*(u8 * *)&((struct Obj10345 *)p)->f98C); *(u32 *)&((struct Obj10345 *)p)->f98C=0; } }
