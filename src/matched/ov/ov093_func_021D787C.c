/*
 * function: BTL_CALC_SetRngState
 * address: 0x021D787C
 * packet: pkt_ov093_021D787C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6368 0x021F6368 data a4
 */
typedef struct { unsigned int v[6]; } Words;
extern Words d_021F6368;
void BTL_CALC_SetRngState(const Words *p) { d_021F6368 = *p; }
