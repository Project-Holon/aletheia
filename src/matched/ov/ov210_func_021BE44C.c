/*
 * function: func_021BE44C
 * address: 0x021BE44C
 * packet: pkt_ov210_021BE44C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: raw field offsets share a compiler-held constant; an enum local
 *        instead hoists p+offset and spills x in a larger frame.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj00222.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *, u32);
extern void func_021B6AE4(u8 *, u32, u16, u16, u32, u32, u16, u32);
extern void func_02045808(struct U16Vec *);
void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode)
{
    struct U16Vec *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00222 *)p)->f1D0, message);
    func_021B6AE4(p + 0x14c + slot * 8, ((struct Obj00222 *)p)->f1DC, x, y, (u32)text, ((struct Obj00222 *)p)->f1CC, color, mode);
    func_02045808(text);
}
