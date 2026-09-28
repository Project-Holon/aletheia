/*
 * function: func_021CA1E4
 * address:  0x021CA1E4
 * packet:   pkt_ov021_021CA1E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the handle at +0x7c8 and allocates a fresh one from the object at +0x6c.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BAF4  0x0200BAF4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020307B0(void *h);
extern u32 func_02012EBC(u32 a);
extern u32 func_0200BAC8(u32 a);
extern void *func_0200BAF4(u32 a, int b);

void func_021CA1E4(u8 *p)
{
    if (*(void **)(p + 0x7c8) != 0)
        func_020307B0(*(void **)(p + 0x7c8));
    *(void **)(p + 0x7c8) = func_0200BAF4(func_0200BAC8(func_02012EBC(*(u32 *)(p + 0x6c))), 4);
}
