/*
 * function: func_021C11FC
 * address:  0x021C11FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C1AC0  0x021C1AC0  thumb  ov217
 *   func_021C1B74  0x021C1B74  thumb  ov217
 *   func_021C1F44  0x021C1F44  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021C1AC0(u8 *p, u8 key);
extern void func_021C1B74(u8 *h, void *e, s16 *out);
extern void func_021C1F44(const s16 *p, s32 *px, s32 *py);

void func_021C11FC(u8 *h, u8 key, s32 *px, s32 *py)
{
    s16 s[4];
    func_021C1B74(h, func_021C1AC0(h, key), s);
    func_021C1F44(s, px, py);
}


