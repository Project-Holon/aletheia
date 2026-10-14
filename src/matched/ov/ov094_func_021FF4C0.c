/*
 * function: BTLV_MCSS_StartPositionTween
 * address: 0x021FF4C0
 * packet: pkt_ov094_021FF4C0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   BTLV_MCSS_CalcSlotPosition 0x022018A8 thumb ov094
 *   BTLV_MCSS_CreateTweenTask 0x0220074C thumb ov094
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_MCSS_PositionTweenTaskMain 0x02200904 thumb ov094
 *   BTLV_MCSS_PositionTweenTaskEnd 0x02200990 thumb ov094
 */
#include "../include/Obj06309.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void BTLV_MCSS_CalcSlotPosition(void *, Vec *, int);
extern void BTLV_MCSS_CreateTweenTask(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_PositionTweenTaskMain(void);
extern void BTLV_MCSS_PositionTweenTaskEnd(void *p);
void BTLV_MCSS_StartPositionTween(char *w, int key, int kind, Vec *q, int a, int b, int c)
{
    int idx = BTLV_MCSS_FindSpriteIndex(w, key);
    char *e;
    int off;
    Vec start;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    MCSS_GetPosition(*(void **)(e + off), (u32 *)&start);
    if (kind == 1) {
        if (key & 1)
            q->x = start.x - q->x;
        else
            q->x += start.x;
        q->y += start.y;
        q->z += start.z;
    }
    if (kind == 5) {
        BTLV_MCSS_CalcSlotPosition(w, q, key);
        kind = 1;
    }
    if (kind == 6) {
        BTLV_MCSS_CalcSlotPosition(w, q, key);
        kind = 0;
    }
    if (kind == 0) {
        MCSS_SetPosition(*(void **)(e + off), (u32 *)q);
        return;
    }
    (*(u8 *)(w + 0x542 + key))++;
    BTLV_MCSS_CreateTweenTask(w, key, kind, &start, q, a, b, c, (void *)BTLV_MCSS_PositionTweenTaskMain, BTLV_MCSS_PositionTweenTaskEnd, 1, *(u8 *)(w + 0x542 + key));
    ((struct Obj06309 *)w)->f514 |= BTLV_EFFECT_GetBitMask(key);
}
