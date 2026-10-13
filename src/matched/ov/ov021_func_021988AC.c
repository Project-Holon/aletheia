/*
 * function: FLDMMDL_ACMD_JumpRight3G12F
 * address:  0x021988AC
 * packet:   pkt_ov021_021988AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_ACMD_JumpInitWithSe 0x0219852C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void FLDMMDL_ACMD_JumpInitWithSe(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g);

int FLDMMDL_ACMD_JumpRight3G12F(u8 *a)
{
    FLDMMDL_ACMD_JumpInitWithSe(a, 3, 0x4000, 12, 3, 0, 0x140);
    return 1;
}
