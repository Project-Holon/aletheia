/*
 * function: HAND_TOKUSEI_AbsorbRaiseStat
 * address:  0x021DA96C
 * packet:   pkt_ov093_021DA96C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj04368.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char    s8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_TOKUSEI_AbsorbRaiseStat(void *a, int id, u32 e, int d)
{
    u8 *r;

    if (func_021D5D14(BTL_SERVER_FLOW_GetPokeParam(a, id), e, d) != 0) {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 14, id);
        r[0xf] = 1;
        r[0x10] = id;
        r[0xe] = 1;
        ((struct Obj04368 *)r)->f4 = e;
        r[0xc] = d;
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    } else {
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
        BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0xd2);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
