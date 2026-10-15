/*
 * function: WF2DMAP_SCRDRAW_SetPoint
 * address: 0x021C59DC
 * packet: pkt_ov127_021C59DC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef signed short s16;
void WF2DMAP_SCRDRAW_SetPoint(s16 *p, s16 a, s16 b) { p[0]=a; p[1]=b; }
