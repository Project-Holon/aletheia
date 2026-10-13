/*
 * unit: yes
 * function: HAND_ITEM_StickyBarb_TurnEndDamage, HAND_ITEM_GetPowerWeightHandlers, HAND_ITEM_GetPowerBracerHandlers, HAND_ITEM_GetPowerBeltHandlers, HAND_ITEM_GetPowerLensHandlers, HAND_ITEM_GetPowerBandHandlers, HAND_ITEM_GetPowerAnkletHandlers
 * address: 0x021DF1B0
 * packet: pkt_ov093_021DF1B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos 0x021C8010 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gPowerWeightHandlers 0x021F138C data a4
 *   gPowerBracerHandlers 0x021F1434 data a4
 *   gPowerBeltHandlers 0x021F15A4 data a4
 *   gPowerLensHandlers 0x021F1554 data a4
 *   gPowerBandHandlers 0x021F15B4 data a4
 *   gPowerAnkletHandlers 0x021F15C4 data a4
 */
#include "../include/Obj05218.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int HAND_ITEM_GetParam(int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void HAND_ITEM_StickyBarb_TurnEndDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2)) {
        m = BTL_SERVER_FLOW_GetPokeParam(b, c);
        r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
        r[6] = c;
        ((struct Obj05218 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, HAND_ITEM_GetParam(a, 2));
        r[7] |= 2;
        ((struct Obj05218 *)r)->f8 = 0x25f;
        r[10] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        r[11] = 6;
        BTL_SERVER_FLOW_InitMsgRecord(r + 12, 2, 0x40e);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), BTL_EVENT_GetFactorKey((void *)a));
        BTL_SERVER_FLOW_CommitCmdRecord(b, r);
    }
}
extern u8 gPowerWeightHandlers[], gPowerBracerHandlers[], gPowerBeltHandlers[], gPowerLensHandlers[], gPowerBandHandlers[], gPowerAnkletHandlers[];
void *HAND_ITEM_GetPowerWeightHandlers(int *p) { *p = 1; return gPowerWeightHandlers; }
void *HAND_ITEM_GetPowerBracerHandlers(int *p) { *p = 1; return gPowerBracerHandlers; }
void *HAND_ITEM_GetPowerBeltHandlers(int *p) { *p = 1; return gPowerBeltHandlers; }
void *HAND_ITEM_GetPowerLensHandlers(int *p) { *p = 1; return gPowerLensHandlers; }
void *HAND_ITEM_GetPowerBandHandlers(int *p) { *p = 1; return gPowerBandHandlers; }
void *HAND_ITEM_GetPowerAnkletHandlers(int *p) { *p = 1; return gPowerAnkletHandlers; }
