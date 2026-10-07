/*
 * file:     field_player_grid_event_p03.c
 * unit:     yes
 * function: func_021BF564, func_021BF584, func_021BF58C, func_021BF5B4
 * address:  0x021BF564
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
 *   func_02043658  0x02043658  arm
 *   func_02043668  0x02043668  arm
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_02188DB0  0x02188DB0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BF694  0x021BF694  thumb  ov021
 *   func_021BF76C  0x021BF76C  thumb  ov021
 */
struct Desc;
struct Obj;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    void *x0;
    u32 x4;
} Work_021BF58C;

typedef struct {
    int f0;
    int f4;
    unsigned char pad8[0x54];
    int f5C;
    int f60;
    int f64;
} Work_021BF5B4;

extern u32 func_02043658(void);
extern u32 func_02043668(void);
extern void func_02188DA0(void);
extern void func_02043534(u32 v);
extern void func_020435F4(u32 v);
extern void func_02188DB0(u8 *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
int func_021BF694(int a, int *s, int *q);
extern int func_021BF76C(void *task, int *state, void **q);
void func_021BF564(void);
void func_021BF584(u8 *a0);
void *func_021BF58C(int a, void *p, int c);
void *func_021BF5B4(int a, int b, int c, int d, int e, int f);


/*
 * Addresses are Black-image addresses.
 */
void func_021BF564(void)
{
    u32 a = func_02043658();
    u32 b = func_02043668();

    func_02188DA0();
    func_02043534(a);
    func_020435F4(b);
}


/*
 * Tail-call thunk: forwards to func_02188DB0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021BF584(u8 *a0)
{
    func_02188DB0(a0);
}


void *func_021BF58C(int a, void *p, int c)
{
    void *task = func_020122C0(p, (void *)a, func_021BF694, 0x68);
    Work_021BF58C *w = func_020124E8(task);

    w->x4 = c;
    w->x0 = p;
    return task;
}



void *func_021BF5B4(int a, int b, int c, int d, int e, int f)
{
    void *t = func_020122C0((void *)b, (void *)a, func_021BF76C, 0x68);
    Work_021BF5B4 *w = func_020124E8(t);
    w->f4 = c;
    w->f0 = b;
    w->f5C = d;
    w->f60 = e;
    w->f64 = f;
    return t;
}
