/*
 * function: HAND_TOKUSEI_RunAway_ShowEscapeMessage
 * address:  0x021DB0E4
 * packet:   pkt_ov093_021DB0E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_COMMON_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_SetMsgRecordSe  0x021C888C  thumb  ov093
 */
#include "../include/Obj21319.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int HAND_COMMON_EventTrySetFlagIfAttacker(int a, int b, int c);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_SetMsgRecordSe(u8 *p, u32 v);

void HAND_TOKUSEI_RunAway_ShowEscapeMessage(int unused, void *a, int id)
{
    u8 *r;

    if (HAND_COMMON_EventTrySetFlagIfAttacker(unused, (int)a, id) != 0) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
        ((struct Obj21319 *)r)->f0 |= 0x800000;
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 1, 0x48);
        BTL_SERVER_FLOW_SetMsgRecordSe(r + 4, 0x56a);
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
