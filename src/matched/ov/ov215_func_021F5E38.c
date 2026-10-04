/*
 * function: func_021F5E38
 * address: 0x021F5E38
 * packet: pkt_ov215_021F5E38
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
#include "../include/Obj10938.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
void func_021F5E38(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 6; i++) func_0204B3B4(*(void **)(p + i * 4 + 0x38));
    func_0204AFD8(((struct Obj10938 *)p)->f34);
    func_0204A8D4(((struct Obj10938 *)p)->f2C);
    func_0204ADA4(((struct Obj10938 *)p)->f30);
}
