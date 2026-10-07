/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F377C, func_021F3798, func_021F37A4, func_021F37C8, func_021F37EC
 * address:  0x021F36C0
 * region:   ov040
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE748  0x021BE748  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   d_021F38D4     0x021F38D4  data  a4
 *   d_021F38EC     0x021F38EC  data  a4
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021BE580 0x021BE580 thumb ov021
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_021F381C 0x021F381C thumb ov040
 */
struct Big;
struct Ctx;
struct Rec94;
struct Desc;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned short u16;

typedef signed int     s32;

extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE310(u32 a, void *b, int c);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern V3 *func_021BE480(u32 a, int b, int c);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern int func_021BE748(u32 a);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
extern void func_021897A0(u8 *p, int i);
extern void func_021BE418(u8 *p, u16 i);
extern void func_021BE580(void *p);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F381C(void *, int *);
void func_021F36C0(u32 a);
void func_021F377C(u8 *p);
void func_021F3798(int *p);
void func_021F37A4(u8 *p);
int func_021F37C8(u8 *p);
void *func_021F37EC(void *p, u32 i);
extern V3 d_021F38D4;
extern char d_021F38EC[];


void func_021F36C0(u32 a)
{
    u32 s;
    u8 *q;
    u8 *e;
    V3 v;

    s = func_02188D2C((int *)a);
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 4);
    func_021897BC((char *)a, 1);
    func_021BE310(s, d_021F38EC, 0);
    q = (u8 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 3);
    v.a = d_021F38D4.a;
    v.b = 0;
    v.c = d_021F38D4.b;
    *func_021BE480(s, 0, 0) = v;
    e = func_021BE674((char *)s, 0, 0, 0);
    func_021BE6B0(e, 1);
    func_021BE6B8(e, 0);
    if (q[4] != 0) {
        func_021BE700((void *)s, 0, 0, 0, 1);
        func_021BE6CC(s, 0, 0, 0, func_021BE748((u32)e));
    }
}

void func_021F377C(u8 *p) { u8 *q; q = (u8 *)func_02188D2C((int *)p); func_021897A0(p, 1); func_021BE418(q, 0); }


void func_021F3798(int *p)
{
    func_021BE580((void *)func_02188D2C(p));
}

void func_021F37A4(u8 *p)
{
    func_021897BC((char *)p, 1);
    *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))), 3) = 1;
}

/*
 * extent: 34 code bytes followed by two zero alignment bytes.
 */
int func_021F37C8(u8 *p)
{
    func_021897BC((char *)p, 1);
    return *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(p))), 3);
}

void *func_021F37EC(void *p, u32 i)
{
    u16 *q = (u16 *)func_021897BC((char *)func_0201210C(p), 1);
    void *r;
    if (i >= 1) return 0;
    r = func_020122C0(p, 0, func_021F381C, 0);
    *q = i;
    return r;
}
