/*
 * function: FLDMMDL_ACMD_DirLeft
 * address:  0x02197FA8
 * packet:   pkt_02197FA8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls FLDMMDL_ACMD_TurnInit(its own argument 1, 0x2) and returns 0x1.
 *
 * symbols:
 *   FLDMMDL_ACMD_TurnInit  0x02197F6C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern int FLDMMDL_ACMD_TurnInit(u32 a, u32 b);

u32 FLDMMDL_ACMD_DirLeft(u32 a1)
{
    FLDMMDL_ACMD_TurnInit(a1, 0x2);

    return 0x1;
}

