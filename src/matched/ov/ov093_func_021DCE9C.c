/*
 * function: BTL_HANDLER_TOKUSEI_VictoryStarBoostAccuracy
 * address: 0x021DCE9C
 * packet: pkt_ov093_021DCE9C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void BTL_EVENT_MultiplyVar(int,int);
void BTL_HANDLER_TOKUSEI_VictoryStarBoostAccuracy(int a,int b,unsigned int c) { unsigned char k; k=BTL_EVENT_GetVar(3); if(func_021B9A24(c,k)) BTL_EVENT_MultiplyVar(53,4506); }
