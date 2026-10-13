/*
 * function: BTL_TOKUSEI_WeatherLock_SetFailFlag
 * address: 0x021D9830
 * packet: pkt_ov093_021D9830
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb
 */

typedef unsigned int u32;
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
void BTL_TOKUSEI_WeatherLock_SetFailFlag(void);

void BTL_TOKUSEI_WeatherLock_SetFailFlag(void)
{
    BTL_EVENT_OverwriteVar(65, 1);
}
