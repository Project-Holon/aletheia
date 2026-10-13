/*
 * function: FIELD_CAMERA_SetAreasEnabled
 * address:  0x0218F1AC
 * packet:   pkt_0218F1AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter at +0xe9 through a displaced pointer.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17915.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v)
{
    ((struct Obj17915 *)p)->fE9 = v;
}
