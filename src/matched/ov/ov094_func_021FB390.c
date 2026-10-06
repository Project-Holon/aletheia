/*
 * function: func_021FB390
 * address:  0x021FB390
 * packet:   pkt_ov094_021FB390
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: when func_0220041C(x, y) reports 1, calls func_02200468(x).
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F8694 0x021F8694 thumb ov094
 *   func_0220041C 0x0220041C thumb ov094
 *   func_02200468 0x02200468 thumb ov094
 */
#include "../include/Obj21661.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern int func_021F8694(void);
extern int func_0220041C(void *, int, int);
extern void func_02200468(void *, int);

int func_021FB390(void *a, char *s)
{
    int x = func_0201134C(a);
    int y = func_0201134C(a);

    if (func_0220041C((void *)func_021F8694(), x, y) == 1)
        func_02200468((void *)func_021F8694(), x);
    return ((struct Obj21661 *)s)->f23C;
}
