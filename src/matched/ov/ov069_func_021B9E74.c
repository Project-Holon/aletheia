/*
 * function: BSUBWAY_RECORD_LIST_StateInput
 * address:  0x021B9E74
 * packet:   pkt_ov069_021B9E74
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   BSUBWAY_RECORD_LIST_PollTouchAndCancel  0x021BA2A4  thumb  ov069
 *   func_02025D2C  0x02025D2C  thumb
 *   BSUBWAY_RECORD_LIST_HandleAction  0x021BA2D8  thumb  ov069
 */
#include "../include/Obj00432.h"

typedef unsigned int   u32;
struct PrintSys;
struct Sound;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int BSUBWAY_RECORD_LIST_PollTouchAndCancel(char *p);
extern int func_02025D2C(struct Sound *obj);
extern void BSUBWAY_RECORD_LIST_HandleAction(char *o, int k);

int BSUBWAY_RECORD_LIST_StateInput(char *o)
{
    int v;

    if (func_0201C6B4((const struct PrintSys *)(((struct Obj00432 *)o)->fE8)) == 0)
        return 1;
    if (BSUBWAY_RECORD_LIST_PollTouchAndCancel(o) == -1) {
        v = func_02025D2C((struct Sound *)(*(int *)&((struct Obj00432 *)o)->f14C));
        if (v == -6)
            BSUBWAY_RECORD_LIST_HandleAction(o, 0);
        else if (v == -5)
            BSUBWAY_RECORD_LIST_HandleAction(o, 1);
    }
    return 1;
}
