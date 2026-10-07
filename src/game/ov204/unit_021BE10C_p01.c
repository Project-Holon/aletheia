/*
 * file:     unit_021BE10C_p01.c
 * unit:     yes
 * function: func_021BE10C, func_021BE11C, func_021BE138
 * address:  0x021BE10C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF094 0x021BF094 thumb ov204
 *   func_021BF4E8 0x021BF4E8 thumb ov204
 *   func_021BF00C 0x021BF00C thumb ov204
 */
#include "../../matched/include/Obj10870.h"
#include "../../matched/include/Obj04608.h"

struct S021BF00C;
struct Q021BF00C;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

extern char *func_021BF094(int);
extern void func_021BF4E8(char *);
extern int func_021BF00C(struct S021BF00C *, struct Q021BF00C *);
int func_021BE10C(char *p, u32 b, int *c);
u32 func_021BE11C(u8 *p);
void func_021BE138(char *p, int which);


int func_021BE10C(char *p, u32 b, int *c)
{
    ((struct Obj10870 *)p)->f1C = *c;
    ((struct Obj10870 *)p)->fA0 = 0;
    return 1;
}


u32 func_021BE11C(u8 *p)
{
    u32 t = *(u32 *)(((struct Obj10870 *)p)->f4 + 8);

    if (t == 0) {
        t = t + 1;
    }
    func_021BE10C((char *)p, 0, (int *)(&t));
    return 1;
}

/*
 * extent: 021BE17A..021BE17C is two zero alignment bytes.
 */
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
