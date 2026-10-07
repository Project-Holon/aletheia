/*
 * file:     field_effect_p49.c
 * unit:     yes
 * function: func_021ABE64, func_021ABE8C
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
 */
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E_021ABE64;

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
    E_021ABE64 *f10;
};

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct E_021ABE8C E_021ABE8C;

extern E_021ABE64 *func_021ABF2C(T *t, int id);
extern D *func_021ABF48(int id);
void func_021ABE64(T *t, int id);
int func_021ABE8C(T *a, int id);


void func_021ABE64(T *t, int id)
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
int func_021ABE8C(T *a, int id)
{
if (func_021ABF2C(a, id) != 0) {
    return 1;
}
return 0;
}
