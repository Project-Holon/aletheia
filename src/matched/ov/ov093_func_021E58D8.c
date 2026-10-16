/*
 * function: HAND_WAZA_RolePlayCopyAbility
 * address:  0x021E58D8
 * packet:   pkt_ov093_021E58D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   POKETRADE_2D_LoadMainPalette  0x021E5958  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10096.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int POKETRADE_2D_LoadMainPalette(u16 v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, unsigned int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_RolePlayCopyAbility(int a, int b, int c)
{
    u8 *m;
    u8 k;
    int n;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        n = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam((int *)b, k), 0x10);
        if (POKETRADE_2D_LoadMainPalette(n) == 0) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord((void *)b, 0x1f, c);
            m[6] = c;
            ((struct Obj10096 *)m)->f4 = n;
            BTL_SERVER_FLOW_InitMsgRecord(m + 0xc, 2, 0x26b);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), k);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), ((struct Obj10096 *)m)->f4);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, m);
        }
    }
}
