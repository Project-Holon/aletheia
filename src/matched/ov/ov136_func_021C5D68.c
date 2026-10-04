/*
 * function: func_021C5D68
 * address: 0x021C5D68
 * packet: pkt_ov136_021C5D68
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02008FA4 0x02008FA4 thumb
 *   func_02049658 0x02049658 arm
 *   func_02049B68 0x02049B68 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00627.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
struct Sub02008F80Obj;
extern u8 func_02008FA4(const struct Sub02008F80Obj *obj);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *);
void func_021C5D68(u8 *p)
{
    void *h;
    u8 *q;
    h = func_020490F4(155,102);
    q = (u8 *)func_02008FA4(*(void **)(*(u8 * *)&((struct Obj00627 *)p)->f8 + 0x298 + p[31]*4));
    func_02049658(h,(u32)(q+12),5,0,0,1,102);
    func_02049B68(h,(u32)q,4,0,64,102);
    func_020498F4(h,(u32)(q+24),5,0,0,1,102);
    func_02049238(h);
}
