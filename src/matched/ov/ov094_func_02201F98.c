/*
 * function: func_02201F98
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
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_0204B404  0x0204B404  arm
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
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);

void func_02201F98(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = func_021F9260(o->mover, &o->x);
    short v[2];

    v[0] = o->x >> 12;
    v[1] = o->y >> 12;
    func_0204B404(t[o->idx].h, (const struct Vec2 *)v, 0);
    if (r == 1)
        func_021F89BC(a);
}
