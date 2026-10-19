/*
 * function: HAND_WAZA_AquaRingApplyEffect
 * address:  0x021E2188
 * packet:   pkt_ov093_021E2188
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10073.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_SICKCONT_MakeKind1Empty(void);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_AquaRingApplyEffect(int u, int a, int b)
{
    u8 *r;

    if (b == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)a, b), 0x23) == 0) {
            r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xc, b);
            ((struct Obj10073 *)r)->f4 = 0x23;
            ((struct Obj10073 *)r)->f8 = BTL_SICKCONT_MakeKind1Empty();
            r[0xf] = b;
            BTL_SERVER_FLOW_InitMsgRecord(r + 0x14, 2, 0x259);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0x14), b);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
        }
    }
}
