/*
 * function: BTL_SERVER_FLOW_ProcHandExBreakIllusion
 * address:  0x021CA570
 * packet:   pkt_ov093_021CA570
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA5BC  0x021CA5BC  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsIllusionActive  0x021D6C24  thumb  ov093
 *   BTL_POKEPARAM_ClearIllusion  0x021D6C2C  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021CA5BC(u8 *p, int k);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct Msg;
struct R4;
struct Unk021D6C2C;
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern void BTL_POKEPARAM_ClearIllusion(struct Unk021D6C2C *p);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);

int BTL_SERVER_FLOW_ProcHandExBreakIllusion(u8 *p, u8 *q)
{
    u8 *m;
    if (func_021CA5BC(p + 0x1AB8, q[4])) {
        m = BTL_SIDE_GetPokeByIdThunk(((struct Obj00003 *)p)->f8, q[4]);
        if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)m)) {
            BTL_POKEPARAM_ClearIllusion((struct Unk021D6C2C *)m);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x4b, q[4]);
            BTL_SERVER_FLOW_PushMsgRecord(p, (const struct Msg *)(q + 8));
            return 1;
        }
    }
    return 0;
}
