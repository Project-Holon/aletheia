/*
 * function: func_021BCE0C
 * address: 0x021BCE0C
 * packet: pkt_ov210_021BCE0C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CD64 0x0202CD64 thumb
 */
#include "../include/Obj01779.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
struct WinMgr;
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021BCE0C(char *p, int delta)
{
    int magnitude;
    int direction;
    ((struct Obj01779 *)p)->f2C8 = 48;
    ((struct Obj01779 *)p)->f2CA = delta;
    magnitude = delta < 0 ? -delta : delta;
    direction = delta / (delta < 0 ? -delta : delta);
    func_0202CD64(*(struct WinMgr * *)&((struct Obj01779 *)p)->f20, 0, 0, direction, 48 / magnitude);
}
