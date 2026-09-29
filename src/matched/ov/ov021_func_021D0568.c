/*
 * function: func_021D0568
 * address:  0x021D0568
 * packet:   pkt_ov021_021D0568
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C6744  0x021C6744  thumb  ov021
 *   func_021C6694  0x021C6694  thumb  ov021
 *   func_021C67A8  0x021C67A8  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C6664  0x021C6664  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    int x;
    int y;
    int z;
} Vec3;

typedef struct R {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u16 h18;
    u16 h1a;
    u16 h1c;
    u16 h1e;
    u32 f20;
} R;

extern void func_021C6744(u32 a, u32 b, u32 c, u32 d);
extern u32 func_021C6694(u32 a, u32 b, u32 c);
extern u32 func_021C67A8(u32 a, u32 b, u32 c);
extern void func_021AC1B8(u32 a, Vec3 *v);
extern void func_021C6664(u32 a, u32 b, Vec3 *v);
extern void func_021C67F4(u32 a, u32 b);

void func_021D0568(u32 a, R *b)
{
    Vec3 v;

    if (b->h1a == 1 && b->h1c == 0) {
        func_021C6744(b->f4, b->h18, 0, b->f20);
        if (func_021C6694(b->f4, b->h18, 0x1000) == 0) {
            b->h1c = 1;
        }
        b->f20 = func_021C67A8(b->f4, b->h18, 0);
    } else {
        func_021C6744(b->f4, b->h18, 0, b->f20);
    }
    func_021AC1B8(a, &v);
    func_021C6664(b->f4, b->h18, &v);
    func_021C67F4(b->f4, b->h18);
}
