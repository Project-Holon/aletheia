/*
 * function: LIVEBATTLEMATCH_FLOW_End
 * address: 0x0217BBD4
 * packet: pkt_ov176_0217BBD4
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 */
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
void LIVEBATTLEMATCH_FLOW_End(int p) {WIFIBATTLEMATCH_UTIL_ClearCallback(p);}
