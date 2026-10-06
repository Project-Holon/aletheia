/*
 * function: func_021D4E04
 * address: 0x021D4E04
 * packet: pkt_ov115_021D4E04
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D584C 0x021D584C thumb ov115
 *   func_02030EAC 0x02030EAC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj02170.h"
typedef unsigned char u8;
extern void func_021D584C(u8 *);
typedef unsigned int   u32;
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
void func_021D4E04(u8 *p) {
    if (((struct Obj02170 *)p)->f8 == 1) func_021D584C(p);
    else if (((struct Obj02170 *)p)->f10) {
        func_02030EAC(((struct Obj02170 *)p)->f10);
        ((struct Obj02170 *)p)->f10 = 0;
        ((struct Obj02170 *)p)->f14 = 0;
    }
    func_02040DA8(5, 1, 0);
    func_02040DA8(6, 1, 0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5, 0);
    func_0203F9B4();
    func_020307B0(p);
}
