/*
 * function: IRCBATTLEMATCH_SetPlayerReady
 * address: 0x021B9824
 * packet: pkt_ov100_021B9824
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: alignment then separately filed follower IRCBATTLEMATCH_OnChangeoverConnected.
 * symbols:
 *   func_02080D24 0x02080D24 arm
 */
#include "../include/Obj13706.h"
extern unsigned char func_02080D24(unsigned x);
void IRCBATTLEMATCH_SetPlayerReady(int a,int b)
{
 if(func_02080D24(((struct Obj13706 *)a)->f2E8 |= 1 << b)>=2) ((struct Obj13706 *)a)->f2EC=1;
}
