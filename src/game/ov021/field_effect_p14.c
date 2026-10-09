/*
 * file:     field_effect_p14.c
 * unit:     yes
 * function: func_021ABE64, func_021ABE8C, func_021ABEA0, func_021ABEAC
 * address:  0x021ABE64
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
 *   func_021ABF2C  0x021ABF2C  thumb
 *   func_021ABF48  0x021ABF48  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE018  0x021DE018  data  a4
 */
#include "../../matched/include/Obj18084.h"

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E_021ABE64;

typedef struct T_021ABE64 T_021ABE64;

typedef struct {
    int id;
    int (*f4)(T_021ABE64 *t, u16 h);
    void (*f8)(T_021ABE64 *t, int v);
} D;

struct T_021ABE64 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E_021ABE64 *f10;
};

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct E_021ABE8C E_021ABE8C;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T_021ABEA0 T_021ABEA0;

struct T_021ABEA0 {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

extern E_021ABE64 *func_021ABF2C(T_021ABE64 *t, int id);
extern D *func_021ABF48(int id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021ABE64(T_021ABE64 *t, int id);
int func_021ABE8C(T_021ABE64 *a, int id);
int func_021ABEA0(u32 a, u32 b);
void func_021ABEAC(T_021ABEA0 *t);
extern char d_021DE018[];



void func_021ABE64(T_021ABE64 *t, int id)
{
    E_021ABE64 *e = func_021ABF2C(t, id);
    D *d;
    if (e != 0) {
        d = func_021ABF48(id);
        d->f8(t, e->f4);
        e->f0 = 0x18;
        e->f4 = 0;
    }
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABE8C(T_021ABE64 *a, int id)
{
if (func_021ABF2C(a, id) != 0) {
    return 1;
}
return 0;
}



int func_021ABEA0(u32 a, u32 b)
{
return ((struct Obj18084 *)((u8 *)(func_021ABF2C((void *)a, b))))->f4;
}



void func_021ABEAC(T_021ABEA0 *t)
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
