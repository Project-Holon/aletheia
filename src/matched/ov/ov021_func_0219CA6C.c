/*
 * function: func_0219CA6C
 * address:  0x0219CA6C
 * packet:   pkt_ov021_0219CA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;
typedef struct { int n; Ent *e; } Tbl;

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
