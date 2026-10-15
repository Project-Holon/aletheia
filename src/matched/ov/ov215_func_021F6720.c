/*
 * function: EGG_DEMO_VIEW_Create
 * address: 0x021F6720
 * packet: pkt_ov215_021F6720
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_020056A0 0x020056A0 thumb
 *   EGG_DEMO_VIEW_Noop 0x021F6AB4 thumb ov215
 *   EGG_DEMO_VIEW_InitMcss 0x021F6AB8 thumb ov215
 *   EGG_DEMO_VIEW_AddPokeMcss 0x021F6AEC thumb ov215
 *   EGG_DEMO_VIEW_CreateParticles 0x021F6DB4 thumb ov215
 *   EGG_DEMO_VIEW_InitModel 0x021F6EF8 thumb ov215
 *   EGG_DEMO_VIEW_AddModel 0x021F6F64 thumb ov215
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 */
#include "../include/Obj00317.h"
typedef unsigned short u16;
extern const char d_021F73F4[];
extern const unsigned d_021F7340[],d_021F7314[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
typedef unsigned int   u32;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void *func_020056A0(void (*)(void),void *,unsigned);
extern void EGG_DEMO_VIEW_Noop(void);
extern void EGG_DEMO_VIEW_InitMcss(char *p);
extern void EGG_DEMO_VIEW_AddPokeMcss(char *p);
extern char *EGG_DEMO_VIEW_CreateParticles(unsigned,unsigned,const void *);
extern void EGG_DEMO_VIEW_InitModel(char *p);
extern void EGG_DEMO_VIEW_AddModel(char *p);
char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    ((struct Obj00317 *)p)->f0=heap;
    ((struct Obj00317 *)p)->f4=mon;
    ((struct Obj00317 *)p)->f8=POKE_TOOL_GetPartyValue(mon,5,0);
    ((struct Obj00317 *)p)->fC=0;
    ((struct Obj00317 *)p)->f10=0;
    ((struct Obj00317 *)p)->f14=0;
    ((struct Obj00317 *)p)->f18=0;
    ((struct Obj00317 *)p)->f1C=0;
    ((struct Obj00317 *)p)->f24=0;
    ((struct Obj00317 *)p)->f28=0;
    ((struct Obj00317 *)p)->f2C=func_020056A0(EGG_DEMO_VIEW_Noop,p,1);
    EGG_DEMO_VIEW_InitMcss(p);
    EGG_DEMO_VIEW_AddPokeMcss(p);
    if(((struct Obj00317 *)p)->f8==490)
        ((struct Obj00317 *)p)->f44=EGG_DEMO_VIEW_CreateParticles(((struct Obj00317 *)p)->f0,5,d_021F7340);
    else
        ((struct Obj00317 *)p)->f44=EGG_DEMO_VIEW_CreateParticles(((struct Obj00317 *)p)->f0,3,d_021F7314);
    EGG_DEMO_VIEW_InitModel(p);
    EGG_DEMO_VIEW_AddModel(p);
    return p;
}
