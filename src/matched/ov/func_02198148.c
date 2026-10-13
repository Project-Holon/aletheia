/*
 * function: FLDMMDL_ACMD_WalkRight8F
 * address:  0x02198148
 * packet:   pkt_02198148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_ACMD_WalkInit  0x02197FC0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FLDMMDL_ACMD_WalkInit(u8 *a, u32 b, u32 c, u16 d, u16 e);

int FLDMMDL_ACMD_WalkRight8F(u32 a, u32 b, u32 c, u32 d)
{
FLDMMDL_ACMD_WalkInit((u8 *)a, 3, (2 << 12), 8, 3);
return 1;
}

