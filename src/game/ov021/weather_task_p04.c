/*
 * file:     weather_task_p04.c
 * unit:     yes
 * function: func_021A1D78, func_021A1DB4, func_021A1DF8
 * address:  0x021A1D78
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
 *   func_02030734  0x02030734  arm
 *   d_021DDE80     0x021DDE80  data  ov021  a4
 *   func_021A20C8  0x021A20C8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj03584.h"

struct O;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern void func_021A20C8(struct O *p);
extern u32 func_020307B0(void *p);
int func_021A1D78(u16 a, u16 b);
u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i);
void func_021A1DF8(u8 *p);
extern u8 d_021DDE80[];


int func_021A1D78(u16 a, u16 b)
{
    int r = 0;

    switch (a) {
    case 1:
        if ((u16)(b + 0xFFFC) <= 1)
            r = 1;
        break;
    case 4:
        if (b == 1 || b == 5)
            r = 1;
        break;
    case 5:
        if (b == 4 || b == 1)
            r = 1;
        break;
    }
    return r;
}


/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A1DB4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 h, u16 i)
{
    u32 *o;

    o = func_02030734(i, 0x784, 1, (const char *)d_021DDE80, 0x17E);
    o[0] = a;
    o[5] = b;
    o[1] = d;
    o[2] = c;
    o[4] = e;
    o[6] = f;
    o[3] = g;
    ((struct Obj03584 *)o)->f1C = h;
    return o;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021A1DF8(u8 *p)
{
    func_021A20C8((struct O *)p);
    func_020307B0(p);
}
