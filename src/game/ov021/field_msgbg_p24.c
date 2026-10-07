/*
 * file:     field_msgbg_p24.c
 * unit:     yes
 * function: func_0218C654, func_0218C674
 * address:  0x0218C654
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
 *   func_0218C9C4  0x0218C9C4  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 *   func_0218C530  0x0218C530  thumb  ov021
 *   func_0218B924  0x0218B924  thumb  ov021
 *   func_0218BCB0  0x0218BCB0  thumb  ov021
 */
#include "../../matched/include/Obj19537.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

void func_0218C9C4(unsigned char *buf, int c);
int func_0218C638(int a, int b, int c);
unsigned char func_0218C530(int b);
int func_0218B924(u8 *p, u32 a1);
unsigned char func_0218BCB0(unsigned short *p);
int func_0218C654(int a, int b, int c);
int func_0218C674(unsigned char *p, int b);


int func_0218C654(int a, int b, int c)
{
    unsigned char buf[16];
    func_0218C9C4(buf, c);
    return func_0218C638(a, b, (int)buf);
}


int func_0218C674(unsigned char *p, int b)
{
    unsigned char v = func_0218C530(b);
    if (v >= 0x80 || v >= ((struct Obj19537 *)p)->f1AC)
        v = 0;
    return func_0218BCB0((short unsigned int *)func_0218B924(p, v));
}
