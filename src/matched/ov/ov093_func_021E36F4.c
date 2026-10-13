/*
 * unit: yes
 * function: HAND_WAZA_ThiefOnDamageEnd, HAND_WAZA_AddTrick
 * address: 0x021E36F4
 * packet: pkt_ov093_021E36F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E37B4 store-and-return stub included.
 * symbols:
 *   gTrickHandlers 0x021F2824 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTLV_CORE_CheckEitherSlotPair 0x021E86E8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
#include "../include/Obj10083.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
typedef unsigned short u16;
struct QI;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTLV_CORE_CheckEitherSlotPair(void *, int, int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_WAZA_ThiefOnDamageEnd(void *a, void *b, int c, int *d)
{
    u8 k;
    void *m;
    u8 *p;
    if (c != BTL_EVENT_GetVar(3)) return;
    if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(b, c)) != 0) return;
    if (*d != 0) return;
    k = BTL_EVENT_GetVar(6);
    if (k == 31) return;
    m = BTL_SERVER_FLOW_GetPokeParam(b, k);
    if (BTL_POKEPARAM_GetItem(m) == 0) return;
    if (BTLV_CORE_CheckEitherSlotPair(b, c, k) != 0) return;
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 36, c);
    p[4] = k;
    BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 1057);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), k);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_POKEPARAM_GetItem(m));
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 58, c);
    ((struct Obj10083 *)p)->f0 |= 0x1000000;
    p[4] = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
}
extern u32 gTrickHandlers[];
u32 *HAND_WAZA_AddTrick(u32 *p)
{
    *p = 1;
    return gTrickHandlers;
}
