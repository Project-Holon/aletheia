/*
 * unit:     yes
 * function: HAND_WAZA_GastroAcidSuppressAbility, HAND_WAZA_GetRolePlayHandlers
 * address:  0x021E5870
 * packet:   pkt_ov093_021E5870
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
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gRolePlayHandlers     0x021F24F4  data   ov093  a4
 */
#include "../include/Obj13528.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef struct { u32 v; } Word;

extern Word BTLV_CORE_MakeSlotKind1Empty(void);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gRolePlayHandlers[];

void HAND_WAZA_GastroAcidSuppressAbility(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0xc, c);
        m[0xf] = k;
        ((struct Obj13528 *)m)->f4 = 0x10;
        *(Word *)(m + 8) = BTLV_CORE_MakeSlotKind1Empty();
        BTL_SERVER_FLOW_InitMsgRecord(m + 0x14, 2, 0x235);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0x14), k);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_GetRolePlayHandlers(int *p)
{
    *p = 1;
    return gRolePlayHandlers;
}
