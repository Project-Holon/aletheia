/*
 * function: func_021B9C4C
 * address: 0x021B9C4C
 * packet: pkt_ov221_021B9C4C
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * arity: 4B294 forwards CFDC's live r0 object result despite legacy void declaration.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_021B9F90 0x021B9F90 thumb ov221
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021BA140 0x021BA140 data a2
 */
#include "../include/Obj01592.h"
typedef unsigned short u16;

struct Obj; struct Vec2 { short x,y; };
extern struct Vec2 d_021BA140;
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
extern unsigned func_021B9F90(char *p);
extern struct Obj *func_0204B294(void *,unsigned,unsigned,unsigned,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
void func_021B9C4C(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f4C=func_0204AC18((void *)((unsigned)h),0,0,0,0,2,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f48=func_0204A6C8((void *)((unsigned)h),3,0,0,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f50=func_0204AF28((void *)((unsigned)h),8,9,((struct Obj01592 *)p)->f0);
    func_02049238(h);
    *(struct Obj * *)&((struct Obj01592 *)p)->f54=func_0204B294((void *)func_021B9F90(((struct Obj01592 *)p)->f8),((struct Obj01592 *)p)->f48,((struct Obj01592 *)p)->f4C,((struct Obj01592 *)p)->f50,&d_021BA140,0,((struct Obj01592 *)p)->f0);
    func_0204B3DC(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
    func_0204B92C(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
}
