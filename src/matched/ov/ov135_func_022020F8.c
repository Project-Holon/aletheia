/*
 * function: func_022020F8
 * address: 0x022020F8
 * packet: pkt_ov135_022020F8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_021F90A0 0x021F90A0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 */
#include "../include/Obj00018.h"
#include "../include/Obj23459.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_02012DD0(u8 *p);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F4FC4(u8 *p);
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
int func_022020F8(u8 *p)
{
    if (func_02012DD0(func_020120F4(((struct Obj23459 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f40)) == 2) {
        func_021F4EC0(p, 1, 0);
        func_021F4FC4(p);
        func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), ((struct Obj00018 *)p)->f24, 1, 0xF0F);
        func_021F4E98(p, 0x2A, 0x20);
    }
    return 2;
}
