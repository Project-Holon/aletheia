/*
 * function: func_021B9044
 * address: 0x021B9044
 * packet: pkt_ov172_021B9044
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BE02C 0x021BE02C thumb ov172
 *   func_021BE030 0x021BE030 thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE0B0 0x021BE0B0 thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_021BE318 0x021BE318 thumb ov172
 *   func_021BE34C 0x021BE34C thumb ov172
 *   func_021B7590 0x021B7590 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021B7B80 0x021B7B80 thumb ov172
 *   func_021B8084 0x021B8084 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B8B34 0x021B8B34 thumb ov172
 *   func_021B8B48 0x021B8B48 thumb ov172
 *   func_021B8B5C 0x021B8B5C thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021B8B84 0x021B8B84 thumb ov172
 *   func_021B9580 0x021B9580 thumb ov172
 *   func_021B97AC 0x021B97AC thumb ov172
 *   func_021B99B4 0x021B99B4 thumb ov172
 *   func_021B9C1C 0x021B9C1C thumb ov172
 *   func_021B9C9C 0x021B9C9C thumb ov172
 *   func_021B9D04 0x021B9D04 thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021B9E3C 0x021B9E3C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021BA050 0x021BA050 thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_021BA248 0x021BA248 thumb ov172
 *   func_021BA24C 0x021BA24C thumb ov172
 *   func_021BA254 0x021BA254 thumb ov172
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02045770 0x02045770 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02043B5C 0x02043B5C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct S {
    int state;
    int f4;
    int f8;
    u8 padC[4];
    void *f10;
    u8 pad14[0x14];
    int f28;
    void *f2C;
    u8 pad30[4];
    int f34;
    u8 f38;
    u8 pad39;
    u8 f3A[0x20];
    u8 f5A[0x20];
    u8 pad7A[2];
    void *f7C;
    u8 pad80[4];
    int f84;
    u16 f88;
    u8 pad8A[2];
    int f8C;
    u8 pad90[8];
    void *f98;
    void *f9C;
} S;

typedef signed short   s16;
typedef signed int     s32;
struct Actor;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct PrintSys;
struct St;
extern u16 func_021BE00C(u16 *p);
extern u32 func_021BE02C(void *p);
extern void func_021BE030(void *p, u32 v);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern void func_021BE0B0(void *p, u32 v);
extern u32 func_021BE044(void *p);
extern void func_021BE318(char *a0, void *a1);
extern void func_021BE34C(void *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021B8084(void *a, char *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern void func_021B8B34(void *p, u32 a, u32 b);
extern int func_021B8B48(void *p, u32 base, int a);
extern u32 func_021B8B5C(void *p, u32 base);
extern u32 func_021B8B68(int unused, char *p);
extern u32 func_021B8B84(int unused, char *p);
extern void func_021B9580(u8 *c, u8 *q);
extern void func_021B97AC(void *ctx, struct St *st);
extern void func_021B99B4(void *a0, char *a1);
extern void func_021B9C1C(void *p, char *q, int id);
extern void func_021B9C9C(void *p, char *q);
extern void func_021B9D04(int self, int *q);
extern int func_021B9DF8(void *p, int *out);
extern void func_021B9E3C(void *p, char *q);
extern void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern int func_021B9F4C(int a, int b, int mode);
extern void func_021BA050(u32 *p);
extern u32 func_021BA244(void *p);
extern int func_021BA248(void *t);
extern int func_021BA24C(void *t);
extern int func_021BA254(void *t);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0203630C(void);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32 index);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02043B5C(struct CharBuf *buf, u8 value);

u32 func_021B9044(void *p, S *s)
{
    u32 heap;
    u32 a;
    u32 b;

    heap = func_021BE00C(p);
    switch (s->state) {
    case 0:
        if (func_021BE02C(p) == 1)
            func_0202208C(0, 1, 1, 0, 6, 1, heap);
        else
            func_0202208C((void *)4, 1, 1, 0, 6, 1, heap);
        s->state = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            s->state = 5;
        break;
    case 2:
        func_0202208C((void *)4, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 0);
        s->state = 4;
        break;
    case 3:
        if (s->f4 == 6 && func_0204B98C(s->f9C) == 1)
            break;
        a = func_021BDFDC(p);
        if (s->f8 != 0 && func_021B7590((int)p, (char *)a) != 1)
            break;
        func_0202208C(0, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 1);
        s->state = 4;
        break;
    case 4:
        if (func_020221A4() != 1)
            break;
        if (s->f4 == 6)
            return 3;
        return 4;
    case 5:
        func_021B9580(p, (u8 *)s);
        break;
    case 6:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (func_021B8740((int)p, func_021BDFE4(p), 6, 0) == 1)
                s->state = 7;
            break;
        }
        s->state = 5;
        break;
    case 7:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        b = func_021BDFE4(p);
        a = func_021B8B68((int)p, (char *)b);
        b = func_021B8B5C(p, b);
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (a != 0xFF) {
                if (a == b) {
                    s->state = 8;
                    s->f4 = 0;
                } else {
                    s->state = 5;
                }
            }
        } else {
            s->state = 5;
        }
        break;
    case 8:
        func_021B97AC(p, (struct St *)s);
        break;
    case 9:
        func_021B9C9C(p, (char *)s);
        break;
    case 10:
        func_021B9D04((int)p, (int *)s);
        break;
    case 11:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) == 1)
            s->state = 12;
    case 12:
        if (func_021BE054(p) > 1)
            break;
        a = func_021BDFDC(p);
        s->f4 = 7;
        s->state = 3;
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)a);
        func_021B7B80((int)p, (char *)a);
        s->f8 = 1;
        break;
    case 13:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021BE0B0(p, 1);
        func_021B9C1C(p, (char *)s, 0x24);
        s->state = 14;
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 14:
        if (func_02035C60() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    case 15:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) != 1)
            break;
        a = func_021BDFDC(p);
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)a);
        s->state = 18;
        break;
    case 16:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x25);
        s->state = 17;
        s->f88 = 0;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 17:
        s->f88++;
        if (func_02035C60() == 1 || (func_020362DC() & 3) || s->f88 >= 300)
            s->state = 18;
        break;
    case 18:
        func_021B8B34(p, func_021BDFE4(p), 0x2F);
        s->state = 19;
        break;
    case 19:
        if (func_021B8B48(p, func_021BDFE4(p), 0x2F) != 1)
            break;
        s->f4 = 7;
        s->state = 3;
        func_021BE34C(p);
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 20:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x26);
        s->state = 21;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 21:
        if (func_02035C60() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021BE0B0(p, 1);
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    }
    func_021B99B4(p, (char *)s);
    func_021BA050(s->f10);
    if (s->f28 == 1) {
        void *h = (void *)func_021BE044(p);
        if (func_0201C6C4(h, func_02045770(s->f7C)) == 0) {
            func_02045334(s->f7C);
            func_02045374(s->f7C);
            func_020409B4(4);
            s->f28 = 0;
            if (s->f84 == 1) {
                s->f84 = 0;
                func_021BE318(p, s->f7C);
            }
        }
    }
    if (s->f34 == 1) {
        s->f38++;
        if (s->f38 > 6) {
            s->f34 = 0;
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        } else if (s->f38 % 12 < 6) {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f3A, 0x20);
        } else {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        }
    }
    if (s->f8C == 0 && s->state != 8 && s->state < 11 && func_021BA244(s->f10) == 1) {
        func_021B9E3C(p, (char *)s);
        s->f8C = 1;
    }
    if (s->f8C == 1) {
        if (func_021BA244(s->f10) == 0) {
            s->f8C = 0;
            func_02043B5C(func_02045770(s->f2C), 0);
            func_02045334(s->f2C);
        } else {
            short *base = (short *)(func_021B8B84((int)p, (char *)func_021BDFE4(p)) + 0x800);
            int n = func_021BA24C(s->f10);
            int max = func_021BA254(s->f10);
            int w = func_021BA248(s->f10);
            if (n > max)
                n = max;
            func_021B9E5C((int)p, (char *)s, base, 3, (u32)(w * n) / max, w);
        }
    }
    if (func_0204B98C(s->f98) == 0) {
        if (s->state == 10)
            func_0204B878(s->f98, 0xF);
        else
            func_0204B878(s->f98, 1);
    }
    return 1;
}
