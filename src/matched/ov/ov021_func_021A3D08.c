/*
 * function: func_021A3D08
 * address:  0x021A3D08
 * packet:   pkt_ov021_021A3D08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A3B78  0x021A3B78  thumb  ov021
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A3190  0x021A3190  thumb  ov021
 */
#include "../include/Obj09562.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_021A3960(u8 *p);
extern u16 func_0216D598(void *p);
extern int func_021A3B78(u8 *);
extern void func_021A3AD8(u8 *p, int a);
extern u32 func_021A398C(u8 *);
extern u16 func_021A3190(int, int);

int func_021A3D08(u8 *p, u32 v)
{
    if (v == func_0216D598(func_021A3960(p))) {
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    if (func_021A3B78(p) == 1) {
        func_021A3AD8(p, v);
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    func_021A3AD8(p, func_021A3190(func_021A398C(p), 0));
    return 0;
}
