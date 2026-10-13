/*
 * unit: yes
 * function: HAND_WAZA_StockpileUseOnMoveEnd, HAND_WAZA_AddSwallow
 * address: 0x021E17DC
 * packet: pkt_ov093_021E17DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E18E0 store-and-return stub included.
 * symbols:
 *   gSwallowHandlers 0x021F2BE8 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_WAZA_StockpileUseOnMoveEnd(void *a, void *b, int c)
{
    void *m;
    int x;
    int y;
    int z;
    u8 *p;
    if (c != BTL_EVENT_GetVar(2)) return;
    m = BTL_SERVER_FLOW_GetPokeParam(b, c);
    x = BTL_POKEPARAM_GetCounter(m, 1);
    y = BTL_POKEPARAM_GetCounter(m, 2);
    z = BTL_POKEPARAM_GetCounter(m, 0);
    if (x != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 2;
        p[12] = -x;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 38, c);
        p[4] = c;
        p[5] = 1;
        p[6] = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
    if (y != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 4;
        p[12] = -y;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 38, c);
        p[4] = c;
        p[5] = 2;
        p[6] = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
    if (z != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 38, c);
        p[4] = c;
        p[5] = 0;
        p[6] = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 724);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
extern u32 gSwallowHandlers[];
u32 *HAND_WAZA_AddSwallow(u32 *p)
{
    *p = 3;
    return gSwallowHandlers;
}
