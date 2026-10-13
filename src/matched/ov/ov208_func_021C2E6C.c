/*
 * function: func_021C2E6C
 * address: 0x021C2E6C
 * packet: pkt_ov208_021C2E6C
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * CLACT_CreateAffineActor returns the actor in r0 here, although its filed C says void.
 * CC40 species is wide here: no truncation before the call.
 * D81C/D898 scalar slots preserve every member of their filed by-value tails,
 * including the key halfword at +20/+16 and unused upper padding bits.
 * symbols:
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021BC738 0x021BC738 thumb ov208
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   CLACT_CreateAffineActor 0x0204B324 arm
 *   func_0204B688 0x0204B688 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Tail {u32 s0,s1,s2,s3,s4;u16 key,pad;};
struct Args {u32 w0,w1,w2,w3;u16 key,pad;};
struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};
extern u16 func_021BC3C0(int);
struct Actor;
extern int func_021BC3A4(int *p);
extern void *func_0200CA1C(void *a);
extern void func_0200CC40(void *,u32,u32 *,u32 *,u32 *,u16);
typedef signed int     s32;
struct Blk37;
struct Ov208Gfx;
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern int POKEGRA_OpenHandle(int a0);
extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int POKEGRA_RegisterPalette(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int POKEGRA_GetArcID(void);
extern s32 POKEGRA_GetPalArcIndex(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u32);
extern void func_02082BCC(void *,u8,u32);
struct Obj;
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot)
{
    struct Desc desc;
    u32 form,b,a;
    u32 arc,special,species;
    void *ctx;
    species=func_021BC3C0(key);
    special=0;
    ctx=func_0200CA1C((void *)func_021BC3A4((int *)key));
    func_0200CC40(ctx,species,&form,&b,&a,*heap);
    if(species==327)special=func_0200D288(ctx,special);
    arc=POKEGRA_OpenHandle(*heap);
    *(u32 *)((u32)p+0x44+slot*4)=POKEGRA_RegisterCgr(arc,species,a,form,b,0,0,special,1,*heap);
    *(u32 *)((u32)p+0x3c+slot*4)=POKEGRA_RegisterPalette(arc,species,a,form,b,0,0,1,(u16)(slot<<5),*heap);
    *(u32 *)((u32)p+0x4c+slot*4)=POKEGRA_RegisterCellAnim(species,a,form,b,0,0,2,1,*heap);
    func_021BC738(((struct Obj00146 *)p)->fC8,arc,POKEGRA_GetPalArcIndex(POKEGRA_GetArcID(),species,a,form,b,0,0),*heap,3,32,(u16)(slot<<4),0);
    ARC_TOOL_DeleteHandle(arc);
    func_02082BCC(&desc,0,24);
    desc.x=128;desc.y=128;desc.z=0;desc.a=0;desc.b=0;desc.c=0;desc.d=0;
    desc.sx=4096;desc.sy=4096;desc.e=0;desc.f=2;
    *(u32 *)((u32)p+0x54+slot*4)=(u32)CLACT_CreateAffineActor(((struct Obj00146 *)p)->f0,*(u32 *)((u32)p+0x44+slot*4),*(u32 *)((u32)p+0x3c+slot*4),*(u32 *)((u32)p+0x4c+slot*4),(u32)(&desc),1,*heap);
    func_0204B688((struct Actor *)(*(u32 *)((u32)p+0x54+slot*4)),0);
    ((struct Obj00146 *)p)->f60=0;
}
