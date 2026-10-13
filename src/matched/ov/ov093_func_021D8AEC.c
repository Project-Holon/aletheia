/*
 * function: BTL_CALC_BlockWeatherDamage
 * address: 0x021D8AEC
 * packet: pkt_ov093_021D8AEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
extern int BTL_EVENT_OverwriteVar(int,unsigned int);

void BTL_CALC_BlockWeatherDamage(int a, int b, int c, int d, unsigned char e)
{
    if(c==BTL_EVENT_GetVar(2) && BTL_EVENT_GetVar(0x32)>0 && e==BTL_EVENT_GetVar(0x39)) BTL_EVENT_OverwriteVar(0x41,1);
}
