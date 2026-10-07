/*
 * file:     scrcmd_proc_fld_p01.c
 * unit:     yes
 * function: func_021B3158, func_021B3258
 * address:  0x021B3158
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_021B30C8  0x021B30C8  thumb  ov021
 *   func_0218FE50  0x0218FE50  thumb  ov021
 *   func_02193060  0x02193060  thumb  ov021
 *   func_021B35A4  0x021B35A4  thumb  ov021
 *   func_0218F9C4  0x0218F9C4  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_0218F878  0x0218F878  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021D9738     0x021D9738  data   ov021  a4
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021B3B14 0x021B3B14 thumb ov021
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_021B38E0 0x021B38E0 thumb ov021
 *   func_021B39C4 0x021B39C4 thumb ov021
 *   func_021B3A64 0x021B3A64 thumb ov021
 *   func_021B331C 0x021B331C thumb ov021
 *   func_021B3BD8 0x021B3BD8 thumb ov021
 *   func_021B3FA0 0x021B3FA0 thumb ov021
 *   func_021B3F00 0x021B3F00 thumb ov021
 *   func_021B40D4 0x021B40D4 thumb ov021
 *   func_021B43EC 0x021B43EC thumb ov021
 */
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Work {
    u8  state;
    u8  sub;
    u8  b2;
    u8  b3;
    u32 f04;
    u8  f08;
} Work;

typedef struct Buf24 {
    u32 w[6];
} Buf24;

extern void *func_0215A5F4(void *p);
extern void *func_02158FB4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C58(void *a);
extern void func_0218F0A8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_021B30C8(u32 *p, u32 b, void *h);
extern int func_0218FE50(u8 *a);
extern void func_02193060(u32 a);
extern int func_021B35A4(u32 a, char *p, u32 c, u8 d);
extern void func_0218F9C4(u8 *p, u8 *src, u16 v);
extern int func_0218EC60(u32 a);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218F05C(unsigned char *a);
extern void func_0218F878(u8 *a);
extern u32 func_020307B0(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern int func_021B3B14(char *p, int a);
extern void *func_02012F08(int *p);
extern int func_0200C258(void);
extern void func_021B38E0(char *p, int a, int b, int c);
extern void func_021B39C4(u8 *, int);
extern void func_021B3A64(char *p, int i);
extern void func_021B331C(u8 *, int);
extern void func_021B3BD8(char *p);
extern void func_021B3FA0(char *w);
extern void func_021B3F00(u8 *);
extern void func_021B40D4(char *w);
extern void func_021B43EC(char *w);
int func_021B3158(u32 a, u32 b);
void func_021B3258(int ctx, u8 *a, int b, int c);
extern const Buf24 d_021D9738;


/*
 * Task callback armed by func_021B2FD8; steps the 0x214-byte work block it
 * allocated.
 *
 * Addresses are Black-image addresses.
 */
int func_021B3158(u32 a, u32 b)
{
    Work **slot;
    Work *w;
    void *t;
    void *x;
    void *h;
    Buf24 buf;

    slot = func_02158FB4(func_0215A5F4((void *)b));
    w = *slot;
    t = func_0215A5DC((void *)b);
    x = func_0201210C((void *)t);
    h = func_02188C58(x);
    switch (w->state) {
    case 0:
        func_0218F0A8(h);
        w->state++;
        break;
    case 1:
        if (func_0218F0E8(h) == 0) {
            w->state++;
        }
        break;
    case 2:
        func_021B30C8((u32 *)w, (u32)x, h);
        w->state++;
        break;
    case 3:
        if (func_0218FE50(h) == 0) {
            w->state++;
            w->f08 = 0;
            func_02193060(0);
        }
        break;
    case 4:
        if (func_021B35A4((u32)t, (char *)(&w->f08), w->b2, w->b3)) {
            w->state++;
        }
        break;
    case 5:
        buf = d_021D9738;
        func_0218F9C4(h, (u8 *)(&buf), 8);
        w->state++;
        w->sub = 0;
        break;
    case 6:
        if (func_0218FE50(h) == 0) {
            func_0218EC60((u32)h);
            func_0218F1AC(h, w->f04);
            func_0218F05C(h);
            func_0218F878(h);
            func_02193060(1);
            w->state++;
        }
        break;
    case 7:
        func_020307B0(*slot);
        return 1;
    }
    return 0;
}


void func_021B3258(int ctx, u8 *a, int b, int c)
{
    void *t = func_020120F4((void *)ctx);
    int r;

    func_02012944(t);
    a[354] = 0;
    b = func_021B3B14((char *)a, b);
    r = b;
    switch (r) {
    case 255:
        func_02012F08(t);
        func_021B38E0((char *)a, r, c, func_0200C258());
        break;
    case 254:
        func_021B39C4(a, 0);
        a[355] = 1;
        break;
    case 253:
        a[355] = 1;
        a[354] = 1;
        func_021B39C4(a, 1);
        break;
    case 247:
    case 248:
    case 249:
    case 250:
    case 251:
        func_021B3A64((char *)a, r);
        break;
    default:
        func_021B38E0((char *)a, r, c, 0);
        break;
    }
    func_021B331C(a, a[355]);
    func_021B3BD8((char *)a);
    func_021B3FA0((char *)a);
    func_021B3F00(a);
    func_021B40D4((char *)a);
    func_021B43EC((char *)a);
}
