/*
 * function: HAND_TOKUSEI_LiquidOoze_DamageAttacker
 * address:  0x021DB5C0
 * packet:   pkt_ov093_021DB5C0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07814.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_LiquidOoze_DamageAttacker(void *a, void *p, int id)
{
    u16 v;
    u8 *r;

    if (id == BTL_EVENT_GetVar(4)) {
        v = BTL_EVENT_GetVar(0x20);
        BTL_EVENT_OverwriteVar(0x20, 0);
        if (v != 0) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(p, 7, id);
            ((struct Obj07814 *)r)->f0 |= 0x800000;
            r[6] = BTL_EVENT_GetVar(3);
            ((struct Obj07814 *)r)->f4 = v;
            BTL_SERVER_FLOW_InitMsgRecord(r + 0xc, 2, 0x1c9);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0xc), r[6]);
            BTL_SERVER_FLOW_CommitCmdRecord(p, r);
        }
    }
}
