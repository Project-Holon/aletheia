/*
 * function: func_021BE138
 * address: 0x021BE138
 * packet: pkt_ov204_021BE138
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BE17A..021BE17C is two zero alignment bytes.
 * symbols:
 *   func_021BF094 0x021BF094 thumb ov204
 *   func_021BF4E8 0x021BF4E8 thumb ov204
 *   func_021BF00C 0x021BF00C thumb ov204
 */
#include "../include/Obj04608.h"
struct S021BF00C; struct Q021BF00C;
extern char *func_021BF094(int);
extern void func_021BF4E8(char *);
extern int func_021BF00C(struct S021BF00C *, struct Q021BF00C *);
void func_021BE138(char *p, int which)
{
    char *q = func_021BF094(((struct Obj04608 *)p)->f1C) + 24 * ((struct Obj04608 *)p)->fA0;
    func_021BF4E8(*(char * *)&((struct Obj04608 *)p)->f18);
    if (which == 0) {
        if (q) func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)q);
    } else {
        q += 24;
        if (q) func_021BF00C((struct S021BF00C *)p, (struct Q021BF00C *)q);
    }
    ((struct Obj04608 *)p)->fA0 += 2;
}
