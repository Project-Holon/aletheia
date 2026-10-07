/*
 * file:     field_effect_p07.c
 * unit:     yes
 * function: func_021A926C, func_021A9294, func_021A92A4, func_021A9350
 * address:  0x021A926C
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
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_02045334  0x02045334  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049238  0x02049238  arm
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0200D418  0x0200D418  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02018598  0x02018598  thumb
 *   func_021A9828  0x021A9828  thumb  ov021
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_021A9DC8  0x021A9DC8  thumb  ov021
 *   func_0201AB08  0x0201AB08  thumb
 */
struct Descriptor;
struct Obj;
struct Big;
struct BigObj;
struct Blk38;
struct Sub0200852CObj;
typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
} S_021A926C;

typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
} S_021A9294;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

struct Sel {
    void *f00;
    void *f04;
    int f08;
    int f0C;
    u8 pad10[5];
    u8 f15;
    u16 f16;
    u16 f18;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 f1D;
    u8 f1E;
    u8 pad1F;
    u32 f20;
    void *f24;
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
    u32 b4 : 1;
    u32 b5 : 1;
    u32 b6 : 9;
    u32 b15 : 1;
};

typedef signed int     s32;

extern unsigned int func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_02045334(struct Descriptor *a);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *o, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02049658(void *o, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u32 e);
extern void func_02049238(void *o);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 a);
extern u32 func_020307B0(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_0200D418(void *p);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u8 func_02018598(void *p);
extern void func_021A9828(struct Sel *s, u16 d);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 func_0200D58C(struct Blk38 *p);
extern u32 func_0201AA50(void *p);
extern u32 func_021A9DC8(void);
extern u32 func_0201AB08(void *p);
void func_021A926C(int a, S_021A926C *s);
void func_021A9294(int a, S_021A9294 *s);
void func_021A92A4(u32 a, u32 b);
void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d);


void func_021A926C(int a, S_021A926C *s)
{
    if (s->f0 == 1) {
        func_020452E8((struct Descriptor *)s->f4);
        if (s->f18 != 0) {
            func_0204B3B4((struct Obj *)s->f18);
            func_0204AFD8(s->f10);
            func_0204A8D4(s->fc);
        }
    }
}


void func_021A9294(int a, S_021A9294 *s)
{
    if (s->f0 == 1) {
        func_02045334((struct Descriptor *)s->f4);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_021A92A4(u32 a, u32 b)
{
    struct Scr *ptr;
    void *h;
    int i;
    u16 *d;
    void *o;

    o = func_020490F4(func_020275E4(), a);
    func_02049B68(o, func_02027624(), 4, 0x60, 0x20, a);
    func_02049658(o, func_02027628(), b, 0x80, 0, 0, a);
    h = func_02049EF4(o, func_0202762C(), 0, (void **)&ptr, a);
    func_02049238(o);
    d = ptr->data;
    for (i = 0; i < 0x300; i++) {
        d[i] = (d[i] + 0x80) | 0x3000;
    }
    func_020410D0((u8)b, 0, 0x15, 0x20, (u32)3, (u32)ptr->data, (u32)0, (u32)0x15, (u32)0x20, (u32)0x18);
    func_02041B6C(b);
    func_020307B0(h);
}


void func_021A9350(struct Sel *s, void *a, int b, int c, u16 d)
{
    void *t;
    void *party;
    void *mon;

    t = func_02012EBC(a);
    party = func_02012934(a);
    func_02082BCC(s, 0, 0x2C);
    s->f08 = b;
    s->f0C = c;
    s->f00 = a;
    s->f04 = func_0200D418(t);
    if (b == 5 || b == 6)
        s->b1 = 1;
    s->f24 = func_02012944(a);
    s->f20 = func_02008530(s->f24);
    mon = func_0201AB28(party, 0);
    s->f1A = func_02017E1C(mon, 0x4C, 0);
    if (s->f1A == 0) {
        s->f16 = func_02017E1C(mon, 5, 0);
        s->f18 = func_02017E1C(mon, 6, 0);
        s->f1B = func_02017E1C(mon, 10, 0);
        s->f1C = func_02017E1C(mon, 0x6E, 0);
        s->f1D = func_02018598(mon);
        func_021A9828(s, d);
    }
    s->b0 = func_020142E8((void *)func_0201296C(a), 0x960);
    if (func_0200D58C(func_0200D418(t)) == 0)
        s->b2 = 1;
    if (s->f0C == 2) {
        s->b3 = 1;
        s->f0C = 0;
    }
    if (s->f0C == 1)
        s->b3 = 1;
    s->b4 = 0;
    s->b5 = 0;
    if (s->f08 == 1 && (int)func_0201AA50(party) >= 2 && func_021A9DC8() < 0x28)
        s->b5 = 1;
    if (s->b15 || s->b2)
        s->f1E = func_02017E1C(func_0201AB28(party, func_0201AB08(party)), 0x9E, 0);
    s->f15 = s->b5 + 1;
}
