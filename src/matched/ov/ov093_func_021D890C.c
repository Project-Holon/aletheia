/*
 * function: BTL_CALC_SlowStartHalveAttack
 * address: 0x021D890C
 * packet: pkt_ov093_021D890C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int WAZA_TOOL_GetDamageType(int a);
extern void BTL_EVENT_MultiplyVar(int,int);

void BTL_CALC_SlowStartHalveAttack(int a, int b, int c, int *d)
{
    if(c==BTL_EVENT_GetVar(3) && d[3]!=0 && WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(0x12))==1) BTL_EVENT_MultiplyVar(0x35,0x800);
}
