/*
 * unit: yes
 * function: HAND_WAZA_BestowGiveItem, HAND_WAZA_AddFinalGambit
 * address: 0x021E7B98
 * packet: pkt_ov093_021E7B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   HAND_COMMON_IsHeldItemBoundToOwnSpecies 0x021E869C thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   HAND_COMMON_IsItemBoundToSpecies 0x021E8638 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   d_021F2AE8 0x021F2AE8 data a4
 */
#include "../include/Obj07837.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u32 FILE_UTIL_IsMailItem(u16);
extern int HAND_COMMON_IsHeldItemBoundToOwnSpecies(void *a, int b);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern int HAND_COMMON_IsItemBoundToSpecies(int, int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *, u32);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F2AE8[];

void HAND_WAZA_BestowGiveItem(int a, int b, int c)
{
    u8 k;
    void *x;
    u16 h;
    u8 *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        x = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
        h = (int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam((int *)b, c));
        if (h != 0 && FILE_UTIL_IsMailItem(h) == 0 && (int)BTL_POKEPARAM_GetItem(x) == 0
            && HAND_COMMON_IsHeldItemBoundToOwnSpecies((void *)b, c) == 0 && HAND_COMMON_IsHeldItemBoundToOwnSpecies((void *)b, k) == 0
            && HAND_COMMON_IsItemBoundToSpecies(BTL_POKEPARAM_GetSpecies(x), h) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x20, c);
            p[6] = c;
            ((struct Obj07837 *)p)->f4 = 0;
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x20, c);
            p[6] = k;
            ((struct Obj07837 *)p)->f4 = h;
            BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x457);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), k);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), h);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}

int *HAND_WAZA_AddFinalGambit(int *p)
{
    *p = 2;
    return d_021F2AE8;
}
