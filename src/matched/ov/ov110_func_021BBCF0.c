/*
 * function: func_021BBCF0
 * address: 0x021BBCF0
 * packet: pkt_ov110_021BBCF0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_0202CA0C 0x0202CA0C thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02020D3C 0x02020D3C thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01248.h"
typedef unsigned char u8;
struct WinMgr;
extern void func_0202CA0C(struct WinMgr *mgr);
struct D;
struct Descriptor;
struct Node;
struct Obj;
struct Rec;
struct U16Vec;
extern void func_02030EAC(struct Node *n);
extern void func_02020D3C(struct D *p);
extern void func_0204B3B4(struct Obj *p);
extern void func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern void func_020452E8(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021BBCF0(u8 *p)
{
    func_0202CA0C(((struct Obj01248 *)p)->f1B4);
    if (((struct Obj01248 *)p)->f1B0) func_02030EAC(((struct Obj01248 *)p)->f1B0);
    if (((struct Obj01248 *)p)->f1A4) func_02030EAC(((struct Obj01248 *)p)->f1A4);
    if (((struct Obj01248 *)p)->f34) func_02020D3C(((struct Obj01248 *)p)->f34);
    if (((struct Obj01248 *)p)->f14) func_0204B3B4(((struct Obj01248 *)p)->f14);
    if (((struct Obj01248 *)p)->f18) func_0204B3B4(((struct Obj01248 *)p)->f18);
    if (((struct Obj01248 *)p)->f2C) func_02045C04(((struct Obj01248 *)p)->f2C);
    if (((struct Obj01248 *)p)->f30) func_02045808(((struct Obj01248 *)p)->f30);
    func_020452E8(((struct Obj01248 *)p)->fC);
    func_020452E8(((struct Obj01248 *)p)->f10);
    func_020307B0(p);
}
