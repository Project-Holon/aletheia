/*
 * function: func_0218EC68
 * address:  0x0218EC68
 * packet:   pkt_ov021_0218EC68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19562.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Light;
extern void func_02048B60(struct Light *l, const u32 *in);

void func_0218EC68(u8 *a, u32 first, ...)
{
    func_02048B60((struct Light *)(((struct Obj19562 *)a)->fC), &first);
}
