/*
 * unit: yes
 * function: func_021C3B14, func_021C3B68
 * address: 0x021C3B14
 * packet: pkt_ov208_021C3B14
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B688 0x0204B688 arm
 *   func_021BC518 0x021BC518 thumb ov208
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
extern void func_0204B688(struct Actor *p, u32 on);
extern void func_021BC518(int *p);
void func_021C3B14(void *unused, u8 *p, int a2)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (*(struct Actor **)(p + i * 4 + 0x54))
            func_0204B688(*(struct Actor **)(p + i * 4 + 0x54), 1);
    }
    for (i = 0; i < 6; i++)
        func_0204B688(*(struct Actor **)(p + i * 4 + 0x9c), 1);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC0);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC4);
}
void func_021C3B68(u16 *p, u32 value)
{
    *p = value;
}
