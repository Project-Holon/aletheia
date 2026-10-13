/*
 * function: FIELD_SAVEANIME_DeleteWindow
 * address:  0x021D13F0
 * packet:   pkt_021D13F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04299.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);

u32 FIELD_SAVEANIME_DeleteWindow(u32 a)
{
func_020452E8((struct Descriptor *)(((struct Obj04299 *)((u8 *)(a)))->f4));
((struct Obj04299 *)((u8 *)(a)))->f4 = 0;
return 0;
}

