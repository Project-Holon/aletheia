/*
 * function: SCRCMD_MMDL_ICA_WaitTask
 * address:  0x021D1A9C
 * packet:   pkt_021D1A9C
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
 *   SCRCMD_MMDL_ICA_IsDone  0x021D18E0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18375.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 SCRCMD_MMDL_ICA_IsDone(u8 *p, u32 a1, u32 a2, u32 a3);

int SCRCMD_MMDL_ICA_WaitTask(u32 a, u32 b, u32 c, u32 d)
{
if (SCRCMD_MMDL_ICA_IsDone((u8 *)(((struct Obj18375 *)((u8 *)(c)))->f0), b, c, d) == 1) {
    return 1;
}
return 0;
}

