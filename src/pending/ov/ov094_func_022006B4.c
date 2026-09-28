/*
 * function: func_022006B4
 * address:  0x022006B4
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02015CAC  0x02015CAC  thumb
 *   func_02015D30  0x02015D30  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02201934  0x02201934  thumb  ov094
 *
 * MATCH: bytes identical; blocked on 0x02015D30, an unlabelled ARM9 Thumb
 * leaf (stores a VecFx32 at +0x104, beside the matched func_02015CAC) with no
 * witness. Filing that ARM9 leaf closes this.
 */
typedef unsigned int u32;
typedef int fx32;
typedef long long s64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work;

typedef struct {
    fx32 x, y, z;
} VecFx32;

extern int func_022019F4(Work *w, int key);
extern int func_02201934(Work *w, int i, int mode);
extern void func_02015CAC(void *p, VecFx32 *src);
extern void func_02015D30(void *p, VecFx32 *src);

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

void func_022006B4(Work *w, int i)
{
    int idx = func_022019F4(w, i);
    fx32 v;
    VecFx32 s;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    v = func_02201934(w, i, w->e[idx].flip);
    if (i & 1)
        v = FX_Mul(v, w->scaleOdd);
    else
        v = FX_Mul(v, w->scaleEven);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    func_02015CAC(w->e[idx].h, &s);
    v = func_02201934(w, i, 0);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    func_02015D30(w->e[idx].h, &s);
}
