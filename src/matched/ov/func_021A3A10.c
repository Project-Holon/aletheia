/*
 * function: func_021A3A10
 * address:  0x021A3A10
 * packet:   pkt_021A3A10
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_021A31D0  0x021A31D0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 func_0216D598(void *p);
extern int func_021A31D0(u16 id);
extern void *func_021A3960(u8 *p);

int func_021A3A10(u32 a, u32 b, u32 c, u32 d)
{
return func_021A31D0(func_0216D598(func_021A3960((u8 *)a)));
}

