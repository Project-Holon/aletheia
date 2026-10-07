/*
 * file:     unit_02198D3C_p11.c
 * unit:     yes
 * function: func_02199D4C, func_02199D8C
 * address:  0x02199D4C
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
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 */
#include "../../matched/include/Obj09499.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_0216D6D4(void *p);
extern void func_02163FC0(int a, int dir, int amt);
extern int func_02164010(int a);
extern int func_02163F10(int a0);
extern u32 func_0216D7CC(u32);
extern u8 *func_0216D6BC(u32, u32);
extern void func_0216D674(void *p, u16 v);
int func_02199D4C(u32 a);
int func_02199D8C(u32 a);


/*
 * Addresses are Black-image addresses.
 */
int func_02199D4C(u32 a)
{
    s16 *p;

    p = func_0216D6D4((void *)a);
    func_02163FC0(a, (u16)((u32 *)p)[1], ((u32 *)p)[2]);
    func_02164010(a);
    p[1] = p[1] - 1;
    if (p[1] > 0) {
        return 0;
    }
    func_02163F10(a);
    func_0216D7CC(a);
    return 1;
}


int func_02199D8C(u32 a)
{
    u8 *p = func_0216D6BC(a, 16);
    ((struct Obj09499 *)p)->f4 = 0x2000;
    ((struct Obj09499 *)p)->f8 = 0;
    p[10] = 0;
    func_0216D674((void *)a, 11);
    func_0216D7CC(a);
    return 1;
}
