/*
 * function: func_02194888
 * address:  0x02194888
 * packet:   pkt_ov021_02194888
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194AC8  0x02194AC8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 f0;
    u32 f4;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
    u16 fc;
    u16 fe;
    u32 f10;
} Cfg;

extern void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, Cfg *s);

void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 2;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 0x13;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, &s);
}
