/*
 * function: MANUAL_COMMON_GetGroupCount
 * address: 0x021B9C50
 * packet: pkt_ov225_021B9C50
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
#include "../include/Obj26138.h"
typedef unsigned short u16;
u16 MANUAL_COMMON_GetGroupCount(const char *p) {return **(u16 * *)&((struct Obj26138 *)p)->fC;}
