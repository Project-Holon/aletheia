/*
 * function: func_02201FF4
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
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_0204B570  0x0204B570  arm
 *   func_0204B5AC  0x0204B5AC  arm
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

extern int func_021F9260(void *m, int *out);
extern void func_021F89BC(void *p);
typedef unsigned int   u32;
struct Actor;
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B5AC(void *h, int *v);

void func_02201FF4(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = func_021F9260(o->mover, &o->x);
    int v[2];

    v[0] = o->x;
    v[1] = o->y;
    func_0204B570(t[o->idx].h, 1);
    func_0204B5AC(t[o->idx].h, v);
    if (r == 1)
        func_021F89BC(a);
}
