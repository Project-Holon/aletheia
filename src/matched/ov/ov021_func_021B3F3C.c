/*
 * function: func_021B3F3C
 * address:  0x021B3F3C
 * packet:   pkt_ov021_021B3F3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj02711.h"

typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02049238(void *a);
struct Bank;
extern u32 func_0204B1CC(struct Bank *bank);

void func_021B3F3C(char *w)
{
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1F4));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1E8));
    func_0204AFD8((u32)(((struct Obj02711 *)w)->f1DC));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1F0));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1E4));
    func_0204A8D4((u32)(((struct Obj02711 *)w)->f1D8));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1EC));
    func_0204ADA4((u32)(((struct Obj02711 *)w)->f1D4));
    func_02049238(((struct Obj02711 *)w)->f1F8);
    func_0204B1CC(((struct Obj02711 *)w)->f1BC);
}
