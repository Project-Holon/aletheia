/*
 * function: MYSTERY_ALBUM_IsIntroIdle
 * address: 0x021DE014
 * packet: pkt_ov121_021DE014
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: boolean accessor after MYSTERY_ALBUM_ResetIntro; separate game leaf.
 */
#include "../include/Obj22908.h"
typedef unsigned short u16;
int MYSTERY_ALBUM_IsIntroIdle(char *p)
{
    if (((struct Obj22908 *)p)->fDC==0) return 1;
    return 0;
}
