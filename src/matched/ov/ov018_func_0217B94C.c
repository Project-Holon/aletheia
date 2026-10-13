/*
 * function: INTRUDE_FIELD_IsInEdgeMargin
 * address: 0x0217B94C
 * packet: pkt_ov018_0217B94C
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
int INTRUDE_FIELD_IsInEdgeMargin(int *p) { if (*p > 0x308000 || *p < 0xe8000) return 1; return 0; }
