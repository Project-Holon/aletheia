/*
 * function: ov021_func_021A46F0
 * address:  0x021A46F0
 * packet:   pkt_ov021_021A46F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021A4768  0x021A4768  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_021A4664  0x021A4664  thumb  ov021
 *   func_021A4698  0x021A4698  thumb  ov021
 *   func_021A482C  0x021A482C  thumb  ov021
 *   func_021A4890  0x021A4890  thumb  ov021
 *   func_021A48A4  0x021A48A4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12735.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_021A3960(unsigned char *p);
extern int func_021A4768(u8 *, void *, u32);
extern int func_021A47B4(u8 *, void *, u32);
extern int func_021A4664(int a, int b, u8 *c);
extern int func_021A4698(u8 *, void *, u32);
extern int func_021A482C(u8 *, void *, u32);
extern int func_021A4890(u8 *a, u32 b, u32 c);
extern int func_021A48A4(u32 a, u32 b, u32 c);

int ov021_func_021A46F0(u8 *a, u32 b)
{
    void *r = func_021A3960(((struct Obj12735 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12735 *)a)->f0) {
    case 0:
        ret = func_021A4768(a, r, b);
        break;
    case 1:
        ret = func_021A47B4(a, r, b);
        break;
    case 2:
        ret = func_021A4664((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = func_021A4698(a, r, b);
        break;
    case 4:
        ret = func_021A482C(a, r, b);
        break;
    case 5:
    case 6:
        ret = func_021A4890(a, (u32)r, b);
        break;
    case 7:
        ret = func_021A48A4((u32)a, (u32)r, b);
        break;
    }
    return ret;
}
