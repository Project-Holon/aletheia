/*
 * function: BTL_SERVER_FLOW_TryForceSwitchTarget
 * address: 0x021C3810
 * packet: pkt_ov093_021C3810
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: BTL_MAIN_GetSlotClientAndNth receives the full position int; its own u8 signature adds an absent truncation.
 * symbols:
 *   BTL_SERVER_FLOW_IsForceSwitchByParty 0x021C39CC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   BTL_SERVER_FLOW_BeginHandExScope 0x021CC8D8 thumb ov093
 *   BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent 0x021C3A4C thumb ov093
 *   BTL_SERVER_FLOW_GetLockState 0x021C88E4 thumb ov093
 *   BTL_SERVER_FLOW_EndHandExScope 0x021CC95C thumb ov093
 *   BTL_MAIN_GetSlotClientAndNth 0x021B8E28 thumb ov093
 *   BTL_SERVER_GetClientChecked 0x021BB85C thumb ov093
 *   BTL_SERVER_FLOW_PickRandomBenchPoke 0x021C39F4 thumb ov093
 *   BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberOutCore 0x021BDD7C thumb ov093
 *   BTL_SERVER_FLOW_PushMsgRecord 0x021C99A0 thumb ov093
 *   BTL_SERVER_FLOW_ProcMemberIn 0x021BD9D4 thumb ov093
 *   BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *   BTL_SERVER_FLOW_ProcAfterMemberIn 0x021BDA00 thumb ov093
 *   BTL_MAIN_PokeIdToClientIdThunk 0x021B8DDC thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_CLIENT_SET_Add 0x021D8244 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Mode { M0, M1, M2, Mneg = -1 };
struct Pair { u8 count, id; };
struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };
extern int BTL_SERVER_FLOW_IsForceSwitchByParty(u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct B;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern u8 BTL_POKEPARAM_GetCounter(u8 *, int);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *, int);
extern int BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent(u8 *, int, u8 *);
extern int BTL_SERVER_FLOW_GetLockState(u8 *);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_MAIN_GetSlotClientAndNth(u8 *, int, u8 *, u8 *);
extern u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
extern int BTL_SERVER_FLOW_PickRandomBenchPoke(u8 *, u8 *);
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
extern void BTL_SERVER_FLOW_ProcMemberOutCore(u8 *, u8 *, u32);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *, const struct Msg *);
extern void BTL_SERVER_FLOW_ProcMemberIn(u8 *p, u8 i, u8 a, u8 b, int c);
extern void BTL_SERVER_CMD_PushVariable(void *, u8, ...);
extern int BTL_SERVER_FLOW_ProcAfterMemberIn(u8 *);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void BTL_CLIENT_SET_Add(struct B *p, int n);
static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}
int BTL_SERVER_FLOW_TryForceSwitchTarget(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    int position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = BTL_SERVER_FLOW_IsForceSwitchByParty(p);
    if (mode == M2) return 0;
    position = BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, BTL_POKEPARAM_GetPokeId(b));
    if (position == 6) return 0;
    if (BTL_POKEPARAM_IsFainted(b)) return 0;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(BTL_POKEPARAM_GetCounter(b, 4)) != 31) return 0;
    lock = BTL_SERVER_FLOW_BeginHandExScope(p + 0x1d74, 8732);
    blocked = BTL_SERVER_FLOW_QueryForceSwitchBlockedEvent(p, (int)a, b);
    if (blocked && BTL_SERVER_FLOW_GetLockState(p)) *out = 1;
    BTL_SERVER_FLOW_EndHandExScope((u32 *)(p + 0x1d74), lock, 8740);
    if (blocked) return 0;
    BTL_MAIN_GetSlotClientAndNth(*(u8 * *)&((struct Obj00003 *)p)->f4, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = BTL_SERVER_FLOW_PickRandomBenchPoke(p, BTL_SERVER_GetClientChecked(*(u8 * *)&((struct Obj00003 *)p)->f0, pair.id));
        if (mode >= 0) {
            id = BTL_POKEPARAM_GetPokeId((u8 *)BTL_SIDE_GetClientPokeParam((char *)(*(u32 *)&((struct Obj00003 *)p)->f8), pair.id, (u8)mode));
            BTL_SERVER_FLOW_ProcMemberOutCore(p, b, move);
            if (msg) BTL_SERVER_FLOW_PushMsgRecord(p, msg);
            BTL_SERVER_FLOW_ProcMemberIn(p, pair.id, pair.count, (u8)mode, 0);
            BTL_SERVER_CMD_PushVariable(((struct Obj00003 *)p)->fC, 0x5b, 845, id, 0xffff0000);
            BTL_SERVER_FLOW_ProcAfterMemberIn(p);
        } else return 0;
    } else {
        int slot;
        slot = BTL_MAIN_PokeIdToClientIdThunk(BTL_POKEPARAM_GetPokeId(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)BTL_POKEPARAM_GetValue(a, 15);
            if ((u8)BTL_POKEPARAM_GetValue(b, 15) > speed) return 0;
        }
        BTL_CLIENT_SET_Add((struct B *)(p + 0x4b8), slot);
        BTL_SERVER_FLOW_ProcMemberOutCore(p, b, move);
        *(u32 *)&((struct Obj00003 *)p)->f14 = 5;
    }
    return 1;
}
