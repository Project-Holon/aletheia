/*
 * function: func_021C4D14
 * address:  0x021C4D14
 * packet:   pkt_ov021_021C4D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_0202B928 and func_0202B920 are witnessed by src/matched/arm9/.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202B928  0x0202B928  thumb
 *   func_0202B920  0x0202B920  thumb
 *   d_021DE48C     0x021DE48C  data  a4
 */
#include "../../../matched/include/Obj01507.h"

typedef unsigned short u16;

extern int d_021DE48C;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B57C(void *obj);
extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
extern int func_0202B928(int a, int b);
extern void func_0202B920(void *m, int i, int a, int b);

void *func_021C4D14(int a, int b, int c, int d, int e)
{
    int n = func_02188C84((u8 *)a);
    int r;
    int *p;

    r = func_0202B57C((void *)func_02012134((u32 *)func_02188C80((void *)a)));
    p = (int *)func_02030734(n, 0x18, 0, (const char *)&d_021DE48C, 0x3c);
    ((struct Obj01507 *)p)->f0 = n;
    p[1] = a;
    p[2] = r;
    p[3] = c;
    p[4] = 0;
    p[5] = b;
    if (func_0202B928(r, c) == 0) {
        func_0202B920((void *)r, c, d, e);
    }
    return p;
}
