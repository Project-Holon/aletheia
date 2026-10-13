/*
 * function: VCT_SESSION_InitPeer
 * address: 0x021B2724
 * packet: pkt_ov013_021B2724
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 *   gVctSession 0x021B60D8 data a4
 *   func_020923B0 0x020923B0 arm
 */
#include "../include/Obj09377.h"
#include "../include/G_Sess.h"
typedef unsigned char u8;
extern struct Sess gVctSession;
extern void *func_020923B0(void *,int,unsigned int);
void VCT_SESSION_InitPeer(u8 *p,u8 v)
{
    func_020923B0(p,0,24);
    ((struct Obj09377 *)p)->f0=((int *)&gVctSession)[4];
    ((struct Obj09377 *)p)->fC=0;
    p[4]=v;
}
