/*
 * function: func_021D52B4
 * address:  0x021D52B4
 * packet:   pkt_ov093_021D52B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F00  0x02017F00  thumb
 */
#include "../include/Obj03696.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_02017E1C(void *h, u32 k, u32 z);
extern u8 func_02017F00(void *h);

void func_021D52B4(u8 *p, void *h, int flag)
{
    if (flag) {
        p[0xf8] = func_02017E1C(h, 0xae, 0);
        p[0xf9] = func_02017E1C(h, 0xaf, 0);
    }
    p[0xfa] = func_02017F00(h);
    ((struct Obj03696 *)p)->fEE = func_02017E1C(h, 0xa2, 0);
    ((struct Obj03696 *)p)->fF0 = func_02017E1C(h, 0xa3, 0);
    ((struct Obj03696 *)p)->fF2 = func_02017E1C(h, 0xa5, 0);
    ((struct Obj03696 *)p)->fF4 = func_02017E1C(h, 0xa6, 0);
    ((struct Obj03696 *)p)->fF6 = func_02017E1C(h, 0xa4, 0);
}
