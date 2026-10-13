/*
 * function: HAND_TOKUSEI_SlowStartBegin
 * address:  0x021D8974
 * packet:   pkt_ov093_021D8974
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21270.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_SlowStartBegin(void *a, int b, int c, int *d)
{
    u8 *p;

    d[0] = 1;
    d[1] = 0;
    d[2] = 0;
    d[3] = 1;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    ((struct Obj21270 *)p)->f0 |= 4 << 21;
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x1f0);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
