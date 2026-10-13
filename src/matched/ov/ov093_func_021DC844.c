/*
 * function: BTL_ABILITY_InfiltratorEnableSkip
 * address: 0x021DC844
 * packet: pkt_ov093_021DC844
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: second payload of BTL_EVENT_SetFactorSkipCheck is the unchanged callback word.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_ABILITY_InfiltratorSkipSideCondition 0x021DC820 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct QS { u8 pad[12]; u32 v; };
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_SetFactorSkipCheck(struct QS *, u32);
extern int BTL_ABILITY_InfiltratorSkipSideCondition(u8 *, int, int, int, u16, u8);
void BTL_ABILITY_InfiltratorEnableSkip(struct QS *a, int b, int c) { if (c == BTL_EVENT_GetVar(3)) BTL_EVENT_SetFactorSkipCheck(a, (u32)BTL_ABILITY_InfiltratorSkipSideCondition); }
