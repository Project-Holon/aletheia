/*
 * function: func_021BC430
 * address:  0x021BC430
 * packet:   pkt_ov088_021BC430
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02008448  0x02008448  thumb
 *   func_0200C31C  0x0200C31C  thumb
 *   func_020070C8  0x020070C8  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02008414  0x02008414  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_02011EEC  0x02011EEC  thumb
 *   func_020312F8  0x020312F8  arm
 *   func_02008450  0x02008450  thumb
 *   func_0200C324  0x0200C324  thumb
 *   func_020315D4  0x020315D4  arm
 *   d_0209DF9C     0x0209DF9C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct Rec12 {
    u32 a, b, c;
} Rec12;

typedef struct S1C {
    u16 f0;
    u16 pad;
    Rec12 rec;
    u32 x, y;
    s16 f18;
    s16 f1a;
} S1C;

struct Blk34;
struct Flags02008414;
struct Flags02008450;
struct Sub02007084Ctrl;
struct Sub02008700Obj;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern u32 func_02008448(void *);
extern u8 func_0200C31C(struct Blk34 *p);
extern int func_020070C8(char *self);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u8 func_02008414(const struct Flags02008414 *p);
extern void func_0200890C(void *, void *);
extern void *func_02011EEC(u32, u16, Rec12 *, int);
extern void func_020312F8(int, void *, void *);
extern void func_02008450(struct Flags02008450 *p, int on);
extern void func_0200C324(struct Blk34 *p, u8 v);
extern void func_020315D4(int);
extern char d_0209DF9C[];

int func_021BC430(int a, int b, int c, u32 *q)
{
    S1C s;
    void *r;
    u32 t;
    u8 h;

    r = func_020070A4();
    t = func_02008448((void *)q[1]);
    h = func_0200C31C((void *)q[3]);
    func_020070C8(r);
    func_02008414((const struct Flags02008414 *)func_0200873C(r));
    func_0200890C(r, &s);
    func_020312F8(-1, d_0209DF9C, func_02011EEC(1, s.f0, &s.rec, s.f18));
    func_02008450((void *)q[1], t);
    func_0200C324((void *)q[3], h);
    func_020315D4(a);
    return 1;
}
