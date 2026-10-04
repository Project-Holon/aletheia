/*
 * function: func_021C0A5C
 * address: 0x021C0A5C
 * packet: pkt_ov217_021C0A5C
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_021C0AD8 0x021C0AD8 thumb ov217
 *   func_021C0B0C 0x021C0B0C thumb ov217
 *   func_021C0B94 0x021C0B94 thumb ov217
 *   func_021C0BBC 0x021C0BBC thumb ov217
 *   func_021C0C40 0x021C0C40 thumb ov217
 *   func_021C0C5C 0x021C0C5C thumb ov217
 *   func_021C0D88 0x021C0D88 thumb ov217
 *   func_021C0CF8 0x021C0CF8 thumb ov217
 *   func_021C0D14 0x021C0D14 thumb ov217
 */
#include "../include/Obj00791.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *);
extern void func_021C0AD8(u32);
extern void func_021C0B0C(u8 *);
extern void func_021C0B94(u32);
extern void func_021C0BBC(u8 *);
extern void func_021C0C40(u32);
extern void func_021C0C5C(u8 *);
extern void func_021C0D88(u8 *);
extern void func_021C0CF8(u32);
extern u32 func_021C0D14(u8 *);
void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap)
{
    ((struct Obj00791 *)p)->f0 = heap;
    *(const struct Ctx * *)&((struct Obj00791 *)p)->f4 = ctx;
    ((struct Obj00791 *)p)->f8 = func_020120F4(ctx);
    func_021C0AD8((u32)p);
    func_021C0B0C(p);
    func_021C0B94((u32)p);
    func_021C0BBC(p);
    func_021C0C40((u32)p);
    func_021C0C5C(p);
    func_021C0D88(p);
    func_021C0CF8((u32)p);
    func_021C0D14(p);
}
