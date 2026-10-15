/*
 * function: WIFIBATTLEMATCH_NET_CompExit
 * address: 0x021D905C
 * packet: pkt_ov175_021D905C
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 */
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
void WIFIBATTLEMATCH_NET_CompExit(unsigned sys) {WIFIBATTLEMATCH_UTIL_ClearCallback(sys);}
