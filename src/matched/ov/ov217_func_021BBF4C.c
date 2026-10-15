/*
 * function: RESEARCH_LIST_GetEntryScreenYBottom
 * address:  0x021BBF4C
 * packet:   pkt_021BBF4C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_GetRowBase  0x021BBF1C  thumb  ov217
 *   RESEARCH_LIST_GetScrollY  0x021BC3AC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int RESEARCH_LIST_GetRowBase(unsigned int unused, unsigned int v);
extern int RESEARCH_LIST_GetScrollY(void);

int RESEARCH_LIST_GetEntryScreenYBottom(unsigned char *p, unsigned int index)
{
    int t = (RESEARCH_LIST_GetRowBase((unsigned int)p, index) << 3) + 0x17;
    return t - RESEARCH_LIST_GetScrollY();
}
