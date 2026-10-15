/*
 * function: MYSTERY_ALBUM_CreateSlotWork
 * address: 0x021DCFC8
 * packet: pkt_ov121_021DCFC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MYSTERY_UTIL_CreateWindowList 0x021DA1BC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF99C 0x021DF99C data a4
 */
#include "../include/Obj00237.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 w[12];} Desc;
typedef struct {u32 w[30];} Config;
typedef struct {s16 x,y,z;u8 a,b;} Record;
extern char d_021DFBB0[];
extern const Config d_021DF99C;
struct Actor;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *MYSTERY_UTIL_CreateWindowList(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *,int,int);
extern struct Obj *CLACT_CreateActor(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern int POKEGRA_OpenHandle(int a0);
extern int POKEGRA_RegisterPalette(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern int POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int POKEGRA_RegisterCgr(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void *MYSTERY_ALBUM_CreateSlotWork(const Desc *p,u16 heap)
{
    char *out;
    Config config;
    Record first;
    Record second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    ((struct Obj00237 *)out)->f88=p->w[5];
    ((struct Obj00237 *)out)->f94=p->w[0];
    ((struct Obj00237 *)out)->f96=p->w[1];
    *(Desc *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        ((struct Obj00237 *)out)->f9C=0;
        ((struct Obj00237 *)out)->f98=0;
        ((struct Obj00237 *)out)->f84=1;
    } else {
        ((struct Obj00237 *)out)->f9C=4;
        ((struct Obj00237 *)out)->f98=1;
        ((struct Obj00237 *)out)->f84=0;
    }
    config=d_021DF99C;
    ((struct Obj00237 *)out)->f0=MYSTERY_UTIL_CreateWindowList((void *)1,(const char *)&config,5,((struct Obj00237 *)out)->fA4,((struct Obj00237 *)out)->fAC,((struct Obj00237 *)out)->fC8,((struct Obj00237 *)out)->fC0,((struct Obj00237 *)out)->fC4,heap);
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj00237 *)out)->f4=CLACT_RegisterPalette(arc,3,((struct Obj00237 *)out)->f98,(u16)(p->w[4]<<5),heap);
    *(int *)&((struct Obj00237 *)out)->fC=CLACT_RegisterCellAnim(arc,33,36,heap);
    *(int *)&((struct Obj00237 *)out)->f8=CLACT_RegisterCharacter(arc,12,0,((struct Obj00237 *)out)->f98,heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&first,0,8);
    first.x=216;first.y=22;
    ((struct Obj00237 *)out)->f1C=CLACT_CreateActor((void *)p->w[6],((struct Obj00237 *)out)->f8,((struct Obj00237 *)out)->f4,((struct Obj00237 *)out)->fC,&first,((struct Obj00237 *)out)->f98,heap);
    CLACT_SetActorObjMode(((struct Obj00237 *)out)->f1C,0);
    CLACT_SetActorDrawEnable(((struct Obj00237 *)out)->f1C,0);
    arc2=(void *)POKEGRA_OpenHandle(heap);
    *(int *)&((struct Obj00237 *)out)->f10=POKEGRA_RegisterPalette((int)arc2,1,0,0,0,0,0,((struct Obj00237 *)out)->f98,p->w[5]<<5,heap);
    *(int *)&((struct Obj00237 *)out)->f18=POKEGRA_RegisterCellAnim(1,0,0,0,0,0,2,((struct Obj00237 *)out)->f98,heap);
    *(int *)&((struct Obj00237 *)out)->f14=POKEGRA_RegisterCgr(arc2,1,0,0,0,0,0,0,((struct Obj00237 *)out)->f98,heap);
    ARC_TOOL_DeleteHandle(arc2);
    MI_CpuFill8(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    ((struct Obj00237 *)out)->f8C=second.b;
    ((struct Obj00237 *)out)->f90=p->w[1]&3;
    ((struct Obj00237 *)out)->f20=CLACT_CreateActor((void *)p->w[6],((struct Obj00237 *)out)->f14,((struct Obj00237 *)out)->f10,((struct Obj00237 *)out)->f18,&second,((struct Obj00237 *)out)->f98,heap);
    CLACT_SetActorAffineMode(((struct Obj00237 *)out)->f20,2);
    CLACT_SetActorObjMode(((struct Obj00237 *)out)->f20,1);
    CLACT_SetActorDrawEnable(((struct Obj00237 *)out)->f20,0);
    return out;
}
