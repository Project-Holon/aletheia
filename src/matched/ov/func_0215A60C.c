/*
 * function: SCRCMD_WORK_GetMsgData
 * address:  0x0215A60C
 * packet:   pkt_0215A60C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reads the word field at +0x14.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17661.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


u32 SCRCMD_WORK_GetMsgData(u8 *p)
{
    return ((struct Obj17661 *)p)->f14;
}

