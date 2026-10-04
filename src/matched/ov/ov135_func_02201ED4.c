/*
 * function: func_02201ED4
 * address: 0x02201ED4
 * packet: pkt_ov135_02201ED4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F90A0 0x021F90A0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021FFBC8 0x021FFBC8 thumb ov135
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4E98(u8 *, u32, u32);
extern void func_021F4EC0(u8 *, u32, u32);
extern void func_021F4FC4(u8 *);
extern void func_021FFBC8(u8 *);
int func_02201ED4(u8 *p)
{
    func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), 0x99, 1, 0xf0f);
    func_021F4E98(p, 0x2a, 0x28);
    func_021F4EC0(p, 1, 0);
    func_021F4FC4(p);
    func_021FFBC8(p);
    return 2;
}
