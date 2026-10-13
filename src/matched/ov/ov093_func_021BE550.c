/*
 * function: BTL_SERVER_FLOW_ProcInterruptMove
 * address: 0x021BE550
 * packet: pkt_ov093_021BE550
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_DispatchMoveInterruptEvent 0x021BEA14 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_SERVER_FLOW_GetMoveParam 0x021C64B4 thumb ov093
 *   BTL_SERVER_FLOW_DecideMoveTargets 0x021CA7F4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   WAZA_TOOL_GetFlag 0x0201BEB8 thumb
 *   BTL_SERVER_FLOW_PushMoveFailMessage 0x021C0520 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   HAND_WAZA_AddMoveHandler 0x021E02DC thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveExecute 0x021BEC58 thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke 0x021E03D8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *, int);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern void BTL_SERVER_FLOW_DispatchMoveInterruptEvent(u8 *, u8 *, u8 *, u32);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
struct Out64B4;
struct Unk021D62A8;
extern void BTL_SERVER_FLOW_GetMoveParam(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern int BTL_SERVER_FLOW_DecideMoveTargets(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u32 WAZA_TOOL_GetFlag(u16, u32);
extern void BTL_SERVER_FLOW_PushMoveFailMessage(u8 *, u8 *, u16, u32);
extern int func_021D59B4(u8 *p, int k);
extern int HAND_WAZA_AddMoveHandler(u8 *, u16, u32);
extern int BTL_SERVER_FLOW_ProcMoveExecute(u8 *p, u8 *a, u16 key, u8 *d);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);
void BTL_SERVER_FLOW_ProcInterruptMove(u8 *p, u8 *b, u16 c, void *unused)
{
    u8 *a;
    u32 lock;
    if ((*(u8 **)(p + 0x4ac))[0] != 0) {
        a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4ac))[1]);
        lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 3720);
        BTL_SERVER_FLOW_DispatchMoveInterruptEvent(p, a, b, c);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 3722);
        BTL_SERVER_FLOW_GetMoveParam(p, c, a, ((struct Obj00003 *)p)->f1AB0);
        BTL_SERVER_FLOW_DecideMoveTargets(p, a, (*(u8 **)(p + 0x4ac))[7], ((struct Obj00003 *)p)->f1AB0, ((struct Obj00003 *)p)->f864);
        if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 15) != 0 && WAZA_TOOL_GetFlag(c, 12) != 0) {
            BTL_SERVER_FLOW_PushMoveFailMessage(p, a, c, 13);
            return;
        }
        HAND_WAZA_AddMoveHandler(a, c, func_021D59B4(a, 12));
        BTL_SERVER_FLOW_ProcMoveExecute(p, a, c, ((struct Obj00003 *)p)->f864);
        HAND_WAZA_RemoveMoveHandlerOfPoke(a, c);
    }
}
