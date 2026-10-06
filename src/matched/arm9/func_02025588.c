/*
 * function: func_02025588
 * address:  0x02025588
 * packet:   pkt_02025518
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj07093.h"

typedef unsigned int u32;

extern void func_02049238(void *p);
struct Obj02025774;
extern void func_02025B18(struct Obj02025774 *p);
extern u32 func_020307B0(void *p);

void func_02025588(void *p)
{
    func_02049238(((struct Obj07093 *)p)->f8);
    func_02025B18(p);
    func_020307B0(p);
}
