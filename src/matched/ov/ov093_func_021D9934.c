/*
 * unit:     yes
 * function: HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun, HAND_TOKUSEI_GetSolarPowerHandlers
 * address:  0x021D9934
 * packet:   pkt_ov093_021D9934
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gSolarPowerHandlers     0x021F0930  data   ov093  a4
 */

typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
typedef unsigned char  u8;
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int WAZA_TOOL_GetDamageType(int a);
typedef signed int     s32;
extern void BTL_EVENT_MultiplyVar(int key, s32 m);
extern int gSolarPowerHandlers[];

void HAND_TOKUSEI_SolarPower_BoostSpecialAttackInSun(int a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk((u8 *)b) == 1) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(0x12)) == 2)
            BTL_EVENT_MultiplyVar(0x35, 0x1800);
    }
}

int *HAND_TOKUSEI_GetSolarPowerHandlers(int *p)
{
    *p = 2;
    return gSolarPowerHandlers;
}
