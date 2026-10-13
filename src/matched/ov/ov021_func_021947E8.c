/*
 * function: TALKMSGWIN_SetupPlainWindow
 * address:  0x021947E8
 * packet:   pkt_ov021_021947E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TALKMSGWIN_SetupEntry  0x02194AC8  thumb  ov021
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

extern void TALKMSGWIN_SetupEntry(u8 *p, u8 *e, u32 a, u32 b, u8 *s);

void TALKMSGWIN_SetupPlainWindow(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n)
{
    Cfg s;
    u8 *e;

    s.f0 = 0;
    s.f4 = 0;
    s.f8 = b;
    s.f9 = c;
    s.fa = d;
    s.fb = f;
    s.fc = 0x7FFF;
    s.fe = h;
    s.f10 = k;
    e = p + 0x18 + i * 100;
    TALKMSGWIN_SetupEntry(p, e, 0, a, (u8 *)(&s));
    e[0x5C] = m;
    e[0x5D] = n;
    e[2] = 1;
}
