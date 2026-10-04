/*
 * function: func_02202878
 * address: 0x02202878
 * packet: pkt_ov135_02202878
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 022028C6..022028C8 zero alignment padding.
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
#include "../include/Obj04532.h"
typedef unsigned char u8;
typedef signed short s16;
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *, s16, s16, unsigned, unsigned, int, unsigned, unsigned, unsigned, unsigned);
void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p)
{
    int v;
    if (((struct Obj04532 *)p)->f10) {
        func_0201CE48(((struct Obj04532 *)p)->f10);
        ((struct Obj04532 *)p)->f10 = 0;
    }
    v = func_02012FFC();
    ((struct Obj04532 *)p)->f10 = func_0201CCE4(a, d, e, c, ((struct Obj04532 *)p)->f0, v, ((struct Obj04532 *)p)->f4, 0, 0x48, 0xF);
    ((struct Obj04532 *)p)->f14 = a;
}
