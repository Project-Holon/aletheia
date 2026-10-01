/*
 * function: func_021FF228
 * address:  0x021FF228
 * packet:   pkt_ov094_021FF228
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015C1C  0x02015C1C  thumb
 *   func_022006B4  0x022006B4  thumb  ov094
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
extern void func_02015C1C(void *h);
extern void func_022006B4(Work *w, int key);

void func_021FF228(Work *w, int key)
{
    int idx = func_022019F4(w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 0;
    func_02015C1C(w->e[idx].h);
    func_022006B4(w, key);
}
