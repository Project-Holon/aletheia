/*
 * function: COMPATIBLE_IRC_SYS_AddCommandTable
 * address: 0x021B64F0
 * packet: pkt_ov101_021B64F0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two zero alignment bytes.
 * symbols:
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 */
#include "../include/Obj22093.h"
typedef unsigned int u32;
extern void GFL_NET_COMMAND_AddCommandTable(u32,u32,u32,u32);
void COMPATIBLE_IRC_SYS_AddCommandTable(u32 p,u32 a,u32 b,u32 c,u32 d) {
    if(((struct Obj22093 *)p)->f78==0) GFL_NET_COMMAND_AddCommandTable(a,b,c,d);
}
