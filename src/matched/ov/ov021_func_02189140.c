/*
 * function: func_02189140
 * address:  0x02189140
 * packet:   pkt_ov021_02189140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02061CA4  0x02061CA4  arm
 */

typedef enum { B_FALSE, B_TRUE } Bool;

typedef signed int     s32;
typedef unsigned int   u32;
s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);

/* Callback: forwards its last three arguments, with the first folded to 0/1. */
void func_02189140(int x, int b, void *c, int d)
{
    func_02061CA4((void *)(x == 0 ? B_FALSE : B_TRUE), b, (u32)c, d);
}
