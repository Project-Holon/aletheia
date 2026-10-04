/*
 * function: func_021C1670
 * address:  0x021C1670
 * packet:   pkt_ov021_021C1670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Finishes the pending effect at +0x48 once it reports done.
 *
 * symbols:
 *   func_021AD5CC  0x021AD5CC  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ABE64  0x021ABE64  thumb  ov021
 *   func_021A35A0  0x021A35A0  thumb  ov021
 */
#include "../include/Obj04271.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AD5CC(u32 a);
extern u32 func_02188CD0(u8 *p);
extern void func_021AC154(u32 a);
extern void func_021ABE64(u32 a, int b);
extern void func_021A35A0(u32 *p, int a);

int func_021C1670(u8 *p)
{
    u32 o;

    if (((struct Obj04271 *)p)->f48 != 0 && func_021AD5CC(((struct Obj04271 *)p)->f48) == 1) {
        o = func_02188CD0((u8 *)(((struct Obj04271 *)p)->f40));
        func_021AC154(((struct Obj04271 *)p)->f48);
        func_021ABE64(o, 9);
        func_021A35A0((u32 *)(((struct Obj04271 *)p)->f3C), 1);
        ((struct Obj04271 *)p)->f48 = 0;
        ((struct Obj04271 *)p)->f6 = 1;
    }
    return 0;
}
