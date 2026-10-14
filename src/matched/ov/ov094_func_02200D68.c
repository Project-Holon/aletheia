/*
 * function: BTLV_MCSS_AlphaTweenTaskMain
 * address:  0x02200D68
 * packet:   pkt_ov094_02200D68
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   MCSS_SetAlpha  0x02015FBC  thumb
 */
#include "../include/Obj06316.h"
typedef unsigned char u8;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void BTLV_EFFECT_DeleteTask(void *o);
extern int BTLV_EFFECT_StepMover(void *m, int *out);
extern void MCSS_SetAlpha(char *p, int v);

void BTLV_MCSS_AlphaTweenTaskMain(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj06316 *)q)->f0;
    int i = BTLV_MCSS_FindSpriteIndex(p, ((struct Obj06316 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        BTLV_EFFECT_DeleteTask(o);
        return;
    }
    if (((struct Obj06316 *)q)->f50 != *(u8 *)(p + ((struct Obj06316 *)q)->f4 + 0x596)) {
        BTLV_EFFECT_DeleteTask(o);
        return;
    }
    r = BTLV_EFFECT_StepMover(q + 0x14, (int *)(q + 8));
    MCSS_SetAlpha(*(char **)(e + off), (u8)(((struct Obj06316 *)q)->f8 >> 12));
    if (r == 1)
        BTLV_EFFECT_DeleteTask(o);
}
