/*
 * function: FLDMMDL_ACMD_MarkGyoe
 * address:  0x02198BA8
 * packet:   pkt_02198BA8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls FLDMMDL_ACMD_MarkInit(its own argument 1, 0x0, 0x0) and returns 0x0.
 *
 * symbols:
 *   FLDMMDL_ACMD_MarkInit  0x02198B4C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_ACMD_MarkInit(u32 a1, u32 a2, u32 a3);

u32 FLDMMDL_ACMD_MarkGyoe(u32 a1)
{
    FLDMMDL_ACMD_MarkInit(a1, 0x0, 0x0);

    return 0x0;
}

