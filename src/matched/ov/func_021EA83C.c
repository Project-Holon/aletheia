/*
 * function: BOX2_SEQ_ResetEntry
 * address:  0x021EA83C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_RefreshBoxUi  0x021DD1E8  thumb  ov170
 *   BOX2_SEQ_SetSeqThird  0x021E8FC0  thumb  ov170
 *
 * Reset the entry then store the field with the dispatcher
 *   thumb-pointer 0x021E01C5 as its second argument.
 */


extern void BOX2_MAIN_RefreshBoxUi(char *);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
int BOX2_SEQ_ResetEntry(char *p, int a)
{
    BOX2_MAIN_RefreshBoxUi(p);
    return BOX2_SEQ_SetSeqThird(p, 0x021E01C5, a);
}
