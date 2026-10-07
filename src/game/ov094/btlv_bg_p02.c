/*
 * file:     btlv_bg_p02.c
 * unit:     yes
 * function: func_02209318, func_02209458
 * address:  0x02209318
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
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020870D0 0x020870D0 arm
 *   func_022094BC 0x022094BC thumb ov094
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   func_02209744 0x02209744 thumb ov094
 *   d_0220ABC0 0x0220ABC0 data a4
 *   d_0220ABC8 0x0220ABC8 data a4
 *   d_0220ABE0 0x0220ABE0 data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02030EAC  0x02030EAC  arm
 */
struct Obj;
struct Node;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef short s16;

typedef struct { s16 x, y, z, rest; } Pos;

typedef struct { int v[2]; } Pair;

typedef struct { int v[6]; } Six;

typedef struct { int v[2][6]; } Twelve;

typedef struct { u32 h[7]; } Entry;

typedef struct {
    u32 h[2]; Entry e[2]; u32 obj40, obj44, obj48;
    int left[2]; u64 time[2]; int state[2]; void *task;
    char pad70[4]; u16 heap;
} Work;

typedef unsigned char  u8;

typedef struct {
    int f[7];
} Row;

typedef struct {
    Row r[2];
    char pad[0x6c - 0x38];
    void *m6c;
    void *m70;
} W;

extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u64 func_020870D0(void);
extern void func_022094BC(u8 *p, int i, int a, int b);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_02209744(int unused, int x);
extern void func_0204B3B4(struct Obj *p);
extern void func_02030EAC(struct Node *n);
void func_02209318(Work *m, int a, int b);
void func_02209458(W *w);
extern const Pair d_0220ABC0;
extern const Six d_0220ABC8;
extern const Twelve d_0220ABE0;

/*
 * lever: y is a full int, narrowed by assignment to pos.y; s16 y sinks
 *   its home store and swaps it with the explicit handle-offset spill.
 *   Aggregate locals are declared icons, values, pos, types in that order.
 */
void func_02209318(Work *m, int a, int b)
{
    Six icons;
    Twelve values;
    Pos pos = {0, 0, 0, 0};
    Pair types;
    int y;
    int off;
    int i, j;
    int *row;
    icons = d_0220ABC8;
    types = d_0220ABC0;
    values = d_0220ABE0;
    for (i = 0; i < 2; i++) {
        if ((i == 0 && a != 0) || (i == 1 && b != 0)) {
            off = i * 4;
            y = types.v[i];
            row = values.v[i];
            for (j = 0; j < 6; j++) {
                pos.x = icons.v[j];
                pos.y = y;
                pos.z = row[j];
                m->e[i].h[j] = (u32)func_0204B294((void *)*(u32 *)((char *)m + off), m->obj40, m->obj48, m->obj44, &pos, 0, m->heap);
                func_0204B92C((struct Obj *)m->e[i].h[j], 1);
            }
        }
    }
    if (a > 5999) a = 5999;
    if (b > 5999) b = 5999;
    m->left[0] = a;
    m->left[1] = b;
    m->time[1] = func_020870D0();
    m->time[0] = m->time[1];
    func_022094BC((u8 *)m, 0, 0, 0);
    func_022094BC((u8 *)m, 1, 0, 0);
    m->task = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))func_02209744, m, 0);
}


void func_02209458(W *w)
{
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            if (w->r[i].f[j + 2] != 0) {
                func_0204B3B4((struct Obj *)w->r[i].f[j + 2]);
                w->r[i].f[j + 2] = 0;
            }
        }
    }
    if (w->m6c != 0) {
        func_02030EAC(w->m6c);
        w->m6c = 0;
    }
    if (w->m70 != 0) {
        func_02030EAC(w->m70);
        w->m70 = 0;
    }
}
