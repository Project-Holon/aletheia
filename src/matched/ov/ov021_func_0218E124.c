/*
 * function: func_0218E124
 * address:  0x0218E124
 * packet:   pkt_ov021_0218E124
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DDA0C  0x021DDA0C  data  ov021  a4
 */
#include "../include/Obj19556.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*StateFunc)(void *a);
extern StateFunc d_021DDA0C[];

void func_0218E124(u8 *a, u32 s)
{
    ((struct Obj19556 *)a)->f14 = s;
    d_021DDA0C[s](a);
}
