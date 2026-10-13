/*
 * function: HAND_FIELD_GetHandlersUseCounter
 * address: 0x06898194
 * packet: pkt_ov095_06898194
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHandFieldUseCounterHandlers 0x0689D628 data a4
 */
extern unsigned gHandFieldUseCounterHandlers[];
unsigned *HAND_FIELD_GetHandlersUseCounter(unsigned *p)
{
    *p = 1;
    return gHandFieldUseCounterHandlers;
}
