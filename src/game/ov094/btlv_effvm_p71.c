/*
 * file:     btlv_effvm_p71.c
 * unit:     yes
 * function: func_02200608, func_02200654, func_022006A0, func_022006B4
 * address:  0x02200608
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
 *   func_021FF348  0x021FF348  thumb  ov094
 *   func_021FFD9C  0x021FFD9C  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021FF374  0x021FF374  thumb  ov094
 *   func_02017214  0x02017214  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   func_02015D30  0x02015D30  thumb
 *   func_02201934  0x02201934  thumb  ov094
 */
struct Stats;
typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 10;   /* 0x4c */
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200608;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200608 e[14];            /* 0x008 */
} Work_02200608;

typedef struct {
    void *h;               /* 0x00 */
    char pad04[0x48];
    unsigned int lo : 5;    /* 0x4c */
    unsigned int f5 : 1;
    unsigned int mid : 4;
    unsigned int f10 : 1;
    unsigned int hi : 21;
    char pad50[0x0c];
} Entry_02200654;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_02200654 e[14];            /* 0x008 */
} Work_02200654;

typedef unsigned int u32;

typedef int fx32;

typedef long long s64;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x48];
    unsigned int f0 : 1;    /* 0x4c */
    unsigned int f1 : 1;
    unsigned int flip : 1;
    char pad50[0x0c];
} Entry_022006B4;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry_022006B4 e[14];            /* 0x008 */
    char pad[0x534 - 0x008 - 14 * 0x5c];
    int active;             /* 0x534 */
    fx32 scaleEven;         /* 0x538 */
    fx32 scaleOdd;          /* 0x53c */
} Work_022006B4;

typedef struct {
    fx32 x, y, z;
} VecFx32;

extern int func_022019F4(char *p, int key);
extern int func_021FFD9C(char *p, int key);
extern int func_021FF348(Work_02200608 *w, int key);
extern void func_021FF374(Work_02200654 *w, int key, int kind);
extern void func_02017214(void *p, struct Stats *out, void *q);
extern int func_02201934(Work_022006B4 *w, int i, int mode);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015D30(void *p, u32 *src);
void func_02200608(Work_02200608 *w);
void func_02200654(Work_02200654 *w);
void func_022006A0(void *p, void *out, int flags);
void func_022006B4(Work_022006B4 *w, int i);


void func_02200608(Work_02200608 *w)
{
    Slot i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            w->e[j].f10 = func_021FF348(w, i);
        }
    }
}


void func_02200654(Work_02200654 *w)
{
    Slot i;
    int j;

    for (i = 0; i < 8; i++) {
        if (func_021FFD9C((char *)w, i)) {
            j = func_022019F4((char *)w, i);
            func_021FF374(w, i, w->e[j].f10);
            w->e[j].f5 = 0;
        }
    }
}


/*
 * Tail-call stub: forwards (p, out) and passes !(flags & 1) as the third
 * argument of func_02017214.
 */
void func_022006A0(void *p, void *out, int flags)
{
    func_02017214(p, out, (void *)((flags & 1) == 0));
}


static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


/*
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 *
 * MATCH: bytes identical; blocked on 0x02015D30, an unlabelled ARM9 Thumb
 * leaf (stores a VecFx32 at +0x104, beside the matched func_02015CAC) with no
 * witness. Filing that ARM9 leaf closes this.
 */
void func_022006B4(Work_022006B4 *w, int i)
{
    int idx = func_022019F4((char *)w, i);
    fx32 v;
    VecFx32 s;

    if (idx == -1)
        return;
    if (w->e[idx].h == 0)
        return;
    v = func_02201934(w, i, w->e[idx].flip);
    if (i & 1)
        v = FX_Mul(v, w->scaleOdd);
    else
        v = FX_Mul(v, w->scaleEven);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    func_02015CAC(w->e[idx].h, (u32 *)(&s));
    v = func_02201934(w, i, 0);
    s.x = v;
    s.y = v;
    s.z = 0x1000;
    func_02015D30(w->e[idx].h, (u32 *)(&s));
}
