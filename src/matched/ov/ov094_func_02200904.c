/*
 * function: BTLV_MCSS_PositionTweenTaskMain
 * address:  0x02200904
 * packet:   pkt_ov094_02200904
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * Task callback, twin of BTLV_MCSS_ScaleTweenTaskMain on the +0xE0 vector.
 */
typedef unsigned char u8;
typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x542 - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x542 */
} Work;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

typedef unsigned int   u32;
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void BTLV_EFFECT_DeleteTask(void *h);
extern int BTLV_EFFECT_StepMover(Mover *m, VecFx32 *out);
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

void BTLV_MCSS_PositionTweenTaskMain(void *h, Ctx *c)
{
    Work *w = c->w;
    int i = BTLV_MCSS_FindSpriteIndex((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        BTLV_EFFECT_DeleteTask(h);
        return;
    }
    if (w->e[i].h == 0) {
        BTLV_EFFECT_DeleteTask(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        BTLV_EFFECT_DeleteTask(h);
        return;
    }
    MCSS_GetPosition(w->e[i].h, (u32 *)(&v));
    r = BTLV_EFFECT_StepMover(&c->mv, &v);
    MCSS_SetPosition(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        BTLV_EFFECT_DeleteTask(h);
}
