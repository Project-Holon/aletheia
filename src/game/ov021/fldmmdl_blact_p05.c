/*
 * file:     fldmmdl_blact_p05.c
 * unit:     yes
 * function: func_0219CA40, func_0219CA6C, func_0219CA98
 * address:  0x0219CA40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c);
void func_0219CA6C(Tbl *t, u16 k);
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);


void func_0219CA40(Tbl *t, u16 a, u16 b, u16 c)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == 0xFFFF) {
            e->a = a;
            e->b = b;
            e->c = c;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}


void func_0219CA6C(Tbl *t, u16 k)
{
    int i;
    Ent *e = t->e;
    i = 0;
    do {
        if (e->a == k) {
            e->a = 0xFFFF;
            e->b = 0xFFFF;
            e->c = 0;
            return;
        }
        i++;
        e++;
    } while (i < t->n);
}


/*
 * Linear search of an 8-byte-entry table (count at +0, entries at *(+4)).
 *
 * Addresses are Black-image addresses.
 */
int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b)
{
    int i = 0;
    u16 *e = (u16 *)o[1];
    if (a) *a = 0xFFFF;
    do {
        if (e[0] == key) {
            if (a) *a = e[1];
            if (b) *b = e[2];
            return 1;
        }
        i++;
        e += 4;
    } while (i < (int)o[0]);
    return 0;
}
