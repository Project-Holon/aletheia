/*
 * unit: yes
 * function: HAND_WAZA_GuardSwapOnUncategorizedMove, HAND_WAZA_AddPowerTrick
 * address: 0x021E4EC4
 * packet: pkt_ov093_021E4EC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gPowerTrickHandlers 0x021F26BC data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern int gPowerTrickHandlers[];

void HAND_WAZA_GuardSwapOnUncategorizedMove(int unused, void *s, int k)
{
    u8 v;
    void *a;
    void *b;
    u32 x;
    u32 y;
    u8 *p;
    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        a = BTL_SERVER_FLOW_GetPokeParam(s, v);
        b = BTL_SERVER_FLOW_GetPokeParam(s, k);
        x = func_021D59B4(b, 2);
        y = func_021D59B4(b, 4);
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 15, k);
        p[4] = k;
        p[5] = func_021D59B4(b, 1);
        p[7] = func_021D59B4(b, 3);
        p[6] = func_021D59B4(a, 2);
        p[8] = func_021D59B4(a, 4);
        p[9] = func_021D59B4(b, 5);
        p[10] = func_021D59B4(b, 6);
        p[11] = func_021D59B4(b, 7);
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 15, k);
        p[4] = v;
        p[5] = func_021D59B4(a, 1);
        p[7] = func_021D59B4(a, 3);
        p[6] = x;
        p[8] = y;
        p[9] = func_021D59B4(a, 5);
        p[10] = func_021D59B4(a, 6);
        p[11] = func_021D59B4(a, 7);
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 4, k);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 679);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
    }
}

int *HAND_WAZA_AddPowerTrick(int *p)
{
    *p = 1;
    return gPowerTrickHandlers;
}
