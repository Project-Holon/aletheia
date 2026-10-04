/*
 * function: func_021B2FD8
 * address:  0x021B2FD8
 * packet:   pkt_ov021_021B2FD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_020127C4  0x020127C4  thumb
 *   func_02030734  0x02030734  arm
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_02012F08  0x02012F08  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_021B3158  0x021B3158  thumb  ov021
 *   func_021655D4  0x021655D4  thumb  ov010
 *   d_021DE210     0x021DE210  data   ov021  a1
 * Addresses are Black-image addresses.
 */

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
    u8  pad09[3];
    u16 f0C;
    u16 pad0E;
    u32 f10;
    u32 f14;
    void *f18;
    u32 f1C;
    u32 f20;
    u32 f24;
} Work;

extern unsigned int func_02159B10(void *, void *);
extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
struct Big;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0215A5F4(void *p);
extern void *func_02158FB4(void *p);
extern u32 func_02188C54(u8 *p);
extern u32 func_020127C4(u32 a);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021904AC(u8 *p);
extern void *func_02012F08(int *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void *func_02012F2C(int *p);
extern void func_020113D0(char *p, int val);
extern int func_021B3158(u32 a, u32 b);
extern void func_021655D4(void);
extern u8 d_021DE210[];

int func_021B2FD8(u32 a, u32 b)
{
    u32 v;
    void *t;
    u32 s;
    void *x;
    Work **slot;
    u32 y;
    u32 z;
    Work *w;

    v = func_02159B10((void *)a, (void *)b);
    func_02159AE8((void *)a, (void *)b);
    t = func_0215A5DC((void *)b);
    s = (u32)func_020120F4(t);
    x = func_0201210C((void *)t);
    slot = func_02158FB4(func_0215A5F4((void *)b));
    y = func_02188C54(x);
    z = func_020127C4(s);
    w = func_02030734(4, 0x214, 1, (const char *)d_021DE210, 0xFC);
    *slot = w;
    w->f10 = func_021904AC((u8 *)y);
    w->f14 = (u32)func_02012F08((int *)s);
    w->f0C = 0x15;
    w->f18 = func_0201292C((const struct BigObj *)s);
    w->f20 = (u32)func_020071CC((struct Sub020071CCCtrl *)func_02012EBC((struct Big *)s), 0x3a);
    w->f1C = (u32)func_02012F2C((int *)s);
    w->f24 = z;
    switch (v) {
    case 0xFF:
        w->b2 = v;
        break;
    case 0xFE:
        w->b2 = v;
        break;
    case 0xFD:
        w->b2 = v;
        break;
    case 0xF7:
    case 0xF8:
    case 0xF9:
    case 0xFA:
    case 0xFB:
        w->b2 = v;
        break;
    default:
        w->b2 = (u8)v;
        w->b3 = (u8)v;
        break;
    }
    func_020113D0((char *)a, (int)func_021B3158);
    if (v != 0xFE && v != 0xFD) {
        func_021655D4();
    }
    return 1;
}
