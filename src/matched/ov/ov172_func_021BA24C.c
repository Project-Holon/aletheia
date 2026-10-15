/*
 * function: CTVT_MIC_GetPlayPos
 * address:  0x021BA24C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter, low half of the u32 at +0x14.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24099.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int CTVT_MIC_GetPlayPos(void *p)
{
    return (u16)((struct Obj24099 *)p)->f14;
}
