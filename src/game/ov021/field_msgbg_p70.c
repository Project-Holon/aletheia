/*
 * file:     field_msgbg_p70.c
 * unit:     yes
 * function: func_021912D8, func_021912F8
 * address:  0x021912D8
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
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_02194950  0x02194950  thumb  ov021
 *   func_02194960  0x02194960  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj00005.h"

struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

extern void func_02045808(struct U16Vec *vec);
extern void func_021927E8(u32 *p);
extern u32 func_02194950(u32, u32);
extern u32 func_02082BCC(u32, u32, u32);
extern u32 func_02194960(u32, u32, u32, u32);
int func_021912D8(u32 a);
int func_021912F8(u32 a, u32 b, u32 c, u32 d);


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021912D8(u32 a)
{
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f4));
}
func_021927E8((u32 *)(a + 12));
return func_02194950(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1));
}


int func_021912F8(u32 a, u32 b, u32 c, u32 d)
{
if (func_02194960(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8, *(u8 *)((u8 *)(a) + 1), c, d) != 0) {
    func_02082BCC(a, 0, 52);
    return 1;
}
return 0;
}
