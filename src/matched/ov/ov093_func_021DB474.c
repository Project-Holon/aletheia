/*
 * function: HAND_TOKUSEI_Redirect_ShowMessage
 * address:  0x021DB474
 * packet:   pkt_ov093_021DB474
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 */
#include "../include/Obj21327.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021E85F8(int id);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);

void HAND_TOKUSEI_Redirect_ShowMessage(int unused, void *a, int id, int *f)
{
    u8 *r;

    if (*f != 0) {
        if (func_021E85F8(id) != 0) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(a, 4, id);
            ((struct Obj21327 *)r)->f0 |= 0x800000;
            BTL_SERVER_FLOW_InitMsgRecord(r + 4, 2, 0x1c0);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 4), id);
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        }
        *f = 0;
    }
}
