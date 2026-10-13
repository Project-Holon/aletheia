/*
 * function: BTL_SERVER_FLOW_ExecCmdFinishHpChange
 * address:  0x021C95D0
 * packet:   pkt_ov093_021C95D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C961C  0x021C961C  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 *   BTL_SERVER_FLOW_ProcPokeHpChangeFinish  0x021C2314  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C961C(int a, u8 b);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);
extern int BTL_SERVER_FLOW_ProcPokeHpChangeFinish(u8 *p, u8 *a);

typedef struct { u32 w; u8 b4; u8 b5; } Ent;

int BTL_SERVER_FLOW_ExecCmdFinishHpChange(int p, const Ent *e)
{
    int a;

    if (func_021C961C(p + 0x1ab8, e->b4)) {
        a = (int)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, e->b4);
        if (BTL_POKEPARAM_IsFainted((void *)a) == 0 || e->b5) {
            BTL_SERVER_FLOW_PushMsgRecord((void *)p, (void *)((u8 *)e + 8));
            BTL_SERVER_FLOW_ProcPokeHpChangeFinish((u8 *)p, (u8 *)a);
            return 1;
        }
    }
    return 0;
}
