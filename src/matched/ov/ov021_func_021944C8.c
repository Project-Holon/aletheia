/*
 * function: func_021944C8
 * address:  0x021944C8
 * packet:   pkt_ov021_021944C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *func_0216D69C(void *p);

void func_021944C8(u32 a)
{
    *(u16 *)(*(u8 **)((u8 *)func_0216D69C((void *)a) + 0xC) + 4) = 1;
}
