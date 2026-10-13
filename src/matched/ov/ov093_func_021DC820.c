/*
 * function: HAND_TOKUSEI_InfiltratorSkipSideCondition
 * address: 0x021DC820
 * packet: pkt_ov093_021DC820
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: scalar u16/u8 stack inputs; named result preserves cmp operand order.
 * symbols:
 *   BTL_EVENT_GetFactorPokeId 0x021D70AC thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 BTL_EVENT_GetFactorPokeId(u8 *);
extern u8 BTL_MAIN_IsPokeIdInSecondPair(unsigned int);
int HAND_TOKUSEI_InfiltratorSkipSideCondition(u8 *a, int b, int c, int d, u16 e, u8 f) { u8 result; if (c == 2) { result = BTL_MAIN_IsPokeIdInSecondPair(BTL_EVENT_GetFactorPokeId(a)); if (result != f && e <= 3) return 1; } return 0; }
