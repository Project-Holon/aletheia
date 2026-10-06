/*
 * function: func_02191184
 * address:  0x02191184
 * packet:   pkt_ov021_02191184
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

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

struct Slot;
extern void func_02190538(struct Slot *s);
extern struct Slot *func_021904EC(u32 *p, u32 a, u32 b);
extern void func_02190590(struct Slot *s, int x, int y, u32 z);

void func_02191184(Q *q, u32 b, int c, u32 d)
{
    if (q->f08 != 0)
        func_02190538(q->f08);
    q->f08 = func_021904EC(q->f14, 0, q->f00);
    func_02190590(q->f08, (u16)(b + 8), c, d);
}
