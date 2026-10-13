/*
 * function: HAND_WAZA_ProtectResetStreakAfterOtherMove
 * address:  0x021E3B14
 * packet:   pkt_ov093_021E3B14
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
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gProtectMoveIds     0x021F284C  data   a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
struct QL;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *p);
extern const u16 gProtectMoveIds[];

void HAND_WAZA_ProtectResetStreakAfterOtherMove(int u, void *a, int c)
{
    unsigned i;
    int r;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        r = BTL_POKEPARAM_GetLastUsedMoveId(BTL_SERVER_FLOW_GetPokeParam(a, c));
        for (i = 0; i < 5; i++) {
            if (r == gProtectMoveIds[i])
                return;
        }
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x26, c);
        p[4] = c;
        p[5] = 3;
        p[6] = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
