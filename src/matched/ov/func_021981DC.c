/*
 * function: FLDMMDL_ACMD_WalkLeft2F
 * address:  0x021981DC
 * packet:   pkt_021981DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   FLDMMDL_ACMD_WalkInit  0x02197FC0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void FLDMMDL_ACMD_WalkInit(u8 *a, u32 b, u32 c, u16 d, u16 e);

int FLDMMDL_ACMD_WalkLeft2F(u32 a)
{
    FLDMMDL_ACMD_WalkInit((u8 *)a, 0x2, 0x8000, 0x2, 0x5);
    return 1;
}
