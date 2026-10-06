/*
 * function: func_0219AA08
 * address:  0x0219AA08
 * packet:   pkt_0219AA08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B404  0x0219B404  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17956.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p, u32 a1, u32 a2, u32 a3);
extern int func_0219B358(u32 a);
extern void func_0219B404(u32 a, u8 *s);

int func_0219AA08(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a, b, c, d) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (u8 *)(b + 4));
    }
    ((struct Obj17956 *)((u8 *)(b)))->f0 = 0;
}
return 0;
}

