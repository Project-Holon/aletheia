/*
 * function: func_021BCE58
 * address: 0x021BCE58
 * packet: pkt_ov210_021BCE58
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   func_021BEE58 0x021BEE58 thumb ov210
 *   func_021BEE38 0x021BEE38 thumb ov210
 * BEE38 parameters widened: original call uses signed full-width loads.
 */
#include "../include/Obj00085.h"
typedef unsigned short u16;
typedef signed short s16;
struct WinMgr;
typedef unsigned int   u32;
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void func_021BEE58(char *, int, short *, short *, unsigned short);
extern void func_021BEE38(char *p, int idx, int a, short b, unsigned short c);
int func_021BCE58(char *p)
{
    unsigned int i;
    short x, y;
    int magnitude;
    if (((struct Obj00085 *)p)->f2C8 == 0) return 0;
    BGWINFRM_UpdateMoves(*(struct WinMgr * *)&((struct Obj00085 *)p)->f20);
    func_02041EE4(4, 4, ((struct Obj00085 *)p)->f2CA);
    func_02041EE4(7, 4, ((struct Obj00085 *)p)->f2CA);
    for (i = 2; i <= 4; i++) {
        func_021BEE58(p, i, &x, &y, 0);
        y += ((struct Obj00085 *)p)->f2CA;
        func_021BEE38(p, i, x, y, 0);
    }
    magnitude = ((struct Obj00085 *)p)->f2CA;
    if (magnitude < 0) magnitude = -magnitude;
    ((struct Obj00085 *)p)->f2C8 -= (u16)magnitude;
    return 1;
}
