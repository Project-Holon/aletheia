/*
 * function: WORLDTRADE_ADAPTER_GetBoxParam
 * address:  0x022026BC
 * packet:   pkt_022026BC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb  arm9
 *

 *
 * Tail-call thunk to the thumb routine at 0x020185F4.
 */

typedef unsigned int u32;

extern void *POKE_TOOL_GetBoxParam(void *a);

u32 WORLDTRADE_ADAPTER_GetBoxParam(void *mon)
{
    return (u32)POKE_TOOL_GetBoxParam(mon);
}
