/*
 * function: func_02190550
 * address:  0x02190550
 * packet:   pkt_ov021_02190550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u8  f20;
} Slot;

extern void func_02045CAC(u32 a, u32 b, u32 c);
extern u32 func_02045770(u32 a);
extern void func_0201C6FC(u32 a, u32 b, s16 c, s16 d, u32 e, u32 f);

void func_02190550(Slot *s, int x, int y, u32 z)
{
    u32 t;

    func_02045CAC(s->f10, z, s->f18);
    t = s->f0c;
    func_0201C6FC(t, func_02045770(s->f1c), x, y, s->f18, s->f08);
    s->f20 = 1;
}
