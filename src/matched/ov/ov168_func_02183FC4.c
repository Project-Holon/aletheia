/*
 * function: MICTEST_CreateActors
 * address: 0x02183FC4
 * packet: pkt_ov168_02183FC4
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 */
#include "../include/Obj01262.h"
#include "../include/Obj10642.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 group,id,config;} Row;
typedef struct {short x,y,id;u8 a,b;} Config;
extern const Row d_02184910[];
extern const Config d_021848AC[];
struct Actor;
struct Bank;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 APP_ICON_GetArchiveId(void);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);
void MICTEST_CreateActors(char *p,u16 heap)
{
    void *first,*second;
    u16 i;
    const Row *r;
    char *q;
    i=0;
    ((struct Obj01262 *)p)->f1C=CLACT_CreateUnit(32,0,heap);
    first=func_020490F4(106,heap);
    second=func_020490F4(APP_ICON_GetArchiveId(),heap);
    ((struct Obj01262 *)p)->f24=CLACT_RegisterPalette(first,6,0,0,heap);
    ((struct Obj01262 *)p)->f20=CLACT_RegisterCharacter(first,7,0,0,heap);
    ((struct Obj01262 *)p)->f28=CLACT_RegisterCellAnim(first,8,9,heap);
    ((struct Obj01262 *)p)->f30=CLACT_RegisterPalette(first,10,0,32,heap);
    ((struct Obj01262 *)p)->f2C=CLACT_RegisterCharacter(first,11,0,0,heap);
    ((struct Obj01262 *)p)->f34=CLACT_RegisterCellAnim(first,12,13,heap);
    ((struct Obj01262 *)p)->f3C=CLACT_RegisterPalette(first,14,0,64,heap);
    ((struct Obj01262 *)p)->f38=CLACT_RegisterCharacter(first,15,0,0,heap);
    ((struct Obj01262 *)p)->f40=CLACT_RegisterCellAnim(first,16,17,heap);
    ((struct Obj01262 *)p)->f48=CLACT_RegisterPalette(second,31,1,0,heap);
    ((struct Obj01262 *)p)->f44=CLACT_RegisterCharacter(second,32,0,1,heap);
    ((struct Obj01262 *)p)->f4C=CLACT_RegisterCellAnim(first,18,19,heap);
    ARC_TOOL_DeleteHandle(second);
    ARC_TOOL_DeleteHandle(first);
    do{
        r=&d_02184910[i];
        q=p+r->group*4;
        *(void **)(p+i*4)=CLACT_CreateActor((void *)*(u32 *)&((struct Obj01262 *)p)->f1C,((struct Obj10642 *)q)->f20,((struct Obj10642 *)q)->f24,((struct Obj10642 *)q)->f28,&d_021848AC[r->config],r->id,heap);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4),1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x10),0);
    CLACT_SetActorAffineMode(((struct Obj01262 *)p)->f0,0);
    CLACT_SetActorFlip(((struct Obj01262 *)p)->f0,1,1);
    ((struct Obj01262 *)p)->fE0=10;
}
