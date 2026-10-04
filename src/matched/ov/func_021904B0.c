/*
 * function: func_021904B0
 * address:  0x021904B0
 * packet:   pkt_021904B0
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
 *   func_02045B38  0x02045B38  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17924.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

int func_021904B0(u32 a, u32 b)
{
return (int)func_02045B38(0, 2, ((b << 16) >> 16), ((struct Obj17924 *)((u8 *)(a)))->f0);
}

