/*
 * file:     comm_player_p31.c
 * unit:     yes
 * function: func_0216ABD8, func_0216AC40, func_0216AC90
 * address:  0x0216ABD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0216AF1C  0x0216AF1C  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0216AF74  0x0216AF74  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021664CC  0x021664CC  thumb  ov010
 *   func_0217C37C  0x0217C37C  thumb  ov018
 *   func_020307B0  0x020307B0  arm
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   func_0216AF3C  0x0216AF3C  thumb  ov010
 */
struct Ctx;
struct Desc;
struct LinkRecord;
struct Big;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 lo : 6;
    u32 mid : 12;
    u32 hi : 6;
    u32 rest : 8;
} Bits;

extern unsigned int func_02159B10(void *a0, void *a1);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0216AED0(void *p, u32 id);
extern int func_0216AF1C();
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5);
extern void func_0215897C(void *vm, void *task);
extern u32 func_02012138(const struct Ctx *p);
extern u16 func_0215A5CC(void *a0);
extern struct LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start);
extern void func_0217C37C();
extern u32 func_020307B0(void *p);
extern void *func_0215A5E4(void *a0);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern int func_0217C294(char *a0);
extern int func_0200E18C();
extern void func_0216AF3C(int a0);
int func_0216ABD8(int a0, int a1);
int func_0216AC40(int a0, int a1);
int func_0216AC90(int a0, int a1);


int func_0216ABD8(int a0, int a1)
{
    int buf;
    int *pb;
    int k;
    u16 *p;
    int q;
    void *s;
    void *t;
    void *r;

    pb = &buf;
    k = func_02159B10((void *)a0, (void *)a1);
    p = func_02159AE8((void *)a0, (void *)a1);
    r = func_0216AED0((void *)a1, k);
    if (r != 0) {
        q = func_0216AF1C(a1, r, 4, pb);
        if (q != 0) {
            s = func_0215A5F4((void *)a1);
            t = func_0215A5DC((void *)a1);
            func_0215897C(s, func_0216AF74((int)t, (int)func_0201210C((void *)t), q, *pb, p, 4));
        }
    }
    return 1;
}


int func_0216AC40(int a0, int a1)
{
    void *w;
    void *h;
    u8 *e;
    int key;

    w = func_0215A5DC((void *)a1);
    h = func_0201210C((void *)w);
    func_02012138(w);
    e = (u8 *)func_021664CC(func_0215A5CC((void *)a1), w, (u32 *)(&key));
    if (e != 0) {
        func_0217C37C(h, key, e, ((Bits *)(e + 0x50))->lo, ((Bits *)(e + 0x50))->hi);
        func_020307B0(e);
    }
    return 0;
}


/*
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0026 call site now attests as `matched`.
 */
int func_0216AC90(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *w;
    void *r;

t5 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AC98:
t4 = a0 + 0;
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACA0:
    w = func_02012EBC(w);
loc_0216ACA4:
    t6 = func_0200E0B0(w);
loc_0216ACA8:
a0 = t5 + 0;
a1 = t4 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACB2:
    if (r == 0) goto loc_0216ACC8;
loc_0216ACB6:
    a0 = func_0217C294(r);
loc_0216ACBA:
a1 = a0 + 0;
    a0 = func_0200E18C(t6, a1);
loc_0216ACC2:
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216ACC8:
a0 = 0;
    return a0;}
