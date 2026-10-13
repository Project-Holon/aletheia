/*
 * file:     unit_021E7D00.c
 * unit:     yes
 * function: func_021E7D00, func_021E7D48, func_021E7D54
 * address:  0x021E7D00
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
 *   func_0689D098  0x0689D098  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnRecord  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   d_021F28C8     0x021F28C8  data   ov093  a4
 */
#include "../../matched/include/Obj21544.h"

struct S;
struct Q7;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u8 *BTL_SERVER_FLOW_GetTurnRecord(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct Q7 *p);
extern int func_0689D098(int a, int b, int c);
void func_021E7D00(int a, u8 *b, int c);
int *func_021E7D48(int *p);
void func_021E7D54(void *a, void *b, int c);
extern int d_021F28C8[];


void func_021E7D00(int a, u8 *b, int c)
{
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x31, c);
        p[4] = BTL_EVENT_GetVar(6);
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 1131);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), p[4]);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}


int *func_021E7D48(int *p)
{
    *p = 2;
    return d_021F28C8;
}


void func_021E7D54(void *a, void *b, int c)
{
    int x;
    u16 y;
    u8 *p;
    if (c == BTL_EVENT_GetVar(2)) {
        x = (int)BTL_SERVER_FLOW_GetTurnRecord((u8 *)((int)b));
        y = BTL_EVENT_GetFactorKey(a);
        if (func_0689D098(x, y, BTL_SERVER_FLOW_GetTurnCount(b)) == 1) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x30, c);
            ((struct Obj21544 *)p)->f4 = y;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
    }
}
