/*
 * function: FIELD_GROUND_ANIME_GetCurrentStep
 * address:  0x021A81DC
 * packet:   pkt_021A81DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

u8 FIELD_GROUND_ANIME_GetCurrentStep(u32 a)
{
return *(u8 *)((u8 *)(((a + *(u8 *)((u8 *)((a + 54)))) + 44)));
}

