/*
 * function: func_021FF144
 * address:  0x021FF144
 * packet:   pkt_ov094_021FF144
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015C48  0x02015C48  thumb
 */

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x24];
    void *task;             /* 0x28 */
    char pad2c[0x30];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(Work *w, int key);
extern void func_02015C48(void *h, VecFx32 *v);

void func_021FF144(Work *w, int key, fx32 x, fx32 y, fx32 z)
{
    int idx = func_022019F4(w, key);
    VecFx32 v;

    v.x = x;
    v.y = y;
    v.z = z;
    func_02015C48(w->e[idx].h, &v);
}
