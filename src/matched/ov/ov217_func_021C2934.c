/*
 * function: func_021C2934
 * address:  0x021C2934
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
 *   func_021C2958  0x021C2958  thumb  ov217
 *   func_021C295C  0x021C295C  thumb  ov217
 *   func_021C29B4  0x021C29B4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021C2958(void *p, u32 v);
extern u32 func_021C295C();
extern void func_021C29B4(void *p, const void *src);
u32 func_021C2934(u32 a0, u32 a1, u32 a2)
{
    func_021C2958((void *)a0, a2);
    func_021C29B4((void *)a0, (const void *)a1);
    return func_021C295C(a0);
}

