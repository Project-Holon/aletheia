/*
 * function: func_021FA64C
 * address: 0x021FA64C
 * packet: pkt_ov132_021FA64C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware control read at 021FA652 and store 021FA658.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01550.h"
typedef unsigned short u16;
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B1CC(struct Bank *bank);
extern void func_020307B0(void *);
void func_021FA64C(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (((struct Obj01550 *)p)->f48 != 255) func_0204B3B4(((struct Obj01550 *)p)->f4C);
    if (((struct Obj01550 *)p)->f4A != 255) func_0204B3B4(((struct Obj01550 *)p)->f50);
    func_0204B3B4(((struct Obj01550 *)p)->f5C);
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f28));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f34));
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f20));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f2C));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f38));
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f24));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f30));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f3C));
    func_0204B1CC(((struct Obj01550 *)p)->f18);
    func_020307B0(p);
}
