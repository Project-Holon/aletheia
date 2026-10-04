/*
 * function: func_0218E284
 * address:  0x0218E284
 * packet:   pkt_ov021_0218E284
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00428.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

void func_0218E284(u8 *a)
{
    Vec3 *p = *(Vec3 * *)&((struct Obj00428 *)a)->f1C;
    if (p != 0)
        *(Vec3 *)(a + 0x48) = *p;
}
