/*
 * function: func_021FF374
 * address:  0x021FF374
 * packet:   pkt_ov094_021FF374
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015E94  0x02015E94  thumb
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015EC4  0x02015EC4  thumb
 *
 * Byte-correct; MATCH blocked on two unlabelled ARM9 Thumb leaves (the integrator's;
 * no witness outside the range): func_02015E94 and func_02015EC4. Verified C
 * (match.py one, no --region, --thumb, EXACT), both over
 *   typedef struct { char pad[0x140]; unsigned int lo : 11; unsigned int b : 1;
 *                    unsigned int hi : 20; } R;
 *   int  func_02015E94(R *p) { return p->b; }
 *   void func_02015EC4(R *p) { p->b = p->b ^ 1; }   (`!p->b` is DIFF)
 * (func_02015EA0/EB0 set/clear the same bit, already matched.)
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 5;    /* 0x4c */
    unsigned int f5 : 1;
    char pad50[0x0c];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
} Work;

extern int func_022019F4(char *p, int key);
extern int func_02015E94(void *h);
extern void func_02015EA0(void *h);
extern void func_02015EB0(void *h);
extern void func_02015EC4(void *h);

void func_021FF374(Work *w, int key, int kind)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    switch (kind) {
    case 2:
        func_02015EC4(w->e[idx].h);
        break;
    case 1:
        func_02015EA0(w->e[idx].h);
        break;
    case 0:
        func_02015EB0(w->e[idx].h);
        break;
    case 3:
        if (func_02015E94(w->e[idx].h))
            w->e[idx].f5 = 1;
        func_02015EA0(w->e[idx].h);
        break;
    case 4:
        if (w->e[idx].f5)
            w->e[idx].f5 = 0;
        else
            func_02015EB0(w->e[idx].h);
        break;
    }
}
