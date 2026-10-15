/*
 * function: BR_CODEIN_ProfileSetActorAnim
 * address: 0x021E11D0
 * packet: pkt_ov183_021E11D0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
#include "../include/Obj01768.h"
typedef unsigned short u16;
void BR_CODEIN_ProfileSetActorAnim(char *p,int state)
{
    ((struct Obj01768 *)p)->f244=((struct Obj01768 *)p)->f240;
    ((struct Obj01768 *)p)->f240=state;
    ((struct Obj01768 *)p)->f248=0;
    ((struct Obj01768 *)p)->f24C=0;
    ((struct Obj01768 *)p)->f250=0;
    ((struct Obj01768 *)p)->f254=0;
    if (state) {
        ((struct Obj01768 *)p)->f248=*(u16 *)(p+(state-1)*4+0x21c);
        ((struct Obj01768 *)p)->f24C=*(u16 *)(p+(state-1)*4+0x21e);
    }
    if (((struct Obj01768 *)p)->f244) {
        ((struct Obj01768 *)p)->f250=*(u16 *)(p+(((struct Obj01768 *)p)->f244-1)*4+0x21c);
        ((struct Obj01768 *)p)->f254=*(u16 *)(p+(((struct Obj01768 *)p)->f244-1)*4+0x21e);
    }
}
