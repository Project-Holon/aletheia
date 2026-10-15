/*
 * function: ZUKAN_DETAIL_TOUCHBAR_Create
 * address: 0x021BD8C0
 * packet: pkt_ov208_021BD8C0
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_021BDCF8 0x021BDCF8 thumb ov208
 *   ZKND_TBAR_SetTouchEnable 0x021BD358 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos 0x021BDD48 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_FlushBar 0x021BDCDC thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DE4 0x021C8DE4 data a1
 */
#include "../include/Obj01080.h"
typedef unsigned short u16;
struct Bank;struct Ov208Scene;
extern const char d_021C8DE4[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void BG_SYS_SetVisibleLayer(int,u16);
extern struct Bank *CLACT_CreateUnit(int,unsigned char,unsigned);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void func_021BDCF8(struct Ov208Scene *);
extern void ZKND_TBAR_SetTouchEnable(char *p, int v);
extern void ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(char *,short);
extern void ZUKAN_DETAIL_TOUCHBAR_FlushBar(int,char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
char *ZUKAN_DETAIL_TOUCHBAR_Create(u16 heap,unsigned arg)
{
    char *p=func_02030734(heap,0x11c,1,d_021C8DE4,0x148);
    ((struct Obj01080 *)p)->f0=heap;((struct Obj01080 *)p)->f4=arg;
    ((struct Obj01080 *)p)->f8=0;((struct Obj01080 *)p)->fC=0;((struct Obj01080 *)p)->f10=0;
    ((struct Obj01080 *)p)->f14=1;((struct Obj01080 *)p)->f18=0;((struct Obj01080 *)p)->f1C=0;((struct Obj01080 *)p)->f20=0;
    func_02040618(1,3,-24);BG_SYS_SetVisibleLayer(1,0);
    p[0x38]=0;((struct Obj01080 *)p)->f3C=0;
    *(struct Bank * *)&((struct Obj01080 *)p)->f28=CLACT_CreateUnit(16,0,((struct Obj01080 *)p)->f0);
    CLACT_SetUnitDefaultRenderer(*(struct Bank * *)&((struct Obj01080 *)p)->f28);
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene *)p);
    ZKND_TBAR_SetTouchEnable(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;ZUKAN_DETAIL_TOUCHBAR_OffsetActorPos(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)ZUKAN_DETAIL_TOUCHBAR_FlushBar,(unsigned)p,1);
    return p;
}
