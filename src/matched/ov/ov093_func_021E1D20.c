/*
 * function: HAND_WAZA_PursuitQueueIntercept
 * address:  0x021E1D20
 * packet:   pkt_ov093_021E1D20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId  0x021C804C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById  0x021C8290  thumb  ov093
 *   BTL_SERVER_FLOW_AppendFrontOrder  0x021C831C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(int a, int b, u32 *out);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(u8 *p, int a, int b, void *item);
extern void BTL_SERVER_FLOW_AppendFrontOrder(u8 *p, int v);

void HAND_WAZA_PursuitQueueIntercept(int u, int a, int b)
{
    u32 x;
    u8 k;

    if (BTL_SERVER_FLOW_GetActionWordByPokeId(a, b, &x) != 0) {
        k = BTL_EVENT_GetVar(6);
        if (BTL_MAIN_IsPokeSamePair(k, b) == 0) {
            BTL_SERVER_FLOW_GetPokeViewPos((u8 *)a, k);
            BTL_SERVER_FLOW_GetPokeViewPos((u8 *)a, b);
            if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById((u8 *)a, b, k, 0) == 0)
                BTL_SERVER_FLOW_AppendFrontOrder((u8 *)a, b);
        }
    }
}
