/*
 * function: func_0218F0D4
 * address:  0x0218F0D4
 * packet:   pkt_ov021_0218F0D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj09464.h"
#include "../include/Obj19568.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

void func_0218F0D4(u8 *a, int b)
{
    u8 *p = *(u8 * *)&((struct Obj19568 *)a)->fEC;
    if (p != 0) {
        ((struct Obj09464 *)p)->f2C = 0;
        ((struct Obj09464 *)p)->f28 = 0;
        ((struct Obj09464 *)p)->f10 = 0;
    }
}
