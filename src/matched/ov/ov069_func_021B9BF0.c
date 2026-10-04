/*
 * function: func_021B9BF0
 * address:  0x021B9BF0
 * packet:   pkt_ov069_021B9BF0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 */
#include "../include/Obj01132.h"

typedef unsigned int   u32;
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
struct Bank;
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);

void func_021B9BF0(char *p)
{
    func_0204A8D4(((struct Obj01132 *)p)->f144);
    func_0204ADA4(((struct Obj01132 *)p)->f140);
    func_0204AFD8(((struct Obj01132 *)p)->f148);
    func_0204A8D4(((struct Obj01132 *)p)->f138);
    func_0204ADA4(((struct Obj01132 *)p)->f134);
    func_0204AFD8(((struct Obj01132 *)p)->f13C);
    func_0204B1CC((struct Bank *)(((struct Obj01132 *)p)->f120));
    func_0204B1CC((struct Bank *)(((struct Obj01132 *)p)->f11C));
    func_0204A5AC();
}
