/*
 * function: func_0218D13C
 * address:  0x0218D13C
 * packet:   pkt_ov021_0218D13C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj07416.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Tagged;
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);

void func_0218D13C(u8 *a)
{
    if (((struct Obj07416 *)a)->f60 != 0) {
        func_020470D0((u32 *)(((struct Obj07416 *)a)->f60));
        func_02046EFC((struct Tagged *)(((struct Obj07416 *)a)->f60));
        ((struct Obj07416 *)a)->f60 = 0;
    }
}
