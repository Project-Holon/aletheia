/*
 * function: BTLV_CORE_CancelWindowModeSelect
 * address:  0x021EAA5C
 * packet:   pkt_ov093_021EAA5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCD_CloseInputScreen  0x0689B558  thumb
 */
#include "../include/Obj21569.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTLV_SCD_CloseInputScreen(int a);

void BTLV_CORE_CancelWindowModeSelect(u8 *o)
{
    BTLV_SCD_CloseInputScreen(((struct Obj21569 *)o)->f180);
}
