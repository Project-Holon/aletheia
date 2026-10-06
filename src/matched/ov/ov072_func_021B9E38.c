/*
 * function: func_021B9E38
 * address:  0x021B9E38
 * packet:   pkt_ov072_021B9E38
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * `u8 a3` puts the request-block stores in source order, and `u16 heap`
 * (with the heap-taking callees declared u16, as ov070's twin does) moves
 * the r3 home store to the front of the prologue; with u32 for both the
 * spill and the stores are scheduled late (22 bytes).  The 64-byte table
 * copy is declared after the request, so it sits below it.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B974  0x0204B974  arm
 *   func_021B62E0  0x021B62E0  thumb  ov067
 *   func_021B6520  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[16]; } Tbl;

typedef struct {
    u8 *f0;
    u32 f4;
    int f8;
    u32 fC;
    u32 f10;
    u32 f14;
    int f18;
    int f1c;
} Req;

extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
struct Obj;
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B92C(struct Obj *p, u32 v);
struct Actor;
extern void func_0204B974(struct Actor *a);
extern u32 func_021B62E0(Req *r, int heap);
extern void func_021B6520(u8 *p, u32 v);
extern Tbl d_021BBB8C;

void func_021B9E38(u32 *o, u32 a1, u32 a2, u8 a3, u8 s0, u8 s1, u32 s2, u16 heap)
{
    Req r;
    Tbl t;
    Rect s;
    void *h;

    func_02082BCC(o, 0, 0x20);
    o[4] = s2;
    h = func_020490F4(0x55, heap);
    o[0] = func_0204AC18(h, 2, 0, 0, 0, 4, heap);
    o[1] = func_0204A6C8(h, 8, 0, 0, heap);
    o[2] = func_0204AF28(h, 0xc, 0x13, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    s.a = 0xa8;
    s.b = 0xa8;
    s.c = 7;
    o[5] = (u32)func_0204B294((void *)a2, o[1], o[0], o[2], &s, 0, heap);
    func_0204B92C((struct Obj *)o[5], 1);
    func_0204B974((struct Actor *)o[5]);
    t = d_021BBB8C;
    func_02082BCC(&r, 0, 0x20);
    r.f0 = (u8 *)&t;
    r.f4 = 2;
    r.f8 = a2;
    r.fC = a3;
    r.f10 = s0;
    r.f14 = s1 + 4;
    r.f18 = 2;
    o[3] = func_021B62E0(&r, heap);
    func_021B6520((u8 *)o[3], 10);
}
