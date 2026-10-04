/*
 * function: func_021ED9C8
 * address: 0x021ED9C8
 * packet: pkt_ov170_021ED9C8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFD1C 0x021EFD1C data a4
 *   func_021DEB14 0x021DEB14 thumb ov170
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EDB64 0x021EDB64 thumb ov170
 *   func_0202590C 0x0202590C thumb
 *   func_021EB874 0x021EB874 thumb ov170
 */
#include "../include/Obj00000.h"
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;
extern const Desc d_021EFD1C;
extern unsigned char func_021DEB14(unsigned char *, signed char);
extern void func_021EC08C(char *, int, short, short, short);
extern void func_021EDB64(char *, int, int);
typedef signed short   s16;
struct Grid;
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern void func_021EB874(char **, unsigned, int);
void func_021ED9C8(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    short i;
    int a, y;
    for (i = 0; i < 6; i++) {
        a = func_021DEB14((unsigned char *)p, i - 1);
        t = base;
        y = i * 0x22;
        t.y += (short)y;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2d, t.x, t.y, 0);
        func_021EDB64(p, a, i + 0x2d);
        func_0202590C(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xc), 0x13c, y + 2);
        func_021EB874((char **)p, a, i + 1);
    }
}
