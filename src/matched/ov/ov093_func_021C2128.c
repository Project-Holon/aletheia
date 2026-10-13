/*
 * function: BTL_SERVER_FLOW_ProcHeldItemActivate
 * address: 0x021C2128
 * packet: pkt_ov093_021C2128
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   func_021C21F4 0x021C21F4 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_RunItemActivateCheckEvent 0x021C2204 thumb ov093
 *   BTL_SERVER_CMD_Reserve 0x021CD4FC thumb ov093
 *   BTL_SERVER_FLOW_SetHandExScopeState 0x021CC918 thumb ov093
 *   BTL_SERVER_FLOW_DispatchPostMoveEvent 0x021C6DD0 thumb ov093
 *   BTL_SERVER_FLOW_GetLockState 0x021C88E4 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_CMD_FillReserved 0x021CD568 thumb ov093
 *   BTL_CALC_GetMonParamWithHeap 0x021D805C thumb ov093
 *   BTL_SERVER_FLOW_SetHeldItem 0x021C2250 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a:10,b:9,c:9,d:1,e:1,f:1,g:1; } Lock;
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int func_021C21F4(void *, u32);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern int BTL_SERVER_FLOW_RunItemActivateCheckEvent(u8 *, u8 *, u16);
extern u32 BTL_SERVER_CMD_Reserve(void *, u32);
extern u32 BTL_SERVER_FLOW_SetHandExScopeState(void *, u16, int);
extern void BTL_SERVER_FLOW_DispatchPostMoveEvent(u8 *, u8 *);
extern int BTL_SERVER_FLOW_GetLockState(u8 *);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_CMD_FillReserved(void *, u32, u32, ...);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern void BTL_SERVER_FLOW_SetHeldItem(u8 *p, u8 *a, u16 b, u32 c);
int BTL_SERVER_FLOW_ProcHeldItemActivate(u8 *p, u8 *a)
{
    int t = BTL_POKEPARAM_GetItem((struct QI *)a);
    int result = 0;
    u32 s;
    u32 v;
    u32 pos;
    if (func_021C21F4(p + 0x1ab8, BTL_POKEPARAM_GetPokeId(a))) {
        s = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 0x1cea);
        if (BTL_SERVER_FLOW_RunItemActivateCheckEvent(p, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = BTL_SERVER_CMD_Reserve(((struct Obj00003 *)p)->fC, 0x42);
            v = BTL_SERVER_FLOW_SetHandExScopeState(p + 0x1d74, (u16)t, 0x1cf4);
            BTL_SERVER_FLOW_DispatchPostMoveEvent(p, a);
            if (BTL_SERVER_FLOW_GetLockState(p) != 2) result = 0;
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), v, 0x1cf9);
            if (result) {
                BTL_SERVER_CMD_FillReserved(((struct Obj00003 *)p)->fC, pos, 0x42, BTL_POKEPARAM_GetPokeId(a));
                if (BTL_CALC_GetMonParamWithHeap((void *)((u16)t), 0x10)) BTL_SERVER_FLOW_SetHeldItem(p, a, 0, 1);
            }
        }
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), s, 0x1d06);
    }
    return result;
}
