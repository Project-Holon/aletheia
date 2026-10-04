/*
 * function: func_021C4D54
 * address: 0x021C4D54
 * packet: pkt_ov136_021C4D54
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C440 0x0201C440 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0202DE5C 0x0202DE5C thumb
 */
#include "../include/Obj00160.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201C440(void *p);
struct Bank;
struct PmsDraw;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
void func_021C4D54(u8 *p)
{
    ((struct Obj00160 *)p)->f158 = (void *)func_0201C440((void *)((u16)((struct Obj00160 *)p)->f0));
    ((struct Obj00160 *)p)->f154 = func_0204B100(8, 1, (u16)((struct Obj00160 *)p)->f0);
    ((struct Obj00160 *)p)->f148 = func_0202DB0C(*(u32 *)&((struct Obj00160 *)p)->f154, 0, *(u32 *)&((struct Obj00160 *)p)->f158, *(u32 *)&((struct Obj00160 *)p)->f24, 0, 4, (u16)((struct Obj00160 *)p)->f0);
    func_0202DE5C(((struct Obj00160 *)p)->f148, 0);
}
