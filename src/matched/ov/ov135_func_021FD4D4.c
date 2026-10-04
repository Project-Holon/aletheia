/*
 * function: func_021FD4D4
 * address: 0x021FD4D4
 * packet: pkt_ov135_021FD4D4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj08187.h"
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021FD4D4(unsigned char *p)
{
    func_0204B3DC((struct Obj *)((struct Obj08187 *)p)->fD34, 0);
    if (((struct Obj08187 *)p)->f20 != 15) {
        if (((struct Obj08187 *)p)->f20 == 6)
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj08187 *)p)->f28 = 0;
    return 3;
}
