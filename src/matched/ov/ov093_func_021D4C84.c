/*
 * function: func_021D4C84
 * address:  0x021D4C84
 * packet:   pkt_ov093_021D4C84
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F3B88     0x021F3B88  data  ov093
 *   func_0203D3F8  0x0203D3F8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 pad04[3];
    u8 f07;
    u8 pad08[5];
    u8 f0d;
};

extern struct S *d_021F3B88;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

u32 func_021D4C84(u32 a, u32 b)
{
    struct S *p = d_021F3B88;
    u32 r;

    r = func_0203D3F8(p->f00, p->f07, 0x108, b, a, 0, 1, 1);
    if (r != 0) {
        p = d_021F3B88;
        p->f0d = 0;
    }
    return r;
}
