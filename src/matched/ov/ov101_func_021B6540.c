/*
 * function: COMPATIBLE_IRC_SYS_SendProfileAck
 * address: 0x021B6540
 * packet: pkt_ov101_021B6540
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncSendAck 0x021B67C4 thumb ov101
 */
#include "../include/Obj22097.h"
typedef unsigned int u32;
extern int COMPATIBLE_IRC_SYS_ProfileSyncSendAck(int *p);
int COMPATIBLE_IRC_SYS_SendProfileAck(u32 p) {
    if(((struct Obj22097 *)p)->f78!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncSendAck((int *)(p+4));
}
