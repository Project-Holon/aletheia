/*
 * function: func_021BEEB4
 * address:  0x021BEEB4
 * packet:   pkt_ov021_021BEEB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_021BF564  0x021BF564  thumb  ov021
 *   func_021BF584  0x021BF584  thumb  ov021
 */
#include "../include/Obj06060.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern u32 func_0204E804(void);
extern void func_021BF564(u32 a);
extern void func_021BF584(u8 *a0);

int func_021BEEB4(u32 p0, int *st, u8 *q)
{
    switch (*st) {
    case 0:
        if (((struct Obj06060 *)q)->f18 != 0) {
            func_021BF564(((struct Obj06060 *)q)->f4);
            func_021BF584((u8 *)(((struct Obj06060 *)q)->f4));
        }
        func_0204E720(((struct Obj06060 *)q)->fC, 0x10, 0, -1);
        *st = *st + 1;
        break;
    case 1:
        if (((struct Obj06060 *)q)->f14 == 1)
            return 1;
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}
