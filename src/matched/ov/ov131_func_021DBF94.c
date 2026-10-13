/*
 * function: P_STA_RIBBON_GetRibbonDescMsg
 * address: 0x021DBF94
 * packet: pkt_ov131_021DBF94
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DC302 0x021DC302 data
 */
struct R { unsigned short v; unsigned char pad[14]; };
extern struct R d_021DC302[];
unsigned int P_STA_RIBBON_GetRibbonDescMsg(int i) {
 return d_021DC302[i].v;
}
