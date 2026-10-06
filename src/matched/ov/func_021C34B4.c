/*
 * function: func_021C34B4
 * address:  0x021C34B4
 * packet:   pkt_021C34B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_021C3490  0x021C3490  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_021C3490(void **p, int i);

int func_021C34B4(void **a, int b)
{
return ((func_021C3490((void **)a, b) + 1) * 100);
}

