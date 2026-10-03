/*
 * function: func_021EDA3C
 * address:  0x021EDA3C
 * packet:   pkt_ov093_021EDA3C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The 0/1 return uses enum constants: with int constants the compiler folds the two returns
 * into a boolean and lays the one first (bne). See
 * docs/idioms/a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md.
 *
 * symbols:
 *   func_021B9AE0  0x021B9AE0  thumb  ov093
 *   func_021B8BD0  0x021B8BD0  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;
extern u8 func_021B9AE0(u32);
extern int func_021B8BD0(u8 *, u8);
Bool func_021EDA3C(u8 *p, u32 x)
{
    if (func_021B8BD0(p, func_021B9AE0(x)) != 0)
        return B_FALSE;
    return B_TRUE;
}
