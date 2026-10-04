/*
 * function: func_021BE2DC
 * address: 0x021BE2DC
 * packet: pkt_ov099_021BE2DC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BE382.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02049EF4 0x02049EF4 arm
 */
#include "../include/Obj05265.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
void func_021BE2DC(char *p, u32 a, int b)
{
    func_02049B68((void *)a, 4, 0, 0x100, 0x80, b);
    func_02049B68((void *)a, 4, 4, 0x100, 0x80, b);
    ((struct Obj05265 *)p)->f10 = func_02049740((void *)a, 13, 1, 0, 0, b);
    ((struct Obj05265 *)p)->f14 = func_02049740((void *)a, 13, 6, 0, 0, b);
    if (((struct Obj05265 *)p)->f8 == 0) {
        ((struct Obj05265 *)p)->f8 = func_02049E74((void *)a, 13, 0, (u32)(p + 12), b);
    }
    if (((struct Obj05265 *)p)->f0 == 0) {
        ((struct Obj05265 *)p)->f0 = func_02049EF4((void *)a, 21, 0, (void **)(p + 4), b);
    }
}
