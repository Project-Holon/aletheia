/*
 * unit: yes
 * function: HAND_ITEM_BlackSludge_HealOrDamage, HAND_ITEM_GetDestinyKnotHandlers
 * address: 0x021DEFC4
 * packet: pkt_ov093_021DEFC4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk 0x021C83D4 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   HAND_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos 0x021C8010 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gDestinyKnotHandlers 0x021F154C data a4
 */
#include "../include/Obj03702.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern int BTL_SERVER_FLOW_CheckShowdownThunk(u8 *p);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern int BTLV_CORE_HasByte(int x, int k);
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
void HAND_ITEM_BlackSludge_HealOrDamage(int a, void *b, int c)
{
    void *m;
    u8 *r;
    if (c == BTL_EVENT_GetVar(2) && BTL_SERVER_FLOW_CheckShowdownThunk(b) == 0) {
        m = BTL_SERVER_FLOW_GetPokeParam(b, c);
        if (BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(m), 3)) {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 5, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, HAND_ITEM_GetParam(a, 2));
            BTL_SERVER_FLOW_InitMsgRecord(r + 8, 2, 0x392);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 8), BTL_EVENT_GetFactorKey((void *)a));
            BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        } else {
            r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
            r[6] = c;
            ((struct Obj03702 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 8);
            r[7] |= 2;
            ((struct Obj03702 *)r)->f8 = 0x25f;
            r[10] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
            r[11] = 6;
            BTL_SERVER_FLOW_InitMsgRecord(r + 12, 2, 0x40e);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), c);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), BTL_EVENT_GetFactorKey((void *)a));
            BTL_SERVER_FLOW_CommitCmdRecord(b, r);
        }
    }
}
extern u8 gDestinyKnotHandlers[];
void *HAND_ITEM_GetDestinyKnotHandlers(int *p) { *p = 1; return gDestinyKnotHandlers; }
