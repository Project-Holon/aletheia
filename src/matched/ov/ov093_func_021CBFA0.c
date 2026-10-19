/*
 * function: BTL_SERVER_FLOW_ItemEffectCheckSlotMessage
 * address:  0x021CBFA0
 * packet:   pkt_ov093_021CBFA0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   func_021CBFF8  0x021CBFF8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
typedef struct Word { u32 v; } Word;
extern Word BTL_SICKCONT_MakeKind2Index(int v);
extern int func_021CBFF8(int a, int b, Word c);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

int BTL_SERVER_FLOW_ItemEffectCheckSlotMessage(u8 *p, u8 *q)
{
    int m;
    u8 *w;
    Word t;
    m = BTL_MAIN_IsPokeIdInSecondPair(BTL_POKEPARAM_GetPokeId(q));
    t = BTL_SICKCONT_MakeKind2Index(5);
    if (func_021CBFF8(m, 3, t)) {
        w = BTL_SERVER_FLOW_AllocCmdRecord((char *)p, 4, 0x1f);
        BTL_SERVER_FLOW_InitMsgRecord(w + 4, 1, 0x88);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 4), m);
        BTL_SERVER_FLOW_CommitCmdRecord(p, w);
        return 1;
    }
    return 0;
}
