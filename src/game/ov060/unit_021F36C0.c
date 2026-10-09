/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3724, func_021F374C, func_021F37B8, func_021F37D8, func_021F37E4, func_021F3850, func_021F3870, func_021F3880, func_021F3938, func_021F3950, func_021F399C
 * address:  0x021F36C0
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   d_021F3A34     0x021F3A34  data  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021F39F4  0x021F39F4  thumb  ov060
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B40  0x02012B40  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
struct Big;
struct Ctx;
struct BigObj;
struct Rec1B0;
struct SaveBlock;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct {
    u16 lo : 3;
} Bf;

typedef struct V {
    int a;
    int b;
    int c;
} V;

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern u32 func_02012138(const struct Ctx *a);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void func_021BE310(void *a, void *b, int c);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021897A0(unsigned char *p, int id);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE580(void *p);
extern void func_021F39F4(u8 *a, void *b);
extern V *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE4B4(void *p, int i, u16 j, int v);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_02012B40(const struct BigObj *p);
extern void *func_020127B8(void *p);
extern void *func_020127AC(struct SaveBlock *p, u32 idx);
extern u16 func_0200BDF8(struct Rec1B0 *p);
extern u16 func_0200BDFC(struct Rec1B0 *p);
extern unsigned int func_02026454(void *p);
extern u32 func_02026474(void *obj);
extern void func_021BE700(void *p, int i, int j, int k, int flag);
extern u8 *func_021BE674(void *p, int i, int j, u16 k);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);
extern void func_021BE6CC(int a, int b, int c, int d, int e);
void func_021F36C0(void *a);
void func_021F3724(unsigned char *p);
void func_021F374C(void *o);
void func_021F37B8(char *p, V *v);
int func_021F37D8(void *p);
void func_021F37E4(u8 *out, void *b, void *c, void *d);
void func_021F3850(char *p);
int func_021F3870(int x);
u8 func_021F3880(void *a, void *b, void *unused);
void *func_021F3938(void *p);
void func_021F3950(void *unused, void *p);
void func_021F399C(u8 *o, void *p, V *v);
extern char d_021F3A34[];




void func_021F36C0(void *a)
{
    u32 r6;
    void *s;
    u32 c;
    u32 h;
    void *v;
    void *o;

    r6 = func_02188C84(a);
    s = (void *)func_02188D2C(a);
    c = (u32)func_02188C80(a);
    h = (u32)func_020120F4((const struct Ctx *)c);
    func_02012EC4((struct Big *)h);
    v = func_021F3938((void *)func_02012138((const struct Ctx *)c));
    o = func_02189764(a, 0, r6, 4);
    func_021BE310(s, d_021F3A34, 0);
    func_021F37E4(o, a, (void *)h, v);
    func_021F3950(o, s);
}




void func_021F3724(unsigned char *p)
{
    func_02012EC4(func_020120F4(func_02188C80(p)));
    func_021BE418((unsigned char *)func_02188D2C((int *)p), 0);
    func_021897A0(p, 0);
}




void func_021F374C(void *o)
{
    u32 c;
    u32 h;
    void *s;
    u8 *q;
    void *v;

    c = (u32)func_02188C80(o);
    h = (u32)func_020120F4((const struct Ctx *)c);
    func_02012EC4((struct Big *)h);
    s = (void *)func_02188D2C(o);
    q = (u8 *)func_021897BC(o, 0);
    v = func_021F3938((void *)func_02012138((const struct Ctx *)c));
    if (v != 0) {
        if (((Bf *)((u8 *)v + 0x86))->lo != *q) {
            func_021F3850((char *)s);
            *q = func_021F3880((void *)h, s, v);
        }
    }
    func_021BE580(s);
    if (q[1] != 0) {
        func_021F39F4(q, s);
    }
}



void func_021F37B8(char *p, V *v)
{
    unsigned char *o;
    void *s;
    o = (unsigned char *)func_021897BC(p, 0);
    s = (void *)func_02188D2C((int *)p);
    func_021F399C(o, s, v);
}

int func_021F37D8(void *p)
{
    return *(unsigned char *)((char *)func_021897BC(p, 0) + 1);
}




void func_021F37E4(u8 *out, void *b, void *c, void *d)
{
    void *s;
    int i;
    V *p;

    s = (void *)func_02188D2C(b);
    for (i = 0; i < 0x15; i++) {
        p = func_021BE480(s, 0, i);
        p->a = 0x1F8000;
        p->b = 0x20000;
        p->c = 0x1B8000;
        func_021BE4A4(s, 0, (u16)i, 1);
        func_021BE4B4(s, 0, i, 1);
    }
    *out = func_021F3880(c, s, d);
}




void func_021F3850(char *p)
{
    int i;

    for (i = 0; i < 0x14; i++) {
        func_021BE4B4(p, 0, (u16)i, 1);
    }
}



int func_021F3870(int x)
{
    int r = x / 3;

    if (r > 9) {
        r = 9;
    }
    return r;
}




u8 func_021F3880(void *a, void *b, void *unused)
{
    int r6;
    int r4;
    int r5;
    int r7;
    int e;
    V *p;

    r6 = func_02012B80(a);
    r4 = r6 - func_02012B58(a);
    if (r4 < 0) {
        r4 += func_02012B40(a);
    }
    if (r6 == func_02012B58(a)) {
        e = (int)func_020127B8(a);
    } else {
        e = (int)func_020127AC(a, r6);
    }
    r7 = e;
    r5 = func_021F3870(func_0200BDF8((struct Rec1B0 *)r7));
    r7 = func_021F3870(func_0200BDFC((struct Rec1B0 *)r7));
    p = func_021BE480(b, 0, r5 + 10);
    r4 = (r4 << 22) + 0x1F8000;
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    p = func_021BE480(b, 0, r7);
    p->a = r4;
    p->b = 0x20000;
    p->c = 0x1B8000;
    func_021BE4B4(b, 0, (u16)(r5 + 10), 0);
    func_021BE4B4(b, 0, (u16)r7, 0);
    return r6;
}




void *func_021F3938(void *p)
{
    if (func_02026454(p) == 2) {
        return (void *)func_02026474(p);
    }
    return 0;
}




void func_021F3950(void *unused, void *p)
{
    int i;
    u8 *e;

    func_021BE4B4(p, 0, 0x14, 1);
    for (i = 0; i < 3; i++) {
        func_021BE700(p, 0, 0x14, (u16)i, 1);
        e = func_021BE674(p, 0, 0x14, (u16)i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 0);
    }
}




void func_021F399C(u8 *o, void *p, V *v)
{
    int i;

    func_021BE4B4(p, 0, 0x14, 0);
    for (i = 0; i < 3; i++) {
        func_021BE6CC((int)p, 0, 0x14, (u16)i, 0);
    }
    *func_021BE480(p, 0, 0x14) = *v;
    o[1] = 1;
}
