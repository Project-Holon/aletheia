/*
 * function: BTL_SERVER_FLOW_ProcTurnCheckSickness
 * address: 0x021C493C
 * packet: pkt_ov093_021C493C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the first out-value is a one-word struct passed by value.
 * symbols:
 *  func_021C4A24 0x021C4A24 thumb ov093
 *  func_021C4A34 0x021C4A34 thumb ov093
 *  func_021C4A44 0x021C4A44 thumb ov093
 *  func_021C4A54 0x021C4A54 thumb ov093
 *  BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *  BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *  BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *  BTL_POKEPARAM_TickSickCont 0x021D6064 thumb ov093
 *  BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *  BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *  BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *  BTL_CALC_PackPokeIds 0x021D806C thumb ov093
 *  BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *  BTL_SERVER_FLOW_ProcFaintRewards 0x021C5200 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 value; } Word;
extern u32 func_021C4A24(u8 *);
extern u8 *func_021C4A34(u8 *, u32);
extern u8 *func_021C4A44(u32);
extern void func_021C4A54(u8 *, u8 *, Word, u32, u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *, int);
extern int BTL_POKEPARAM_IsFainted(void *p);
union Slot;
extern int BTL_POKEPARAM_TickSickCont(u8 *p, u32 k, union Slot *out, int *changed);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *);
extern u32 BTL_CALC_PackPokeIds(const u8 *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *p);
int BTL_SERVER_FLOW_ProcTurnCheckSickness(u8 *p, u8 *a)
{
    u8 list[6];
    Word y;
    u32 x;
    u32 i, n, k, s;
    u8 *q, *m;
    list[0] = 0;
    list[1] = 0;
    list[2] = 0;
    list[3] = 0;
    list[4] = 3;
    list[5] = 0;
    i = 0;
    n = func_021C4A24(a);
    for (; i < n; i++) list[i] = BTL_POKEPARAM_GetPokeId(func_021C4A34(a, i));
    k = 0;
    for (;;) {
        q = func_021C4A44(k++);
        if (q == 0) break;
        for (i = 0; i < n; i++) {
            m = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, list[i]);
            if (BTL_POKEPARAM_IsFainted(m) == 0) {
                if (BTL_POKEPARAM_TickSickCont(m, (u32)q, (union Slot *)(&y), (int *)(&x))) {
                    s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 9719);
                    func_021C4A54(m, q, y, x, p);
                    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 9721);
                }
            }
        }
        if (BTL_SERVER_FLOW_CheckShowdown(p)) break;
    }
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x15, (u8)n, (u8)k, BTL_CALC_PackPokeIds(list));
    return BTL_SERVER_FLOW_ProcFaintRewards(p);
}
