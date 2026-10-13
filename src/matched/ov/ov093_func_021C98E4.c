/*
 * function: BTL_SERVER_FLOW_ExecCmdChangeWeather
 * address:  0x021C98E4
 * packet:   pkt_ov093_021C98E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_CanChangeWeather  0x021C3B8C  thumb  ov093
 *   BTL_SERVER_FLOW_ApplyWeatherChange  0x021C3BB8  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupIn  0x021C5A1C  thumb  ov093
 *   BTL_SERVER_FLOW_PushAbilityPopupOut  0x021C5A34  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_NotifyWeatherEffectEvent  0x021C7BF8  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_CanChangeWeather(void *w, u32 a, u32 b);
extern void BTL_SERVER_FLOW_ApplyWeatherChange(u8 *p, u32 a, u32 b);
extern void BTL_SERVER_FLOW_PushAbilityPopupIn(u8 *p, u8 *a);
extern void BTL_SERVER_FLOW_PushAbilityPopupOut(u8 *p, u8 *a);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_NotifyWeatherEffectEvent(u8 *p);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);

u8 BTL_SERVER_FLOW_ExecCmdChangeWeather(u8 *w, struct Cmd *c)
{
    u8 *id = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (BTL_SERVER_FLOW_CanChangeWeather(w, c->b4, c->b5) != 0) {
            if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(w, id);
            BTL_SERVER_FLOW_ApplyWeatherChange(w, c->b4, c->b5);
            BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 8));
            r = 1;
            if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(w, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupIn(w, id);
        BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 8));
        s = BTL_SERVER_FLOW_BeginHandExScope(w + 0x1D74, 15467);
        BTL_SERVER_FLOW_NotifyWeatherEffectEvent(w);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(w + 0x1D74), s, 15469);
        r = 1;
        if (c->flag) BTL_SERVER_FLOW_PushAbilityPopupOut(w, id);
    }
    return r;
}
