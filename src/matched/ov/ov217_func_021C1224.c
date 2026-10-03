/*
 * function: func_021C1224
 * address:  0x021C1224
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
 *   func_021C1AB4  0x021C1AB4  thumb  ov217
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

extern void *func_021C1AB4(void *p, u32 n);
extern void func_021C1B74(u8 *h, void *e, s16 *out);
extern void func_021C1F44(const s16 *p, s32 *px, s32 *py);

void func_021C1224(u8 *h, u8 n, s32 *px, s32 *py)
{
    s16 s[4];
    func_021C1B74(h, func_021C1AB4(h, n), s);
    func_021C1F44(s, px, py);
}


