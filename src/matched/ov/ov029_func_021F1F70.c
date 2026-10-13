/*
 * function: C_GEAR_GetBatteryFrame
 * address: 0x021F1F70
 * packet: pkt_ov029_021F1F70
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UI_GetPowerState 0x0203568C arm
 *   d_021F3520 0x021F3520 data a1
 */
typedef unsigned char u8;
extern int UI_GetPowerState(void);
extern const u8 d_021F3520[];
u8 C_GEAR_GetBatteryFrame(void)
{
    return d_021F3520[UI_GetPowerState()];
}
