/*
 * function: func_021EB2A8
 * address:  0x021EB2A8
 * packet:   pkt_ov093_021EB2A8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the parameter is const u8 *; without const the ldrh of the heap
 * halfword schedules after the second zero stack store (DIFF, 19 lines).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049238  0x02049238  arm
 *   func_020414EC  0x020414EC  arm
 *   func_0204989C  0x0204989C  arm
 */
#include "../include/Obj05226.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void * h);
extern void func_020414EC(u32 i);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);

void func_021EB2A8(const u8 *a)
{
    void *h = func_020490F4(0xb, (((struct Obj05226 *)a)->f13C & 0x7fff) | 0x8000);

    func_02049658(h, 0xd5, 3, ((struct Obj05226 *)a)->f14, 0, 0, ((struct Obj05226 *)a)->f13C);
    func_02049658(h, 0xdd, 3, ((struct Obj05226 *)a)->f10, 0, 0, ((struct Obj05226 *)a)->f13C);
    func_02049238(h);
    func_020414EC(3);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, ((struct Obj05226 *)a)->f13C);
}
