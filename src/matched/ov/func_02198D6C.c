/*
 * function: FLDMMDL_ACMD_WalkRight3F
 * address:  0x02198D6C
 * packet:   pkt_02198D6C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_ACMD_WalkTableInit(its own argument 1, 0x3, 0x3, 0x7) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_ACMD_WalkTableInit  0x02198C08  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_ACMD_WalkTableInit(u32 a1, u32 a2, u32 a3, u32 a4);

u32 FLDMMDL_ACMD_WalkRight3F(u32 a1)
{
    FLDMMDL_ACMD_WalkTableInit(a1, 0x3, 0x3, 0x7);

    return 0x1;
}

