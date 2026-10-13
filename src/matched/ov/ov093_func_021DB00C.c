/*
 * unit: yes
 * function: HAND_TOKUSEI_BadDreamsHurtSleepers, HAND_TOKUSEI_GetBadDreamsHandlers
 * address: 0x021DB00C
 * packet: pkt_ov093_021DB00C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke 0x021C7D00 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gBadDreamsHandlers 0x021F07E8 data a4
 * The unit includes the store-return follower; labelled 021DB0DC is excluded.
 * An 8-bit candidate count keeps its immediate spill/reload; m precedes n
 * in the declaration list to place those spills at +8 and +4 respectively.
 */
#include "../include/Obj13471.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void HAND_TOKUSEI_BadDreamsHurtSleepers(int a, void *b, int c)
{
    u8 list[4];
    void *m;
    u8 n;
    int flag;
    u8 *r;
    u8 i;
    if (c == BTL_EVENT_GetVar(2)) {
        flag = 0;
        n = BTL_SERVER_FLOW_CollectAlivePokeIds(b, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(b, c) | 0x100), list);
        for (i = 0; i < n; i++) {
            m = BTL_SERVER_FLOW_GetPokeParam(b, list[i]);
            if (BTL_POKEPARAM_HasSick(m, 2)) {
                if (!flag) {
                    flag = 1;
                    BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
                }
                r = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 7, c);
                r[6] = list[i];
                ((struct Obj13471 *)r)->f4 = BTL_CALC_DivideMaxHpMin1(m, 8);
                BTL_SERVER_FLOW_InitMsgRecord(r + 12, 2, 0x1e4);
                BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 12), list[i]);
                BTL_SERVER_FLOW_CommitCmdRecord(b, r);
            }
        }
        if (flag) BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
    }
}
extern u8 gBadDreamsHandlers[];
void *HAND_TOKUSEI_GetBadDreamsHandlers(int *p) { *p = 1; return gBadDreamsHandlers; }
