/*
 * function: func_021AC2F0
 * address:  0x021AC2F0
 * packet:   pkt_ov021_021AC2F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct V3 { int x, y, z; } V3;

typedef struct Desc {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Sys { u8 pad[0x10]; u32 f10; u32 f14; u32 f18; } Sys;
typedef struct Arg4 { u8 b0; } Arg4;

typedef struct P {
    u32 f0;
    Sys *sys;
    u32 f8;
    u16 fc[4];
    u32 f14;
} P;

struct BbActDesc;
struct BbActSys;
extern int func_021AC1AC(u32 a);
extern int func_0216E1A4(int a0, int a1);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_0204F6DC(u8 *a0, int i, u8 *px);
extern void func_021AC178(u32 a);

void func_021AC2F0(u32 a, P *p)
{
    u32 *q = (u32 *)func_021AC1AC(a);
    Arg4 t;
    Desc s;

    p->sys = (Sys *)q[0];
    p->f8 = q[1];
    func_0216E1A4(q[1], (int)p->fc);
    s.slot = 0;
    s.v12 = 0x1000;
    s.v14 = 0x1000;
    s.k = 0x13;
    s.flag = 1;
    s.w = 1;
    {
        V3 zero = {0, 0, 0};

        s.pos = zero;
    }
    s.f1c = 0;
    s.f20 = (u32)p;
    p->f14 = func_02050340((struct BbActSys *)p->sys->f10, (u16)p->sys->f18, (const struct BbActDesc *)(&s), 1, 3);
    if (p->f14 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    t.b0 = 2;
    func_0204F6DC((u8 *)p->sys->f14, p->f14, (u8 *)(&t));
    func_021AC178(a);
}
