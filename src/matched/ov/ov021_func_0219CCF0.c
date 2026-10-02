/*
 * function: func_0219CCF0
 * address:  0x0219CCF0
 * packet:   pkt_ov021_0219CCF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The record pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps r in r0 instead of hoisting the count into a register.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 id; u8 pad[10]; } A;
typedef struct { u8 pad[16]; u32 f10; } B;
typedef struct { u32 f0; u8 pad[12]; u32 f10; u8 pad2[20]; } C;
typedef struct { u8 pad[4]; u16 n0; u16 n1; u16 n2; u16 pad2; A *a; B *b; C *c; } R;

int func_0219CCF0(u8 *s)
{
    const R *r = *(const R **)(s + 0x1c);
    u32 i;
    const A *a;
    const B *b;
    const C *c;

    a = r->a;
    for (i = 0; i < r->n0; i++, a++) {
        if (a->id != 0xFFFF) {
            return 1;
        }
    }
    b = r->b;
    for (i = 0; i < r->n1; i++, b++) {
        if (b->f10 != 0) {
            return 1;
        }
    }
    c = r->c;
    for (i = 0; i < r->n2; i++, c++) {
        if (c->f0 != 0 && c->f10 != 0) {
            return 1;
        }
    }
    return 0;
}
