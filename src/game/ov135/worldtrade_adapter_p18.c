/*
 * file:     worldtrade_adapter_p18.c
 * unit:     yes
 * function: func_021FE84C, func_021FE8A8
 * address:  0x021FE84C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj14175.h"
#include "../../matched/include/Obj14176.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

extern void func_021FF318(unsigned char *p, unsigned int k, int b, int c, int d);
extern void func_021F4E98(u8 *p, unsigned int a, unsigned int b);
extern void func_020061E4(u32 a);
int func_021FE84C(char *p);
int func_021FE8A8(char *p);

int func_021FE84C(char *p)
{
    if (((struct Obj14175 *)p)->fD0 == 0) {
        func_021FF318((unsigned char *)p, 14, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 1);
        func_020061E4(0x557);
    } else {
        func_021FF318((unsigned char *)p, 36, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 21);
        ((struct Obj14175 *)p)->fDFC = 0;
    }
    return 2;
}

int func_021FE8A8(char *p)
{
    if (++((struct Obj14176 *)p)->fDFC > 45) {
        func_021FF318((unsigned char *)p, 38, 1, 0, 0xf0f);
        func_021F4E98((u8 *)p, 23, 1);
        ((struct Obj14176 *)p)->fE1A = 1;
    }
    return 2;
}
