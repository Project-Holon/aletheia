/*
 * unit: yes
 * function: func_021FD7D4, func_021FD814, func_021FD830
 * address: 0x021FD7D4
 * packet: pkt_ov132_021FD7D4
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FDA74 0x021FDA74 thumb ov132
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../include/Obj14141.h"
#include "../include/Obj23297.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021FDA74(u32, u32, int);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
void func_021FD7D4(u8 *p)
{
    u32 *q = *(u32 * *)&((struct Obj23297 *)p)->f140;
    u32 id;
    func_021FDA74(q[3], q[10], 0);
    id = (u32)func_0203996C(255);
    func_0203D3F8(id, 255, 0x1108, (*(u32 **)(p + 0x140))[10], (*(u32 **)(p + 0x140))[3], 1, 0, 1);
}
void func_021FD814(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct Obj14141 *)p)->f178 = 1;
    q = *(u32 * *)&((struct Obj14141 *)p)->f140;
    func_021FDA74(q[3], q[10], 10);
}
u32 func_021FD830(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[3];
}
