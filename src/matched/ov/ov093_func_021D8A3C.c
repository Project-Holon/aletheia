/*
 * unit: yes
 * function: BTL_CALC_CompoundEyesBoostAccuracy, BTL_CALC_GetCompoundEyesHandlers
 * address: 0x021D8A3C
 * packet: pkt_ov093_021D8A3C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gCompoundEyesHandlers 0x021F0650 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern unsigned char gCompoundEyesHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int,int);

void BTL_CALC_CompoundEyesBoostAccuracy(int a, int b, int c)
{
    if(c==BTL_EVENT_GetVar(3)) BTL_EVENT_MultiplyVar(0x35,0x14CD);
}

void *BTL_CALC_GetCompoundEyesHandlers(int *p)
{
    *p = 1;
    return gCompoundEyesHandlers;
}
