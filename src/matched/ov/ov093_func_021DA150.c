/*
 * function: HAND_TOKUSEI_TraceOnMemberIn
 * address: 0x021DA150
 * packet: pkt_ov093_021DA150
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
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021DA2D0 0x021DA2D0 thumb ov093
 *   func_021DA2E0 0x021DA2E0 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_IsPokeSamePair 0x021B9A24 thumb ov093
 *   BTL_MAIN_IsPosInTable 0x021B9A6C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos 0x021C8010 thumb ov093
 *   BTL_SERVER_FLOW_GetRule 0x021C815C thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 */
#include "../include/Obj06254.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern u16 BTL_SERVER_FLOW_GetFrontPosOfPoke(void *, int);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021DA2D0(u16);
extern int func_021DA2E0(u16);
extern u32 BTL_CALC_Random(u32);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_IsPokeSamePair(u32 a, u32 b);
extern int BTL_MAIN_IsPosInTable(int a, u32 b);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int BTL_SERVER_FLOW_GetRule(int *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_TOKUSEI_TraceOnMemberIn(int a, void *b, int c, int *d)
{
    u8 buf[3];
    u8 selected[3];
    u8 chosen;
    u32 move;
    u8 active;
    u8 count, i, choice;
    u32 n;
    u16 mask;
    int slot;
    void *q;
    int candidate;
    u8 *p;
    active = BTL_EVENT_GetVar(2);
    chosen = 31;
    move = 0;
    if (active == c) {
        mask = BTL_SERVER_FLOW_GetFrontPosOfPoke(b, c);
        n = BTL_SERVER_FLOW_CollectAlivePokeIds(b, (u16)(mask | 0x100), buf);
        for (count = 0, i = 0; i < n; i++) {
            if (!func_021DA2D0((u16)func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(b, buf[i]), 16))) selected[count++] = buf[i];
        }
        if (count != 0) {
            choice = count == 1 ? 0 : BTL_CALC_Random(count);
            q = BTL_SERVER_FLOW_GetPokeParam(b, selected[choice]);
            move = func_021D59B4(q, 16);
            chosen = BTL_POKEPARAM_GetPokeId(q);
        } else {
            *d = 1;
        }
    } else if (!BTL_MAIN_IsPokeSamePair(active, c) && *d == 1) {
        slot = BTL_SERVER_FLOW_GetPokeViewPos(b, active);
        mask = BTL_SERVER_FLOW_GetFrontPosOfPoke(b, c);
        if (slot != 6 && (BTL_SERVER_FLOW_GetRule(b) != 2 || BTL_MAIN_IsPosInTable(mask, slot))) {
            candidate = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(b, active), 16);
            if (!func_021DA2E0((u16)candidate)) { move = candidate; chosen = active; }
        }
    }
    if (move != 0 && c != 31) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 31, c);
        p[6] = c;
        ((struct Obj06254 *)p)->f4 = move;
        p[8] = 1;
        ((struct Obj06254 *)p)->f0 |= 1 << 23;
        BTL_SERVER_FLOW_InitMsgRecord(p + 12, 2, 0x17d);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), chosen);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 12), ((struct Obj06254 *)p)->f4);
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}
