/*
 * function: func_0216CC58
 * address:  0x0216CC58
 * packet:   pkt_ov010_0216CC58
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0216E280  0x0216E280  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 */
#include "../include/Obj04949.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_0216E280(int a0, int a1);
extern char d_02172B48[];

char *func_0216CC58(int a, int b, int c)
{
    char *p = (char *)func_02030734(a, 0x48, 1, d_02172B48, 0xc3);
    ((struct Obj04949 *)p)->f18 = (int)func_02030734(a, b << 8, 1, d_02172B48, 0xc4);
    ((struct Obj04949 *)p)->f4 = b;
    ((struct Obj04949 *)p)->f8 = a;
    ((struct Obj04949 *)p)->f2C = c;
    ((struct Obj04949 *)p)->fC = 0x80;
    func_0216E280((int)p, a);
    ((struct Obj04949 *)p)->f44 = (int)func_02030734(a, 0xc4 << 2, 1, d_02172B48, 0xcf);
    return p;
}
