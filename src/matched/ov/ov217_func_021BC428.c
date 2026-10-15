/*
 * function: RESEARCH_LIST_NeedsScrollbar
 * address:  0x021BC428
 * packet:   pkt_021BC428
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_LIST_GetEntryCount  0x021BC6DC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int RESEARCH_LIST_GetEntryCount(void *p);

int RESEARCH_LIST_NeedsScrollbar(void *p)
{
    return (int)RESEARCH_LIST_GetEntryCount(p) * 0x18 > 0x90;
}
