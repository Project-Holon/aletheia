/*
 * function: func_021A7420
 * address:  0x021A7420
 * packet:   pkt_ov021_021A7420
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_0206E9A4  0x0206E9A4  arm
 *   func_02030734  0x02030734  arm
 *   func_021A7508  0x021A7508  thumb  ov021
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char d_021DDF7C;
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_0206E9A4(u32 a, u32 b);
extern void *func_02030734(u32 heap, u32 size, int one, const char *file, u16 line);
extern void func_021A7508(u32 a, u32 b, u32 c);

void func_021A7420(u32 *s, u32 a, u32 b, u32 n, u32 heap)
{
    u32 i;
    u32 h;
    i = 0;
    s[2] = func_0204A1BC(a, b, 0, heap);
    h = func_0206E9A4(s[2], 0);
    s[0] = (u32)func_02030734(heap, n * 12, 1, &d_021DDF7C, 0x196);
    s[1] = n;
    for (i = 0; i < s[1]; i++)
        func_021A7508(s[0] + i * 12, h, heap);
}
