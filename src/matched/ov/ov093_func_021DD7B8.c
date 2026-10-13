/*
 * function: HAND_ITEM_FlavorHeal
 * address:  0x021DD7B8
 * packet:   pkt_ov093_021DD7B8
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
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetNatureStatMod  0x020189D0  thumb
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 */
#include "../include/Obj07817.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int HAND_ITEM_GetParam(int a, int b);
struct QQ;
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *l, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *l, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern int POKE_TOOL_GetNatureStatMod(void *m, int b);
extern void BTL_CALC_MakeSickContFromKind(int a, void *b, void *out);

void HAND_ITEM_FlavorHeal(int a, u8 *b, int c, int *d, int e)
{
    void *m;
    u8 *p;
    if (*d == 0 && c == BTL_EVENT_GetVar(2)) {
        m = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 5, c);
        p[6] = c;
        *(u16 *)&((struct Obj07817 *)p)->f4 = BTL_CALC_DivideMaxHpMin1(m, HAND_ITEM_GetParam(a, 2));
        BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 908);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetFactorKey((void *)a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        if (POKE_TOOL_GetNatureStatMod(BTL_POKEPARAM_GetMon(m), e) == -1) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xc, c);
            p[0xf] = c;
            ((struct Obj07817 *)p)->f4 = 6;
            BTL_CALC_MakeSickContFromKind(6, m, p + 8);
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
        }
        *d = 1;
    }
}
