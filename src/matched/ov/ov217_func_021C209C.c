/*
 * function: func_021C209C
 * address:  0x021C209C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C25A8  0x021C25A8  thumb  ov217
 *   func_021C25C4  0x021C25C4  thumb  ov217
 *   func_021C2614  0x021C2614  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C25A8();
extern u32 func_021C25C4();
extern void func_021C2614(char *p);
u32 func_021C209C(u32 a0)
{
    func_021C2614((char *)a0);
    func_021C25C4(a0);
    return func_021C25A8(a0);
}

