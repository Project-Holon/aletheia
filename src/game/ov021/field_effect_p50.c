/*
 * file:     field_effect_p50.c
 * unit:     yes
 * function: func_021ABEA0, func_021ABEAC
 * address:  0x021ABEA0
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
 *   func_021ABF2C  0x021ABF2C  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   d_021DE018  0x021DE018  data  a4
 */
#include "../../matched/include/Obj18084.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T T;

typedef struct {
    int id;
    int (*f4)(T *t, u16 h);
    void (*f8)(T *t, int v);
} D;

struct T {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

extern u32 func_021ABF2C(u32, u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_021ABEA0(u32 a, u32 b);
void func_021ABEAC(T *t);
extern char d_021DE018[];


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABEA0(u32 a, u32 b)
{
return ((struct Obj18084 *)((u8 *)(func_021ABF2C(a, b))))->f4;
}


void func_021ABEAC(T *t)
{
    E *e;
    int i;
    e = t->f10 = func_02030734(t->h4, t->f0 * 8, 1, d_021DE018, 0x174);
    i = 0;
    if (t->f0 > 0) {
        for (; i < t->f0; i++) {
            e->f0 = 0x18;
            e++;
        }
    }
}
