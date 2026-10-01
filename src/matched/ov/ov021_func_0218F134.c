/*
 * function: func_0218F134
 * address:  0x0218F134
 * packet:   pkt_ov021_0218F134
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02082BCC(void *dst, int val, u32 size);

void func_0218F134(u8 *a)
{
    func_02082BCC(a + 0x88, 0, 0x60);
    *(a + 0xe8) = 0;
}
