/*
 * function: BTLV_MCSS_DrawScaleTweenTaskMain
 * address:  0x02200B48
 * packet:   pkt_ov094_02200B48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * symbols:
 *   MCSS_GetDrawScale  0x02015D4C  thumb
 *   MCSS_SetDrawScale  0x02015D64  thumb
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_MCSS_FindSpriteIndex  0x022019F4  thumb  ov094
 *
 * MATCH: bytes identical; blocked on two unfiled ARM9 Thumb leaves (the integrator's),
 * no witness outside this range. Verified C, each EXACT with `one --thumb`
 * and no --region (cc 1.1p1, -O4,p), packets pkt_02015D4C / pkt_02015D64:
 *
 *   typedef unsigned int u32;
 *   void MCSS_GetDrawScale(void *p, u32 *out)   // 0x02015D4C, 64 B extent
 *   {
 *       out[0] = *(u32 *)((char *)p + 0x110);
 *       out[1] = *(u32 *)((char *)p + 0x114);
 *       out[2] = *(u32 *)((char *)p + 0x118);
 *   }
 *   void MCSS_SetDrawScale(void *p, u32 *src)  // 0x02015D64, inverse
 *   {
 *       *(u32 *)((char *)p + 0x110) = src[0];
 *       *(u32 *)((char *)p + 0x114) = src[1];
 *       *(u32 *)((char *)p + 0x118) = src[2];
 *   }
 *
 * Task callback, twin of BTLV_MCSS_ScaleTweenTaskMain.
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
    char pad[0x56c - 0x008 - 14 * 0x5c];
    u8 tag[1];              /* 0x56c */
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
extern void MCSS_GetDrawScale(void *p, u32 *out);
extern void MCSS_SetDrawScale(void *p, u32 *src);
extern void BTLV_EFFECT_DeleteTask(void *h);
extern int BTLV_EFFECT_StepMover(Mover *m, VecFx32 *out);
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);

void BTLV_MCSS_DrawScaleTweenTaskMain(void *h, Ctx *c)
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
    MCSS_GetDrawScale(w->e[i].h, (u32 *)(&v));
    r = BTLV_EFFECT_StepMover(&c->mv, &v);
    MCSS_SetDrawScale(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        BTLV_EFFECT_DeleteTask(h);
}
