/*
 * function: HAND_WAZA_SuckerPunchCheckNoEffect
 * address:  0x021E1C8C
 * packet:   pkt_ov093_021E1C8C
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
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId  0x021C804C  thumb  ov093
 *   BTL_ACTION_GetFightMove  0x021D8340  thumb  ov093
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *
 * The 12-byte tail (movs r1,#3; str r1,[r0]; ldr r0,[pc]; bx lr; .word) is an
 * unlabelled follower stub, not part of this function.
 * Lever: q = BTL_SERVER_FLOW_GetPokeParam(...) bound to a local before `ok = 0` keeps the
 * `movs r4, #0` between the argument setup and the BTL_POKEPARAM_TestTurnFlag call.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct UtilWork;
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern int BTL_SERVER_FLOW_GetActionWordByPokeId(int a, int b, u32 *out);
extern u32 BTL_ACTION_GetFightMove(u32 *m);
extern u32 WAZA_TOOL_IsDamaging(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);

void HAND_WAZA_SuckerPunchCheckNoEffect(int u, int a, int b)
{
    u32 buf;
    u8 k;
    int ok;
    void *q;
    u32 m;

    if (b == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        q = BTL_SERVER_FLOW_GetPokeParam((int *)a, k);
        ok = 0;
        if (BTL_POKEPARAM_TestTurnFlag(q, 3) == 0) {
            if (BTL_SERVER_FLOW_GetActionWordByPokeId(a, k, &buf) != 0 && (m = BTL_ACTION_GetFightMove(&buf)) != 0 && WAZA_TOOL_IsDamaging((void *)m) != 0)
                ok = 1;
        }
        if (ok == 0) {
            if ((m = BTL_ACTION_GetFightMove(&buf)) == 0 || WAZA_TOOL_IsDamaging((void *)m) == 0) {
                if (BTL_EVENT_OverwriteVar(0x40, 1) != 0)
                    BTL_SERVER_FLOW_InitMsgRecord((void *)BTL_EVENT_GetVar(0x3f), 1, 0x47);
            }
        }
    }
}
