/*
 * function: func_021A0A50
 * address:  0x021A0A50
 * packet:   pkt_ov021_021A0A50
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

void func_021A0A50(u8 *a, u8 *b, u32 c, u32 d)
{
    s32 i;

    *(u16 *)(a + 0xf0) = 0;
    *(u16 *)(a + 0xf2) = d;
    *(u16 *)a = *(u16 *)b;
    *(s16 *)(a + 2) = *(s16 *)(b + 2);
    for (i = 0; i < 4; i++) {
        func_021A0818(a + 8 + i * 12, *(u16 *)(b + 8 + i * 2), c);
        func_021A08CC((s32 *)(a + 0x38 + i * 0x1c), (const s16 *)(b + 0x10 + i * 6), (u32)(b + 0x10 + i * 6));
        a[4 + i] = b[4 + i];
    }
    func_021A0818(a + 0xa8, *(u16 *)(b + 0x28), c);
    func_021A0818(a + 0xb4, *(u16 *)(b + 0x2a), c);
    func_021A0818(a + 0xc0, *(u16 *)(b + 0x2c), c);
    func_021A0818(a + 0xcc, *(u16 *)(b + 0x2e), c);
    func_021A0818(a + 0xd8, *(u16 *)(b + 0x30), c);
    func_021A0818(a + 0xe4, *(u16 *)(b + 0x32), c);
}
