/*
 * function: func_021A0104
 * address:  0x021A0104
 * packet:   pkt_ov021_021A0104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   d_021DDE1C     0x021DDE1C  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDE1C[];
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void func_021A01D8(u8 *p);

u8 *func_021A0104(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x44, 1, d_021DDE1C, 0x89);
    p[1] = 0;
    p[3] = 0x1F;
    *(u32 *)(p + 4) = 0x7FFF;
    func_021A01D8(p);
    return p;
}
