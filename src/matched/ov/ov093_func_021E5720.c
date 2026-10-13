/*
 * function: HAND_WAZA_FutureSightArmDelayedAttack
 * address:  0x021E5720
 * packet:   pkt_ov093_021E5720
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_WAZA_ArmDelayedAttack  0x021E5784  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void HAND_WAZA_ArmDelayedAttack(void *a, void *b, int c, int d);

void HAND_WAZA_FutureSightArmDelayedAttack(void *a, void *b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(0xd);
        HAND_WAZA_ArmDelayedAttack(a, b, c, k);
    }
}
