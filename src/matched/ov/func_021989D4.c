/*
 * function: FLDMMDL_ACMD_Wait16F
 * address:  0x021989D4
 * packet:   pkt_021989D4
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_ACMD_WaitInit(its own argument 1, 0x10) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_ACMD_WaitInit  0x02198960  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_ACMD_WaitInit(u32 a1, u32 a2);

u32 FLDMMDL_ACMD_Wait16F(u32 a1)
{
    FLDMMDL_ACMD_WaitInit(a1, 0x10);

    return 0x1;
}

