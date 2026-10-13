/*
 * function: PLACE_NAME_LETTER_Delete
 * address:  0x021BD184
 * packet:   pkt_021BD184
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
 *   PLACE_NAME_LETTER_DeleteBmpOam  0x021BD2A4  thumb  ov021
 *   PLACE_NAME_LETTER_DeleteBmp  0x021BD264  thumb  ov021
 *   PLACE_NAME_LETTER_FreeWork  0x021BD22C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 PLACE_NAME_LETTER_FreeWork(void *a0);
extern void PLACE_NAME_LETTER_DeleteBmp(u8 *p);
extern u32 PLACE_NAME_LETTER_DeleteBmpOam(u32, u32, u32, u32);

int PLACE_NAME_LETTER_Delete(void *a, u32 b, u32 c, u32 d)
{
PLACE_NAME_LETTER_DeleteBmpOam((u32)a, b, c, d);
PLACE_NAME_LETTER_DeleteBmp((u8 *)a);
return PLACE_NAME_LETTER_FreeWork(a);
}

