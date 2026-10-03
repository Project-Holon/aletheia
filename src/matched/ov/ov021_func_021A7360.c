/*
 * function: func_021A7360
 * address:  0x021A7360
 * packet:   pkt_ov021_021A7360
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A7420  0x021A7420  thumb  ov021
 *   func_021A75DC  0x021A75DC  thumb  ov021
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021DDF7C;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021A7420(u32 *s, u32 a, u32 b, u32 n, u32 heap);
extern void func_021A75DC(u32 *s, u32 a, u32 b, u32 c, u32 heap);

typedef struct D { u16 lo : 8; u16 hi : 8; u16 f1, f2, f3, f4, f5, f6; } D;

u32 *func_021A7360(const D *p, u32 c, u32 heap)
{
    u32 *r;
    r = func_02030734(heap, 0x41c, 1, &d_021DDF7C, 0xd6);
    if (p->lo != 0) {
        u32 n = p->f1;
        u32 x = p->f2;
        u32 y = p->f3;
        func_021A7420(r + 2, x, y, n, heap);
    }
    if (p->hi != 0)
        func_021A75DC(r + 6, p->f4, p->f5, c, heap);
    r[0] = 1;
    r[1] = 0x1000;
    return r;
}
