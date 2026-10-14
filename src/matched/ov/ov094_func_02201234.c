/*
 * function: BTLV_MCSS_MosaicTweenTaskMain
 * address:  0x02201234
 * packet:   pkt_ov094_02201234
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
 *   BTLV_MCSS_SetMosaic  0x02200108  thumb  ov094
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   BTLV_MCSS_IdleAnimCallback  0x02201718  thumb  ov094
 */
#include "../include/Obj05243.h"
typedef unsigned char u8;

extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void BTLV_EFFECT_DeleteTask(void *o);
extern int BTLV_EFFECT_StepMover(void *m, int *out);
extern void BTLV_MCSS_SetMosaic(char *p, int key, int x);
extern void MCSS_SetAnimCallback(void *a, int i, void (*fn)(int), int one);
extern void BTLV_MCSS_IdleAnimCallback(int i);

void BTLV_MCSS_MosaicTweenTaskMain(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj05243 *)q)->f0;
    int i = BTLV_MCSS_FindSpriteIndex(p, ((struct Obj05243 *)q)->f4);
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
    if (((struct Obj05243 *)q)->f50 != *(u8 *)(p + ((struct Obj05243 *)q)->f4 + 0x5A4)) {
        BTLV_EFFECT_DeleteTask(o);
        return;
    }
    r = BTLV_EFFECT_StepMover(q + 0x14, (int *)(q + 8));
    BTLV_MCSS_SetMosaic(p, ((struct Obj05243 *)q)->f4, ((struct Obj05243 *)q)->f8 >> 12);
    if (r == 1) {
        MCSS_SetAnimCallback(*(void **)(e + off), i, BTLV_MCSS_IdleAnimCallback, 1);
        BTLV_EFFECT_DeleteTask(o);
    }
}
