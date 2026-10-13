/*
 * function: func_021EC8E4
 * address:  0x021EC8E4
 * packet:   pkt_ov170_021EC8E4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   d_021EFCE0 0x021EFCE0 data a1
 */
#include "../include/Obj00000.h"
#include "../include/Obj24016.h"

typedef struct { unsigned char a; unsigned char b; } Off;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern const Off d_021EFCE0[];

void func_021EC8E4(char *p)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    BGWINFRM_GetPos(*(struct WinMgr * *)&((struct Obj24016 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74, 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + i + 0x3DF0),
                      (short)(y + d_021EFCE0[i].a), (short)(x + d_021EFCE0[i].b), (short)0);
}
