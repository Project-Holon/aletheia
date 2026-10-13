/*
 * function: HAND_WAZA_DestinyBondOnFaint
 * address:  0x021E6728
 * packet:   pkt_ov093_021E6728
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
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   func_021E67E4  0x021E67E4  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_EVENT_MarkFactorDead  0x021D7090  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int func_021E67E4(u32 v);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
struct Node;
extern void BTL_EVENT_MarkFactorDead(u8 *p);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_WAZA_DestinyBondOnFaint(int m, void *a, u32 b)
{
    u8 *e;
    void *x;
    u8 k;

    if (b == BTL_EVENT_GetVar(4)) {
        if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(a, b)) != 0) {
            if (func_021E67E4((u16)BTL_EVENT_GetVar(0x12)) == 0) {
                k = BTL_EVENT_GetVar(3);
                x = BTL_SERVER_FLOW_GetPokeParam(a, k);
                if (BTL_MAIN_IsPokeSamePair(b, k) == 0 && BTL_POKEPARAM_IsFainted(x) == 0) {
                    BTL_EVENT_MarkFactorDead((u8 *)m);
                    e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x13, b);
                    e[4] = b;
                    e[5] = 1;
                    BTL_SERVER_FLOW_CommitCmdRecord(a, e);
                    e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0x13, b);
                    e[4] = BTL_EVENT_GetVar(3);
                    BTL_SERVER_FLOW_InitMsgRecord(e + 8, 2, 0x275);
                    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(e + 8), b);
                    BTL_SERVER_FLOW_CommitCmdRecord(a, e);
                }
            }
            BTL_EVENT_RemoveFactor((struct Node *)m);
        }
    }
}
