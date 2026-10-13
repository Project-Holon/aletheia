/*
 * function: HAND_ITEM_EjectButtonUse
 * address:  0x021DFE88
 * packet:   pkt_ov093_021DFE88
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj21422.h"
typedef unsigned char u8;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_EjectButtonUse(int a, void *b, int c)
{
    char *p;
    char *q;

    if (c == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(b, c) != 0) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x19e);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        q = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x29, c);
        ((struct Obj21422 *)q)->f4C = c;
        BTL_SERVER_FLOW_CommitCmdRecord(b, q);
    }
}
