/*
 * function: POKE_TOOL_GetPlateTypeForwarder
 * address:  0x02019CF8
 * packet:   pkt_02019CF8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPlateType  0x02019BBC  thumb
 *
 * Plain forwarder to POKE_TOOL_GetPlateType (ldr r3, =target; bx r3).  Callee of
 * ov170 BOX2_MAIN_CanPlaceInBox.
 */

extern unsigned int POKE_TOOL_GetPlateType(unsigned int item);

unsigned int POKE_TOOL_GetPlateTypeForwarder(unsigned int item)
{
    return POKE_TOOL_GetPlateType(item);
}
