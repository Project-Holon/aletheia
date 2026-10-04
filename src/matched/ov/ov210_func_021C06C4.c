/*
 * function: func_021C06C4
 * address:  0x021C06C4
 * packet:   pkt_ov210_021C06C4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BECAC 0x021BECAC thumb ov210
 *   func_021BFA14 0x021BFA14 thumb ov210
 *   func_021BFB8C 0x021BFB8C thumb ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25636.h"

typedef unsigned char u8;

extern void func_021BECAC(int p, unsigned *b);
extern void func_021BFA14(char *p, int y, int flag);
extern void func_021BFB8C(int p, unsigned short a, int c, int d);

void func_021C06C4(int p, unsigned a, unsigned *b, int c, int d)
{
    func_021BECAC(p, b);
    if ((*(u8 **)(*(int * *)&((struct Obj25636 *)p)->f0 + 2))[6] == a)
        func_021BFA14((char *)p, c, d);
    func_021BFB8C(p, a, c, d);
}
