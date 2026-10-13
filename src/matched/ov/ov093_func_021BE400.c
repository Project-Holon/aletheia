/*
 * function: BTL_SERVER_FLOW_ProcDeferredMoves
 * address: 0x021BE400
 * packet: pkt_ov093_021BE400
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchDeferredMoveEvent 0x021BEA60 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_GetMoveParam 0x021C64B4 thumb ov093
 *   BTL_SERVER_FLOW_DecideMoveTargets 0x021CA7F4 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SuspendPokeFactors 0x021D7394 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   HAND_WAZA_AddMoveHandler 0x021E02DC thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecute 0x021BEC58 thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke 0x021E03D8 thumb ov093
 *   BTL_EVENT_ResumePokeFactors 0x021D73D4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Out { u8 pad[16]; u32 flag : 1; u32 rest : 31; };
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *, int);
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_DispatchDeferredMoveEvent(u8 *, u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
struct Out64B4;
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int BTL_SERVER_FLOW_DecideMoveTargets(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SuspendPokeFactors(int kind);
extern int func_021D59B4(u8 *p, int k);
extern int HAND_WAZA_AddMoveHandler(u8 *, u16, u32);
extern int BTL_SERVER_FLOW_ProcMoveExecute(u8 *p, u8 *a, u16 key, u8 *d);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);
extern void BTL_EVENT_ResumePokeFactors(int kind);
void BTL_SERVER_FLOW_ProcDeferredMoves(u8 *p, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (*(u8 **)(p + 0x4b0))[0]; i++) {
        a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 1]);
        b = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 13]);
        if (BTL_POKEPARAM_IsAbleToBattle(a) != 0) {
            lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 3657);
            BTL_SERVER_FLOW_DispatchDeferredMoveEvent(p, a, b, key);
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 3659);
            BTL_SERVER_FLOW_GetMoveParam(p, key, a, (struct Out64B4 *)(*(struct Out * *)&((struct Obj00003 *)p)->f1AB0));
            (*(struct Out **)(p + 0x1ab0))->flag = 1;
            BTL_SERVER_FLOW_DecideMoveTargets(p, a, (*(u8 **)(p + 0x4b0))[i + 7], (const u8 *)(*(struct Out **)(p + 0x1ab0)), ((struct Obj00003 *)p)->f864);
            BTL_EVENT_SuspendPokeFactors(BTL_POKEPARAM_GetPokeId(a));
            HAND_WAZA_AddMoveHandler(a, key, func_021D59B4(a, 12));
            BTL_SERVER_FLOW_ProcMoveExecute(p, a, key, ((struct Obj00003 *)p)->f864);
            HAND_WAZA_RemoveMoveHandlerOfPoke(a, key);
            BTL_EVENT_ResumePokeFactors(BTL_POKEPARAM_GetPokeId(a));
        }
    }
}
