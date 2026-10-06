/*
 * function: func_021B4510
 * address:  0x021B4510
 * packet:   pkt_ov021_021B4510
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of func_021B45A0 (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to func_02020D0C.
 *
 * symbols:
 *   func_02020D0C 0x02020D0C thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_021B44CC 0x021B44CC thumb ov021
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02390.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02020D0C(u8 *p);
struct Bmp;
struct StrObj;
struct WordSet;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

void func_021B4510(u8 *p, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C(p);
    if (a != -2) {
        func_0201EFA4((struct WordSet *)(((struct Obj02390 *)w)->f190), 1, *(u32 *)(w + a * 8 + 0x24), 5, 0, 1);
        func_0201F250((struct WordSet *)(((struct Obj02390 *)w)->f190), (void *)(((struct Obj02390 *)w)->f198), (void *)(((struct Obj02390 *)w)->f194));
        lo = func_0201D304((struct StrObj *)(((struct Obj02390 *)w)->f198), ((struct Obj02390 *)w)->f8, 0);
        hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C)));
        func_021B44CC((void *)(((struct Obj02390 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C), hi - lo, b,
                      ((struct Obj02390 *)w)->f198, ((struct Obj02390 *)w)->f8, 0x31A0);
    }
}
