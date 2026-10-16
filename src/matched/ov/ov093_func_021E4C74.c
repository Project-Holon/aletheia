/*
 * unit: yes
 * function: HAND_WAZA_HeartSwapOnUncategorizedMove, HAND_WAZA_AddPowerSwap
 * address: 0x021E4C74
 * packet: pkt_ov093_021E4C74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gPowerSwapHandlers 0x021F2724 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *p, int b);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern int gPowerSwapHandlers[];

void HAND_WAZA_HeartSwapOnUncategorizedMove(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 *t;
    int i;
    u8 *p;
    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        a = BTL_SERVER_FLOW_GetPokeParam(s, v);
        b = BTL_SERVER_FLOW_GetPokeParam(s, k);
        t = (u32 *)BTL_SERVER_FLOW_GetScratchBuffer(s, 28);
        for (i = 1; i <= 7; i++) {
            t[i - 1] = BTL_POKEPARAM_GetValue(b, i);
        }
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 15, k);
        p[4] = k;
        p[5] = BTL_POKEPARAM_GetValue(a, 1);
        p[6] = BTL_POKEPARAM_GetValue(a, 2);
        p[7] = BTL_POKEPARAM_GetValue(a, 3);
        p[8] = BTL_POKEPARAM_GetValue(a, 4);
        p[9] = BTL_POKEPARAM_GetValue(a, 5);
        p[10] = BTL_POKEPARAM_GetValue(a, 6);
        p[11] = BTL_POKEPARAM_GetValue(a, 7);
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 15, k);
        p[4] = v;
        p[5] = t[0];
        p[6] = t[1];
        p[7] = t[2];
        p[8] = t[3];
        p[9] = t[4];
        p[10] = t[5];
        p[11] = t[6];
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 4, k);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 673);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
    }
}

int *HAND_WAZA_AddPowerSwap(int *p)
{
    *p = 1;
    return gPowerSwapHandlers;
}
