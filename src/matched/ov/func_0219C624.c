/*
 * function: func_0219C624
 * address:  0x0219C624
 * packet:   pkt_0219C624
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
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0219CEAC  0x0219CEAC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216D520(void *p);
extern u32 func_0219CEAC(u32);

int func_0219C624(void *p)
{
return func_0219CEAC(func_0216D520(p));
}

