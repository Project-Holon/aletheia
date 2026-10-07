/*
 * file:     field_wfbc_p20.c
 * unit:     yes
 * function: func_02194AC8, func_02194B3C, func_02194B70, func_02194B78, func_02194B84
 * address:  0x02194AC8
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
 *   func_02194A94  0x02194A94  thumb  ov021
 *   func_02194A74  0x02194A74  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 *   func_02195338  0x02195338  thumb  ov021
 *   func_02195E80  0x02195E80  thumb  ov021
 *   func_0201CCE4  0x0201CCE4  thumb
 */
#include "../../matched/include/Obj01492.h"
#include "../../matched/include/Obj03114.h"
#include "../../matched/include/Obj04217.h"
#include "../../matched/include/Obj12071.h"
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj01493.h"

struct Descriptor;
struct FrameStyle;
struct Rec3;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern u32 func_02194A94(u8 *p, u8 x, u8 y, int w, int h);
extern int func_02194A74(u32 a);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02195E90(struct FrameStyle *style, void *win);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02195338(u8 *p, u8 *e);
extern int func_02195E80(u32 a, u32 b);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s);
void func_02194B3C(u8 *p, u8 *e);
void func_02194B70(u16 *p, int i);
void func_02194B78(u8 *p, int i);
void func_02194B84(u8 *p, u8 *e);


/*
 * Addresses are Black-image addresses.
 */
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


void func_02194B3C(u8 *p, u8 *e)
{
    if (func_02194A74((u32)e) == 0) {
        if (((struct Obj04217 *)e)->f8 != 0) {
            func_0201CE48((struct Rec3 *)(((struct Obj04217 *)e)->f8));
            ((struct Obj04217 *)e)->f8 = 0;
        }
        func_02195E90((struct FrameStyle *)p, (void *)(((struct Obj04217 *)e)->fC));
        func_020452E8((struct Descriptor *)(((struct Obj04217 *)e)->fC));
        ((struct Obj04217 *)e)->f2 = 0;
        ((struct Obj04217 *)e)->f0 = 0;
    }
}


/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): stores 2
 * into the u16 at offset 0.  Listing bytes 02 21 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B70(u16 *p, int i)
{
    *p = 2;
}


/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): two u16
 * constant stores, one at offset 0 and one at +0x5e.  Listing bytes
 * 05 21 01 80 04 21 5E 30 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B78(u8 *p, int i)
{
    ((struct Obj12071 *)p)->f0 = 5;
    ((struct Obj12071 *)p)->f5E = 4;
}


void func_02194B84(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj01493 *)e)->f0) {
    case 0:
    case 1:
        break;
    case 2:
        func_02195338(p, e);
        ((struct Obj01493 *)e)->f5E = 0;
        ((struct Obj01493 *)e)->f0 = 3;
        return;
    case 3:
        func_02195338(p, e);
        if (((struct Obj01493 *)e)->f5E < 8) {
            ((struct Obj01493 *)e)->f5E += 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 4;
        t = ((struct Obj01493 *)e)->f60;
        func_02195E80((u32)p, (u32)e);
        ((struct Obj01493 *)e)->f8 = func_0201CCE4(((struct Obj01493 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj01493 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 4:
        if (func_02195338(p, e) == 1) {
            func_02195E80((u32)p, (u32)e);
        }
        return;
    case 5:
        if (((struct Obj01493 *)e)->f5E != 0) {
            ((struct Obj01493 *)e)->f5E -= 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}
