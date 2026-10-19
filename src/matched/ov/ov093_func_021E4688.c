/*
 * function: HAND_WAZA_EncoreAddSick
 * address:  0x021E4688
 * packet:   pkt_ov093_021E4688
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   func_021E4738  0x021E4738  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind2  0x021E896C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastSelectedMoveId(u8 *q);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int func_021E4738(int w);
struct UtilWork;
extern int BTL_POKEPARAM_GetMovePPById(struct UtilWork *p, int id);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef struct Word { u32 v; } Word;
typedef enum { K_0 } KType;
struct Rec { u32 f0; u32 f4; Word f8; u8 fc; u8 fd; u8 fe; u8 ff; };

extern Word BTL_SICKCONT_MakeKind2(int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_EncoreAddSick(int a0, u8 *s, int k)
{
    KType c = 3;
    u8 v;
    u8 *q;
    int w;
    struct Rec *e;

    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        q = BTL_SERVER_FLOW_GetPokeParam((int *)s, v);
        w = BTL_POKEPARAM_GetLastSelectedMoveId(q);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)q, 0x17) == 0 && func_021E4738(w) == 0 && BTL_POKEPARAM_GetMovePPById((struct UtilWork *)q, w) != 0) {
            if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)q, 1) != 0)
                c = (u8)(c + 1);
            e = (struct Rec *)BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 12, k);
            e->f4 = 0x17;
            e->f8 = BTL_SICKCONT_MakeKind2(c, w);
            e->ff = v;
            e->fc = 0;
            BTL_SERVER_FLOW_InitMsgRecord((u8 *)e + 0x14, 2, 559);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)e + 0x14), v);
            BTL_SERVER_FLOW_CommitCmdRecord(s, (u8 *)e);
        }
    }
}
