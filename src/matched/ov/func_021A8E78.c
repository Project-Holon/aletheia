/*
 * function: FIELD_MENU_GetSlotIndex
 * address:  0x021A8E78
 * packet:   pkt_021A8E78
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

int FIELD_MENU_GetSlotIndex(u32 a, u32 b)
{
return (a + (b << 1));
}

