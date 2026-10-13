/*
 * function: HAND_TOKUSEI_SnowCloakLowerAccuracy
 * address: 0x021D8AA8
 * packet: pkt_ov093_021D8AA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 */
extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern void BTL_EVENT_MultiplyVar(int,int);

void HAND_TOKUSEI_SnowCloakLowerAccuracy(int a, int b, int c)
{
    if(c==BTL_EVENT_GetVar(4) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)b)==3) BTL_EVENT_MultiplyVar(0x35,0xCCD);
}
