/*
 * function: FLDMMDL_ACMD_JumpDown3G24FNoSe
 * address:  0x021988F4
 * packet:   pkt_ov021_021988F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_JumpInit 0x021984C0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void FLDMMDL_ACMD_JumpInit(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g, u32 h);

int FLDMMDL_ACMD_JumpDown3G24FNoSe(u8 *a)
{
    FLDMMDL_ACMD_JumpInit(a, 1, 0x2000, 24, 3, 0, 0xA0, 0);
    return 1;
}
