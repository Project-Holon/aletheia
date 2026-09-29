/*
 * function: func_0218BE84
 * address:  0x0218BE84
 * packet:   pkt_ov021_0218BE84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_0218C0D8  0x0218C0D8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0(void *p);
extern void func_0218C0D8(void *p);

void func_0218BE84(u8 *s, u8 *e)
{
    u32 i;

    if (*(void **)e != 0) {
        func_020307B0(*(void **)e);
        *(void **)e = 0;
    }
    if (*(void **)(e + 8) != 0) {
        func_020307B0(*(void **)(e + 8));
        *(void **)(e + 8) = 0;
    }
    if (*(u8 **)(s + 0x1d8) != 0) {
        for (i = 0; i < *(u32 *)(s + 0x1d4); i++)
            func_0218C0D8(*(u8 **)(s + 0x1d8) + i * 0x18);
        func_020307B0(*(u8 **)(s + 0x1d8));
        *(u32 *)(s + 0x1d4) = 0;
        *(u8 **)(s + 0x1d8) = 0;
    }
}
