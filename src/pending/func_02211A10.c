/*
 * function: func_02211A10
 * address:  0x02211A10
 * packet:   pkt_02211A10
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_0220AFDC  0x0220AFDC  thumb  ov196
 *
 * BLOCKER (2 bytes): the image decrements the pooled 0x218C index in place
 * (`subs r2, r2, #4` / `ldr r0, [r0, r2]`); mwcc keeps the pre-decrement
 * source live for the just-issued store and materialises the index-4 into r1
 * (`subs r1, r2, #4` / `ldr r0, [r0, r1]`).  `i -= 4` vs a named `j = i - 4`
 * vs the compound spelling `p[i - 4]` all reproduce r1; the store before the
 * decrement is what pins r2.  Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0220AFDC(u32);

u32 func_02211A10(u8 *p, u32 v)
{
    u32 i = 0x218c;

    *(u32 *)(p + i) = v;
    i -= 4;
    return func_0220AFDC(*(u32 *)(p + i));
}

