/*
 * function: HAND_ITEM_GetGripClawHandlers
 * address: 0x021DED1C
 * packet: pkt_ov093_021DED1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGripClawHandlers 0x021F1384 data a4
 */
extern int gGripClawHandlers;
int *HAND_ITEM_GetGripClawHandlers(int *p) { *p=1; return &gGripClawHandlers; }
