/*
 * function: func_021C65E4
 * address:  0x021C65E4
 * packet:   pkt_ov136_021C65E4
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 */
#include "../include/Obj10606.h"

typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
struct Bank;
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
void func_021C65E4(u8 *p)
{
    func_0204AFD8((u32)(((struct Obj10606 *)p)->f230));
    func_0204ADA4((u32)(((struct Obj10606 *)p)->f250));
    func_0204B1CC(((struct Obj10606 *)p)->f1EC);
    func_0204A5AC();
}
