/*
 * file:     fldeff_ripple_p06.c
 * unit:     yes
 * function: func_021C4024, func_021C4030
 * address:  0x021C4024
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
 *   func_021C4078  0x021C4078  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017ED8  0x02017ED8  thumb
 */
#include "../../matched/include/Obj20194.h"

typedef unsigned int u32;

u32 func_021C4078(void);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern u32 func_02017ED8(u32 a, u32 b);
void func_021C4024(int a, char *p);
void func_021C4030(u32 *p, u32 *q);


void func_021C4024(int a, char *p)
{
    ((struct Obj20194 *)p)->f34 = func_021C4078();
}


void func_021C4030(u32 *p, u32 *q)
{
    int i = 0;
    u32 a = func_02017E1C((void *)p[0], 0xc, 0);

    if (a == func_02017E1C((void *)p[1], 0xc, 0))
        return;
    if (func_02017ED8(q[0xc], q[0xd]) != 0)
        return;
    do {
        q[0xd] = func_021C4078();
        if (func_02017ED8(q[0xc], q[0xd]) != 0)
            return;
        i++;
    } while (i < 5);
}
