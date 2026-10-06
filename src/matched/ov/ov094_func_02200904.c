/*
 * function: func_02200904
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
 *   func_02015C30  0x02015C30  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *
 * Task callback, twin of func_02200A84 on the +0xE0 vector.
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
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_021F89BC(void *h);
extern int func_021F9260(Mover *m, VecFx32 *out);
extern int func_022019F4(char *p, int key);

void func_02200904(void *h, Ctx *c)
{
    Work *w = c->w;
    int i = func_022019F4((char *)w, c->key);
    VecFx32 v;
    int r;

    if (i == -1) {
        func_021F89BC(h);
        return;
    }
    if (w->e[i].h == 0) {
        func_021F89BC(h);
        return;
    }
    if (c->tag != w->tag[c->key]) {
        func_021F89BC(h);
        return;
    }
    func_02015C30(w->e[i].h, (u32 *)(&v));
    r = func_021F9260(&c->mv, &v);
    func_02015C48(w->e[i].h, (u32 *)(&v));
    if (r == 1)
        func_021F89BC(h);
}
