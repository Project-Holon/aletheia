/*
 * function: func_0218FFE8
 * address:  0x0218FFE8
 * packet:   pkt_ov021_0218FFE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E138  0x0218E138  thumb
 *   func_0218E13C  0x0218E13C  thumb
 */
#include "../include/Obj02372.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0218E138(u8 *p);
extern void func_0218E13C(u8 *a, u32 s);

void func_0218FFE8(u8 *a, u32 a1, u32 a2, u32 a3)
{
    void *x = ((struct Obj02372 *)a)->f4;
    ((struct Obj02372 *)a)->f10 = func_0218E138(x);
    func_0218E13C(x, 0);
}
