/*
 * function: func_021A9350
 * address:  0x021A9350
 * packet:   pkt_ov021_021A9350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
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
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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
struct Big;
struct BigObj;
struct Blk38;
struct Sub0200852CObj;
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
