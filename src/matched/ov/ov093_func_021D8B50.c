/*
 * unit: yes
 * function: HAND_TOKUSEI_FilterHalveSuperEffective, HAND_TOKUSEI_GetFilterHandlers
 * address: 0x021D8B50
 * packet: pkt_ov093_021D8B50
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gFilterHandlers 0x021F07C0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern unsigned char gFilterHandlers[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_CALC_SummarizeTypeAffinity(int);
extern void BTL_EVENT_MultiplyVar(int,int);

void HAND_TOKUSEI_FilterHalveSuperEffective(int a, int b, int c)
{
    if(c==BTL_EVENT_GetVar(4) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(0x38))==2) BTL_EVENT_MultiplyVar(0x35,0xC00);
}

void *HAND_TOKUSEI_GetFilterHandlers(int *p)
{
    *p = 1;
    return gFilterHandlers;
}
