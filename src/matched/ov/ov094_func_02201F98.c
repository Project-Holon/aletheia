/*
 * function: BTLV_CLACT_MoveTaskMain
 * address:  0x02201F98
 * packet:   pkt_ov094_02201F98
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */
typedef struct {
    int a, b;
    void *h;
    int d;
} Ent;

typedef struct {
    Ent *tbl;   /* 0x00 */
    int x, y;   /* 0x04 */
    int pad;    /* 0x0c */
    int idx;    /* 0x10 */
    int mover[1]; /* 0x14 */
} Obj;

extern int BTLV_EFFECT_StepMover(void *m, int *out);
extern void BTLV_EFFECT_DeleteTask(void *p);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

void BTLV_CLACT_MoveTaskMain(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = BTLV_EFFECT_StepMover(o->mover, &o->x);
    short v[2];

    v[0] = o->x >> 12;
    v[1] = o->y >> 12;
    CLACT_AddActorSurfacePos(t[o->idx].h, (const struct Vec2 *)v, 0);
    if (r == 1)
        BTLV_EFFECT_DeleteTask(a);
}
