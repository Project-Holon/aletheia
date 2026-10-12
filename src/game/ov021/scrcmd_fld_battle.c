/*
 * file:     scrcmd_fld_battle.c
 * unit:     yes
 * function: func_021B5700, func_021B574C, func_021B57CC, func_021B5824, func_021B58B0, func_021B59B0
 * address:  0x021B5700
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201A354  0x0201A354  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_02030734  0x02030734  arm
 *   g_021DE248     0x021DE248  data  a1
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02019ED4  0x02019ED4  thumb
 *   func_0201A090  0x0201A090  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
 */

typedef struct BattleTaskWork {
    unsigned int sys;
    unsigned int f4;
    unsigned char pad8[4];
    unsigned int party;
    unsigned int w;
    unsigned char rulesFlag;
    unsigned char r2Flag;
    unsigned short k;
    unsigned int out;
} BattleTaskWork;

struct WordSet;
struct Blk37;
struct Big;
struct BigObj;
struct Ctx;
struct Desc;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u8 f14;
    u8 f15;
    u16 f16;
    u16 *f18;
} Work;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02158F74(void *p);
extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u16 func_0215A5CC(void *a0);
extern void *func_0215A5DC(void *a0);
extern void *func_0201A354(int a, int b);
extern u32 func_020307B0(void *p);
extern void func_0215897C(void *vm, void *task);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void *func_0200CA1C(void *a);
extern u32 func_0200CED4(struct Blk37 *p, u16 id);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern int func_02019ED4(void *ctx, void *q);
extern int func_0201A090(void *rules, void *party, u32 *mask);
extern void *func_0200BAC8(void *);
extern u32 func_0200BBA8(void *a);
extern void *func_0200BAF4(int a0, int a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern struct Obj *func_021CC720(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heap);
extern int func_021CC810(struct Obj *p);
extern u32 func_021CC7B4(struct Obj *p, u32 *out);
int func_021B5700(void *a0, void *a1);
int func_021B574C(int a0, int a1);
u16 func_021B57CC(void *a0, void *a1, u32 a2, int a3);
u16 *func_021B5824(u8 *a0, void *a1, u16 *a2, int a3);
void *func_021B58B0(void *sys, int flag, void *rules, u16 *out, u16 k);
int func_021B59B0(int a0, int *state, Work *w);
extern const char g_021DE248[];



int func_021B5700(void *a0, void *a1)
{
    void *r6 = func_0215A5F4(a1);
    void *s = func_0215A5E4(a1);
    unsigned int r7;
    u16 *r5;

    r6 = func_02158F74(r6);
    r7 = func_02159B10(a0, a1);
    r5 = func_02159AE8(a0, a1);
    *r5 = func_021B57CC(s, r6, r7, func_0215A5CC(a1));
    return 0;
}



/*
 * func_0201A354 is filed as src/matched/arm9/func_0201A354.c (witness).
 */
int func_021B574C(int a0, int a1)
{
    void *s8 = func_0215A5F4((void *)a1);
    void *s4 = func_0215A5DC((void *)a1);
    int r4 = func_02159B10((void *)a0, (void *)a1);
    u16 *r7 = func_02159AE8((void *)a0, (void *)a1);
    u16 r6 = func_0215A5CC((void *)a1);
    void *r5 = func_0201A354(r4, r6);
    int r1 = 1;
    u16 d = r4 + 0xffec;
    void *res;

    if (d > 2) {
        r1 = 0;
    }
    res = func_021B58B0((void *)s4, r1, r5, r7, r6);
    func_020307B0(r5);
    if (res == 0) {
        return 0;
    }
    func_0215897C(s8, res);
    return 1;
}



u16 func_021B57CC(void *a0, void *a1, u32 a2, int a3)
{
    u16 n = 0;
    u16 i = 0;
    void *t;
    u16 *v;

    t = func_0201A354(a2, a3);
    v = func_021B5824(t, a0, &n, a3);
    for (i = 0; i < n; i++) {
        func_0201EE60(a1, i, v[i]);
    }
    func_020307B0(v);
    func_020307B0(t);
    return n;
}



u16 *func_021B5824(u8 *a0, void *a1, u16 *a2, int a3)
{
    int i = 0;
    void *r;
    u16 *v;

    *a2 = 0;
    r = func_0200CA1C(a1);
    v = func_02030734((u16)((a3 & 0x7fff) | 0x8000), 0x40, 1, g_021DE248, 0xac);
    for (i = 0; i < 0x28b; i++) {
        if (a0[0xa + i / 8] & (1 << (i % 8))) {
            if (func_0200CED4(r, (u16)i)) {
                if (*a2 >= 0x20) {
                    break;
                }
                v[(*a2)++] = i;
            }
        }
    }
    return v;
}



/*
 * Two spellings carry the block layout: the else arm's result goes through
 * a temporary (tmp), which keeps the inner if/else ahead of the outer else
 * rather than sunk before the rest; and the not-1 path is an if/else of two
 * stores, not a ternary (which compiles branch-free).  `b = 0` after the
 * task call is what puts its zero in r1.
 *
 * Addresses are Black-image addresses.
 */
void *func_021B58B0(void *sys, int flag, void *rules, u16 *out, u16 k)
{
    u32 mask = 0;
    void *w;
    void *party;
    int r2;
    void *q;
    void *task;
    BattleTaskWork *e;
    u32 b;
    int r1;
    int tmp;

    w = func_020120F4(sys);
    mask = 0;
    party = func_02012934(w);
    if (flag) {
        r1 = func_02019ED4(rules, party);
    } else {
        r1 = func_0201A090(rules, party, &mask);
    }
    q = func_0200BAC8(func_02012EBC(w));
    if (func_0200BBA8(q) == 1) {
        mask = 0;
        w = func_0200BAF4((int)q, k);
        if (flag) {
            r2 = func_02019ED4(rules, w);
        } else {
            tmp = func_0201A090(rules, w, &mask);
            r2 = tmp;
        }
    } else {
        if (r1) {
            *out = 3;
        } else {
            *out = 0;
        }
        return 0;
    }
    if (r1 && r2) {
        if (w) {
            func_020307B0(w);
        }
        *out = 3;
        return 0;
    }
    task = func_020122C0(sys, 0, (void *)func_021B59B0, 0x1c);
    b = 0;
    e = func_020124E8(task);
    e->sys = (u32)sys;
    e->f4 = (u32)func_0201210C(sys);
    e->out = (u32)out;
    e->k = k;
    e->party = (u32)party;
    e->w = (u32)w;
    if (r1) {
        b = 1;
    }
    e->rulesFlag = b;
    e->r2Flag = r2 ? 1 : 0;
    return task;
}



int func_021B59B0(int a0, int *state, Work *w)
{
    int loc;

    switch (*state) {
    case 0:
        w->f8 = (u32)func_021CC720(w->f4, w->fc, w->f10, w->f14, w->f15, w->f16);
        (*state)++;
        break;
    case 1:
        if (func_021CC810((struct Obj *)w->f8)) {
            *w->f18 = func_021CC7B4((struct Obj *)w->f8, (u32 *)(&loc));
            if (loc == 1) {
                *w->f18 = 3;
            }
            func_020307B0((void *)w->f10);
            return 1;
        }
        break;
    }
    return 0;
}
