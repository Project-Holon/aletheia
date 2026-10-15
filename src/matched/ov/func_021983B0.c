/*
 * function: FLDMMDL_ACMD_StayWalkRight32F
 * address:  0x021983B0
 * packet:   pkt_021983B0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_ACMD_StayWalkInit(its own argument 1, 0x3, 0x20, 0x1) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_ACMD_StayWalkInit  0x02198318  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_ACMD_StayWalkInit(u32 a, u32 b, u16 c, u16 d);

u32 FLDMMDL_ACMD_StayWalkRight32F(u32 a1)
{
    FLDMMDL_ACMD_StayWalkInit(a1, 0x3, 0x20, 0x1);

    return 0x1;
}

