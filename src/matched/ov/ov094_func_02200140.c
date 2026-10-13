/*
 * function: func_02200140
 * address:  0x02200140
 * packet:   pkt_ov094_02200140
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_ReloadResource   0x02014CF8  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef struct {
    int a, b, c, d;
} Quad;

typedef struct {
    void *h;                /* 0x00 */
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    char pad24[0x08];
    Quad q;                 /* 0x2c */
    char pad3c[0x20];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

struct Sub02014CF8Ctx;
struct Sub02014CF8Rec;
extern int func_022019F4(char *p, int key);
extern void MCSS_ReloadResource(void *a, struct Sub02014CF8Ctx *b, const struct Sub02014CF8Rec *c);

void func_02200140(Work *w, int key1, int key2)
{
    int i1 = func_022019F4((char *)w, key1);
    int i2 = func_022019F4((char *)w, key2);

    w->e[i2].f04 = w->e[i1].f04;
    w->e[i2].f0c = w->e[i1].f0c;
    if (key1 & 1) {
        w->e[i2].f08 = w->e[i1].f08 + 9;
        w->e[i2].f10 = w->e[i1].f10 + 9;
        w->e[i2].f14 = w->e[i1].f14 + 9;
        w->e[i2].f18 = w->e[i1].f18 + 9;
        w->e[i2].f1c = w->e[i1].f1c + 9;
        w->e[i2].f20 = w->e[i1].f20 + 9;
    } else {
        w->e[i2].f08 = w->e[i1].f08 - 9;
        w->e[i2].f10 = w->e[i1].f10 - 9;
        w->e[i2].f14 = w->e[i1].f14 - 9;
        w->e[i2].f18 = w->e[i1].f18 - 9;
        w->e[i2].f1c = w->e[i1].f1c - 9;
        w->e[i2].f20 = w->e[i1].f20 - 9;
    }
    w->e[i2].q = w->e[i1].q;
    MCSS_ReloadResource(w->obj, w->e[i2].h, (const struct Sub02014CF8Rec *)(&w->e[i2].f04));
}
