/*
 * file:     unit_021E9634.c
 * unit:     yes
 * function: func_021E9634, func_021E964C
 * address:  0x021E9634
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D3D90  0x021D3D90  thumb  ov093
 *   func_021E96A4  0x021E96A4  thumb  ov093
 *   func_021E96B4  0x021E96B4  thumb  ov093
 */
#include "../../matched/include/Obj03707.h"

typedef unsigned char u8;

typedef unsigned int u32;

struct Pair {
    u8 *a;
    u32 pad;
    char *const *q;
};

extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D3D90(u8 *p);
extern void func_021E96A4(void *a, int b, int c, int d, int e);
extern int func_021E96B4(void *a);
u8 *func_021E9634(struct Pair *s, u32 k);
int func_021E964C(char *p, int *st);


u8 *func_021E9634(struct Pair *s, u32 k)
{
    return func_021B98AC(s->q, func_021B8ED8(s->a, k));
}


int func_021E964C(char *p, int *st)
{
    switch (*st) {
    case 0:
        func_021E96A4(((struct Obj03707 *)p)->f180, ((struct Obj03707 *)p)->fBC, ((struct Obj03707 *)p)->f175,
                      func_021D3D90(((struct Obj03707 *)p)->f4), ((struct Obj03707 *)p)->fB8);
        (*st)++;
    case 1:
        ((struct Obj03707 *)p)->fC4 = func_021E96B4(((struct Obj03707 *)p)->f180);
        if (((struct Obj03707 *)p)->fC4)
            return 1;
    }
    return 0;
}
