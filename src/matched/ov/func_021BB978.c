/*
 * function: FIELD_SUBPROC_DrawTcb
 * address:  0x021BB978
 * packet:   pkt_021BB978
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07224.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void FIELD_SUBPROC_DrawTcb(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 20))(b, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->f0)), ((struct Obj07224 *)((u8 *)(b)))->f10, *(u32 *)((u8 *)(((struct Obj07224 *)((u8 *)(b)))->fC) + 20));
}
}

