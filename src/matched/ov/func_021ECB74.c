/*
 * function: BOX2_SEQ_SetActorMode1
 * address:  0x021ECB74
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetSlotActorsMode  0x021ECA6C  thumb  ov170
 *
 * One range call with the selector pair fixed.
 */



extern void BOX2_SEQ_SetSlotActorsMode(unsigned char *p, int flag, int i, unsigned end, int mode);
void BOX2_SEQ_SetActorMode1(char *a, int b)
{
    BOX2_SEQ_SetSlotActorsMode((unsigned char *)a, 1, b, b + 1, 1);
}
