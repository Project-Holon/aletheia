/*
 * unit:     yes
 * function: HAND_WAZA_AddSideEffect, HAND_WAZA_AddTransform
 * address:  0x021E556C
 * packet:   pkt_ov093_021E556C
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
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gTransformHandlers     0x021F2484  data   ov093  a4
 */
#include "../include/Obj13525.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 v; } Word;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gTransformHandlers[];

void HAND_WAZA_AddSideEffect(int a, void *b, int c, int d, u8 e, int f, Word g, u16 h)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x19, c);
        ((struct Obj13525 *)m)->f4 = f;
        m[0xc] = e;
        *(Word *)(m + 8) = g;
        BTL_SERVER_FLOW_InitMsgRecord(m + 0x10, 1, h);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0x10), e);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_AddTransform(int *p)
{
    *p = 1;
    return gTransformHandlers;
}
