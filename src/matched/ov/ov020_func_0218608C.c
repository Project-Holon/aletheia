/*
 * function: EVENT_MAPCHANGE_NopHook
 * address:  0x0218608C
 * packet:   pkt_ov020_0218608C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf: an empty function (`bx lr` plus two bytes of padding)
 * after EVENT_MAPCHANGE_AllocWorkBufferB.  ov020 EVENT_MAPCHANGE_ChangeFieldEvent passes its address as the end
 * of the range handed to the ov230 routine func_021883CC, the same way it
 * passes EVENT_MAPCHANGE_AllocWorkBufferA and EVENT_MAPCHANGE_AllocWorkBufferB to func_021882A0 and func_02188318.
 */

void EVENT_MAPCHANGE_NopHook(void)
{
}
