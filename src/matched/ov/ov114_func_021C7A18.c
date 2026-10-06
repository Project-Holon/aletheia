/*
 * function: func_021C7A18
 * address:  0x021C7A18
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0209477C(const u8 *s);

u32 func_021C7A18(const u8 *a0)
{
    return func_0209477C(a0);
}
