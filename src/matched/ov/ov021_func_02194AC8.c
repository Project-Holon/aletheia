/*
 * function: func_02194AC8
 * address:  0x02194AC8
 * packet:   pkt_ov021_02194AC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *   func_02194A94  0x02194A94  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01492.h"
#include "../include/Obj03114.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02194B3C(u8 *p, u8 *e);
extern u32 func_02194A94(u8 *p, u8 x, u8 y, int w, int h);

void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s)
{
    int w;
    int h;
    int y;
    u8 x;

    func_02194B3C(p, e);
    ((struct Obj01492 *)e)->f10 = a;
    ((struct Obj01492 *)e)->f14 = b;
    ((struct Obj01492 *)e)->f18 = ((struct Obj03114 *)s)->fC;
    ((struct Obj01492 *)e)->f1A = 0;
    ((struct Obj01492 *)e)->f4 = ((struct Obj03114 *)s)->f0;
    ((struct Obj01492 *)e)->f3 = ((struct Obj03114 *)s)->fE;
    ((struct Obj01492 *)e)->f60 = ((struct Obj03114 *)s)->f10;
    w = s[0xA];
    x = s[8];
    x = (x + w > 0x20) ? 0x20 - w : x;
    h = s[0xB];
    y = s[9];
    if (y + h > 0x18)
        y = 0x18 - h;
    ((struct Obj01492 *)e)->fC = func_02194A94(p, x, y, w, h);
    ((struct Obj01492 *)e)->f58 = ((struct Obj03114 *)s)->f4;
    ((struct Obj01492 *)e)->f5C = 8;
    ((struct Obj01492 *)e)->f5D = 0;
    ((struct Obj01492 *)e)->f0 = 1;
}
