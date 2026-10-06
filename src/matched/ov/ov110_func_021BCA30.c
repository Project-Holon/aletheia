/*
 * function: func_021BCA30
 * address: 0x021BCA30
 * packet: pkt_ov110_021BCA30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding after return.
 * symbols:
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_021BD344 0x021BD344 thumb ov110
 *   func_021BD174 0x021BD174 thumb ov110
 *   func_021BD0D4 0x021BD0D4 thumb ov110
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00295.h"
typedef unsigned char u8;
extern void func_021BCAD8(u8 *);
extern void func_021BD344(u8 *);
extern void func_021BD174(u8 *);
extern void func_021BD0D4(u8 *);
struct Obj;
struct Rec;
struct TaskMenuState;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
void func_021BCA30(u8 *p)
{
    int i;
    func_021BCAD8(p);
    func_0204B3B4(((struct Obj00295 *)p)->f28);
    func_0204ADA4((u32)(((struct Obj00295 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj00295 *)p)->f20));
    func_0204AFD8((u32)(((struct Obj00295 *)p)->f24));
    for (i=0;i<3;i++) func_02027FD8(*(void **)(p+0x34+i*4));
    func_021BD344(p); func_021BD174(p); func_021BD0D4(p);
    func_02045C04(((struct Obj00295 *)p)->f30);
    func_020307B0(p);
}
