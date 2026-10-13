/*
 * function: HAND_WAZA_SecretPowerOnPrepareMove
 * address:  0x021E11B8
 * packet:   pkt_ov093_021E11B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   HAND_WAZA_SecretPowerGetGroundEffect  0x021E112C  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 */

typedef unsigned char u8;

extern int BTL_EVENT_GetVar(int key);
extern u8 HAND_WAZA_SecretPowerGetGroundEffect(int *a, u8 *p1, u8 *p2);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);

void HAND_WAZA_SecretPowerOnPrepareMove(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2))
        BTL_SERVER_FLOW_SetCurTurnStateFlag(b, HAND_WAZA_SecretPowerGetGroundEffect(b, 0, 0));
}
