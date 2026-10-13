/*
 * unit: yes
 * function: HAND_WAZA_TrickOnWazaExecute, HAND_WAZA_AddMagnitude
 * address: 0x021E37C0
 * packet: pkt_ov093_021E37C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E38F8 store-and-return stub included.
 * symbols:
 *   gMagnitudeHandlers 0x021F2E58 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTLV_CORE_CheckPartySlotCondition 0x021E86C8 thumb ov093
 *   HAND_COMMON_IsItemBoundToSpecies 0x021E8638 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int BTLV_CORE_CheckPartySlotCondition(void *, int);
extern int HAND_COMMON_IsItemBoundToSpecies(int, int);
extern u32 func_0202136C(u16 v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_WAZA_TrickOnWazaExecute(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u16 x;
    u16 y;
    int t;
    int u;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    k = BTL_EVENT_GetVar(6);
    if (BTLV_CORE_CheckPartySlotCondition(b, c) != 0) return;
    m = BTL_SERVER_FLOW_GetPokeParam(b, c);
    n = BTL_SERVER_FLOW_GetPokeParam(b, k);
    x = (int)BTL_POKEPARAM_GetItem(m);
    y = (int)BTL_POKEPARAM_GetItem(n);
    if (x == 0 && y == 0) return;
    t = BTL_POKEPARAM_GetSpecies(m);
    u = BTL_POKEPARAM_GetSpecies(n);
    if (func_0202136C(x) != 0) return;
    if (func_0202136C(y) != 0) return;
    if (HAND_COMMON_IsItemBoundToSpecies(t, y) != 0) return;
    if (HAND_COMMON_IsItemBoundToSpecies(u, x) != 0) return;
    if (HAND_COMMON_IsItemBoundToSpecies(t, x) != 0) return;
    if (HAND_COMMON_IsItemBoundToSpecies(u, y) != 0) return;
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 36, c);
    p[4] = k;
    BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 682);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
    if (y != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(p + 80, 2, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 80), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 80), y);
    }
    if (x != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(p + 44, 2, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 44), k);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 44), x);
    }
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
}
extern u32 gMagnitudeHandlers[];
u32 *HAND_WAZA_AddMagnitude(u32 *p)
{
    *p = 4;
    return gMagnitudeHandlers;
}
