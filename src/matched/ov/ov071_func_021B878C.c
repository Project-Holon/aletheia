/*
 * function: func_021B878C
 * address:  0x021B878C
 * packet:   pkt_ov071_021B878C
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to MONOLITH_TOOL_FreeLabel((char *)p + 0x18).
 *
 * symbols:
 *   MONOLITH_TOOL_FreeLabel  0x021B6EEC  thumb  ov071
 */

void func_021B878C(void *p)
{
    void MONOLITH_TOOL_FreeLabel(void **p);
    MONOLITH_TOOL_FreeLabel((void **)((char *)p + 0x18));
}
