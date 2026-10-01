/*
 * function: func_02204698
 * address:  0x02204698
 * packet:   pkt_ov094_02204698
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-01): 3 instructions off at +0056..+005A: original loads the row table base
 *   into r0 and a<<5 into r1 (adds r0, r0, r1); this C swaps the two registers. Tried
 *   tbl[a], tbl + a, a + tbl, char-offset form, local tbl copy, row += a, 2-D int/Pos tables,
 *   no row local; all same or worse. Everything else (stack slots via decl order) matches.
 *
 * symbols:
 *   func_0220684C  0x0220684C  thumb  ov094
 *   func_022047CC  0x022047CC  thumb  ov094
 *   func_022047F8  0x022047F8  thumb  ov094
 *   d_0220AEB0  0x0220AEB0  data  a4
 *   d_0220A53C  0x0220A53C  data  a4
 *   d_0220A85C  0x0220A85C  data  a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned a:1; unsigned n:3; unsigned rest:28; } Bits;
typedef struct Obj {
    void *h0;
    char pad04[0x68 - 4];
    Bits f68;
    char pad6c[0x104 - 0x6c];
    int h104;
    int h108;
    int h10c;
    char pad110[0x240 - 0x110];
    u16 heap;
} Obj;
typedef struct Quad { u16 v[4]; } Quad;
typedef struct Pos { short x; short y; } Pos;
typedef struct Row { Pos pos[6]; int val[2]; } Row;
typedef struct Res { Obj *owner; void *h; void *e[6]; } Res;
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_0204B100(int, int, u16);
extern void *func_0204B294(void *, int, int, int, Quad *, int, u16);
extern void func_0204B404(void *, Pos *, int);
extern void func_0204B570(void *, int);
extern void func_0204B92C(void *, int);
extern void func_0204B878(void *, u16);
extern void *func_02030DA8(void *, void (*)(void *, Res *), void *, u32);
extern void func_0220684C(Obj *, void *, void (*)(void *));
extern void func_022047CC(void *, Res *);
extern void func_022047F8(void *);
extern const char d_0220AEB0[];
extern const Quad d_0220A53C;
extern Row d_0220A85C[];

void func_02204698(Obj *p, int a, int b)
{
    Res *r;
    u16 v;
    int i;
    Row *row;
    Quad quad;

    r = func_02030734((p->heap & 0x7fff) | 0x8000, 0x20, 0, d_0220AEB0, 0xc53);
    quad = d_0220A53C;
    r->owner = p;
    r->h = func_0204B100(6, 0, p->heap);
    row = &d_0220A85C[a];
    v = row->val[b];
    for (i = 0; i < 6; i++) {
        if (row->pos[i].x == -1) {
            r->e[i] = 0;
        } else {
            r->e[i] = func_0204B294(r->h, p->h104, p->h108, p->h10c, &quad, 1, p->heap);
            func_0204B404(r->e[i], &row->pos[i], 1);
            func_0204B570(r->e[i], 2);
            func_0204B92C(r->e[i], 1);
            func_0204B878(r->e[i], v);
        }
    }
    func_0220684C(p, func_02030DA8(p->h0, func_022047CC, r, 0), func_022047F8);
    p->f68.n++;
}
