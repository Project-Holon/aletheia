/*
 * function: func_021FF260
 * address:  0x021FF260
 * packet:   pkt_ov094_021FF260
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: three unlabelled arm9 Thumb leaves (relocation wildcards, no witness):
 *   func_02015DB0, func_02015DC0, func_02015DD4.  All Ilias's; verified C
 *   (one --thumb, no --region, EXACT each; +0x140 is a register-like word):
 *     struct R { unsigned int : 8; unsigned int f : 1; };
 *     void func_02015DB0(void *p) { *(unsigned int *)((char *)p + 0x140) |= 0x100u; }
 *     void func_02015DC0(void *p) { *(unsigned int *)((char *)p + 0x140) &= ~0x100u; }
 *     void func_02015DD4(void *p) { ((struct R *)((char *)p + 0x140))->f ^= 1; }
 *   Re-run this file once layout/matched/arm9 shards for all three exist.
 *
 * symbols:
 *   func_02015DB0  0x02015DB0  thumb
 *   func_02015DC0  0x02015DC0  thumb
 *   func_02015DD4  0x02015DD4  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;
    char pad04[0x48];
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;

extern int func_022019F4(Work *w, int key);
extern void func_02015DB0(void *p);
extern void func_02015DC0(void *p);
extern void func_02015DD4(void *p);

void func_021FF260(Work *w, int key, int mode)
{
    int idx = func_022019F4(w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 4) {
        func_02015DC0(w->e[idx].h);
        w->e[idx].f0 = 0;
    }
    if (w->e[idx].f0)
        return;
    if (mode == 2) {
        func_02015DD4(w->e[idx].h);
    } else if (mode == 1) {
        func_02015DB0(w->e[idx].h);
    } else if (mode == 3) {
        func_02015DB0(w->e[idx].h);
        w->e[idx].f0 = 1;
    } else {
        func_02015DC0(w->e[idx].h);
    }
}
