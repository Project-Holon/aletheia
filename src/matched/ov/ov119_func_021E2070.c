/*
 * function: POKETRADE_SAVE_CreateTypeIcons
 * address: 0x021E2070
 * packet: pkt_ov119_021E2070
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_DeleteTypeIconActor 0x021E0DA0 thumb ov119
 *   POKETRADE_SAVE_CreateTypeIconActor 0x021E0DBC thumb ov119
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj08065.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int a,b,c,d; } Quad;
struct Obj;
extern void POKETRADE_SAVE_DeleteTypeIconActor(char *p);
extern void POKETRADE_SAVE_CreateTypeIconActor(char *,void *,int,int,int,int,int,u16);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void POKETRADE_SAVE_CreateTypeIcons(char *p,void *mon,Quad *t)
{
    u32 a,b;
    POKETRADE_SAVE_DeleteTypeIconActor(p+0x900+t->a*20);
    POKETRADE_SAVE_DeleteTypeIconActor(p+0x900+t->b*20);
    POKETRADE_SAVE_CreateTypeIconActor(p+0x900+t->a*20,mon,0,((struct Obj08065 *)p)->f9C4,176,95,0,((struct Obj08065 *)p)->f5F4);
    a=POKE_TOOL_GetPartyValue(mon,174,0);
    b=POKE_TOOL_GetPartyValue(mon,175,0);
    if(a!=b)
        POKETRADE_SAVE_CreateTypeIconActor(p+0x900+t->b*20,mon,1,((struct Obj08065 *)p)->f9C4,210,95,0,((struct Obj08065 *)p)->f5F4);
    if(*(void **)(p+t->c*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->c*20+0x910),0);
    if(*(void **)(p+t->d*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->d*20+0x910),0);
}
