/*
 * function: func_021BD194
 * address: 0x021BD194
 * packet: pkt_ov110_021BD194
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BAC40 0x021BAC40 thumb ov110
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj02462.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 x,y,z; u8 a,b; } Params;
extern unsigned int func_020275E4(void);
typedef unsigned int   u32;
struct Obj;
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_021BAC40(u8 *p);
extern struct Obj *func_0204B294(void *owner,u32 i,u32 j,u32 k,const void *position,u16 space,u16 heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021BD194(u8 *p) {
    void *h;
    int a;
    Params t;
    h=func_020490F4(func_020275E4(),42);
    ((struct Obj02462 *)p)->f1C=(void *)func_0204AC18(h,func_02027614(),0,384,0,3,42);
    ((struct Obj02462 *)p)->f20=(void *)func_0204A6C8(h,func_02027618(),0,0,42);
    a=func_0202761C(1);
    ((struct Obj02462 *)p)->f24=(void *)func_0204AF28(h,a,func_02027620(1),42);
    func_02049238(h);
    func_02082BCC(&t,0,8);
    t.x=232; t.y=168; t.z=1; t.a=0; t.b=3;
    ((struct Obj02462 *)p)->f28=func_0204B294((void *)func_021BAC40(((struct Obj02462 *)p)->f0),(u32)((struct Obj02462 *)p)->f20,(u32)((struct Obj02462 *)p)->f1C,(u32)((struct Obj02462 *)p)->f24,&t,0,42);
    func_0204B92C(((struct Obj02462 *)p)->f28,1);
    func_0204B3DC(((struct Obj02462 *)p)->f28,0);
    ((struct Obj02462 *)p)->f2C=0;
}
