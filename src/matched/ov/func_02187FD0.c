/*
 * function: FIELDMAP_ProcMain
 * address:  0x02187FD0
 * packet:   pkt_02187FD0
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
 *   FIELDMAP_Main  0x02188B58  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17856.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_Main(void *a, u8 *b, u32 a2, u32 a3);

int FIELDMAP_ProcMain(u32 a, u32 b, u32 c, u32 d)
{
if (FIELDMAP_Main((void *)c, (u8 *)(((struct Obj17856 *)((u8 *)(d)))->f0), c, d) == 1) {
    return 1;
}
return 0;
}

