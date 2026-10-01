/*
 * function: func_0218EFD4
 * address:  0x0218EFD4
 * packet:   pkt_ov021_0218EFD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020307B0(void *p);

void func_0218EFD4(u8 *a)
{
    if (*(u8 **)(a + 0xec) != 0) {
        func_020307B0(*(void **)(*(u8 **)(a + 0xec) + 0x20));
        func_020307B0(*(void **)(*(u8 **)(a + 0xec) + 0x24));
        func_020307B0(*(void **)(a + 0xec));
        *(void **)(a + 0xec) = 0;
    }
}
