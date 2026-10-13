/*
 * unit: yes
 * function: HAND_TOKUSEI_FriskShowOpponentItem, HAND_TOKUSEI_GetFriskHandlers, HAND_TOKUSEI_GetSturdyHandlers
 * address: 0x021DA624
 * packet: pkt_ov093_021DA624
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds 0x021C7D54 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gFriskHandlers 0x021F09B0 data a4
 *   gSturdyHandlers 0x021F0B00 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern u8 BTL_SERVER_FLOW_CollectOpponentPokeIds(u8 *p, u8 *k, u8 *out);
struct QI;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 BTL_CALC_Random(u32);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *, int, int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_TOKUSEI_FriskShowOpponentItem(int a, void *b, int c)
{
    u16 values[4];
    u8 buf[4];
    u8 n;
    u8 count;
    u8 i;
    u8 choice;
    u8 *p;
    void *q;
    if (c != BTL_EVENT_GetVar(2)) return;
    n = BTL_SERVER_FLOW_CollectOpponentPokeIds(b, (u8 *)c, buf);
    count = 0;
    for (i = 0; i < n; i++) {
        q = BTL_SERVER_FLOW_GetPokeParam(b, buf[i]);
        values[count] = BTL_POKEPARAM_GetItem(q);
        if (values[count] != 0) count++;
    }
    if (count == 0) return;
    choice = BTL_CALC_Random(count);
    BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x1b7);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), values[choice]);
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
}
extern int gFriskHandlers, gSturdyHandlers;
int *HAND_TOKUSEI_GetFriskHandlers(int *p) { *p = 2; return &gFriskHandlers; }
int *HAND_TOKUSEI_GetSturdyHandlers(int *p) { *p = 3; return &gSturdyHandlers; }
