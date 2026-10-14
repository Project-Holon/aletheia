/*
 * function: MB_SEQ_ShowBagResultMessage
 * address:  0x021C7084
 * packet:   pkt_ov136_021C7084
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_ShowMessageWindow 0x021C62BC thumb
 *   MB_SEQ_ShowItemMessage 0x021C7620 thumb
 */

typedef unsigned char u8;
extern void MB_SEQ_ShowMessageWindow(u8 *);
extern void MB_SEQ_ShowItemMessage(u8 *);
void MB_SEQ_ShowBagResultMessage(u8 *p)
{
    MB_SEQ_ShowMessageWindow(p);
    MB_SEQ_ShowItemMessage(p);
}
