/*
 * function: func_021FFDF8
 * address:  0x021FFDF8
 * packet:   pkt_ov094_021FFDF8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_020160D4  0x020160D4  thumb
 */

typedef struct {
    int w[9];
} Rec;

typedef struct {
    void *h;                /* 0x00 */
    Rec rec;                /* 0x04 */
    char pad28[0x0c];
    int k34;                /* 0x34 */
    char pad38[0x24];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(Work *w, int key);
extern void func_020160D4(void *obj, void *h, int a, int b);

void func_021FFDF8(Work *w, int key, int a, int b)
{
    int idx = func_022019F4(w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    func_020160D4(w->obj, w->e[idx].h, a, b);
}
