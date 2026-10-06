/*
 * function: func_021A6F4C
 * address:  0x021A6F4C
 * packet:   pkt_021A6F4C
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
 *   func_0216D888  0x0216D888  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *func_0216D888(void *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);

int func_021A6F4C(u32 a, u32 b, u32 c, u32 d)
{
return (int)func_0216D888(func_021A3074(func_02188CB4((struct Obj00020 *)a)));
}

