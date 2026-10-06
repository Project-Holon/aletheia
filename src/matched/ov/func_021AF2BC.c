/*
 * function: func_021AF2BC
 * address:  0x021AF2BC
 * packet:   pkt_021AF2BC
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021AF26C  0x021AF26C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0215A5F4(void *p);
extern void func_021AF26C(u32 a);

int func_021AF2BC(u32 a, u32 b, u32 c, u32 d)
{
func_021AF26C((u32)func_0215A5F4((void *)b));
return 0;
}

