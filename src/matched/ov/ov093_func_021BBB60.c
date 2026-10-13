/*
 * function: BTL_SERVER_FLOW_RunBattleStart
 * address: 0x021BBB60
 * packet: pkt_ov093_021BBB60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Lever: declare i before result for stack order; declare j inside the
 * q-tested block for the original q/j register allocation.
 * extent: followed by padding and separately matched accessor 0x021BBC34.
 * symbols:
 *   BTL_MAIN_GetFieldSituation 0x021B8714 thumb ov093
 *   BTL_SERVER_FLOW_TryChangeWeather 0x021C3B68 thumb ov093
 *   BTL_SERVER_GetClientIfUsed 0x021BB878 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberInCore 0x021BD8F0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_RegisterZukanSeen 0x021B8750 thumb ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn 0x021BDA00 thumb ov093
 */
#include "../include/Obj00003.h"
#include "../include/Obj09958.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *BTL_MAIN_GetFieldSituation(void *);
extern int BTL_SERVER_FLOW_TryChangeWeather(u8 *, int, u8);
struct S2;
extern u8 *BTL_SERVER_GetClientIfUsed(u8 *p, u32 i);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern void BTL_SERVER_FLOW_ProcMemberInCore(u8 *, u8, u8, u8);
extern u32 BTL_MAIN_GetRule(void **p);
extern void BTL_MAIN_RegisterZukanSeen(char *p, unsigned char k, void *m);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *);
int BTL_SERVER_FLOW_RunBattleStart(u8 *p)
{
    u8 *initial;
    u32 i;
    int result;
    void *m;
    u32 *out = *(u32 * *)&((struct Obj00003 *)p)->fC;
    out[0] = 0;
    result = 0;
    out[1] = 0;
    initial = BTL_MAIN_GetFieldSituation(((struct Obj00003 *)p)->f4);
    if (initial[8] && BTL_SERVER_FLOW_TryChangeWeather(p, initial[8], 255)) result = 1;
    for (i = 0; i < 4; i++) {
        u8 *q = BTL_SERVER_GetClientIfUsed(((struct Obj00003 *)p)->f0, (u8)i);
        if (q) {
            u32 j;
            for (j = 0; j < q[9]; j++) {
                m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                if (m && !BTL_POKEPARAM_IsFainted(m)) BTL_SERVER_FLOW_ProcMemberInCore(p, i, j, j);
            }
            if (BTL_MAIN_GetRule(((struct Obj00003 *)p)->f4) == 3) {
                for (j = 0; j < 3; j++) {
                    m = (void *)func_021B9BF0(((struct Obj09958 *)q)->f4, (u8)j);
                    if (m && !BTL_POKEPARAM_IsFainted(m)) BTL_MAIN_RegisterZukanSeen(((struct Obj00003 *)p)->f4, i, m);
                }
            }
        }
    }
    if (BTL_SERVER_FLOW_ProcAfterMemberIn(p)) result = 1;
    return result;
}
