/*
 * function: BTL_SERVER_FLOW_ProcHandExSwapPositions
 * address:  0x021CA3D0
 * packet:   pkt_ov093_021CA3D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_FindPoke  0x021B9C98  thumb  ov093
 *   BTL_SERVER_FLOW_ShiftPokes  0x021BD43C  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_DispatchShiftEvents  0x021BD4E4  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern char *BTL_SIDE_GetSlotOfClient(char *p, int i);
struct Msg;
extern int BTL_SLOT_FindPoke(u8 *p, u32 v);
extern void BTL_SERVER_FLOW_ShiftPokes(u8 *p, int i, u8 a, u8 b, int c);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern void BTL_SERVER_FLOW_DispatchShiftEvents(u8 *p, int i, u8 a, u8 b);

int BTL_SERVER_FLOW_ProcHandExSwapPositions(u8 *p, u8 *q)
{
    int a, b;
    u8 *m1, *m2;
    char *o;
    s16 i, j;
    if (q[4] != q[5]) {
        a = BTL_MAIN_PokeIdToClientIdThunk(q[4]);
        b = BTL_MAIN_PokeIdToClientIdThunk(q[5]);
        if (a == b) {
            m1 = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
            m2 = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
            if (!BTL_POKEPARAM_IsFainted(m1) && !BTL_POKEPARAM_IsFainted(m2)) {
                o = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, a);
                i = BTL_SLOT_FindPoke((u8 *)o, (u32)m1);
                j = BTL_SLOT_FindPoke((u8 *)o, (u32)m2);
                if (i >= 0 && j >= 0) {
                    BTL_SERVER_FLOW_ShiftPokes(p, a, i, j, 0);
                    BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(q + 8));
                    BTL_SERVER_FLOW_DispatchShiftEvents(p, a, i, j);
                    return 1;
                }
            }
        }
    }
    return 0;
}
