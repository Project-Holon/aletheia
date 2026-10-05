/*
 * function: func_02205384
 * address:  0x02205384
 * packet:   pkt_02205384
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0220549C 0x0220549C thumb ov195
 *   func_02205620 0x02205620 thumb ov195
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 */
#include "../include/Obj01429.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0220549C(char *, int);
extern u32 func_02205620(u32, u32, u32, u32, u32, u32, u32);
extern signed char func_02012FFC(void);
typedef signed short   s16;
typedef signed int     s32;
struct Rec;
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);

void func_02205384(char *a, u32 b, u32 c, u32 d, u32 k0, u32 v0, u32 k1, u32 v1)
{
    func_0220549C(a, 0xf);
    *(u32 *)&((struct Obj01429 *)a)->f80 = func_02205620(((struct Obj01429 *)a)->f2, b, c, k0, v0, k1, v1);
    *(u32 *)&((struct Obj01429 *)a)->f64 = (u32)func_0201CD10(*(u32 *)&((struct Obj01429 *)a)->f6C, 0, 0, *(u32 *)&((struct Obj01429 *)a)->f80, ((struct Obj01429 *)a)->f8,
                                       func_02012FFC(), ((struct Obj01429 *)a)->f68, 2, ((struct Obj01429 *)a)->f2, 0xf, d);
}
