/*
 * function: func_0217F310
 * address:  0x0217F310
 * packet:   pkt_ov019_0217F310
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12529.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02034714(const char *a, u32 b, const char *c);
struct Handle;
extern u32 func_02188C54(u8 *p);
extern int func_0219049C(u32 a);
extern int func_021909E4(struct Handle *h);
extern u32 d_021807F8[];

int func_0217F310(char *p, u32 a1)
{
    u32 h = func_02188C54((u8 *)a1);

    if (h == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (h != 0 && func_0219049C(h) == 0) {
        return -1;
    }
    if (((struct Obj12529 *)p)->f2810 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return func_021909E4((struct Handle *)(((struct Obj12529 *)p)->f2810));
}
