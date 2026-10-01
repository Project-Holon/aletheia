/*
 * function: func_02191648
 * address:  0x02191648
 * packet:   pkt_ov021_02191648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021904EC  0x021904EC  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02190590  0x02190590  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
} Fx;

typedef struct R {
    u32 f00;
    u32 f04;
    u32 f08;
    Fx *f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;
    u32 f24;
    u16 f28;
} R;

extern void func_02190538(void *s);
extern void *func_021904EC(Fx *p, u32 a, u32 b);
extern void func_02190590(void *s, int x, int y, u32 z);

void func_02191648(R *r, int b, int c, u32 d)
{
    if (r->f20 != 0)
        func_02190538(r->f20);
    r->f20 = func_021904EC(r->f0c, 0, r->f18);
    func_02190590(r->f20, b, c, d);
}
