/*
 * function: func_021BEC60
 * address:  0x021BEC60
 * packet:   pkt_ov210_021BEC60
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045738 0x02045738 arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04620.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021B9394(char *p);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
struct Descriptor;
extern u8 func_02045738(struct Descriptor *p);

void func_021BEC60(int p, int *a, u32 b)
{
    u32 x = func_021B9394(*(char * *)&((struct Obj04620 *)p)->f1E0);

    func_021B6AE4((u8 *)a, x, (u16)(func_02045738((struct Descriptor *)(*a)) * 8 / 2), 4, b,
                  ((struct Obj04620 *)p)->f1CC, 0x39e0, 2);
}
