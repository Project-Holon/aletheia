/*
 * function: func_021FC6B8
 * address: 0x021FC6B8
 * packet: pkt_ov135_021FC6B8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021F4D50 0x021F4D50 thumb ov135
 *   func_021F5034 0x021F5034 thumb ov135
 */
#include "../include/Obj00448.h"
typedef unsigned int u32;
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(void *table, void *msg, u32 b, u32 tag, u32 heap);
extern void func_021F4D50(void *p, u32 a, int b, u32 c);
extern void func_021F5034(u32 x);
int func_021FC6B8(char *p)
{
    ((struct Obj00448 *)p)->fDE8 = func_0201F81C(2, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, ((struct Obj00448 *)p)->fB6C, 0x3d, 1, 0x48);
    func_0201F878(((struct Obj00448 *)p)->fDE8, ((struct Obj00448 *)p)->fB6C, 0x3e, 2, 0x48);
    func_021F4D50(p, 2, 2, 0x14);
    func_021F5034(1);
    *(int *)&((struct Obj00448 *)p)->f28 = 8;
    return 2;
}
