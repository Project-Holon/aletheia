/*
 * function: func_021BC91C
 * address: 0x021BC91C
 * packet: pkt_ov209_021BC91C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD934 0x021BD934 thumb ov209
 */
#include "../include/Obj00088.h"
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_02041EE4(u32, u32, u32);
extern void func_021BD958(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern void func_021BD934(char *p, int idx, short a, short b, unsigned short c);
int func_021BC91C(char *p)
{
    unsigned i;
    s16 pair[2];
    int d;
    if (((struct Obj00088 *)p)->fC40 == 0) return 0;
    func_02041EE4(5, 4, ((struct Obj00088 *)p)->fC42);
    func_02041EE4(1, 5, ((struct Obj00088 *)p)->fC42);
    for (i = 3; i <= 9; i++) {
        func_021BD958(p, i, &pair[1], &pair[0], 0);
        pair[0] += ((struct Obj00088 *)p)->fC42;
        func_021BD934(p, i, pair[1], pair[0], 0);
    }
    d = ((struct Obj00088 *)p)->fC42;
    if (d < 0) d = -d;
    ((struct Obj00088 *)p)->fC40 -= d;
    return 1;
}
