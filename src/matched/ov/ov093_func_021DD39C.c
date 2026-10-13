/*
 * unit: yes
 * function: HAND_ITEM_PushRecoverPp, HAND_ITEM_AddOranBerry
 * address: 0x021DD39C
 * packet: pkt_ov093_021DD39C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   HAND_ITEM_FindLastMoveEmptySlot 0x021DD338 thumb ov093
 *   HAND_ITEM_FindEmptyMoveSlot 0x021DD368 thumb ov093
 *   BTL_POKEPARAM_GetMoveCount 0x021D5448 thumb ov093
 *   BTL_POKEPARAM_GetMovePPLost 0x021D554C thumb ov093
 *   BTL_POKEPARAM_GetMoveId 0x021D54C0 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gOranBerryHandlers 0x021F1BB4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct QG;
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u8 HAND_ITEM_FindLastMoveEmptySlot(void *a, int b);
extern u8 HAND_ITEM_FindEmptyMoveSlot(void *a, int b);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u8 BTL_POKEPARAM_GetMovePPLost(u8 *p, u8 i);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
int HAND_ITEM_PushRecoverPp(int a, void *b, u8 c, int d, int e)
{
    void *m;
    u32 i;
    u32 n;
    u8 slot;
    u8 *r;
    m = BTL_SERVER_FLOW_GetPokeParam(b, c);
    slot = HAND_ITEM_FindLastMoveEmptySlot(b, c);
    if (slot == 4) {
        slot = HAND_ITEM_FindEmptyMoveSlot(b, c);
        if (slot == 4 && e) {
            n = BTL_POKEPARAM_GetMoveCount(m);
            for (i = 0; i < n; i++) {
                if (BTL_POKEPARAM_GetMovePPLost(m, i)) {
                    slot = i;
                    break;
                }
            }
        }
    }
    if (slot != 4) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 9, c);
        r[4] = 10;
        r[5] = c;
        r[6] = slot;
        r[7] = (r[7] & ~1) | 1;
        BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 0x38f);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), BTL_EVENT_GetFactorKey((void *)a));
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), BTL_POKEPARAM_GetMoveId(m, slot));
        BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        return 1;
    }
    return 0;
}
extern u8 gOranBerryHandlers[];
void *HAND_ITEM_AddOranBerry(int *p) { *p = 5; return gOranBerryHandlers; }
