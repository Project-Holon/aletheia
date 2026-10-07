/*
 * file:     btlv_effvm_p61.c
 * unit:     yes
 * function: func_021FF228, func_021FF260, func_021FF2D8, func_021FF304
 * address:  0x021FF228
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_02015C1C  0x02015C1C  thumb
 *   func_022006B4  0x022006B4  thumb  ov094
 *   func_02015DB0  0x02015DB0  thumb
 *   func_02015DC0  0x02015DC0  thumb
 *   func_02015DD4  0x02015DD4  thumb
 *   func_02015DF8  0x02015DF8  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015E28  0x02015E28  thumb
 *   func_02015E70  0x02015E70  thumb
 *   func_02015E4C  0x02015E4C  thumb
 */
typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF228;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_021FF228 e[14];            /* 0x008 */
} Work;

typedef struct {
    void *h;
    char pad04[0x48];
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF260;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_021FF2D8;

typedef struct {
    void *h;
    char pad[0x58];
} Entry_021FF304;

extern int func_022019F4(char *p, int key);
extern void func_02015C1C(void *h);
extern void func_022006B4(Work *w, int key);
extern void func_02015DB0(void *p);
extern void func_02015DC0(void *p);
extern void func_02015DD4(void *p);
extern int func_02015DF8(void *h);
extern void func_02015E04(void *p);
extern void func_02015E28(void *p);
extern void func_02015E70(void *p);
extern void func_02015E4C(void *p);
void func_021FF228(Work *w, int key);
void func_021FF260(Work *w, int key, int mode);
int func_021FF2D8(Work *w, int key);
void func_021FF304(Work *w, int key, int mode);


void func_021FF228(Work *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return;
    w->e[idx].flip = 0;
    func_02015C1C(w->e[idx].h);
    func_022006B4(w, key);
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   func_02015DB0, func_02015DC0, func_02015DD4.  All Ilias's; verified C
 *   (one --thumb, no --region, EXACT each; +0x140 is a register-like word):
 *     struct R { unsigned int : 8; unsigned int f : 1; };
 *     void func_02015DB0(void *p) { *(unsigned int *)((char *)p + 0x140) |= 0x100u; }
 *     void func_02015DC0(void *p) { *(unsigned int *)((char *)p + 0x140) &= ~0x100u; }
 *     void func_02015DD4(void *p) { ((struct R *)((char *)p + 0x140))->f ^= 1; }
 *   Re-run this file once layout/matched/arm9 shards for all three exist.
 */
void func_021FF260(Work *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

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


int func_021FF2D8(Work *w, int key)
{
    int idx = func_022019F4((char *)w, key);

    if (idx == -1)
        return 0;
    if (w->e[idx].h == 0)
        return 0;
    return func_02015DF8(w->e[idx].h);
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 *   func_02015E28 (0x02015E28) and func_02015E70 (0x02015E70).  Both are Ilias's;
 *   verified C (one --thumb, no --region, EXACT each):
 *     struct R { unsigned int : 9; unsigned int f : 2; };
 *     void func_02015E28(void *p) { ((struct R *)((char *)p + 0x140))->f |= 2; }
 *     void func_02015E70(void *p) { ((struct R *)((char *)p + 0x140))->f &= ~2u; }
 *   Re-run this file once layout/matched/arm9 shards for both exist.
 */
void func_021FF304(Work *w, int key, int mode)
{
    int idx = func_022019F4((char *)w, key);

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
