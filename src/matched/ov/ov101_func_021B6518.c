/*
 * function: COMPATIBLE_IRC_SYS_SendProfileRequest
 * address: 0x021B6518
 * packet: pkt_ov101_021B6518
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncSendRequest 0x021B678C thumb ov101
 */
#include "../include/Obj22095.h"
typedef unsigned int u32;
extern int COMPATIBLE_IRC_SYS_ProfileSyncSendRequest(int *p, int a, int b);
int COMPATIBLE_IRC_SYS_SendProfileRequest(u32 p,u32 a,u32 b) {
    if(((struct Obj22095 *)p)->f78!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncSendRequest((int *)(p+4),a,b);
}
