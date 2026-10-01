/*
 * function: func_0218D13C
 * address:  0x0218D13C
 * packet:   pkt_ov021_0218D13C
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

extern void func_020470D0(u32 a);
extern void func_02046EFC(u32 a);

void func_0218D13C(u8 *a)
{
    if (*(u32 *)(a + 0x60) != 0) {
        func_020470D0(*(u32 *)(a + 0x60));
        func_02046EFC(*(u32 *)(a + 0x60));
        *(u32 *)(a + 0x60) = 0;
    }
}
