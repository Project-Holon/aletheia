/*
 * function: HAND_ITEM_RockyHelmetDamageReaction
 * address:  0x021DFABC
 * packet:   pkt_ov093_021DFABC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Rec {
    int pad00;
    u16 f04;
    u8 f06;
    u8 pad07[5];
    u8 f0c[1];
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int HAND_ITEM_GetParam(int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_ITEM_RockyHelmetDamageReaction(int a, int q, int id)
{
    Rec *r;
    void *m;
    int n;

    if (id != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(70) != 0)
        return;
    if (!WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(18), 0))
        return;
    r = (Rec *)BTL_SERVER_FLOW_AllocCmdRecord((void *)q, 7, id);
    r->f06 = BTL_EVENT_GetVar(3);
    m = BTL_SERVER_FLOW_GetPokeParam((int *)q, r->f06);
    n = (u8)HAND_ITEM_GetParam(a, 2);
    r->f04 = BTL_CALC_DivideMaxHpMin1(m, n);
    BTL_SERVER_FLOW_InitMsgRecord(r->f0c, 2, 424);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)r->f0c, r->f06);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)q, r);
}
