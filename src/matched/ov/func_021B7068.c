/*
 * function: func_021B7068
 * address:  0x021B7068
 * packet:   pkt_021B7068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0201EF40  0x0201EF40  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18097.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct WordSet;
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);

int func_021B7068(u32 a, u32 b, u32 c, u32 d)
{
func_0201EF40((struct WordSet *)a, 0, ((((struct Obj18097 *)((u8 *)(b)))->f0 << 16) >> 16));
return 8;
}

