/*
 * function: HAND_ITEM_ToxicOrbPoisonHolderOnTurnEnd
 * address:  0x021DF594
 * packet:   pkt_ov093_021DF594
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Index15  0x021E8A58  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec {
    int f00;
    int f04;
    u32 f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
struct QQ;
extern int BTLV_CORE_MakeSlotKind1Index15(void);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_ITEM_ToxicOrbPoisonHolderOnTurnEnd(void *self, void *q, int id)
{
    Rec *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord(q, 12, id);
    r->f04 = 5;
    r->f08 = BTLV_CORE_MakeSlotKind1Index15();
    r->f0c = 0;
    r->id = id;
    BTL_SERVER_FLOW_InitMsgRecord((u8 *)r + 0x14, 2, 0xf0);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)r + 0x14), id);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)r + 0x14), BTL_EVENT_GetFactorKey(self));
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
