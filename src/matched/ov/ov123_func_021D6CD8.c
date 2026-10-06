/*
 * function: func_021D6CD8
 * address: 0x021D6CD8
 * packet: pkt_ov123_021D6CD8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: narrow the helper result through a named u16 local before the call.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj02474.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Point { s16 x,y; u16 f4; u8 f6,f7; };
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
void func_021D6CD8(u8 *p)
{
    struct Point pt;
    void *h;
    u16 n;
    h=func_020490F4(7,((struct Obj02474 *)p)->f43C4);
    n=func_0201BABC(1,0,0,0);
    ((struct Obj02474 *)p)->f44=(void *)func_0204A6C8(h,n,0,0,((struct Obj02474 *)p)->f43C4);
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    ((struct Obj02474 *)p)->fB4=func_0204B294((void *)((struct Obj02474 *)p)->fC,(u32)((struct Obj02474 *)p)->f44,((struct Obj02474 *)p)->f28,((struct Obj02474 *)p)->f5C,&pt,0,((struct Obj02474 *)p)->f43C4);
    func_0204B92C(((struct Obj02474 *)p)->fB4,0);
    func_0204B3DC(((struct Obj02474 *)p)->fB4,0);
    func_02049238(h);
}
