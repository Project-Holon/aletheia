/*
 * function: BTL_HANDLER_TOKUSEI_IllusionBreakOnAbilityChange
 * address: 0x021DCE18
 * packet: pkt_ov093_021DCE18
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_HANDLER_TOKUSEI_IllusionBreak 0x021DCE48 thumb ov093
 */
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_HANDLER_TOKUSEI_IllusionBreak(int,unsigned char *,int);
void BTL_HANDLER_TOKUSEI_IllusionBreakOnAbilityChange(int a,unsigned char *b,int c) { int k; k=BTL_EVENT_GetVar(16); if(k!=BTL_EVENT_GetFactorKey((void *)a) && c==BTL_EVENT_GetVar(2)) BTL_HANDLER_TOKUSEI_IllusionBreak(a,b,c); }
