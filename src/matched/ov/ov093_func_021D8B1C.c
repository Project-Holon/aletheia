/*
 * unit: yes
 * function: BTL_CALC_TintedLensDoubleResisted, BTL_CALC_GetTintedLensHandlers
 * address: 0x021D8B1C
 * packet: pkt_ov093_021D8B1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gTintedLensHandlers 0x021F0738 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern unsigned char gTintedLensHandlers[];
extern int BTL_EVENT_GetVar(int);
extern int BTL_CALC_SummarizeTypeAffinity(int);
extern void BTL_EVENT_MultiplyVar(int,int);

void BTL_CALC_TintedLensDoubleResisted(int a, int b, int c)
{
    if(c==BTL_EVENT_GetVar(3) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(0x38))==3) BTL_EVENT_MultiplyVar(0x35,0x2000);
}

void *BTL_CALC_GetTintedLensHandlers(int *p)
{
    *p = 1;
    return gTintedLensHandlers;
}
