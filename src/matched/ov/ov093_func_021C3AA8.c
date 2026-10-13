/*
 * function: BTL_SERVER_FLOW_ProcMoveWeather
 * address:  0x021C3AA8
 * packet:   pkt_ov093_021C3AA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WAZA_TOOL_GetWeather  0x0201C184  thumb
 *   BTL_SERVER_FLOW_QueryWeatherPokeEvent  0x021C3C10  thumb  ov093
 *   BTL_SERVER_FLOW_TryChangeWeather  0x021C3B68  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgStdFailed  0x021C5718  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchPokeMoveEvent  0x021C3CCC  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockState  0x021C88E4  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
#include "../include/Obj13330.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } Q;

extern u32 WAZA_TOOL_GetWeather(int id);
extern u8 BTL_SERVER_FLOW_QueryWeatherPokeEvent(u8 *p, int k, u8 *a);
extern int BTL_SERVER_FLOW_TryChangeWeather(u8 *p, int k, u8 v);
extern void BTL_SERVER_FLOW_PushMsgStdFailed(u8 *p, u8 *b, int c);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_DispatchPokeMoveEvent(u8 *p, u8 *b, int c);
extern int BTL_SERVER_FLOW_GetLockState(u8 *p);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

void BTL_SERVER_FLOW_ProcMoveWeather(u8 *p, u16 *a, u8 *b)
{
    u8 k = WAZA_TOOL_GetWeather(*a);
    if (k) {
        int x = BTL_SERVER_FLOW_QueryWeatherPokeEvent(p, k, b);
        if (BTL_SERVER_FLOW_TryChangeWeather(p, k, (u8)(x + 5))) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
            return;
        }
        BTL_SERVER_FLOW_PushMsgStdFailed(p, b, *a);
    } else {
        u32 s;
        int e;
        s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x22c8);
        BTL_SERVER_FLOW_DispatchPokeMoveEvent(p, b, *a);
        e = (BTL_SERVER_FLOW_GetLockState(p) == 2);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 0x22cc);
        if (e) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else {
            BTL_SERVER_FLOW_PushMsgStdFailed(p, b, *a);
        }
    }
}
