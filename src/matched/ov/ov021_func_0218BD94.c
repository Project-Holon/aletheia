/*
 * function: func_0218BD94
 * address:  0x0218BD94
 * packet:   pkt_ov021_0218BD94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0218BF84  0x0218BF84  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0(void *p);
extern void func_0218BF84(void *p);

void func_0218BD94(u8 *s)
{
    u32 i;

    if (*(u8 **)(s + 0x1cc) != 0) {
        for (i = 0; i < *(u32 *)(s + 0x1c8); i++)
            func_0218BF84(*(u8 **)(s + 0x1cc) + i * 0x18);
        func_020307B0(*(u8 **)(s + 0x1cc));
        *(u32 *)(s + 0x1c8) = 0;
        *(u8 **)(s + 0x1cc) = 0;
    }
}
