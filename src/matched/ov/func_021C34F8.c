/*
 * function: SODATEYA_GetPokemon
 * address:  0x021C34F8
 * packet:   pkt_021C34F8
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
 *   DAYCARE_IsSlotInUse  0x0200BCA8  thumb
 *   DAYCARE_GetSlotMon  0x0200BC2C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04896.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *DAYCARE_GetSlotMon(void *e, u32 i);
extern u32 DAYCARE_IsSlotInUse(void *e, u32 i);

void *SODATEYA_GetPokemon(void *a, u32 b)
{
DAYCARE_IsSlotInUse(((struct Obj04896 *)a)->f8, b);
return DAYCARE_GetSlotMon(((struct Obj04896 *)a)->f8, b);
}

