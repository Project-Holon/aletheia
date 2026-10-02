/*
 * function: func_021CC6FC
 * address:  0x021CC6FC
 * packet:   pkt_021CC6FC
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
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021F5340  0x021F5340  thumb  ov083
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0215897C(u32, u32);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4();
extern u32 func_021F5340(u32);

int func_021CC6FC(u32 a, u32 b, u32 c, u32 d)
{
func_0215897C(func_0215A5F4(b, b, c, d), func_021F5340(func_0215A5DC((void *)b)));
return 1;
}

