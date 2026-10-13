/*
 * function: BTL_SERVER_FLOW_GetSideEffectEntry
 * address: 0x021C82D0
 * packet: pkt_ov093_021C82D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes alignment padding precede non-C veneer 021C82E4.
 * symbols:
 *   BTL_MAIN_GetPosParity 0x021B9AE0 thumb ov093
 *   func_021C82E4 0x021C82E4 thumb ov093
 */
typedef unsigned char u8;
extern u8 BTL_MAIN_GetPosParity(unsigned int);
extern int func_021C82E4(unsigned int, int);
int BTL_SERVER_FLOW_GetSideEffectEntry(int unused, unsigned int v, int k) { return func_021C82E4(BTL_MAIN_GetPosParity(v),k); }
