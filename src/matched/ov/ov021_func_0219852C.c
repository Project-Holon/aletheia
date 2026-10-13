/*
 * function: FLDMMDL_ACMD_JumpInitWithSe
 * address:  0x0219852C
 * packet:   pkt_ov021_0219852C
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

void FLDMMDL_ACMD_JumpInitWithSe(u8 *a, u32 b, u32 c, u32 d, u16 e, s16 f, u16 g)
{
    FLDMMDL_ACMD_JumpInit(a, b, c, d, e, f, g, 0x55E);
}
