/*
 * function: BOX2_SEQ_StatePushSlot
 * address:  0x021E78F4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_PrintPrompt  0x021EBC58  thumb  ov170
 *
 * Push the 0x16 field through the 0x18 selector; return 75.
 */



extern void BOX2_SEQ_PrintPrompt(unsigned char *p, int sel, int kind, int i);
int BOX2_SEQ_StatePushSlot(char *p)
{
    BOX2_SEQ_PrintPrompt((unsigned char *)p, (unsigned char)p[0x16], 1, 0x18);
    return 0x4b;
}
