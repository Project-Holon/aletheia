/*
 * function: func_021F1F24
 * address:  0x021F1F24
 * packet:   pkt_ov029_021F1F24
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02051C6C  0x02051C6C  arm
 *   func_021F1E98  0x021F1E98  thumb  ov029
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj07621.h"

struct Bank;
extern void func_02051C6C(void *p);
typedef unsigned int   u32;
extern void func_021F1E98(char *p);
extern void func_0204B084(int);
extern void func_0204B1CC(struct Bank *bank);
extern void func_020403F4(u32 i);
extern void func_02040588(u32 which, u32 enable);

void func_021F1F24(char *p)
{
    if (((struct Obj07621 *)p)->f10)
        func_02051C6C((void *)(((struct Obj07621 *)p)->f10));
    func_021F1E98(p);
    func_0204B084(((struct Obj07621 *)p)->f38);
    func_0204B1CC((struct Bank *)(((struct Obj07621 *)p)->f34));
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
}
