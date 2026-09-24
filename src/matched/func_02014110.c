/*
 * function: func_02014110
 * address:  0x02014110
 * packet:   pkt_02014110
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialiser: clears +0x00 and +0x0C, stores four halfwords at +0x04..+0x0A
 * and three words at +0x10..+0x18.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 x00;
    u16 x04, x06, x08, x0A;
    u32 x0C, x10, x14, x18;
} Rect14110;

void func_02014110(Rect14110 *p, u16 a, u16 b, u16 c, u16 d, u32 e, u32 f, u32 g)
{
    p->x00 = 0;
    p->x04 = a;
    p->x06 = b;
    p->x08 = c;
    p->x0A = d;
    p->x0C = 0;
    p->x10 = e;
    p->x14 = f;
    p->x18 = g;
}
