/*
 * function: func_02200468
 * address:  0x02200468
 * packet:   pkt_ov094_02200468
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   func_02201894  0x02201894  thumb  ov094
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(char *p, int key);
extern void MCSS_SetAnimCallback(void *h, int idx, void (*fn)(int), int v);
extern void func_02201894(int i);

void func_02200468(Work *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    MCSS_SetAnimCallback(w->e[idx].h, idx, func_02201894, 1);
}
