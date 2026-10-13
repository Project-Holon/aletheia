/*
 * unit:     yes
 * function: HAND_WAZA_PaybackDoublePowerIfTargetMoved, HAND_WAZA_EruptionGetHandlers
 * address:  0x021E2948
 * packet:   pkt_ov093_021E2948
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
 *   gEruptionHandlers     0x021F24A4  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void BTLV_CORE_EventScaleDamage(int n);
extern int gEruptionHandlers[];

void HAND_WAZA_PaybackDoublePowerIfTargetMoved(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(4)), 1))
            BTLV_CORE_EventScaleDamage(2);
    }
}

int *HAND_WAZA_EruptionGetHandlers(int *p)
{
    *p = 1;
    return gEruptionHandlers;
}
