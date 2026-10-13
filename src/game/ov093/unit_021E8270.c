/*
 * file:     unit_021E8270.c
 * unit:     yes
 * function: func_021E8270, func_021E82A0, func_021E82AC, func_021E8304, func_021E8310
 * address:  0x021E8270
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689D0C8  0x0689D0C8  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F2814     0x021F2814  data   ov093  a4
 *   BTL_SERVER_FLOW_GetTurnRecord  0x021C812C  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   d_021F27E4     0x021F27E4  data   ov093  a4
 */
struct QQ;
struct S;
struct Q7;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u8 *BTL_SERVER_FLOW_GetTurnRecord(u8 *p);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct Q7 *p);
extern int func_0689D0C8(int a, int b);
extern void BTL_EVENT_MultiplyVar(int a, int b);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(char *p, int x);
void func_021E8270(int a, void *b, int c);
int *func_021E82A0(int *p);
void func_021E82AC(void *a, void *b, int c);
int *func_021E8304(int *p);
void func_021E8310(void *a, void *b, int c);
extern int d_021F2814[];
extern int d_021F27E4[];


void func_021E8270(int a, void *b, int c)
{
    int v;

    if (c == BTL_EVENT_GetVar(3) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(b) == 1) {
        v = BTL_EVENT_GetVar(0x20);
        if (v == 1)
            v++;
        BTL_EVENT_OverwriteVar(0x20, v);
    }
}


int *func_021E82A0(int *p)
{
    *p = 1;
    return d_021F2814;
}


void func_021E82AC(void *a, void *b, int c)
{
    u8 *p;
    int v;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetFactorKey(a) == 0x229)
            v = 0x35f;
        else
            v = 0x362;
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, (u16)v);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}


int *func_021E8304(int *p)
{
    *p = 1;
    return d_021F27E4;
}


void func_021E8310(void *a, void *b, int c)
{
    int m;
    int t;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (int)BTL_SERVER_FLOW_GetTurnRecord(b);
        switch (BTL_EVENT_GetFactorKey(a)) {
        case 0x22e:
            t = 0x22f;
            break;
        case 0x22f:
            t = 0x22e;
            break;
        default:
            t = 0;
            break;
        }
        if (t != 0 && t == func_0689D0C8(m, BTL_SERVER_FLOW_GetTurnCount(b))) {
            BTL_EVENT_MultiplyVar(0x31, 0x2000);
            BTL_SERVER_FLOW_SetCurTurnStateFlag(b, 1);
        }
    }
}
