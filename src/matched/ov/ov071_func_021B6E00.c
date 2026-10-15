/*
 * unit:     yes
 * function: MONOLITH_TOOL_GetHighlightColorA, MONOLITH_TOOL_GetHighlightColorB, MONOLITH_TOOL_GetHighlightColorCount
 * address:  0x021B6E00
 * packet:   pkt_ov071_021B6E00
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two bounded constant selectors and a constant return.
 */

int MONOLITH_TOOL_GetHighlightColorA(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}

int MONOLITH_TOOL_GetHighlightColorB(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}

int MONOLITH_TOOL_GetHighlightColorCount(int a0)
{
    return 3;
}
