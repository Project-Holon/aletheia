/*
 * function: func_021A6B88
 * address:  0x021A6B88
 * packet:   pkt_021A6B88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02082BCC(void *p, u32 v, u32 n);

int func_021A6B88(void *a)
{
    func_02082BCC(a, 0, 8);
    *(u32 *)((u8 *)a + 4) = 9;
    return 9;
}

