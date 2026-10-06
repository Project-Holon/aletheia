/*
 * function: func_021D6C84
 * address: 0x021D6C84
 * packet: pkt_ov121_021D6C84
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D6CEA.
 * volatile: 0x021D6C8E and 0x021D6CA6 read the same halfword; only the latter access is volatile.
 * symbols:
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 */
#include "../include/Obj10405.h"
#include "../include/Obj13938.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
extern s32 func_021DAAA4(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
static inline int wrap(int n, u16 *p)
{
    if (*p + n >= 65536) return *p + n - 65536;
    return *(volatile u16 *)&((struct Obj10405 *)p)->f0 + n;
}
void func_021D6C84(u8 *p)
{
    int i;
    ((struct Obj13938 *)p)->f98 = wrap(1024, (u16 *)(p + 0x98));
    for (i = 0; i < 5; i++)
        func_021DAAA4(14, (u16 *)(p + 0x9a) + i, ((struct Obj13938 *)p)->f98, 0, (u8)i, *(u16 *)(p + 0xba + i * 2), *(u16 *)(p + 0xda + i * 2));
}
