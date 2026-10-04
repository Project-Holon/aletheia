/*
 * function: func_021C3D44
 * address: 0x021C3D44
 * packet: pkt_ov136_021C3D44
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   d_021C7EE0 0x021C7EE0 data a1
 */
#include "../include/Obj01163.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C7EE0[];
typedef unsigned int   u32;
struct Big;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082AC0(unsigned, void *, unsigned);
extern void *func_02012EBC(struct Big *p);
extern void *func_02008F08(unsigned);
extern unsigned func_02017E1C(void *, unsigned, unsigned);
void *func_021C3D44(void *a, void *b, unsigned heap)
{
    u8 *p;
    p = func_02030734((u16)(((u16)heap & 0x7FFF) | 0x8000), 0x1C, 0, d_021C7EE0, 0x97);
    func_02082AC0(0, p, 0x1C);
    ((struct Obj01163 *)p)->f0 = 0;
    ((struct Obj01163 *)p)->f10 = func_02012EBC(a);
    ((struct Obj01163 *)p)->f14 = func_02008F08((u16)heap);
    func_02017E1C(b, 0xA7, (u32)((struct Obj01163 *)p)->f14);
    return p;
}
