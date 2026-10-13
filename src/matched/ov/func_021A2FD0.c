/*
 * function: FIELD_PLAYER_ChangeToNormalForm
 * address:  0x021A2FD0
 * packet:   pkt_021A2FD0
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
 *   FIELD_PLAYER_CORE_StartFormChange  0x021A3CB0  thumb  ov021
 *   FIELD_PLAYER_CORE_FinishFormChange  0x021A3CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00614.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_PLAYER_CORE_StartFormChange(u32 a, u32 b);
extern u32 FIELD_PLAYER_CORE_FinishFormChange(u32);

int FIELD_PLAYER_ChangeToNormalForm(void *a)
{
FIELD_PLAYER_CORE_StartFormChange(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4, 1);
return FIELD_PLAYER_CORE_FinishFormChange(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4);
}

