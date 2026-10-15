/*
 * function: RESEARCH_LIST_GetScrollRange
 * address:  0x021BC40C
 * packet:   pkt_021BC40C
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

int RESEARCH_LIST_GetScrollRange(void *p)
{
    return (int)RESEARCH_LIST_GetEntryCount(p) * 0x18 - 0xa8;
}
