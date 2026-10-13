/*
 * function: TALKMSGWIN_IsEntryFree
 * address:  0x02194A74
 * packet:   pkt_02194A74
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
#include "../include/Obj17942.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int TALKMSGWIN_IsEntryFree(u32 a)
{
if (((struct Obj17942 *)((u8 *)(a)))->f0 == 0) {
    return 1;
}
return 0;
}

