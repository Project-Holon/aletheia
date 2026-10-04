/*
 * function: func_021C5418
 * address:  0x021C5418
 * packet:   pkt_ov093_021C5418
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021BD1D0  0x021BD1D0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D5BDC(u8 *p, u32 n);
extern u8 func_021D5440(u8 *p);
extern void func_021C6110(u8 *p, u8 *a, unsigned int n);
extern int func_021D62C4(u8 *p, int i);
struct Slot { u32 kind : 3; u32 rest : 29; };
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021BD1D0(u8 *p, u8 n);

int func_021C5418(u8 *p, u8 *a, int b)
{
    u8 n;
    if (func_021D5BDC(a, b)) {
        n = func_021D5440(a);
        func_021C6110(p, a, b);
        b = 0x1a;
        if (func_021D62C4(a, 0x1a)) {
            func_021C5620(p, a, b, 0);
        }
        func_021CD4B0(((struct Obj00003 *)p)->fC, 0x31, n, 0);
        func_021BD1D0(p, n);
        return 1;
    }
    return 0;
}
