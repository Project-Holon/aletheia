/*
 * function: func_021FFCB0
 * address:  0x021FFCB0
 * packet:   pkt_ov094_021FFCB0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201600C  0x0201600C  thumb
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    unsigned int pad510 : 2;    /* 0x510 */
    unsigned int f510 : 1;
    int m514;              /* 0x514 */
    int m518;               /* 0x518 */
    int m51c;               /* 0x51c */
    int m520;               /* 0x520 */
    int m524;               /* 0x524 */
    int m528;               /* 0x528 */
    int m52c;               /* 0x52c */
    int m530;               /* 0x530 */
} Work;

extern int func_022019F4(Work *w, int key);
extern int func_021FFD9C(Work *w, int key);
extern int func_0201600C(void *h);
extern int func_021F935C(int x);

int func_021FFCB0(Work *w, int key)
{
    int r = 0;

    if (func_021FFD9C(w, key))
        r = func_0201600C(w->e[func_022019F4(w, key)].h);
    if (func_021F935C(key) & w->m514
        || func_021F935C(key) & w->m518
        || func_021F935C(key) & w->m524
        || func_021F935C(key) & w->m520
        || func_021F935C(key) & w->m51c
        || func_021F935C(key) & w->m528
        || func_021F935C(key) & w->m52c
        || func_021F935C(key) & w->m530
        || w->f510
        || r)
        return 1;
    return 0;
}
