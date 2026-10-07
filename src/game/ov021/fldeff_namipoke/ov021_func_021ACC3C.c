/*
 * function: func_021ACC3C
 * address:  0x021ACC3C
 * packet:   pkt_ov021_021ACC3C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021AC1A0  0x021AC1A0  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj19874.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Blk { u32 w[7]; } Blk;
typedef struct Inner { u16 a; u16 b; u8 pad[0x18]; u16 c; u16 pad2; u32 d, e, f; } Inner;
typedef struct B {
    u8 pad0[9];
    u8 f9;
    u8 pad1[2];
    u16 fc;
    u8 pad2[2];
    u32 f10;
    u32 f14;
    u16 f18;
    u8 pad3[2];
    Blk blk;
    Inner in;
} B;

extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32 a, u8 *b);
extern u32 func_021ABE18(u8 *p);
extern int func_021AC1A0(u32 a);
extern void func_021AC178(u32 a);

void func_021ACC3C(u32 a, B *b)
{
    u8 *p = (u8 *)func_021AC1AC(a);
    Inner *q;
    u32 k = 0x1000;
    b->blk = *(Blk *)p;
    func_021AC1CC(a, p + 0x10);
    b->fc = ((struct Obj19874 *)p)->fC;
    func_021ABE18((u8 *)(*(u32 *)b->blk.w[0]));
    b->f18 = *(u16 *)(b->blk.w[0] + 8);
    b->f9 = func_021AC1A0(a);
    b->f10 = k;
    b->f14 = k >> 2;
    q = &b->in;
    q->c = *(u16 *)(b->blk.w[0] + 0xa);
    b->in.a = 1;
    q->b = 9;
    q->d = k;
    q->e = k;
    q->f = k;
    func_021AC178(a);
}
