/*
 * unit:     yes
 * function: HAND_WAZA_AssuranceOnWazaPower, HAND_WAZA_AddLowKick
 * address:  0x021E2E90
 * packet:   pkt_ov093_021E2E90
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   gLowKickHandlers     0x021F24CC  data  ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void BTLV_CORE_EventScaleDamage(int n);
extern u8 gLowKickHandlers[];

void HAND_WAZA_AssuranceOnWazaPower(int u, void *p, int k)
{
    if (k == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(p, (u8)BTL_EVENT_GetVar(4)), 2) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}

u8 *HAND_WAZA_AddLowKick(int *p)
{
    *p = 1;
    return gLowKickHandlers;
}
