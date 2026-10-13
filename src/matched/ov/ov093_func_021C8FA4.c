/*
 * function: BTL_SERVER_FLOW_ExecCmdRestoreMovePp
 * address:  0x021C8FA4
 * packet:   pkt_ov093_021C8FA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsAbleToBattle  0x021D5B7C  thumb  ov093
 *   BTL_POKEPARAM_IsMovePPFull  0x021D55D8  thumb  ov093
 *   BTL_SERVER_FLOW_RestoreMovePp  0x021C6080  thumb  ov093
 *   BTL_SERVER_FLOW_PushMsgRecord  0x021C99A0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsAbleToBattle(void *m);
extern int BTL_POKEPARAM_IsMovePPFull(u8 *p, int i, int s);
extern void BTL_SERVER_FLOW_RestoreMovePp(u8 *p, u8 *a, int b, int c, int d);
struct Msg;
extern int BTL_SERVER_FLOW_PushMsgRecord(void *w, const struct Msg *m);

typedef struct {
    u32 pad : 8; u32 idx : 5; u32 rest : 19;
    u8 b4; u8 b5; u8 b6; u8 f7a : 1; u8 f7b : 1; u8 f7c : 6;
} Ent;

int BTL_SERVER_FLOW_ExecCmdRestoreMovePp(int p, const Ent *e)
{
    u8 *a;
    int r;

    BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx);
    a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, e->b5);
    if (BTL_POKEPARAM_IsAbleToBattle(a) || e->f7b) {
        r = !e->f7a;
        if (BTL_POKEPARAM_IsMovePPFull(a, e->b6, r) == 0) {
            BTL_SERVER_FLOW_RestoreMovePp((u8 *)p, a, e->b6, e->b4, r);
            BTL_SERVER_FLOW_PushMsgRecord((void *)p, (void *)((u8 *)e + 8));
            return 1;
        }
    }
    return 0;
}
