/*
 * file:     unit_021B6DC0_p02.c
 * unit:     yes
 * function: func_021B7020, func_021B7038, func_021B7068
 * address:  0x021B7020
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
 *   func_021B6EB0  0x021B6EB0  thumb ov021
 *   func_0215A5E4  0x0215A5E4  thumb ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EF40  0x0201EF40  thumb
 */
#include "../../matched/include/Obj18097.h"

struct WordSet;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern int func_021B6EB0(u32 *o, int k);
extern void *func_0215A5E4(void *a0);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
int func_021B7020(void *a, void *b, u8 *c);
int func_021B7038(void *a, u32 *b, void *c);
int func_021B7068(u32 a, u32 b, u32 c, u32 d);


int func_021B7020(void *a, void *b, u8 *c)
{
    if (func_021B6EB0((u32 *)c, c[0xB3]) == 1) {
        return 4;
    }
    return 3;
}


int func_021B7038(void *a, u32 *b, void *c)
{
    void *t;
    u16 x;

    t = func_02012944(func_0215A5E4(c));
    x = *b;
    func_0201F02C(a, 0, t);
    func_0201EF40(a, 1, x);
    return 7;
}


int func_021B7068(u32 a, u32 b, u32 c, u32 d)
{
func_0201EF40((struct WordSet *)a, 0, ((((struct Obj18097 *)((u8 *)(b)))->f0 << 16) >> 16));
return 8;
}
