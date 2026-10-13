/*
 * function: HAND_ITEM_HitBackAttacker
 * address:  0x021DE180
 * packet:   pkt_ov093_021DE180
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
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   HAND_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj10068.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int HAND_ITEM_GetParam(int a, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_HitBackAttacker(int a, void *b, int c, int *d)
{
    u8 *m;
    void *mon;
    u8 k;
    u8 j;

    if (c == BTL_EVENT_GetVar(2) && *d != 0) {
        k = *d - 1;
        mon = BTL_SERVER_FLOW_GetPokeParam(b, k);
        if (BTL_POKEPARAM_IsFainted(mon) == 0) {
            j = HAND_ITEM_GetParam(a, 2);
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
            m[6] = k;
            ((struct Obj10068 *)m)->f4 = BTL_CALC_DivideMaxHpMin1(mon, j);
            BTL_SERVER_FLOW_InitMsgRecord(m + 0xc, 2, 0x407);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), m[6]);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 0xc), BTL_EVENT_GetFactorKey((void *)a));
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
