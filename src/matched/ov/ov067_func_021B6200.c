/*
 * function: UI_SCENE_AdvancePhaseFrame
 * address: 0x021B6200
 * packet: pkt_ov067_021B6200
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: ov2139D80 receives the ov0676100 state object, reads its E byte via61FC and advances it here. Existing6144 is not a unit and lists neither helper.
 */
void UI_SCENE_AdvancePhaseFrame(unsigned char *p)
{
    p[14]++;
}
