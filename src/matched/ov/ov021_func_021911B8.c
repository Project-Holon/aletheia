/*
 * function: func_021911B8
 * address:  0x021911B8
 * packet:   pkt_ov021_021911B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02193044  0x02193044  thumb  ov021
 *   func_02193170  0x02193170  thumb  ov021
 *   func_02193200  0x02193200  thumb  ov021
 *   func_02193210  0x02193210  thumb  ov021
 *   func_021927C0  0x021927C0  thumb  ov021
 *   func_02194848  0x02194848  thumb  ov021
 *   func_02194888  0x02194888  thumb  ov021
 *   func_021948CC  0x021948CC  thumb  ov021
 *   func_02194940  0x02194940  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 x, y, z; } V3;

typedef struct { u32 f0; u32 f4; } S15C;
typedef struct A { u16 h[4]; u8 pad[0x15C - 8]; S15C s; } A;

typedef struct B {
    u8 f00;
    u8 mode;
    u16 f02;
    u32 f04;
    u32 f08;
    u32 f0c[2];
    A *a;
    V3 *v;
    V3 pos;
} B;

extern void func_02193170(u32);
extern void func_02193044(u32);
extern u32 func_02193210(u8 *p);
extern int func_02193200(u32 a);
struct Fx;
struct G;
extern void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
extern void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
extern void func_02194940(u8 *p, int i);
extern void func_021927C0(struct G *g, struct Fx *a);
extern void func_020061E4(u32);

void func_021911B8(A *a, B *b, u8 mode, V3 *v, u32 d, u32 e, u32 f)
{
    b->v = v;
    b->pos = *v;
    a->h[3] = 11;
    b->a = a;
    b->f08 = a->s.f0;
    b->mode = mode;
    func_02193170(a->h[0]);
    func_02193044(0);
    switch (mode) {
    case 0:
        func_02194848((u8 *)b->f08, 0, (u32)v, d, 15, e, f, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    case 1:
        func_02194888((u8 *)b->f08, 1, (u32)v, d, 15, e, f, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    default:
        func_021948CC((u8 *)b->f08, 2, (u32)v, d, 15, e, func_02193210((u8 *)((u32)&a->s.f4)));
        break;
    }
    func_02193200((u32)a + 0x160);
    func_02194940((u8 *)b->f08, b->mode);
    func_021927C0((struct G *)b->f0c, (struct Fx *)a->h);
    if (e == 1) {
        b->f02 = 8;
        func_020061E4(0x72C);
    }
}
