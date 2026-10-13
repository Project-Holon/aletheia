/*
 * function: FLDMMDL_ACMD_HopDownFaceLeft8F
 * address:  0x02199BAC
 * packet:   pkt_ov021_02199BAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_HopInit  0x02199888  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_ACMD_HopInit(u32 a, int b, u32 c, u32 d, u8 e, u8 f, u8 g, u8 h, u8 i);

int FLDMMDL_ACMD_HopDownFaceLeft8F(u32 a)
{
    FLDMMDL_ACMD_HopInit(a, -0x2000, 2, 1, 8, 3, 1, 1, 0);
    return 1;
}
