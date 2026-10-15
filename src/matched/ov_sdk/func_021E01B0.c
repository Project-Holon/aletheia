/*
 * function: BOX2_MAIN_IsWindowBusy
 * address:  0x021E01B0
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_UpdateBarMove  0x021EF400  thumb  ov170
 *
 * Boolean of the state test.
 */



extern int BOX2_UI_UpdateBarMove(unsigned char *p);
int BOX2_MAIN_IsWindowBusy(unsigned char *p)
{
    return BOX2_UI_UpdateBarMove(p) != 0;
}
