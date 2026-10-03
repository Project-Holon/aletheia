/*
 * function: func_0218E104
 * address:  0x0218E104
 * packet:   pkt_ov021_0218E104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218E58C  0x0218E58C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0218E58C(u8 *a, u32 b);

void func_0218E104(u8 *a, u32 b)
{
    void (*fp)(void *, u32) = *(void (**)(void *, u32))(a + 0x1ac);
    if (fp != 0)
        fp(a, *(u32 *)(a + 0x1a8));
    func_0218E58C(a, b);
}
