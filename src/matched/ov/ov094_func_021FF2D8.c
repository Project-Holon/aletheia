/*
 * function: func_021FF2D8
 * address:  0x021FF2D8
 * packet:   pkt_ov094_021FF2D8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015DF8  0x02015DF8  thumb
 */

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
} Work;

extern int func_022019F4(Work *w, int key);
extern int func_02015DF8(void *h);

int func_021FF2D8(Work *w, int key)
{
    int idx = func_022019F4(w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return func_02015DF8(w->e[idx].h);
}
