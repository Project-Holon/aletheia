/*
 * function: HAND_WAZA_WeatherBallOnWazaTypeCheck
 * address:  0x021E2F48
 * packet:   pkt_ov093_021E2F48
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);

void HAND_WAZA_WeatherBallOnWazaTypeCheck(int u, void *p, int key)
{
    int two = 2;
    if (key == BTL_EVENT_GetVar(two)) {
        int s = BTL_SERVER_FLOW_GetEffectiveWeatherThunk(p);
        u8 v = BTL_EVENT_GetVar(0x16);
        int r = 0;
        switch (s) {
        case 1: v = 9; r = 1; break;
        case 2: v = 10; r = 4; break;
        case 4: v = 5; r = 3; break;
        case 3: v = 14; r = two; break;
        }
        BTL_EVENT_OverwriteVar(0x16, v);
        BTL_SERVER_FLOW_SetCurTurnStateFlag(p, r);
    }
}
