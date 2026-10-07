/*
 * file:     unit_021F36C0_p01.c
 * unit:     yes
 * function: func_021F36C0, func_021F380C, func_021F3828
 * address:  0x021F36C0
 * region:   ov042
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3A58     0x021F3A58  data  a4
 *   d_021F3AD4     0x021F3AD4  data  a4
 *   d_021F3A68     0x021F3A68  data  a4
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 */
struct Big;
struct Ctx;
struct Rec94;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    V v[9];
} T;

typedef signed int     s32;

extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void  func_021BE760(void *p, void *a, int b);
extern int func_021BE480(char *p, unsigned i, int j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(unsigned char *p, int v);
extern void func_021BE6B8(unsigned char *p, int v);
extern int func_021BE748(u32 a);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern int *func_021897BC(char *, int);
extern void func_021897A0(u8 *, int);
extern void func_021BE418(u8 *, u16);
extern void func_021BE580(void *);
void func_021F36C0(void *a0);
void func_021F380C(u8 *p);
void func_021F3828(void *p);
extern int d_021F3A58;
extern T d_021F3AD4;
extern T d_021F3A68;


void func_021F36C0(void *a0)
{
    void *s;
    u8 *q;
    char *e;
    void *b;
    u32 i;
    u8 x;
    T ta;
    T tb;

    s = (void *)func_02188D2C(a0);
    q = (u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(a0))), 4);
    func_02189764(a0, 1, func_02188C84(a0), 4);
    func_021BE760(s, &d_021F3A58, 0);
    ta = d_021F3AD4;
    for (i = 0; i < 9; i = (u8)(i + 1)) {
        e = (char *)func_021BE480(s, 0, (u8)i);
        *(V *)e = ta.v[i];
        func_021BE4A4(s, 0, (u8)i, 1);
    }
    tb = d_021F3A68;
    for (i = 0; i < 3; i = (u8)(i + 1)) {
        e = (char *)func_021BE480(s, 0, (u8)(i + 9));
        *(V *)e = tb.v[i];
        func_021BE4A4(s, 0, (u8)(i + 9), 1);
    }
    for (i = 0; i < 3; i = (u8)(i + 1)) {
        if (q[i]) {
            x = i + 9;
            func_021BE700(s, 0, x, 0, 1);
            b = func_021BE674(s, 0, x, 0);
            func_021BE6B0(b, 0);
            func_021BE6B8(b, 0);
            func_021BE6CC((int)s, 0, x, 0, func_021BE748((u32)b));
        }
    }
}

void func_021F380C(u8 *p)
{
    int x = func_02188D2C((int *)p);
    func_021897A0(p, 1);
    func_021BE418((u8 *)x, 0);
}


void func_021F3828(void *p)
{
    func_021BE580((void *)func_02188D2C(p));
}
