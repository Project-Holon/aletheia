/*
 * file:     ircbattlemenu_p10.c
 * unit:     yes
 * function: func_021989EC, func_02198A10
 * address:  0x021989EC
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
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 */
#include "../../matched/include/Obj17952.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int x, y, z; } Vec;

extern void func_0216D674(void *p, u16 v);
extern void *func_0216D6BC(int a0, int a1, int a2);
extern u32 func_0216D7CC(u32);
extern void *func_0216D6D4(void *p);
extern void func_0216D8C0(u32, Vec *);
int func_021989EC(u32 a, u32 b, u32 c, u32 d);
int func_02198A10(u32 a);


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216D7CC (0x0216D7CC) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021989EC(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17952 *)((u8 *)(func_0216D6BC(a, 8, c))))->f4 = (8 << 13);
func_0216D674((void *)a, 0);
func_0216D7CC(a);
return 1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_02198A10(u32 a)
{
    int *p;

    p = func_0216D6D4((void *)a);
    p[0] = p[0] + p[1];
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        func_0216D8C0(a, &v);
    }
    if (p[0] / 0x8000 < 0x28) {
        return 0;
    }
    func_0216D7CC(a);
    return 1;
}
