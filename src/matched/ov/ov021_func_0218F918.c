/*
 * function: func_0218F918
 * address:  0x0218F918
 * packet:   pkt_ov021_0218F918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218F89C  0x0218F89C  thumb
 *   func_0218F7D0  0x0218F7D0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0218F89C(void *a);
extern void func_0218F7D0(void *a, void *b);

void func_0218F918(u8 *a)
{
    if (a != 0) {
        func_0218F89C(a);
        func_0218F7D0(a, a + 0x124);
    }
}
