/*
 * function: func_021A0B4C
 * address:  0x021A0B4C
 * packet:   pkt_ov021_021A0B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Inverse of func_021A0A50. The source pointer must be const: without it
 * the six trailing strh stores are scheduled ahead of the next call's
 * `adds rN, #0xf0/#0xf2` address setup (24 bytes differ).
 *
 * symbols:
 *   func_021A0860  0x021A0860  thumb  ov021
 *   func_021A0918  0x021A0918  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern u16 func_021A0860(const void *o, u32 x, u32 y);
extern void func_021A0918(const void *o, u32 x, u32 y, void *out);

void func_021A0B4C(const u8 *a, u8 *b)
{
    s32 i;
    u16 r;

    *(u16 *)b = *(const u16 *)a;
    *(s16 *)(b + 2) = *(const s16 *)(a + 2);
    for (i = 0; i < 4; i++) {
        *(u16 *)(b + 8 + i * 2) = func_021A0860(a + 8 + i * 12, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
        func_021A0918(a + 0x38 + i * 0x1c, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2), b + 0x10 + i * 6);
        b[4 + i] = a[4 + i];
    }
    r = func_021A0860(a + 0xa8, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x28) = r;
    r = func_021A0860(a + 0xb4, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x2a) = r;
    r = func_021A0860(a + 0xc0, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x2c) = r;
    r = func_021A0860(a + 0xcc, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x2e) = r;
    r = func_021A0860(a + 0xd8, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x30) = r;
    r = func_021A0860(a + 0xe4, *(const u16 *)(a + 0xf0), *(const u16 *)(a + 0xf2));
    *(u16 *)(b + 0x32) = r;
}
