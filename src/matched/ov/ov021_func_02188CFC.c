/*
 * function: FIELDMAP_GetMoveKind
 * address:  0x02188CFC
 * packet:   pkt_ov021_02188CFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   sCtrlMoveKindTable  0x021D35A8  data
 *   FIELDMAP_CTRL_HYBRID_GetMode  0x021A6DC0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern const u8 sCtrlMoveKindTable[];
extern u32 FIELDMAP_CTRL_HYBRID_GetMode(u8 *p);

u32 FIELDMAP_GetMoveKind(u8 *p)
{
    u32 r;
    u32 k = sCtrlMoveKindTable[**(u32 * *)&((struct Obj00020 *)p)->f108];

    if (k == 2)
        k = FIELDMAP_CTRL_HYBRID_GetMode(((struct Obj00020 *)p)->f10C);
    r = k;
    return r;
}
