/*
 * function: func_021905C8
 * address:  0x021905C8
 * packet:   pkt_ov021_021905C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C724  0x0201C724  thumb  arm9
 *   func_02045770  0x02045770  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
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

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_0201C724(u32 a, u32 b, s16 c, s16 d, u32 e, u32 f, u16 g);

void func_021905C8(Slot *s, int x, int y, u32 z, u16 w, u32 v)
{
    u32 t;

    t = s->f0c;
    func_0201C724(t, (u32)func_02045770((struct Descriptor *)s->f1c), x, y, z, v, w);
    s->f20 = 1;
}
