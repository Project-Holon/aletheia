/*
 * function: func_021FF304
 * address:  0x021FF304
 * packet:   pkt_ov094_021FF304
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: two unlabelled arm9 Thumb leaves (relocation wildcards, no witness):
 *   func_02015E28 (0x02015E28) and func_02015E70 (0x02015E70).  Both are Ilias's;
 *   verified C (one --thumb, no --region, EXACT each):
 *     struct R { unsigned int : 9; unsigned int f : 2; };
 *     void func_02015E28(void *p) { ((struct R *)((char *)p + 0x140))->f |= 2; }
 *     void func_02015E70(void *p) { ((struct R *)((char *)p + 0x140))->f &= ~2u; }
 *   Re-run this file once layout/matched/arm9 shards for both exist.
 *
 * symbols:
 *   func_02015E04  0x02015E04  thumb
 *   func_02015E28  0x02015E28  thumb
 *   func_02015E70  0x02015E70  thumb
 *   func_02015E4C  0x02015E4C  thumb
 *   func_022019F4  0x022019F4  thumb  ov094
 */
typedef struct {
    void *h;
    char pad[0x58];
} Entry;
typedef struct {
    int pad00;
    void *obj;
    Entry e[14];
} Work;

extern int func_022019F4(Work *w, int key);
extern void func_02015E04(void *p);
extern void func_02015E28(void *p);
extern void func_02015E70(void *p);
extern void func_02015E4C(void *p);

void func_021FF304(Work *w, int key, int mode)
{
    int idx = func_022019F4(w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    if (mode == 1)
        func_02015E04(w->e[idx].h);
    else if (mode == 2)
        func_02015E28(w->e[idx].h);
    else if (mode == 3)
        func_02015E70(w->e[idx].h);
    else
        func_02015E4C(w->e[idx].h);
}
