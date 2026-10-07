/*
 * file:     field_player_grid_event_p04.c
 * unit:     yes
 * function: func_021BF5E8, func_021BF61C, func_021BF644
 * address:  0x021BF5E8
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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BF8EC  0x021BF8EC  thumb  ov021
 *   func_021BFA6C  0x021BFA6C  thumb  ov021
 *   func_021BFB90  0x021BFB90  thumb  ov021
 */
struct Desc;
struct Obj;
typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 pad[21]; u32 f5C; u32 f60; u32 f64; } X;

typedef struct {
    int f0;
    int f4;
} Work;

typedef struct {
    int f0;
    int f4;
} Ent;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int func_021BF8EC(void *task, int *state, void **q);
extern void func_021BFA6C(void);
int func_021BFB90(int task, int *state, int *q);
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_021BF61C(int a, int b, int c);
int func_021BF644(int a, int b, int c);

/*
 * Addresses are Black-image addresses.
 */
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f)
{
    u32 h = (u32)func_020122C0((void *)b, (void *)a, func_021BF8EC, 0x68);
    X *x = func_020124E8((struct Obj *)h);
    x->f4 = c;
    x->f0 = b;
    x->f5C = d;
    x->f60 = e;
    x->f64 = f;
    return h;
}


void *func_021BF61C(int a, int b, int c)
{
    void *t = func_020122C0((void *)b, (void *)a, func_021BFA6C, 0x68);
    Work *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    return t;
}


int func_021BF644(int a, int b, int c)
{
    int h = (int)func_020122C0((void *)b, (void *)a, func_021BFB90, 0x68);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f4 = c;
    e->f0 = b;
    return h;
}
