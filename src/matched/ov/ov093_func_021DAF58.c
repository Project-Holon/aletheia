/*
 * function: HAND_TOKUSEI_FlashFireAbsorbFire
 * address:  0x021DAF58
 * packet:   pkt_ov093_021DAF58
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_AbsorbCheckMoveType  0x021DA8A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj13470.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int HAND_TOKUSEI_AbsorbCheckMoveType(int a, int b, int c);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_TOKUSEI_FlashFireAbsorbFire(int unused, void *a, int id)
{
    u8 *r;

    if (HAND_TOKUSEI_AbsorbCheckMoveType((int)a, id, 9) != 0) {
        BTL_SERVER_FLOW_PushCmdRecord(a, 2, id);
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(a, id), 13) == 0) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
            BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x1ab);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 0x17, id);
            r[8] = id;
            ((struct Obj13470 *)r)->f4 = 13;
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        } else {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
            BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        }
        BTL_SERVER_FLOW_PushCmdRecord(a, 3, id);
    }
}
