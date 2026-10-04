/*
 * function: func_021A0980
 * address:  0x021A0980
 * packet:   pkt_ov021_021A0980
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0818  0x021A0818  thumb  ov021
 *   func_021A08CC  0x021A08CC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A0818(void *o, u32 a, u32 b);
extern void func_021A08CC(s32 *o, const s16 *in, u32 c);

void func_021A0980(u8 *a, u8 *b, u8 *c, u16 d)
{
    u8 *p0;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    int i;

    i = 0;
    *(u16 *)(a + 0xf0) = i;
    *(u16 *)(a + 0xf2) = d;
    *(u16 *)(a + 0) = *(u16 *)(c + 0);
    *(s16 *)(a + 2) = *(s16 *)(c + 2);
    p0 = a;
    p0 += 8;
    p1 = a;
    p1 += 0x38;
    p2 = b;
    p2 += 0x10;
    p3 = c;
    p3 += 0x10;
    for (; i < 4; i++) {
        func_021A0818(p0 + i * 12, *(u16 *)(b + 8 + i * 2), *(u16 *)(c + 8 + i * 2));
        func_021A08CC((s32 *)(p1 + i * 0x1c), (const s16 *)(p2 + i * 6), (u32)(p3 + i * 6));
        a[4 + i] = c[4 + i];
    }
    func_021A0818(a + 0xa8, *(u16 *)(b + 0x28), *(u16 *)(c + 0x28));
    func_021A0818(a + 0xb4, *(u16 *)(b + 0x2a), *(u16 *)(c + 0x2a));
    func_021A0818(a + 0xc0, *(u16 *)(b + 0x2c), *(u16 *)(c + 0x2c));
    func_021A0818(a + 0xcc, *(u16 *)(b + 0x2e), *(u16 *)(c + 0x2e));
    func_021A0818(a + 0xd8, *(u16 *)(b + 0x30), *(u16 *)(c + 0x30));
    func_021A0818(a + 0xe4, *(u16 *)(b + 0x32), *(u16 *)(c + 0x32));
}
