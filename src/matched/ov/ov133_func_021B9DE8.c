/*
 * function: DUP_FITTING_CreateActors
 * address: 0x021B9DE8
 * packet: pkt_ov133_021B9DE8
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: B294 leaves the forwarded result live in r0; request address is the unchanged fifth word.
 * note 2026-10-05 (wave D9r lane 131): removed the 8 dead first assignments
 * (`a=0x1848;` before `a=0x1860;`; `b=0x1848;` before `b=0x186c;` and 6
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT in --lang c99 and --lang c: the output bytes
 * do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 */
#include "../include/Obj01062.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct {s16 x,y,index;u8 a,b;} Params;
struct Actor;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
void DUP_FITTING_CreateActors(u8 *p)
{
    Params configs[2];
    int a,b,c,d,e,f,g,h;
    u8 i;
    i=0;
    a=0x1860;
    b=0x186c;
    c=0x1878;
    d=0x1890;
    e=0x1890;
    f=0x1890;
    g=0x1890;
    h=0x18b8;
    do {
        configs[1].x=0;configs[1].y=0;configs[1].index=0;configs[1].a=0;configs[1].b=0;
        *(void **)(p+(unsigned)i*4+d)=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,*(u32 *)(p+a),*(u32 *)(p+b),*(u32 *)(p+c),&configs[1],1,((struct Obj01062 *)p)->f0);
        CLACT_SetActorDrawEnable(*(void **)(p+(unsigned)i*4+e),1);
        CLACT_SetActorAutoAnim(*(void **)(p+(unsigned)i*4+f),1);
        CLACT_SetActorObjMode(*(void **)(p+(unsigned)i*4+g),0);
        p[(unsigned)i+h]=0;
        ++i;
    } while(i<8);
    configs[0].x=128;configs[0].y=96;configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct Obj01062 *)p)->f18B0=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj01062 *)p)->f18B0,0);
    CLACT_SetActorAutoAnim(((struct Obj01062 *)p)->f18B0,1);
    configs[0].index=2;
    ((struct Obj01062 *)p)->f18B4=CLACT_CreateActor((void *)((struct Obj01062 *)p)->f1848,((struct Obj01062 *)p)->f185C,((struct Obj01062 *)p)->f1868,((struct Obj01062 *)p)->f1874,&configs[0],0,((struct Obj01062 *)p)->f0);
    CLACT_SetActorDrawEnable(((struct Obj01062 *)p)->f18B4,0);
    CLACT_SetActorAutoAnim(((struct Obj01062 *)p)->f18B4,1);
}
