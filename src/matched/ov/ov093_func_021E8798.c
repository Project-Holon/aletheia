/*
 * function: HAND_COMMON_EventCounterMove
 * address:  0x021E8798
 * packet:   pkt_ov093_021E8798
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveQueueWithPos  0x021C8434  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_PushMoveQueueWithPos(u8 *p, int a, int b);

void HAND_COMMON_EventCounterMove(int u, void *a, int b, int d)
{
    u8 k;
    u16 m;
    int z;

    z = 4;
    if (b == BTL_EVENT_GetVar(4)) {
        if (BTL_EVENT_GetVar(0x4e) == 0) {
            if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(a, b)) == 0) {
                m = BTL_EVENT_GetVar(0x12);
                if (WAZA_TOOL_GetFlag(m, z) != 0) {
                    z = 1;
                    if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
                        k = BTL_EVENT_GetVar(3);
                        BTL_SERVER_FLOW_PushMoveQueueWithPos(a, b, k);
                        BTL_EVENT_OverwriteVar(0x51, z);
                    }
                }
            }
        }
    }
}
