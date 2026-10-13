/*
 * function: func_021B6508
 * address: 0x021B6508
 * packet: pkt_ov101_021B6508
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 */
#include "../include/Obj22094.h"
typedef unsigned int u32;
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
void func_021B6508(u32 p,u32 a) {
    if(((struct Obj22094 *)p)->f78==0) GFL_NET_COMMAND_DeleteCommandTable(a);
}
