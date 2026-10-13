/*
 * function: FLDMMDL_BLACT_AddResIndex
 * address:  0x0219CA40
 * packet:   pkt_ov021_0219CA40
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

void FLDMMDL_BLACT_AddResIndex(Tbl *t, u16 a, u16 b, u16 c)
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
