/*
 * function: BOX2_MAIN_UpdateWindowMove
 * address: 0x021E01A8
 * packet: pkt_ov170_021E01A8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_UI_UpdateTopBarMove 0x021EF6E0 thumb ov170
 * Tail forwarder; following code starts at 021E01B0.
 */
extern unsigned BOX2_UI_UpdateTopBarMove(char *p);
int BOX2_MAIN_UpdateWindowMove(char *p)
{
    return BOX2_UI_UpdateTopBarMove(p);
}
