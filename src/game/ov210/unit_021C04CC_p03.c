/*
 * file:     unit_021C04CC_p03.c
 * unit:     yes
 * function: func_021C06AC, func_021C06C4
 * address:  0x021C06AC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BFBF8 0x021BFBF8 thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BECAC 0x021BECAC thumb ov210
 *   func_021BFA14 0x021BFA14 thumb ov210
 *   func_021BFB8C 0x021BFB8C thumb ov210
 */
#include "../../matched/include/Obj25636.h"

typedef unsigned char  u8;

extern void func_021BFBF8(int p, int v);
extern void func_021BF728(u8 *p, int a);
extern void func_021BECAC(int p, unsigned *b);
extern void func_021BFA14(char *p, int y, int flag);
extern void func_021BFB8C(char *ctx, unsigned long slot, int y, int flag);
void func_021C06AC(int p, int v);
void func_021C06C4(int p, unsigned a, unsigned *b, int c, int d);


void func_021C06AC(int p, int v)
{
    func_021BFBF8(p, (signed char)(-v));
    func_021BF728((u8 *)p, 1);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C06C4(int p, unsigned a, unsigned *b, int c, int d)
{
    func_021BECAC(p, b);
    if ((*(u8 **)(*(int * *)&((struct Obj25636 *)p)->f0 + 2))[6] == a)
        func_021BFA14((char *)p, c, d);
    func_021BFB8C((char *)p, (unsigned short)a, c, d);
}
