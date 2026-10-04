/*
 * function: func_021BA324
 * address: 0x021BA324
 * packet: pkt_ov133_021BA324
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F04 0x021F4F04 thumb ov112
 *   func_021F4EFC 0x021F4EFC thumb ov112
 *   func_021F4EE0 0x021F4EE0 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   d_020A1B38 0x020A1B38 data a4
 */
#include "../include/Obj04525.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { int x, y; } Offset;
typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags;
extern void func_021F4F04(u8 *, Offset *);
extern int func_021F4EFC(int, Flags *);
extern void func_021F4EE0(int, u16 *, u16 *);
extern const s16 d_020A1B38[];
unsigned int func_021BA324(u8 *p, int x, int y)
{
    s16 s;
    int pos[2];
    u16 angle;
    s16 c;
    int dx, dy;
    s16 rx, ry;
    func_021F4F04(((struct Obj04525 *)p)->fC, (Offset *)pos);
    if (func_021F4EFC(0, ((struct Obj04525 *)p)->fC) == 1) {
        func_021F4EE0(0, ((struct Obj04525 *)p)->fC, &angle);
        s = d_020A1B38[(angle >> 4) * 2];
        c = d_020A1B38[(angle >> 4) * 2 + 1];
        dx = (int)((float)(pos[0] * c - pos[1] * s) / 4096.0f);
        dy = (int)((float)(pos[0] * s + pos[1] * c) / 4096.0f);
        rx = ((struct Obj04525 *)p)->f10 - dx - x;
        ry = ((struct Obj04525 *)p)->f14 - dy - y;
    } else {
        rx = ((struct Obj04525 *)p)->f10 - x;
        ry = ((struct Obj04525 *)p)->f14 - y;
    }
    return rx * rx + ry * ry;
}
