/*
 * function: POKETRADE_SAVE_ToggleTypeIconSet
 * address: 0x021E2140
 * packet: pkt_ov119_021E2140
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_CreateTypeIcons 0x021E2070 thumb ov119
 *   gTypeIconSetA 0x021E7954 data a4
 *   gTypeIconSetB 0x021E7964 data a4
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef struct { int a,b,c,d; } Quad;
extern const Quad gTypeIconSetA,gTypeIconSetB;
extern void POKETRADE_SAVE_CreateTypeIcons(void *,int,Quad *);
void POKETRADE_SAVE_ToggleTypeIconSet(char *p,int a)
{
    if(((struct Obj00001 *)p)->f1098) {
        Quad t;
        t=gTypeIconSetA;
        POKETRADE_SAVE_CreateTypeIcons(p,a,&t);
        ((struct Obj00001 *)p)->f1098=0;
    } else {
        Quad t;
        t=gTypeIconSetB;
        POKETRADE_SAVE_CreateTypeIcons(p,a,&t);
        ((struct Obj00001 *)p)->f1098=1;
    }
}
