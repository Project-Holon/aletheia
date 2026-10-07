/*
 * file:     bsubway_scr_p17.c
 * unit:     yes
 * function: func_021C9550, func_021C95D8, func_021C963C, func_021C9660, func_021C9690
 * address:  0x021C9550
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
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAC80     0x021DAC80  data  a4
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02047504  0x02047504  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_020478B8  0x020478B8  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   d_021DAC94  0x021DAC94  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02047AC8  0x02047AC8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 */
struct Actor;
struct VecFx32;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Arg;
typedef unsigned int u32;

typedef struct V3 { int v[3]; } V3;

typedef struct Rec { u32 h; V3 pos; } Rec;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;

typedef struct { u32 a[6]; u32 b[9]; } T;

typedef struct { u32 f0; u32 f4; } E;

extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u16 func_0216D5F8(void *p);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32, void *, u32, u32, Rec *, u32);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u32 *b);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020478B8(void *a, int idx, int amount);
extern void func_021AC154(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0207ADC4(void *p);
extern void func_021AC1B8(u32 a, T *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
void func_021C9550(u32 a, u32 b);
void func_021C95D8(u32 a, u32 *b);
void func_021C963C(void *task, Q *q);
void func_021C9660(u32 a, Q *q);
void func_021C9690(u32 a, E *e);
extern u32 d_021DAC80[];
extern T d_021DAC94;


/*
 * Addresses are Black-image addresses.
 */
void func_021C9550(u32 a, u32 b)
{
    V3 v;
    Rec r;

    func_0216D88C((const struct Actor *)a, (struct VecFx32 *)&v);
    switch (func_0216D5F8((void *)a)) {
    case 0:
        v.v[2] -= 0x10000;
        break;
    case 1:
        v.v[2] += 0x10000;
        break;
    case 2:
        v.v[0] -= 0x10000;
        break;
    case 3:
        v.v[0] += 0x10000;
        break;
    }
    r.h = func_021ABEA0(b, 0xc);
    r.pos = v;
    func_021ABFA8(b, d_021DAC80, 0, 0, &r, 0);
}


/*
 * The `adds r4, r6, #0` before the first loop is the second loop's counter
 * initialised to 0 and shared as the first loop's constant 0 argument; both
 * loops use one counter i. Callee widths from arm9 func_02048744.
 * Addresses are Black-image addresses.
 */
void func_021C95D8(u32 a, u32 *b)
{
    u32 *p = (u32 *)func_021AC1AC(a);
    int i;

    b[0] = p[0];
    func_021AC1CC(a, p + 1);
    b[5] = (u32)func_02047400((void *)(((u32 *)b[0])[1]), 0, (void *)(((u32 *)b[0])[1]));
    for (i = 0; i < 3; i++)
        b[2 + i] = (u32)func_02047564((struct G3dOwner *)b[5], (const struct G3dOwner *)(((u32 *)b[0])[2 + i]), 0);
    b[1] = (u32)func_0204767C(b[5], b + 2, 3);
    for (i = 0; i < 3; i++)
        func_020477A4((struct G3dSys *)b[1], (u16)i);
}

void func_021C963C(void *task, Q *q)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204762C((struct Rec *)q->f8[i]);
    func_02047738((struct Rec *)q->f4);
    func_02047504((struct Rec *)q->f14);
}

void func_021C9660(u32 a, Q *q)
{
    int done = 1;
    int i;
    for (i = 0; i < 3; i++) {
        if (func_020478B8((void *)q->f4, (u16)i, (u32)0x1000) == 1)
            done = 0;
    }
    if (done)
        func_021AC154(a);
}

void func_021C9690(u32 a, E *e)
{
    T t = d_021DAC94;
    func_0207ADC4(t.b);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)e->f4, (struct Arg *)(&t));
}
