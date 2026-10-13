/*
 * function: HAND_WAZA_ChargeBoostElectricPower
 * address:  0x021E1F18
 * packet:   pkt_ov093_021E1F18
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_WAZA_ChargeBoostElectricPower(int u, int a, int b, int *p)
{
    if (*p == 2) {
        if (b == BTL_EVENT_GetVar(3)) {
            if (BTL_EVENT_GetVar(0x16) == 0xc)
                BTL_EVENT_MultiplyVar(0x31, 0x2000);
        }
    }
}
