/*
 * function: BR_UTIL_EffectToPoint
 * address: 0x021FE1C4
 * packet: pkt_ov186_021FE1C4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Initialize i before the second start=p+18 assignment to interleave movs with the pointer adds (four bytes out to EXACT).
 * abi: B404 third parameter is u16 because the original truncates the loaded heap word immediately before blx.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`start=p;` before `start=p+0x18;`; `offset=0x228;` before
 * `offset=0x1f8;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 *
 * symbols:
 *   BR_UTIL_SetHandlesAnimSeq 0x021FD940 thumb ov186
 *   BR_UTIL_InitOrbit 0x021FE2BC thumb ov186
 *   BR_UTIL_StepOrbit 0x021FE2F8 thumb ov186
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_EffectIdle 0x021FD964 thumb ov186
 *   d_02200AD8 0x02200AD8 data a4
 */
#include "../include/Obj06632.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct {int x,y;} Pair;
typedef struct {short x,y;} ShortPair;
extern const u32 d_02200AD8[];
struct Pair;
extern void BR_UTIL_SetHandlesAnimSeq(unsigned char *p, u32 value);
extern int BR_UTIL_InitOrbit(unsigned char *p, const struct Pair *origin, u16 a, u16 b, u16 c, u16 d, int duration);
extern int BR_UTIL_StepOrbit(char *,int *,int);
typedef unsigned char  u8;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_AddActorSurfacePos(void *,const ShortPair *,u16);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void BR_UTIL_EffectIdle(void *unused, int *state, u8 *p);
void BR_UTIL_EffectToPoint(int *task,int *state,char *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0: {
        char *start;
        int offset;
        BR_UTIL_SetHandlesAnimSeq((unsigned char *)p,0);
        start=p+0x18;
        offset=0x1f8;
        for(i=6;i<12;i++) {
            u16 angle;
            angle=*(u16 *)(p+i*32+0x2a)+((struct Obj06632 *)p)->f228/ *(int *)(p+i*32+0x2c);
            BR_UTIL_InitOrbit((unsigned char *)(start+i*32),(void *)d_02200AD8,15,1,angle,angle+0xf000,30);
            CLACT_SetActorObjMode(*(void **)(p+i*4+offset),0);
        }
        ((struct Obj06632 *)p)->f228=0;
        *state=1;
    }
    case 1: {
        char *start;
        int offset;
        offset=0x228;start=p;i=6;start=p+0x18;offset=0x1f8;
        for(;i<12;i++) {
            BR_UTIL_StepOrbit(start+i*32,(int *)&full,((struct Obj06632 *)p)->f228);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos(*(void **)(p+i*4+offset),&pos,((struct Obj06632 *)p)->fC);
        }
        if((((struct Obj06632 *)p)->f228)++>60)*state=2;
        break;
    }
    case 2:BR_UTIL_SetTaskStep(task,(int)BR_UTIL_EffectIdle);break;
    }
}
