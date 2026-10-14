/*
 * function: BTLV_CLACT_MoveTaskMainWide
 * address:  0x02201FF4
 * packet:   pkt_ov094_02201FF4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StepMover  0x021F9260  thumb  ov094
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
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
struct Actor;
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
struct Obj;
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);

void BTLV_CLACT_MoveTaskMainWide(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = BTLV_EFFECT_StepMover(o->mover, &o->x);
    int v[2];

    v[0] = o->x;
    v[1] = o->y;
    CLACT_SetActorAffineMode(t[o->idx].h, 1);
    CLACT_SetActorScale(t[o->idx].h, (struct Pair *)v);
    if (r == 1)
        BTLV_EFFECT_DeleteTask(a);
}
