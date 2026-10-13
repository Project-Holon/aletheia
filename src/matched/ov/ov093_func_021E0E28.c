/*
 * function: HAND_WAZA_CurseApply
 * address:  0x021E0E28
 * packet:   pkt_ov093_021E0E28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * BTLV_CORE_MakeSlotKind1Empty returns a one-word struct (Word): the by-value struct return
 * reserves a 4-byte stack temporary, which is the second slot of the original's
 * `sub sp,#8` frame. An int return keeps m in the push's r3 slot with no sub sp.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Word { unsigned int v; } Word;

typedef struct RecA {
    int pad00;
    int f04;
    Word f08;
    signed char f0c;
    u8 pad0d[2];
    u8 f0f;
    u8 f10;
} RecA;

typedef struct RecB {
    u32 f00;
    u8 f04;
    u8 pad05[2];
    u8 f07;
    u8 pad08[8];
    int f10;
} RecB;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasType(void *m, int k);
extern int func_021D59B4(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern Word BTLV_CORE_MakeSlotKind1Empty(void);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);

void HAND_WAZA_CurseApply(int a, void *q, int id)
{
    void *m;
    int flag;
    u8 k;
    RecA *r;
    RecB *s;

    if (id != BTL_EVENT_GetVar(3))
        return;
    m = BTL_SERVER_FLOW_GetPokeParam(q, id);
    flag = 0;
    if (BTL_POKEPARAM_HasType(m, 7)) {
        if (func_021D59B4(m, 13) > 0) {
            k = BTL_EVENT_GetVar(6);
            if (k != 31) {
                r = (RecA *)BTL_SERVER_FLOW_AllocCmdRecord(q, 12, id);
                r->f0f = k;
                r->f04 = 10;
                r->f08 = BTLV_CORE_MakeSlotKind1Empty();
                BTL_SERVER_FLOW_InitMsgRecord((u8 *)r + 0x14, 2, 1064);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)r + 0x14), id);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)r + 0x14), k);
                BTL_SERVER_FLOW_CommitCmdRecord(q, r);
                s = (RecB *)BTL_SERVER_FLOW_AllocCmdRecord(q, 8, id);
                s->f07 = id;
                s->f10 = -BTL_CALC_DivideMaxHpMin1(m, 2);
                s->f04 = 1;
                s->f00 |= 0x1000000;
                BTL_SERVER_FLOW_CommitCmdRecord(q, s);
            }
        }
        flag = 1;
    } else {
        r = (RecA *)BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 5;
        r->f0c = -1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = (RecA *)BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 1;
        r->f0c = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
        r = (RecA *)BTL_SERVER_FLOW_AllocCmdRecord(q, 14, id);
        r->f0f = 1;
        r->f10 = id;
        r->f04 = 2;
        r->f0c = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(q, r);
    }
    BTL_SERVER_FLOW_SetCurTurnStateFlag(q, flag);
}
