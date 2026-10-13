/*
 * function: PLACE_NAME_LETTER_Setup
 * address:  0x021BD19C
 * packet:   pkt_021BD19C
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
 *   PLACE_NAME_LETTER_SetFont  0x021BD2C4  thumb  ov021
 *   PLACE_NAME_LETTER_SetChar  0x021BD2D0  thumb  ov021
 *   PLACE_NAME_LETTER_MeasureGlyph  0x021BD30C  thumb  ov021
 *   PLACE_NAME_LETTER_ClearBmp  0x021BD57C  thumb  ov021
 *   PLACE_NAME_LETTER_PrintChar  0x021BD588  thumb  ov021
 *   PLACE_NAME_LETTER_SetMotion  0x021BD554  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12115.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void PLACE_NAME_LETTER_SetFont(u8 *p, u32 v);
extern void PLACE_NAME_LETTER_SetChar(u8 *p, u16 v);
extern void PLACE_NAME_LETTER_MeasureGlyph(char *p);
extern u32 PLACE_NAME_LETTER_SetMotion(u32, u32);
extern void PLACE_NAME_LETTER_ClearBmp(u8 *p);
extern void PLACE_NAME_LETTER_PrintChar(u32 *p);

int PLACE_NAME_LETTER_Setup(u32 a, u32 b)
{
PLACE_NAME_LETTER_SetFont((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f20);
PLACE_NAME_LETTER_SetChar((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f24);
PLACE_NAME_LETTER_MeasureGlyph((char *)a);
PLACE_NAME_LETTER_ClearBmp((u8 *)a);
PLACE_NAME_LETTER_PrintChar((u32 *)a);
return PLACE_NAME_LETTER_SetMotion(a, b);
}

