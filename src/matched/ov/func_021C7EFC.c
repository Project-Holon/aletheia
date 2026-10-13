/*
 * function: FIELD_FLASH_CmdInit
 * address:  0x021C7EFC
 * packet:   pkt_021C7EFC
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
 *   FIELD_FLASH_SetTweenSize  0x021C7EF0  thumb  ov021
 *   FIELD_FLASH_SetTweenAlpha  0x021C7EF8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18330.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_FLASH_SetTweenSize(u8 *p, u32 v);
extern u8 *FIELD_FLASH_SetTweenAlpha(u8 *p, u8 v);

int FIELD_FLASH_CmdInit(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj18330 *)((u8 *)(a)))->f1C = 1;
FIELD_FLASH_SetTweenSize((u8 *)(a + 4), (3 << 12));
return (int)FIELD_FLASH_SetTweenAlpha((u8 *)(a + 4), 31);
}

