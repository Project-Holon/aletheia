/*
 * function: func_021ED8A4
 * address: 0x021ED8A4
 * packet: pkt_ov170_021ED8A4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 */
#include "../include/Obj14281.h"
#include "../include/Obj24023.h"
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_021EC08C(char *, int, short, short, short);
void func_021ED8A4(char *p)
{
    signed char t[2];
    unsigned i;
    short x, y;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24023 *)(*(char * *)&((struct Obj14281 *)p)->f2C))->f74, 7, &t[1], &t[0]);
    i = 0;
    y = t[0] * 8 + 8;
    x = t[1] * 8 + 0x17;
    for (; i < 6; i++)
        func_021EC08C(*(char * *)&((struct Obj14281 *)p)->f2C, i + 0xd, x + (i % 2) * 0x20, y + (i / 2) * 0x18, 0);
}
