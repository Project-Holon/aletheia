/*
 * file:     unit_021AE604.c
 * unit:     yes
 * function: func_021AE604, func_021AE630, func_021AE650
 * address:  0x021AE604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 */
#include "../../matched/include/Obj07222.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; u32 fc; } S;

extern int func_0216D3CC(int a0);
extern u32 func_0216D410(u32, u32);
extern int func_02197E7C(int a, int b);
extern int func_0216D454(u32 a);
int func_021AE604(u32 a);
int func_021AE630(S *s);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021AE604(u32 a)
{
if (func_0216D3CC(((struct Obj07222 *)((u8 *)(a)))->f8) == 1) {
    func_0216D410(((struct Obj07222 *)((u8 *)(a)))->f8, func_02197E7C(((((struct Obj07222 *)((u8 *)(a)))->f10 << 16) >> 16), 12));
    ((struct Obj07222 *)((u8 *)(a)))->f0 = 12;
}
return 0;
}


int func_021AE630(S *s)
{
    if (func_0216D454(s->f8) == 0)
        return 0;
    s->fc--;
    s->f0 = 10;
    return 1;
}

typedef struct IwaTask {
    int state;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int cnt;
} IwaTask;

int func_021AE650(IwaTask *w)
{
    w->cnt++;
    if (w->cnt < 8) {
        return 0;
    }
    w->cnt = 0;
    w->state = 14;
    return 1;
}
