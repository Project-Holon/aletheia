/*
 * function: RESEARCH_LIST_GetEntryScreenX
 * address:  0x021BBF28
 * packet:   pkt_021BBF28
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_GetRowOffset  0x021BBF04  thumb  ov217
 *   BG_SYS_GetChannelScrollX  0x02041648  arm
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int RESEARCH_LIST_GetRowOffset(unsigned int p, unsigned int slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BG_SYS_GetChannelScrollX(u8 channel);

int RESEARCH_LIST_GetEntryScreenX(unsigned char *p, unsigned int slot)
{
    int t = RESEARCH_LIST_GetRowOffset((unsigned int)p, slot) << 3;
    return t - BG_SYS_GetChannelScrollX(2);
}
