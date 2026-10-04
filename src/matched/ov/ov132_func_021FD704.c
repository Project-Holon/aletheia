/*
 * unit: yes
 * function: func_021FD704, func_021FD744, func_021FD760
 * address: 0x021FD704
 * packet: pkt_ov132_021FD704
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
#include "../include/Obj14135.h"
#include "../include/Obj23295.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021FDA74(u32, u32, int);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
void func_021FD704(u8 *p)
{
    u32 *q = *(u32 * *)&((struct Obj23295 *)p)->f140;
    u32 id;
    func_021FDA74(q[1], q[8], 2);
    id = (u32)func_0203996C(255);
    func_0203D3F8(id, 255, 0x1106, (*(u32 **)(p + 0x140))[8], (*(u32 **)(p + 0x140))[1], 1, 0, 1);
}
void func_021FD744(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct Obj14135 *)p)->f170 = 1;
    q = *(u32 * *)&((struct Obj14135 *)p)->f140;
    func_021FDA74(q[1], q[8], 12);
}
u32 func_021FD760(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[1];
}
