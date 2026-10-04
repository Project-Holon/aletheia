/*
 * function: func_0218A4BC
 * address:  0x0218A4BC
 * packet:   pkt_0218A4BC
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
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218A074  0x0218A074  thumb  ov021
 *   func_0218A240  0x0218A240  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CFC(u32, u32, u32, u32);
extern int func_0218A074(void *a, int b);
extern int func_0218A240(void *p, unsigned char *pos);

int func_0218A4BC(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188CFC(b, b, c, d) == 0) {
    return func_0218A074((void *)a, b);
}
return func_0218A240((void *)a, (unsigned char *)b);
}

