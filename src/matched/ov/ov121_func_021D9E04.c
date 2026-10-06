/*
 * function: func_021D9E04
 * address: 0x021D9E04
 * packet: pkt_ov121_021D9E04
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02031140 0x02031140 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02180.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Rec3;
struct S02031140;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_0202F038(u8 *);
extern int func_02028604(int a0);
extern void func_02031140(struct S02031140 *p);
extern void func_0201F7A8(void *, u32);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
void func_021D9E04(u8 *p)
{
    if (((struct Obj02180 *)p)->f8) {
        func_0201CE48(((struct Obj02180 *)p)->f8);
        ((struct Obj02180 *)p)->f8 = 0;
    }
    if (((struct Obj02180 *)p)->f3C) {
        func_0202F038(((struct Obj02180 *)p)->f3C);
        ((struct Obj02180 *)p)->f3C = 0;
    }
    if (((struct Obj02180 *)p)->f30) func_02028604((int)(((struct Obj02180 *)p)->f30));
    func_02031140(((struct Obj02180 *)p)->fC);
    func_0201F7A8(((struct Obj02180 *)p)->f10, 0);
    func_020452E8(((struct Obj02180 *)p)->f10);
    func_02045808(((struct Obj02180 *)p)->f14);
    func_020307B0(p);
}
