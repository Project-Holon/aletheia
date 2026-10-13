/*
 * function: BTL_SERVER_FLOW_ProcHandExForceItemFactor
 * address:  0x021C9E3C
 * packet:   pkt_ov093_021C9E3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   HAND_ITEM_AddForcedFactor  0x021DCF78  thumb  ov093
 *   HAND_ITEM_RemoveFactor  0x021DCF9C  thumb  ov093
 *   BTL_SERVER_CMD_Reserve  0x021CD4FC  thumb  ov093
 *   BTL_SERVER_CMD_FillReserved  0x021CD568  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchPostMoveKindEvent  0x021C6E00  thumb  ov093
 *   BTL_SERVER_FLOW_GetLockState  0x021C88E4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *HAND_ITEM_AddForcedFactor(void *p, unsigned int k);
extern void HAND_ITEM_RemoveFactor(void *n);
extern int BTL_SERVER_CMD_Reserve(void *p, int k);
extern void BTL_SERVER_CMD_FillReserved(void *p, int a, int k, u32 b);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_DispatchPostMoveKindEvent(u8 *p, u8 *a, u8 k);
extern int BTL_SERVER_FLOW_GetLockState(u8 *p);

int BTL_SERVER_FLOW_ProcHandExForceItemFactor(u8 *w, struct Cmd *c)
{
    int r = (int)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    int x;
    int t;
    u32 s;
    if (BTL_POKEPARAM_IsFainted((void *)r) == 0) {
        x = (int)HAND_ITEM_AddForcedFactor((void *)r, c->h6);
        if (x != 0) {
            t = BTL_SERVER_CMD_Reserve(((struct Obj00003 *)w)->fC, 0x42);
            s = BTL_SERVER_FLOW_BeginHandExScope(w + 0x1D74, 15755);
            BTL_SERVER_FLOW_DispatchPostMoveKindEvent(w, (u8 *)r, c->id);
            if (BTL_SERVER_FLOW_GetLockState(w) == 2) {
                BTL_SERVER_CMD_FillReserved(((struct Obj00003 *)w)->fC, t, 0x42, c->b4);
            }
            BTL_SERVER_FLOW_EndHandExScope((u32 *)(w + 0x1D74), s, 15762);
            HAND_ITEM_RemoveFactor((void *)x);
            return 1;
        }
    }
    return 0;
}
