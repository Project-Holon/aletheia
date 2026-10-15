/*
 * function: MYSTERY_PollOamSprite
 * address: 0x021D94B8
 * packet: pkt_ov121_021D94B8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 * symbols:
 *   MYSTERY_UTIL_IsMenuFinished 0x021DA9F8 thumb ov121
 */
#include "../include/Obj22871.h"
typedef unsigned char  u8;
extern int MYSTERY_UTIL_IsMenuFinished(u8 *p);
int MYSTERY_PollOamSprite(char *p)
{
    return MYSTERY_UTIL_IsMenuFinished(((struct Obj22871 *)p)->f4);
}
