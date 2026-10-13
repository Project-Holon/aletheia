/*
 * function: INTRUDE_FIELD_IsAtAreaEdge
 * address: 0x0217B930
 * packet: pkt_ov018_0217B930
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 */
int INTRUDE_FIELD_IsAtAreaEdge(int *p) { if (*p >= 0x348000 || *p <= 0xb8000) return 1; return 0; }
