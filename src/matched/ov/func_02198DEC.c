/*
 * function: FLDMMDL_ACMD_WalkUp12F
 * address:  0x02198DEC
 * packet:   pkt_02198DEC
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_ACMD_WalkTableInit(its own argument 1, 0x0, 0xc, 0x9) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_ACMD_WalkTableInit  0x02198C08  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_ACMD_WalkTableInit(u32 a1, u32 a2, u32 a3, u32 a4);

u32 FLDMMDL_ACMD_WalkUp12F(u32 a1)
{
    FLDMMDL_ACMD_WalkTableInit(a1, 0x0, 0xc, 0x9);

    return 0x1;
}

