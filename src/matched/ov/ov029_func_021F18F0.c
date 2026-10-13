/*
 * function: C_GEAR_OnButtonEvent
 * address: 0x021F18F0
 * packet: pkt_ov029_021F18F0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   C_GEAR_IsAnyIndicatorShown 0x021F2DA8 thumb ov029
 *   C_GEAR_HandleButton 0x021F1758 thumb ov029
 */
typedef unsigned char u8;
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
extern void C_GEAR_HandleButton(u8 *p, int key);
void C_GEAR_OnButtonEvent(int key, int flag, u8 *p)
{
    if (C_GEAR_IsAnyIndicatorShown(p) == 0 && flag == 0)
        C_GEAR_HandleButton(p, key);
}
