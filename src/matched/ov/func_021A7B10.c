/*
 * function: func_021A7B10
 * address:  0x021A7B10
 * packet:   pkt_021A7B10
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D4B4(void *);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(unsigned char *p);

int func_021A7B10(void *a)
{
return func_0216D4B4(func_021A3074(func_02188CB4((u8 *)a)));
}

