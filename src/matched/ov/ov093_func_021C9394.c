/*
 * function: BTL_SERVER_FLOW_ExecCmdSetStatStages
 * address:  0x021C9394
 * packet:   pkt_ov093_021C9394
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C9438  0x021C9438  thumb  ov093
 *   BTL_SIDE_GetPokeByIdThunk  0x021B9934  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_SetStatStage  0x021D5EA8  thumb  ov093
 *   BTL_SERVER_CMD_Push  0x021CD4B0  thumb  ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C9438(int a, u8 b);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void BTL_POKEPARAM_SetStatStage(u8 *p, int i, u8 n);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);

typedef struct {
    u32 w; u8 b[8];
} Ent;

int BTL_SERVER_FLOW_ExecCmdSetStatStages(int p, const Ent *e)
{
    u8 *a;

    if (func_021C9438(p + 0x1ab8, e->b[0])) {
        a = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, e->b[0]);
        if (BTL_POKEPARAM_IsFainted(a) == 0) {
            BTL_POKEPARAM_SetStatStage(a, 1, e->b[1]);
            BTL_POKEPARAM_SetStatStage(a, 2, e->b[2]);
            BTL_POKEPARAM_SetStatStage(a, 3, e->b[3]);
            BTL_POKEPARAM_SetStatStage(a, 4, e->b[4]);
            BTL_POKEPARAM_SetStatStage(a, 5, e->b[5]);
            BTL_POKEPARAM_SetStatStage(a, 6, e->b[6]);
            BTL_POKEPARAM_SetStatStage(a, 7, e->b[7]);
            BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0xb, e->b[0], e->b[1], e->b[2], e->b[3], e->b[4], e->b[5], e->b[6], e->b[7]);
            return 1;
        }
    }
    return 0;
}
