/*
 * function: HAND_ITEM_FlameOrbBurnHolderOnTurnEnd
 * address:  0x021DF640
 * packet:   pkt_ov093_021DF640
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Word { u32 v; } Word;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    u8 f0c;
    u8 pad0d[2];
    u8 id;
    u8 pad10[4];
    u8 f14[8];
    u32 f1c;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern Word BTL_CALC_MakeDefaultSickCont(int x);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_ITEM_FlameOrbBurnHolderOnTurnEnd(void *self, void *q, int id)
{
    Rec *r;

    if (id != BTL_EVENT_GetVar(2))
        return;
    r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord(q, 12, id);
    r->f04 = 4;
    r->f08 = BTL_CALC_MakeDefaultSickCont(4);
    r->f0c = 0;
    r->id = id;
    r->f1c = BTL_EVENT_GetFactorKey(self);
    BTL_SERVER_FLOW_InitMsgRecord(r->f14, 2, 0x102);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)r->f14, id);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)r->f14, BTL_EVENT_GetFactorKey(self));
    BTL_SERVER_FLOW_CommitCmdRecord(q, r);
}
