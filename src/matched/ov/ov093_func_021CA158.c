/*
 * function: BTL_SERVER_FLOW_ProcHandExForceMemberOut
 * address:  0x021CA158
 * packet:   pkt_ov093_021CA158
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdown  0x021BC2B0  thumb  ov093
 *   BTL_SERVER_FLOW_IsPokeAfflictedByStatus  0x021C8374  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_ProcMemberOut  0x021BDD00  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   BTL_SERVER_AddPokeChangeRequest  0x021BB930  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u8 pad[0x4C];
    u8 b4c;
    u8 b4d;
};

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *p);
extern int BTL_SERVER_FLOW_IsPokeAfflictedByStatus(u8 *p, int i);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern int BTL_SERVER_FLOW_ProcMemberOut(u8 *p, u8 *a, int c);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *p, void *a, u32 b);
extern void BTL_SERVER_AddPokeChangeRequest(u8 *p, u32 value);

int BTL_SERVER_FLOW_ProcHandExForceMemberOut(u8 *w, struct Cmd *c)
{
    u8 *r = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)w)->f8, c->b4c);
    if (BTL_SERVER_FLOW_CheckShowdown(w) == 0 && BTL_SERVER_FLOW_IsPokeAfflictedByStatus(w, c->b4c) == 0 && ((struct Obj00003 *)w)->f14 == 0) {
        BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 4));
        if (BTL_SERVER_FLOW_ProcMemberOut(w, r, c->b4d) != 0) {
            BTL_SERVER_AddPokeChangeRequest(((struct Obj00003 *)w)->f0, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00003 *)w)->f4, ((struct Obj00003 *)w)->f8, c->b4c));
            BTL_SERVER_FLOW_PushMsgRecord(w, (const struct Msg *)((u8 *)c + 0x28));
            ((struct Obj00003 *)w)->f14 = 1;
            return 1;
        }
    }
    return 0;
}
