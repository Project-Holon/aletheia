/*
 * function: COMPATIBLE_IRC_SYS_PollProfileRequest
 * address: 0x021B652C
 * packet: pkt_ov101_021B652C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_ProfileSyncPollRequest 0x021B67B0 thumb ov101
 */
#include "../include/Obj22096.h"
typedef unsigned int u32;
extern int COMPATIBLE_IRC_SYS_ProfileSyncPollRequest(int *p);
int COMPATIBLE_IRC_SYS_PollProfileRequest(u32 p) {
    if(((struct Obj22096 *)p)->f78!=0) return 1;
    return COMPATIBLE_IRC_SYS_ProfileSyncPollRequest((int *)(p+4));
}
