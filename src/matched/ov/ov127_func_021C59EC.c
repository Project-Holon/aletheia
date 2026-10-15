/*
 * function: WF2DMAP_SCRDRAW_GetPointX
 * address: 0x021C59EC
 * packet: pkt_ov127_021C59EC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef signed short s16;
int WF2DMAP_SCRDRAW_GetPointX(const s16 *p) { return p[1]; }
