/*
 * function: HAND_WAZA_BrickBreakRemoveScreens
 * address:  0x021E0850
 * packet:   pkt_ov093_021E0850
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   func_021E08E0  0x021E08E0  thumb  ov093
 *   func_021E08F0  0x021E08F0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int key);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern int func_021E08E0(int a, int b);
extern int func_021E08F0(int a, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_BrickBreakRemoveScreens(int a, void *b, int c)
{
    int t;
    u8 *p;
    u8 *q;
    unsigned i;

    if (c == BTL_EVENT_GetVar(3)) {
        t = (int)BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(4));
        if (func_021E08E0(t, 0) != 0 || func_021E08F0(t, 1) != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1a, c);
            p[7] = t;
            p[4] = 3;
            for (i = 1; i < 3; i++) {
                p[4 + i] = 0;
            }
            if (p[4] > 1) {
                p[5] |= 1;
            }
            if (p[4] > 1) {
                p[5] |= 2;
            }
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            q = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x3a, c);
            q[4] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(b, q);
        }
    }
}
