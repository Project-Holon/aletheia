/*
 * function: BTL_SERVER_FLOW_ProcWeatherTurnCheck
 * address: 0x021C4D1C
 * packet: pkt_ov093_021C4D1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_FIELD_TickCountdown 0x021EF8B8 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SERVER_FLOW_ProcWeatherChanged 0x021C3BE0 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeather 0x021C2AB0 thumb ov093
 *   SOUND_OBJ_SetAnimeFrame 0x021C4E08 thumb ov093
 *   func_021C4E18 0x021C4E18 thumb ov093
 *   func_021C4E28 0x021C4E28 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   BTL_CALC_GetWeatherDamage 0x021D7BD4 thumb ov093
 *   BTL_SERVER_FLOW_CalcWeatherDamage 0x021C4E38 thumb ov093
 *   BTL_SERVER_FLOW_ApplyWeatherDamage 0x021C4EA4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintedPoke 0x021C4F64 thumb ov093
 *   BTL_SERVER_FLOW_PushEffectAnim 0x021C70E4 thumb ov093
 *   BTL_SERVER_FLOW_ProcFaintRewards 0x021C5200 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 BTL_FIELD_TickCountdown(void);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern void BTL_SERVER_FLOW_ProcWeatherChanged(u8 *p, u32 a);
extern int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *);
extern void SOUND_OBJ_SetAnimeFrame(void *);
extern u8 *func_021C4E18(void *);
extern u8 *func_021C4E28(void *);
extern int BTL_POKEPARAM_IsFainted(void *);
struct UtilWork;
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern u32 func_021CC8D8(void *, int);
extern int BTL_CALC_GetWeatherDamage(void *, int);
extern int BTL_SERVER_FLOW_CalcWeatherDamage(u8 *, u8 *, u32, u32);
extern void BTL_SERVER_FLOW_ApplyWeatherDamage(u8 *, u8 *, int, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int BTL_SERVER_FLOW_ProcFaintedPoke(u8 *, u8 *);
extern void BTL_SERVER_FLOW_PushEffectAnim(u8 *p, int a, int b, int c, int e, u32 f);
extern int BTL_SERVER_FLOW_ProcFaintRewards(u8 *);
int BTL_SERVER_FLOW_ProcWeatherTurnCheck(u8 *p, void *it)
{
    int r;
    int changed;
    int mode;
    u8 *a;
    u32 lock;
    int line;
    r = BTL_FIELD_TickCountdown();
    if (r) {
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x40, r);
        BTL_SERVER_FLOW_ProcWeatherChanged(p, 0);
        return 0;
    }
    changed = 0;
    mode = BTL_SERVER_FLOW_GetEffectiveWeather(p);
    SOUND_OBJ_SetAnimeFrame(it);
    a = func_021C4E18(it);
    if (a) {
        line = 0x26c6;
        line += 12;
        do {
            if (!BTL_POKEPARAM_IsFainted(a) && !BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 5) && !BTL_POKEPARAM_TestContFlag((struct UtilWork *)a, 4)) {
                lock = func_021CC8D8(p + 0x1d74, 0x26c6);
                r = BTL_SERVER_FLOW_CalcWeatherDamage(p, a, mode, BTL_CALC_GetWeatherDamage(a, mode));
                if (r) {
                    BTL_SERVER_FLOW_ApplyWeatherDamage(p, a, mode, r);
                    changed = 1;
                }
                func_021CC95C((u32 *)(p + 0x1d74), lock, line);
                BTL_SERVER_FLOW_ProcFaintedPoke(p, a);
            }
            a = func_021C4E28(it);
        } while (a);
    }
    if (changed) BTL_SERVER_FLOW_PushEffectAnim(p, 0x255, 6, 6, 0, 0);
    return BTL_SERVER_FLOW_ProcFaintRewards(p);
}
