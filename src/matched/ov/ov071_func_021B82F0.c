/*
 * function: MONOLITH_TOOL_MENU_FreeCursor
 * address:  0x021B82F0
 * packet:   pkt_ov071_021B82F0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_DeleteBlink with the pointer advanced by 0x34.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/MONOLITH_TOOL_DeleteBlink.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 *
 * Region-qualified packet: this address is also resident in ov021.
 *
 * symbols:
 *   MONOLITH_TOOL_DeleteBlink  0x021B70B8  thumb  ov071
 */

void MONOLITH_TOOL_MENU_FreeCursor(void *p)
{
    void MONOLITH_TOOL_DeleteBlink(void **p);
    MONOLITH_TOOL_DeleteBlink((void **)((char *)p + 0x34));
}
